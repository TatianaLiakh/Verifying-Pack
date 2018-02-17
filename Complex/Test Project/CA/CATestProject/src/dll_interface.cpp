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


MgErr _ports_array_resize(PortsHdl new_handler, size_t size, INT8S * array, int32_t & counter)
{
	MgErr error = NumericArrayResize(uB, 1, (UHandle*)(&new_handler), size );
	if (error == mgNoErr)
	{
		(*new_handler)->dimSize = size;
		counter = (*new_handler)->dimSize;
	}
	
	//(*new_handler)->ports[size] = 255;
	return error;
}

 int8_t set_input_ports_array(PortsHdl new_handler)
{
	return _ports_array_resize(new_handler, size_t(INPUT_PORTS_COUNTER), aInput, input_counter);
}

 int8_t set_output_ports_array(PortsHdl new_handler)
{
	return _ports_array_resize(new_handler, size_t(OUTPUT_PORTS_COUNTER), aOutput, output_counter);

}

MgErr _msg_array_resize(ArrayOfMessagesHdl _msgs)
{
	int32_t new_size = ARRLENRSMSG; 
		MgErr err;
		if (mgNoErr == (err = DSSetHSzClr(_msgs, Offset(ArrayOfMessages, message) + new_size * sizeof(MessageCluster))))
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

 int8_t set_input_msg(ArrayOfMessagesHdl input_msg)
{
	return _msg_array_resize(input_msg); 
}

int8_t set_output_msg(ArrayOfMessagesHdl output_msg)
{
	return _msg_array_resize(output_msg);
}


 int8_t set_states_array(ArrayOfStatesHdl states_hdl)
{	
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

void parse_input_msg_array(ArrayOfMessagesHdl inputMsgArray)
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

void parse_output_msg_array(ArrayOfMessagesHdl outputMsgArray)
{
	for (int32_t i = 0; i < (*outputMsgArray)->dimSize; i++)
	{
		if (true != isEmptyMsgQueue(&MainOutputQueue))
		{
			QueueMsg msg;
			GetHeadMsgQueue(&MainOutputQueue, &msg);
			(*outputMsgArray)->message[i].msg = msg.code;
			(*outputMsgArray)->message[i].param = msg.param.pr_long;
			(*outputMsgArray)->message[i].type = msg.type;
		}
		else
		{
			(*outputMsgArray)->message[i].msg = -1;
			(*outputMsgArray)->message[i].param = 0;
			(*outputMsgArray)->message[i].type = 0;
		}
	}

}


