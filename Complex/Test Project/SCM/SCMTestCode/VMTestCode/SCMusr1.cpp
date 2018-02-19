#include "SCMusr1.h"
#include "msg_queue.h"
QueueMsg last_msg_from_VM;

MsgQueue InputQueueFromVM;

MsgQueue SCM2CA_OutputQueue;
MsgQueue SCM2VP_OutputQueue;
MsgQueue SCM2VM_OutputQueue;

int GetOutMsgNumber_VM(void)
{
	return GetLenMsgQueue(&InputQueueFromVM);
}

/************************/
/*VM Input msg queue*/
/************************/
//тсмйжхъ жек GetNextMsgFromVM(осярн);
int GetNextMsgFromVM(void)
{
	return GetHeadMsgQueue(&InputQueueFromVM, &last_msg_from_VM);
}

//тсмйжхъ жек  GetMsgCodeFromVM        (осярн);  /*ВРЕМХЕ ХГ ОЮЛЪРХ ЙНДЮ ЯНАШРХЪ */
int GetMsgCodeFromVM()
{
	return last_msg_from_VM.code;
}

//тсмйжхъ окюб GetFloatParamFromVM     (осярн);  /*ВРЕМХЕ ХГ ОЮЛЪРХ ОЮПЮЛЕРПЮ ЯНАШРХЪ */
float GetFloatParamFromVM()
{
	return last_msg_from_VM.param.pr_float;

}
//тсмйжхъ джек GetLongParamFromVM      (осярн);
long GetLongParamFromVM()
{
	return last_msg_from_VM.param.pr_long;
}

/************************/
/*  Output VP msg queue*/
/************************/
//тсмйжхъ жек  SendMessageToVirtualPlantCode       (жек);
int SendMsgToVirtualPlantCode(int code)
{
	return PutTailMsgQueue(&SCM2VP_OutputQueue, code);
}

//тсмйжхъ жек  SendMsgFloatParamToVirtualPlant (жек, окюб);
int SendMsgFloatParamToVirtualPlant(int code, float param)
{
	return PutTailMsgQueueF(&SCM2VP_OutputQueue, code, param);

}

/* тсмйжхъ жек  SendMsgShortParamToVirtualPlant (жек, йжек); */
int SendMsgShortParamToVirtualPlant(int code, short param)
{
	return PutTailMsgQueueS(&SCM2VP_OutputQueue, code, param);

}

/* тсмйжхъ жек  SendMsgIntParamToVirtualPlant   (жек, жек); */
int SendMsgIntParamToVirtualPlant(int code, int param)
{
	return PutTailMsgQueueI(&SCM2VP_OutputQueue, code, param);

}

//тсмйжхъ жек  SendMsgLongParamToVirtualPlant  (жек, джек);
int SendMsgLongParamToVirtualPlant(int code, long param)
{
	return PutTailMsgQueueL(&SCM2VP_OutputQueue, code, param);
}



/********/
/*CA  Output msg queue*/
/********/

//тсмйжхъ жек  SendMsgToControlAlgorythmCode       (жек);
int SendMsgToControlAlgorythmCode(int code)
{
	return PutTailMsgQueue(&SCM2CA_OutputQueue, code);
}

//тсмйжхъ жек  SendMsgFloatParamToControlAlgorythm (жек, окюб);
int SendMsgFloatParamToControlAlgorythm(int code, float param)
{
	return PutTailMsgQueueF(&SCM2CA_OutputQueue, code, param);

}

/* тсмйжхъ жек  SendMsgShortParamToControlAlgorythm (жек, йжек); */
int SendMsgShortParamToControlAlgorythm(int code, short param)
{
	return PutTailMsgQueueS(&SCM2CA_OutputQueue, code, param);

}

/* тсмйжхъ жек  SendMsgIntParamToControlAlgorythm   (жек, жек); */
int SendMsgIntParamToControlAlgorythm(int code, int param)
{
	return PutTailMsgQueueI(&SCM2CA_OutputQueue, code, param);

}

//тсмйжхъ жек  SendMsgLongParamToControlAlgorythm  (жек, джек);
int SendMsgLongParamToControlAlgorythm(int code, long param)
{
	return PutTailMsgQueueL(&SCM2CA_OutputQueue, code, param);
}




/********/
/*VM  Output msg queue*/
/********/

//тсмйжхъ жек  SendMsgToVerificationModuleCode       (жек);
int SendMsgToVerificationModuleCode(int code)
{
	return PutTailMsgQueue(&SCM2VM_OutputQueue, code);
}

//тсмйжхъ жек  SendMsgFloatParamToVerificationModule (жек, окюб);
int SendMsgFloatParamToVerificationModule(int code, float param)
{
	return PutTailMsgQueueF(&SCM2VM_OutputQueue, code, param);

}

/* тсмйжхъ жек  SendMsgShortParamToVerificationModule (жек, йжек); */
int SendMsgShortParamToVerificationModule(int code, short param)
{
	return PutTailMsgQueueS(&SCM2VM_OutputQueue, code, param);

}

/* тсмйжхъ жек  SendMsgIntParamToVerificationModule   (жек, жек); */
int SendMsgIntParamToVerificationModule(int code, int param)
{
	return PutTailMsgQueueI(&SCM2VM_OutputQueue, code, param);

}

//тсмйжхъ жек  SendMsgLongParamToVerificationModule  (жек, джек);
int SendMsgLongParamToVerificationModule(int code, long param)
{
	return PutTailMsgQueueL(&SCM2VM_OutputQueue, code, param);
}







