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
//тсмйжхъ жек GetNextMsgGUI(осярн);
int GetNextMsgFromCA(void)
{
	return GetHeadMsgQueue(&CAInputQueue, &last_msg_from_CA);
}

//тсмйжхъ жек  GetMsgCodeFromCA        (осярн);  /*ВРЕМХЕ ХГ ОЮЛЪРХ ЙНДЮ ЯНАШРХЪ */
int GetMsgCodeFromCA()
{
	return last_msg_from_CA.code;
}

//тсмйжхъ окюб GetFloatParamFromCA     (осярн);  /*ВРЕМХЕ ХГ ОЮЛЪРХ ОЮПЮЛЕРПЮ ЯНАШРХЪ */
float GetFloatParamFromCA()
{
	return last_msg_from_CA.param.pr_float;

}
//тсмйжхъ джек GetLongParamFromCA      (осярн);
long GetLongParamFromCA()
{
	return last_msg_from_CA.param.pr_long;
}

/************************/
/*SCM Input msg queue*/
/************************/
//тсмйжхъ жек GetNextMsgGUI(осярн);
int GetNextMsgFromSCM(void)
{
	return GetHeadMsgQueue(&SCMInputQueue, &last_msg_from_SCM);
}

//тсмйжхъ жек  GetMsgCodeFromSCM        (осярн);  /*ВРЕМХЕ ХГ ОЮЛЪРХ ЙНДЮ ЯНАШРХЪ */
int GetMsgCodeFromSCM()
{
	return last_msg_from_SCM.code;
}

//тсмйжхъ окюб GetFloatParamFromSCM     (осярн);  /*ВРЕМХЕ ХГ ОЮЛЪРХ ОЮПЮЛЕРПЮ ЯНАШРХЪ */
float GetFloatParamFromSCM()
{
	return last_msg_from_SCM.param.pr_float;

}
//тсмйжхъ джек GetLongParamFromSCM      (осярн);
long GetLongParamFromSCM()
{
	return last_msg_from_SCM.param.pr_long;
}


/************************/
/*  Output GUI msg queue*/
/************************/
//тсмйжхъ жек  SendMsgGUICode       (жек);
int SendMsgGUICode(int code)
{
	return PutTailMsgQueue(&MainGUIOutputQueue, code);
}

//тсмйжхъ жек  SendMsgFloatParamGUI (жек, окюб);
int SendMsgFloatParamGUI(int code, float param)
{
	return PutTailMsgQueueF(&MainGUIOutputQueue, code, param);

}

/* тсмйжхъ жек  SendMsgShortParamGUI (жек, йжек); */
int SendMsgShortParamGUI(int code, short param)
{
	return PutTailMsgQueueS(&MainGUIOutputQueue, code, param);

}

/* тсмйжхъ жек  SendMsgIntParamGUI   (жек, жек); */
int SendMsgIntParamGUI(int code, int param)
{
	return PutTailMsgQueueI(&MainGUIOutputQueue, code, param);

}

//тсмйжхъ жек  SendMsgLongParamGUI  (жек, джек);
int SendMsgLongParamGUI(int code, long param)
{
	return PutTailMsgQueueL(&MainGUIOutputQueue, code, param);
}



/********/
/*SCM  Output msg queue*/
/********/

//тсмйжхъ жек  SendMsgSCMCode       (жек);
int SendMsgSCMCode(int code)
{
	return PutTailMsgQueue(&SCMOutputQueue, code);
}

//тсмйжхъ жек  SendMsgFloatParamSCM (жек, окюб);
int SendMsgFloatParamSCM(int code, float param)
{
	return PutTailMsgQueueF(&SCMOutputQueue, code, param);

}

/* тсмйжхъ жек  SendMsgShortParamSCM (жек, йжек); */
int SendMsgShortParamSCM(int code, short param)
{
	return PutTailMsgQueueS(&SCMOutputQueue, code, param);

}

/* тсмйжхъ жек  SendMsgIntParamSCM   (жек, жек); */
int SendMsgIntParamSCM(int code, int param)
{
	return PutTailMsgQueueI(&SCMOutputQueue, code, param);

}

//тсмйжхъ жек  SendMsgLongParamSCM  (жек, джек);
int SendMsgLongParamSCM(int code, long param)
{
	return PutTailMsgQueueL(&SCMOutputQueue, code, param);
}










