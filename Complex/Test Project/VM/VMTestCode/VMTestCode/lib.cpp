#include "lib.h"


extern PortsHdl algInputPorts;
extern PortsHdl algOutputPorts;


MgErr checkPortsArrays()
{
	if (algInputPorts != nullptr && algOutputPorts != nullptr)
	{
		if ((*algInputPorts)->dimSize + (*algOutputPorts)->dimSize != INPUT_PORTS_COUNTER)
			return mgArgErr;
		else
		{
			aInput = new INT8S[INPUT_PORTS_COUNTER];
			for (int i = 0; i < INPUT_PORTS_COUNTER; i++)
			{
				aInput[i] = 0;
			}
		}
	}
	return mgNoErr;
}

MgErr _msg_array_resize(ArrayOfMessagesHdl _msgs)
{
	int32_t new_size = ARRLENRSMSG;
	MgErr err;
	if (mgNoErr == (err = DSSetHSzClr(_msgs, Offset(ArrayOfMessages, message) + new_size* sizeof(MessageCluster))))
//	if (mgNoErr == (err = DSSetHSzClr(_msgs, sizeof(int32) + sizeof(MessageCluster))))

	{
		for (size_t i = 0; i < new_size; i++)
		{
			//UHandle msg = DSNewHandle(sizeof(MessageCluster)); 
			//
			//MessageCluster ** msgPtrtPtr = (MessageCluster **)msg; 

			////MessageCluster * mP = ()
			//(*msgPtrtPtr)->msg = 0; 
			//(*msgPtrtPtr)->type = 0;

			//(*msgPtrtPtr)->param = 0;

				//;// = &((*_msgs)->message[i]);
			MessageCluster * msg = &(*_msgs)->message[i];
			msg->msg = 10;
			msg->type = -9;
			msg->param = 100; // For new string - (LStrHandle)DSNewHClr(sizeof(LStrHandle) + sizeof(uChar)*size_of_srting +1);
		//	MoveBlock(msgPtrtPtr, &((*_msgs)->message[i]), sizeof(MessageCluster));
			//	(*_msgs)->message[i] = *msgPtrtPtr; 
		}
		(*_msgs)->dimSize = new_size;
	}
	return err;
}

void parse_input_msg_array(ArrayOfMessagesHdl input_LV_queue, MsgQueue & result_queue)
{
	//inputMsgArray
	MessageCluster * iter = (*input_LV_queue)->message;

	for (int i = 0; i < (*input_LV_queue)->dimSize; i++)
	{
		if (-1 == iter[i].msg)
			return;

		switch (iter[i].type)
		{
		case EMPTY_MSG:
			PutTailMsgQueue(&result_queue, iter[i].msg);
			break;
		case BYTE_TYPE:
			PutTailMsgQueueB(&result_queue, iter[i].msg, static_cast<char> (iter[i].param));
			break;
		case  INT_TYPE:
			PutTailMsgQueueI(&result_queue, iter[i].msg, iter[i].param);
			break;
		case FLOAT_TYPE:
			PutTailMsgQueueF(&result_queue, iter[i].msg, *(float32 *)(&(iter[i].param)));
			break;
		default:
			break;
		}
	}
}

void parse_output_msg_array(MsgQueue & output_queue, ArrayOfMessagesHdl output_LV_queue)
{
	for (int i = 0; true != isEmptyMsgQueue(&output_queue); i++)
	{
		QueueMsg msg;
		if ((*output_LV_queue)->dimSize < i) return;

		GetHeadMsgQueue(&output_queue, &msg);
		(*output_LV_queue)->message[i].msg = msg.code;
		(*output_LV_queue)->message[i].param = msg.param.pr_long;
		(*output_LV_queue)->message[i].type = msg.type;

	}
}