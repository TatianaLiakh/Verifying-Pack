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
//������� ��� GetNextMsgFromVM(�����);
int GetNextMsgFromVM(void)
{
	return GetHeadMsgQueue(&InputQueueFromVM, &last_msg_from_VM);
}

//������� ���  GetMsgCodeFromVM        (�����);  /*������ �� ������ ���� ������� */
int GetMsgCodeFromVM()
{
	return last_msg_from_VM.code;
}

//������� ���� GetFloatParamFromVM     (�����);  /*������ �� ������ ��������� ������� */
float GetFloatParamFromVM()
{
	return last_msg_from_VM.param.pr_float;

}
//������� ���� GetLongParamFromVM      (�����);
long GetLongParamFromVM()
{
	return last_msg_from_VM.param.pr_long;
}

/************************/
/*  Output VP msg queue*/
/************************/
//������� ���  SendMessageToVirtualPlantCode       (���);
int SendMsgToVirtualPlantCode(int code)
{
	return PutTailMsgQueue(&SCM2VP_OutputQueue, code);
}

//������� ���  SendMsgFloatParamToVirtualPlant (���, ����);
int SendMsgFloatParamToVirtualPlant(int code, float param)
{
	return PutTailMsgQueueF(&SCM2VP_OutputQueue, code, param);

}

/* ������� ���  SendMsgShortParamToVirtualPlant (���, ����); */
int SendMsgShortParamToVirtualPlant(int code, short param)
{
	return PutTailMsgQueueS(&SCM2VP_OutputQueue, code, param);

}

/* ������� ���  SendMsgIntParamToVirtualPlant   (���, ���); */
int SendMsgIntParamToVirtualPlant(int code, int param)
{
	return PutTailMsgQueueI(&SCM2VP_OutputQueue, code, param);

}

//������� ���  SendMsgLongParamToVirtualPlant  (���, ����);
int SendMsgLongParamToVirtualPlant(int code, long param)
{
	return PutTailMsgQueueL(&SCM2VP_OutputQueue, code, param);
}



/********/
/*CA  Output msg queue*/
/********/

//������� ���  SendMsgToControlAlgorythmCode       (���);
int SendMsgToControlAlgorythmCode(int code)
{
	return PutTailMsgQueue(&SCM2CA_OutputQueue, code);
}

//������� ���  SendMsgFloatParamToControlAlgorythm (���, ����);
int SendMsgFloatParamToControlAlgorythm(int code, float param)
{
	return PutTailMsgQueueF(&SCM2CA_OutputQueue, code, param);

}

/* ������� ���  SendMsgShortParamToControlAlgorythm (���, ����); */
int SendMsgShortParamToControlAlgorythm(int code, short param)
{
	return PutTailMsgQueueS(&SCM2CA_OutputQueue, code, param);

}

/* ������� ���  SendMsgIntParamToControlAlgorythm   (���, ���); */
int SendMsgIntParamToControlAlgorythm(int code, int param)
{
	return PutTailMsgQueueI(&SCM2CA_OutputQueue, code, param);

}

//������� ���  SendMsgLongParamToControlAlgorythm  (���, ����);
int SendMsgLongParamToControlAlgorythm(int code, long param)
{
	return PutTailMsgQueueL(&SCM2CA_OutputQueue, code, param);
}




/********/
/*VM  Output msg queue*/
/********/

//������� ���  SendMsgToVerificationModuleCode       (���);
int SendMsgToVerificationModuleCode(int code)
{
	return PutTailMsgQueue(&SCM2VM_OutputQueue, code);
}

//������� ���  SendMsgFloatParamToVerificationModule (���, ����);
int SendMsgFloatParamToVerificationModule(int code, float param)
{
	return PutTailMsgQueueF(&SCM2VM_OutputQueue, code, param);

}

/* ������� ���  SendMsgShortParamToVerificationModule (���, ����); */
int SendMsgShortParamToVerificationModule(int code, short param)
{
	return PutTailMsgQueueS(&SCM2VM_OutputQueue, code, param);

}

/* ������� ���  SendMsgIntParamToVerificationModule   (���, ���); */
int SendMsgIntParamToVerificationModule(int code, int param)
{
	return PutTailMsgQueueI(&SCM2VM_OutputQueue, code, param);

}

//������� ���  SendMsgLongParamToVerificationModule  (���, ����);
int SendMsgLongParamToVerificationModule(int code, long param)
{
	return PutTailMsgQueueL(&SCM2VM_OutputQueue, code, param);
}







