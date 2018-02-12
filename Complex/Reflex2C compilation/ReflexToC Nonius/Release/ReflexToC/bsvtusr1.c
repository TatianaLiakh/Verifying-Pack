#include "bsvtusr1.h"
#include "queue_const.h"
QueueMsg last_msg;

int GetOutMsgNumber_GUI(void)
{
	return GetLenMsgQueue(&MainOutputQueue);
}
//������� ��� GetNextMsgGUI(�����);
int GetNextMsgGUI (void)
{
	return GetHeadMsgQueue ( & MainInputQueue, & last_msg ); 
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
	return last_msg.param.pr_int[0];
}

//������� ���� GetLongParamPIV      (�����);
long GetLongParamGUI()
{
	return last_msg.param.pr_long;
}

//������� ���  SendMsgGUICode       (���);
int SendMsgGUICode(int code)
{
	return PutTailMsgQueue( & MainOutputQueue, code );
}

//������� ���  SendMsgFloatParamGUI (���, ����);
int SendMsgFloatParamGUI(int code, float param)
{
	return PutTailMsgQueueF( & MainOutputQueue, code , param );

}

/* ������� ���  SendMsgShortParamPIV (���, ����); */
int SendMsgShortParamPIV(int code, short param)
{
	return PutTailMsgQueueS( & MainOutputQueue, code , param );

}

/* ������� ���  SendMsgIntParamPIV   (���, ���); */
int SendMsgIntParamPIV(int code, int param)
{
	return PutTailMsgQueueI( & MainOutputQueue, code , param );

}

//������� ���  SendMsgLongParamGUI  (���, ����);
int SendMsgLongParamGUI(int code, long param)
{
	return PutTailMsgQueueL( & MainOutputQueue, code , param );
}

//������� ���  GetInpMsgNumber_PIV (�����);  /* ������ ����� �����. �� �����. ������ */
int GetInpMsgNumber_PIV()
{
	return GetLenMsgQueue(& MainInputQueue);
}

//������� ���  GetOutMsgNumber_PIV (�����); /* ������ ����� �����. � ������. ������ */*/
int GetOutMsgNumber_PIV()
{
		return GetLenMsgQueue(& MainOutputQueue);

}

/*
* ��������
*/

//������� ���  InitChannelStatus_PIV (�����); /* ������������� �������,
//��������� ����� ������ */
int InitChannelStatus_PIV()
{
	return 0;
}

//������� ���  GetChannelStatus_PIV  (�����);  /* ������ ������� ������ 0/1 */
int GetChannelStatus_PIV()
{
	return 0;
}

//������� ���  GetErrorNumberCS_PIV  (�����);  /* ������ ����� ������ �� */
int GetErrorNumberCS_PIV()
{
	return 0;
}

//������� ���  GetErrorNumberTO_PIV  (�����);  /* ������ ����� ������ �� ���� ���� */
int GetErrorNumberTO_PIV()
{
	return 0;
}

float GetFP_P_BAK_COMPRESSOR() 
{
	return FP_P_BAK_COMPRESSOR;
}    

float GetFP_P_PATRUBKA()
{
	return FP_P_PATRUBKA;
}       			

float GetFP_T_RUBACHKA()
{
	return FP_T_RUBACHKA;
}      			   

float GetFP_T_BAK()
{
	return FP_T_BAK;
}    			 

float GetFP_P_TRUBA()
{
	return FP_P_TRUBA;
}    


