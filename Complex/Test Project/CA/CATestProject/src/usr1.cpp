#include "CAusr1.h"
#include "msg_queue.h"
QueueMsg last_msg;

MsgQueue MainInputQueue;
MsgQueue MainOutputQueue;


int GetOutMsgNumber_GUI(void)
{
	return GetLenMsgQueue(&MainOutputQueue);
}
//������� ��� GetNextMsgGUI(�����);
int GetNextMsgGUI(void)
{
	return GetHeadMsgQueue(&MainInputQueue, &last_msg);
}

//������� ���  GetMsgGUICode        (�����);  /*������ �� ������ ���� ������� */
int GetMsgGUICode()
{
	return last_msg.code;
}

//������� ���� GetFloatParamPIV     (�����);  /*������ �� ������ ��������� ������� */
float GetFloatParamGUI()
{
	return last_msg.param.pr_float;
}

/* ������� ���� GetShortParamPIV     (�����); */
short GetShortParamPIV()
{
	return last_msg.param.pr_short[0];
}

//������� ���  GetIntParamPIV       (�����);
int GetIntParamPIV()
{
	return last_msg.param.pr_int;
}

//������� ���� GetLongParamPIV      (�����);
long GetLongParamGUI()
{
	return last_msg.param.pr_long;
}

//������� ���  SendMsgGUICode       (���);
int SendMsgGUICode(int code)
{
	return PutTailMsgQueue(&MainOutputQueue, code);
}

//������� ���  SendMsgFloatParamGUI (���, ����);
int SendMsgFloatParamGUI(int code, float param)
{
	return PutTailMsgQueueF(&MainOutputQueue, code, param);

}

/* ������� ���  SendMsgShortParamPIV (���, ����); */
int SendMsgShortParamPIV(int code, short param)
{
	return PutTailMsgQueueS(&MainOutputQueue, code, param);

}

/* ������� ���  SendMsgIntParamPIV   (���, ���); */
int SendMsgIntParamPIV(int code, int param)
{
	return PutTailMsgQueueI(&MainOutputQueue, code, param);

}

//������� ���  SendMsgLongParamGUI  (���, ����);
int SendMsgLongParamGUI(int code, long param)
{
	return PutTailMsgQueueL(&MainOutputQueue, code, param);
}

//������� ���  GetInpMsgNumber_PIV (�����);  /* ������ ����� �����. �� �����. ������ */
int GetInpMsgNumber_PIV()
{
	return GetLenMsgQueue(&MainInputQueue);
}

//������� ���  GetOutMsgNumber_PIV (�����); /* ������ ����� �����. � ������. ������ */*/
int GetOutMsgNumber_PIV()
{
	return GetLenMsgQueue(&MainOutputQueue);

}