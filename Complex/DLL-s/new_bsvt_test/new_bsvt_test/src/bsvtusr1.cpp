#include "bsvtusr1.h"
#include "queue_const.h"
QueueMsg last_msg;

float FP_T_BAK;
float FP_P_BAK_COMPRESSOR;
float FP_P_PATRUBKA;
float FP_T_RUBACHKA;
float FP_P_TRUBA;

MsgQueue MainInputQueue;
MsgQueue MainOutputQueue;


int GetOutMsgNumber_GUI(void)
{
	return GetLenMsgQueue(&MainOutputQueue);
}
//ФУНКЦИЯ ЦЕЛ GetNextMsgGUI(ПУСТО);
int GetNextMsgGUI (void)
{
	return GetHeadMsgQueue ( & MainInputQueue, & last_msg ); 
}

//ФУНКЦИЯ ЦЕЛ  GetMsgGUICode        (ПУСТО);  /*чтение из памяти кода события */
int GetMsgGUICode()
{
	return last_msg.code;
}

//ФУНКЦИЯ ПЛАВ GetFloatParamPIV     (ПУСТО);  /*чтение из памяти параметра события */
float GetFloatParamGUI()
{
	return last_msg.param.pr_float;
}

/* ФУНКЦИЯ КЦЕЛ GetShortParamPIV     (ПУСТО); */
short GetShortParamPIV()
{
	return last_msg.param.pr_short[0];
}

//ФУНКЦИЯ ЦЕЛ  GetIntParamPIV       (ПУСТО);
int GetIntParamPIV()
{
	return last_msg.param.pr_int;
}

//ФУНКЦИЯ ДЦЕЛ GetLongParamPIV      (ПУСТО);
long GetLongParamGUI()
{
	return last_msg.param.pr_long;
}

//ФУНКЦИЯ ЦЕЛ  SendMsgGUICode       (ЦЕЛ);
int SendMsgGUICode(int code)
{
	return PutTailMsgQueue( & MainOutputQueue, code );
}

//ФУНКЦИЯ ЦЕЛ  SendMsgFloatParamGUI (ЦЕЛ, ПЛАВ);
int SendMsgFloatParamGUI(int code, float param)
{
	return PutTailMsgQueueF( & MainOutputQueue, code , param );

}

/* ФУНКЦИЯ ЦЕЛ  SendMsgShortParamPIV (ЦЕЛ, КЦЕЛ); */
int SendMsgShortParamPIV(int code, short param)
{
	return PutTailMsgQueueS( & MainOutputQueue, code , param );

}

/* ФУНКЦИЯ ЦЕЛ  SendMsgIntParamPIV   (ЦЕЛ, ЦЕЛ); */
int SendMsgIntParamPIV(int code, int param)
{
	return PutTailMsgQueueI( & MainOutputQueue, code , param );

}

//ФУНКЦИЯ ЦЕЛ  SendMsgLongParamGUI  (ЦЕЛ, ДЦЕЛ);
int SendMsgLongParamGUI(int code, long param)
{
	return PutTailMsgQueueL( & MainOutputQueue, code , param );
}

//ФУНКЦИЯ ЦЕЛ  GetInpMsgNumber_PIV (ПУСТО);  /* чтение числа сообщ. во входн. буфере */
int GetInpMsgNumber_PIV()
{
	return GetLenMsgQueue(& MainInputQueue);
}

//ФУНКЦИЯ ЦЕЛ  GetOutMsgNumber_PIV (ПУСТО); /* чтение числа сообщ. в выходн. буфере */*/
int GetOutMsgNumber_PIV()
{
		return GetLenMsgQueue(& MainOutputQueue);

}

/*
* ЗАГЛУШКИ
*/

//ФУНКЦИЯ ЦЕЛ  InitChannelStatus_PIV (ПУСТО); /* инициализация статуса,
//обнуление числа ошибок */
int InitChannelStatus_PIV()
{
	return 0;
}

//ФУНКЦИЯ ЦЕЛ  GetChannelStatus_PIV  (ПУСТО);  /* чтение статуса канала 0/1 */
int GetChannelStatus_PIV()
{
	return 0;
}

//ФУНКЦИЯ ЦЕЛ  GetErrorNumberCS_PIV  (ПУСТО);  /* чтение числа ошибок КС */
int GetErrorNumberCS_PIV()
{
	return 0;
}

//ФУНКЦИЯ ЦЕЛ  GetErrorNumberTO_PIV  (ПУСТО);  /* чтение числа ошибок по тайм ауту */
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


