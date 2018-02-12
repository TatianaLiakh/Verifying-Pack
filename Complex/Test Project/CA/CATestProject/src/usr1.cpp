#include "CAusr1.h"
#include "msg_queue.h"
QueueMsg last_msg;

MsgQueue MainInputQueue;
MsgQueue MainOutputQueue;


int GetOutMsgNumber_GUI(void)
{
	return GetLenMsgQueue(&MainOutputQueue);
}
//ÔÓÍÊÖÈß ÖÅË GetNextMsgGUI(ÏÓÑÒÎ);
int GetNextMsgGUI(void)
{
	return GetHeadMsgQueue(&MainInputQueue, &last_msg);
}

//ÔÓÍÊÖÈß ÖÅË  GetMsgGUICode        (ÏÓÑÒÎ);  /*÷òåíèå èç ïàìÿòè êîäà ñîáûòèÿ */
int GetMsgGUICode()
{
	return last_msg.code;
}

//ÔÓÍÊÖÈß ÏËÀÂ GetFloatParamPIV     (ÏÓÑÒÎ);  /*÷òåíèå èç ïàìÿòè ïàğàìåòğà ñîáûòèÿ */
float GetFloatParamGUI()
{
	return last_msg.param.pr_float;
}

/* ÔÓÍÊÖÈß ÊÖÅË GetShortParamPIV     (ÏÓÑÒÎ); */
short GetShortParamPIV()
{
	return last_msg.param.pr_short[0];
}

//ÔÓÍÊÖÈß ÖÅË  GetIntParamPIV       (ÏÓÑÒÎ);
int GetIntParamPIV()
{
	return last_msg.param.pr_int;
}

//ÔÓÍÊÖÈß ÄÖÅË GetLongParamPIV      (ÏÓÑÒÎ);
long GetLongParamGUI()
{
	return last_msg.param.pr_long;
}

//ÔÓÍÊÖÈß ÖÅË  SendMsgGUICode       (ÖÅË);
int SendMsgGUICode(int code)
{
	return PutTailMsgQueue(&MainOutputQueue, code);
}

//ÔÓÍÊÖÈß ÖÅË  SendMsgFloatParamGUI (ÖÅË, ÏËÀÂ);
int SendMsgFloatParamGUI(int code, float param)
{
	return PutTailMsgQueueF(&MainOutputQueue, code, param);

}

/* ÔÓÍÊÖÈß ÖÅË  SendMsgShortParamPIV (ÖÅË, ÊÖÅË); */
int SendMsgShortParamPIV(int code, short param)
{
	return PutTailMsgQueueS(&MainOutputQueue, code, param);

}

/* ÔÓÍÊÖÈß ÖÅË  SendMsgIntParamPIV   (ÖÅË, ÖÅË); */
int SendMsgIntParamPIV(int code, int param)
{
	return PutTailMsgQueueI(&MainOutputQueue, code, param);

}

//ÔÓÍÊÖÈß ÖÅË  SendMsgLongParamGUI  (ÖÅË, ÄÖÅË);
int SendMsgLongParamGUI(int code, long param)
{
	return PutTailMsgQueueL(&MainOutputQueue, code, param);
}

//ÔÓÍÊÖÈß ÖÅË  GetInpMsgNumber_PIV (ÏÓÑÒÎ);  /* ÷òåíèå ÷èñëà ñîîáù. âî âõîäí. áóôåğå */
int GetInpMsgNumber_PIV()
{
	return GetLenMsgQueue(&MainInputQueue);
}

//ÔÓÍÊÖÈß ÖÅË  GetOutMsgNumber_PIV (ÏÓÑÒÎ); /* ÷òåíèå ÷èñëà ñîîáù. â âûõîäí. áóôåğå */*/
int GetOutMsgNumber_PIV()
{
	return GetLenMsgQueue(&MainOutputQueue);

}