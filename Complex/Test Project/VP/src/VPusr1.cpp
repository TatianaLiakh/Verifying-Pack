#include "VPusr1.h"
#include "msg_queue.h"
QueueMsg last_msg;

MsgQueue MainInputQueue;
MsgQueue MainOutputQueue;


int GetOutMsgNumberFromScenariousBlock(void)
{
	return GetLenMsgQueue(&MainOutputQueue);
}
//ÔÓÍÊÖÈß ÖÅË GetMessageFromScenariousBlock(ÏÓÑÒÎ);
int GetMessageFromScenariousBlock(void)
{
	return GetHeadMsgQueue(&MainInputQueue, &last_msg);
}

//ÔÓÍÊÖÈß ÖÅË  GetMessageCodeFromScenariousBlock        (ÏÓÑÒÎ);  /*÷òåíèå èç ïàìÿòè êîäà ñîáûòèÿ */
int GetMessageCodeFromScenariousBlock()
{
	return last_msg.code;
}

//ÔÓÍÊÖÈß ÏËÀÂ GetFloatParamFromScenariousBlock     (ÏÓÑÒÎ);  /*÷òåíèå èç ïàìÿòè ïàğàìåòğà ñîáûòèÿ */
float GetFloatParamFromScenariousBlock()
{
	return last_msg.param.pr_float;
}

/* ÔÓÍÊÖÈß ÊÖÅË GetShortParamFromScenariousBlock     (ÏÓÑÒÎ); */
short GetShortParamFromScenariousBlock()
{
	return last_msg.param.pr_short[0];
}

//ÔÓÍÊÖÈß ÖÅË  GetIntParamFromScenariousBlock       (ÏÓÑÒÎ);
int GetIntParamFromScenariousBlock()
{
	return last_msg.param.pr_int;
}

//ÔÓÍÊÖÈß ÄÖÅË GetLongParamFromScenariousBlock      (ÏÓÑÒÎ);
long GetLongParamFromScenariousBlock()
{
	return last_msg.param.pr_long;
}

//ÔÓÍÊÖÈß ÖÅË  SendMsgFromScenariousBlockCode       (ÖÅË);
int SendMsgFromScenariousBlockCode(int code)
{
	return PutTailMsgQueue(&MainOutputQueue, code);
}

//ÔÓÍÊÖÈß ÖÅË  SendMsgFloatParamFromScenariousBlock (ÖÅË, ÏËÀÂ);
int SendMsgFloatParamFromScenariousBlock(int code, float param)
{
	return PutTailMsgQueueF(&MainOutputQueue, code, param);

}

/* ÔÓÍÊÖÈß ÖÅË  SendMsgShortParamFromScenariousBlock (ÖÅË, ÊÖÅË); */
int SendMsgShortParamFromScenariousBlock(int code, short param)
{
	return PutTailMsgQueueS(&MainOutputQueue, code, param);

}

/* ÔÓÍÊÖÈß ÖÅË  SendMsgIntParamFromScenariousBlock   (ÖÅË, ÖÅË); */
int SendMsgIntParamFromScenariousBlock(int code, int param)
{
	return PutTailMsgQueueI(&MainOutputQueue, code, param);

}

//ÔÓÍÊÖÈß ÖÅË  SendMsgLongParamFromScenariousBlock  (ÖÅË, ÄÖÅË);
int SendMsgLongParamFromScenariousBlock(int code, long param)
{
	return PutTailMsgQueueL(&MainOutputQueue, code, param);
}

//ÔÓÍÊÖÈß ÖÅË  GetInpMsgNumber_FromScenariousBlock (ÏÓÑÒÎ);  /* ÷òåíèå ÷èñëà ñîîáù. âî âõîäí. áóôåğå */
int GetInpMsgNumber_FromScenariousBlock()
{
	return GetLenMsgQueue(&MainInputQueue);
}

