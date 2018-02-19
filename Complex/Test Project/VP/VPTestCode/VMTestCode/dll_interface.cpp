#include "dll_interface.h" 
#include "r_io.h"
#include "R_LIB.H"

#include "r_main.h" 
#include "msg_queue.h"
#include "queue_const.h"
#include "extcode.h"


int32_t input_counter  = 0;
int32_t output_counter = 0;






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

