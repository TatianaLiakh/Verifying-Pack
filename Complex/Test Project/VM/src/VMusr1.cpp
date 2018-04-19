#include "VMusr1.h"
#include "msg_queue.h"
QueueMsg last_msg_from_CA;
QueueMsg last_msg_from_SCM;

MsgQueue CAInputQueue;
MsgQueue SCMInputQueue;

MsgQueue MainGUIOutputQueue;
MsgQueue SCMOutputQueue;

int GetOutMsgNumber_GUI(void)
{
	return GetLenMsgQueue(&MainGUIOutputQueue);
}

int GetOutSCMMsgNumber_GUI(void)
{
	return GetLenMsgQueue(&SCMOutputQueue);
}

/************************/
/*CA Input msg queue*/
/************************/
//������� ��� GetNextMsgGUI(�����);
int GetNextMsgFromCA(void)
{
	return GetHeadMsgQueue(&CAInputQueue, &last_msg_from_CA);
}

//������� ���  GetMsgCodeFromCA        (�����);  /*������ �� ������ ���� ������� */
int GetMsgCodeFromCA()
{
	return last_msg_from_CA.code;
}

//������� ���� GetFloatParamFromCA     (�����);  /*������ �� ������ ��������� ������� */
float GetFloatParamFromCA()
{
	return last_msg_from_CA.param.pr_float;

}
//������� ���� GetLongParamFromCA      (�����);
long GetLongParamFromCA()
{
	return last_msg_from_CA.param.pr_long;
}

/************************/
/*SCM Input msg queue*/
/************************/
//������� ��� GetNextMsgGUI(�����);
int GetNextMsgFromSCM(void)
{
	return GetHeadMsgQueue(&SCMInputQueue, &last_msg_from_SCM);
}

//������� ���  GetMsgCodeFromSCM        (�����);  /*������ �� ������ ���� ������� */
int GetMsgCodeFromSCM()
{
	return last_msg_from_SCM.code;
}

//������� ���� GetFloatParamFromSCM     (�����);  /*������ �� ������ ��������� ������� */
float GetFloatParamFromSCM()
{
	return last_msg_from_SCM.param.pr_float;

}
//������� ���� GetLongParamFromSCM      (�����);
long GetLongParamFromSCM()
{
	return last_msg_from_SCM.param.pr_long;
}


/************************/
/*  Output GUI msg queue*/
/************************/
//������� ���  SendMsgGUICode       (���);
int SendMsgGUICode(int code)
{
	return PutTailMsgQueue(&MainGUIOutputQueue, code);
}

//������� ���  SendMsgFloatParamGUI (���, ����);
int SendMsgFloatParamGUI(int code, float param)
{
	return PutTailMsgQueueF(&MainGUIOutputQueue, code, param);

}

/* ������� ���  SendMsgShortParamGUI (���, ����); */
int SendMsgShortParamGUI(int code, short param)
{
	return PutTailMsgQueueS(&MainGUIOutputQueue, code, param);

}

/* ������� ���  SendMsgIntParamGUI   (���, ���); */
int SendMsgIntParamGUI(int code, int param)
{
	return PutTailMsgQueueI(&MainGUIOutputQueue, code, param);

}

//������� ���  SendMsgLongParamGUI  (���, ����);
int SendMsgLongParamGUI(int code, long param)
{
	return PutTailMsgQueueL(&MainGUIOutputQueue, code, param);
}



/********/
/*SCM  Output msg queue*/
/********/

//������� ���  SendMsgSCMCode       (���);
int SendMsgSCMCode(int code)
{
	return PutTailMsgQueue(&SCMOutputQueue, code);
}

//������� ���  SendMsgFloatParamSCM (���, ����);
int SendMsgFloatParamSCM(int code, float param)
{
	return PutTailMsgQueueF(&SCMOutputQueue, code, param);

}

/* ������� ���  SendMsgShortParamSCM (���, ����); */
int SendMsgShortParamSCM(int code, short param)
{
	return PutTailMsgQueueS(&SCMOutputQueue, code, param);

}

/* ������� ���  SendMsgIntParamSCM   (���, ���); */
int SendMsgIntParamSCM(int code, int param)
{
	return PutTailMsgQueueI(&SCMOutputQueue, code, param);

}

//������� ���  SendMsgLongParamSCM  (���, ����);
int SendMsgLongParamSCM(int code, long param)
{
	return PutTailMsgQueueL(&SCMOutputQueue, code, param);
}










