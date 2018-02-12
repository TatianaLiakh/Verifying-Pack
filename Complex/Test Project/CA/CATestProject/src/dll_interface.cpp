#include "dll_interface.h" 
#include "r_io.h"
#include "R_LIB.H"

#include "r_main.h" 
#include "msg_queue.h"
#include "queue_const.h"
#include "extcode.h"



INT8S * aInput = nullptr;
INT8S * aOutput = nullptr;

int32_t input_counter  = 0;
int32_t output_counter = 0;

ArrayOfMessagesHdl inputMsgArray = nullptr;
ArrayOfMessagesHdl outputMsgArray = nullptr;

ArrayOfStatesHdl states = nullptr;


MgErr _array_resize(PortsHdl new_handler, size_t size, INT8S * & array, int32_t & counter)
{
	MgErr error = NumericArrayResize(uB, 1, (UHandle*)(&new_handler), size );
	if (error == mgNoErr)
	{
		(*new_handler)->dimSize = size;
		array = reinterpret_cast<INT8S*> ((*new_handler)->ports);
		counter = (*new_handler)->dimSize;
	}
	
	//(*new_handler)->ports[size] = 255;
	return error;
}

__declspec(dllexport) int8_t set_input_ports_array(PortsHdl new_handler)
{
	return _array_resize(new_handler, size_t(INPUT_PORTS_COUNTER), aInput, input_counter);
}

__declspec(dllexport) int8_t set_output_ports_array(PortsHdl new_handler)
{
	return _array_resize(new_handler, size_t(OUTPUT_PORTS_COUNTER), aOutput, output_counter);

}

MgErr _msg_array_resize(ArrayOfMessagesHdl _msgs)
{
	int32_t new_size = ARRLENRSMSG; 
		MgErr err;
		if (mgNoErr == (err = DSSetHSzClr(_msgs, Offset(ArrayOfMessages, message) + sizeof(MessageCluster))))
		{
			for (size_t i = 0; i < new_size; i++)
			{
				MessageCluster *msg = &((*_msgs)->message[i]);
				msg->msg = -1;
				msg->type = 0;
				msg->param = 0; // For new string - (LStrHandle)DSNewHClr(sizeof(LStrHandle) + sizeof(uChar)*size_of_srting +1);
			}
			(*_msgs)->dimSize = new_size;
		}
		return err;
}

__declspec(dllexport) int8_t set_input_msg(ArrayOfMessagesHdl input_msg)
{
	inputMsgArray = input_msg; 
	return _msg_array_resize(input_msg); 
}

__declspec(dllexport) int8_t set_output_msg(ArrayOfMessagesHdl output_msg)
{
	outputMsgArray = output_msg;
	return _msg_array_resize(output_msg);
}


__declspec(dllexport) int8_t set_states_array(ArrayOfStatesHdl states_hdl)
{	
	states = states_hdl;
	MgErr error;
	if (mgNoErr == (error = DSSetHSzClr(states_hdl, Offset(ArrayOfStates, state) + sizeof(ProcessState) * (PROCESS_Nn + 1))))
	{
		for (size_t i = 0; i <= PROCESS_Nn; i++)
		{
			(*states_hdl)->state[i].cur_state = (int8_t)STATE_OF_STOP;
			(*states_hdl)->state[i].TimeInState = 0;
		}
	}
	return error;

}

void parse_input_msg_array()
{
	//inputMsgArray
	MessageCluster * iter = (*inputMsgArray)->message;

	for (int i = 0; i < (*inputMsgArray)->dimSize; i++)
	{
		if (-1 == iter[i].msg)
			return;

		switch (iter[i].type)
		{
			case EMPTY_MSG:
				PutTailMsgQueue(&MainInputQueue, iter[i].msg );
				break;
			case BYTE_TYPE:
				PutTailMsgQueueB(&MainInputQueue, iter[i].msg, static_cast<char> (iter[i].param));
				break;
			case  INT_TYPE:
				PutTailMsgQueueI(&MainInputQueue, iter[i].msg, iter[i].param);
				break;
			case FLOAT_TYPE:
				PutTailMsgQueueF(&MainInputQueue, iter[i].msg, *(float32 *)(&(iter[i].param)));
				break;
			default:
				break;
		}
	}
}

void parse_output_msg_array()
{
	for (int i = 0; true != isEmptyMsgQueue(&MainOutputQueue); i++)
	{
		QueueMsg msg;
		if ((*outputMsgArray)->dimSize < i) return;

		GetHeadMsgQueue(&MainOutputQueue, &msg);
		(*outputMsgArray)->message[i].msg = msg.code;
		(*outputMsgArray)->message[i].param = msg.param.pr_long;
		(*outputMsgArray)->message[i].type = msg.type;

	}
}

__declspec(dllexport)void LLD()
{
	static int32_t counter = 0;
	if (0 == counter)
	{
		Init_PSW((INT16U)(PROCESS_N1), (INT16U)PROCESS_Nn); // »нициализаци¤  PSW процессов
		counter = 1;
		ConstructMsgQueue(&MainInputQueue);
		ConstructMsgQueue(&MainOutputQueue); 
	}

	parse_input_msg_array();
	Control_Loop();
	parse_output_msg_array();

	for (int k = 0; k < (*states)->dimSize && k <= PROCESS_Nn; k++)
	{
		(*states)->state[k].cur_state = Pr_States[k].cur_state;
		(*states)->state[k].TimeInState = Pr_States[k].TimeInState;
	}

}

