#include "VPusr1.h"
#include "msg_queue.h"
QueueMsg last_msg;

MsgQueue MainInputQueue;
MsgQueue MainOutputQueue;


int GetOutMsgNumberFromScenariousBlock(void)
{
	return GetLenMsgQueue(&MainOutputQueue);
}
//������� ��� GetMessageFromScenariousBlock(�����);
int GetMessageFromScenariousBlock(void)
{
	return GetHeadMsgQueue(&MainInputQueue, &last_msg);
}

//������� ���  GetMessageCodeFromScenariousBlock        (�����);  /*������ �� ������ ���� ������� */
int GetMessageCodeFromScenariousBlock()
{
	return last_msg.code;
}

//������� ���� GetFloatParamFromScenariousBlock     (�����);  /*������ �� ������ ��������� ������� */
float GetFloatParamFromScenariousBlock()
{
	return last_msg.param.pr_float;
}

/* ������� ���� GetShortParamFromScenariousBlock     (�����); */
short GetShortParamFromScenariousBlock()
{
	return last_msg.param.pr_short[0];
}

//������� ���  GetIntParamFromScenariousBlock       (�����);
int GetIntParamFromScenariousBlock()
{
	return last_msg.param.pr_int;
}

//������� ���� GetLongParamFromScenariousBlock      (�����);
long GetLongParamFromScenariousBlock()
{
	return last_msg.param.pr_long;
}

//������� ���  SendMsgFromScenariousBlockCode       (���);
int SendMsgFromScenariousBlockCode(int code)
{
	return PutTailMsgQueue(&MainOutputQueue, code);
}

//������� ���  SendMsgFloatParamFromScenariousBlock (���, ����);
int SendMsgFloatParamFromScenariousBlock(int code, float param)
{
	return PutTailMsgQueueF(&MainOutputQueue, code, param);

}

/* ������� ���  SendMsgShortParamFromScenariousBlock (���, ����); */
int SendMsgShortParamFromScenariousBlock(int code, short param)
{
	return PutTailMsgQueueS(&MainOutputQueue, code, param);

}

/* ������� ���  SendMsgIntParamFromScenariousBlock   (���, ���); */
int SendMsgIntParamFromScenariousBlock(int code, int param)
{
	return PutTailMsgQueueI(&MainOutputQueue, code, param);

}

//������� ���  SendMsgLongParamFromScenariousBlock  (���, ����);
int SendMsgLongParamFromScenariousBlock(int code, long param)
{
	return PutTailMsgQueueL(&MainOutputQueue, code, param);
}

//������� ���  GetInpMsgNumber_FromScenariousBlock (�����);  /* ������ ����� �����. �� �����. ������ */
int GetInpMsgNumber_FromScenariousBlock()
{
	return GetLenMsgQueue(&MainInputQueue);
}

