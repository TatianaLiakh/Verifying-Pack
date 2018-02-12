#ifndef _bcvtusr1_h
#define _bcvtusr1_h 1
/* bcvtUSR1.H file. Place your code here. */
/* It will be included at the top of all include-files in every generated file. */

//extern struct MsgQueue; 
//MsgQueue MainInputQueue;
//MsgQueue MainOutputQueue; 

float FP_T_BAK;
float FP_P_BAK_COMPRESSOR;
float FP_P_PATRUBKA;
float FP_T_RUBACHKA;
float FP_P_TRUBA;

int GetOutMsgNumber_GUI(void);

//ФУНКЦИЯ ЦЕЛ GetNextMsgGUI(ПУСТО);
int GetNextMsgGUI (void); 

//ФУНКЦИЯ ЦЕЛ  GetMsgGUICode        (ПУСТО);  /*чтение из памяти кода события */
int GetMsgGUICode();

//ФУНКЦИЯ ПЛАВ GetFloatParamPIV     (ПУСТО);  /*чтение из памяти параметра события */
float GetFloatParamGUI();

/* ФУНКЦИЯ КЦЕЛ GetShortParamPIV     (ПУСТО); */
short GetShortParamPIV();

//ФУНКЦИЯ ЦЕЛ  GetIntParamPIV       (ПУСТО);
int GetIntParamPIV();

//ФУНКЦИЯ ДЦЕЛ GetLongParamPIV      (ПУСТО);
long GetLongParamGUI();

//ФУНКЦИЯ ЦЕЛ  SendMsgGUICode       (ЦЕЛ);
int SendMsgGUICode(int code);

//ФУНКЦИЯ ЦЕЛ  SendMsgFloatParamGUI (ЦЕЛ, ПЛАВ);
int SendMsgFloatParamGUI(int code, float param);

/* ФУНКЦИЯ ЦЕЛ  SendMsgShortParamPIV (ЦЕЛ, КЦЕЛ); */
int SendMsgShortParamPIV(int code, short param);

/* ФУНКЦИЯ ЦЕЛ  SendMsgIntParamPIV   (ЦЕЛ, ЦЕЛ); */
int SendMsgIntParamPIV(int code, int param);

//ФУНКЦИЯ ЦЕЛ  SendMsgLongParamGUI  (ЦЕЛ, ДЦЕЛ);
int SendMsgLongParamGUI(int code, long param); 

//ФУНКЦИЯ ЦЕЛ  GetInpMsgNumber_PIV (ПУСТО);  /* чтение числа сообщ. во входн. буфере */
int GetInpMsgNumber_PIV();

//ФУНКЦИЯ ЦЕЛ  GetOutMsgNumber_PIV (ПУСТО); /* чтение числа сообщ. в выходн. буфере */*/
int GetOutMsgNumber_PIV();

/*
* ЗАГЛУШКИ
*/

//ФУНКЦИЯ ЦЕЛ  InitChannelStatus_PIV (ПУСТО); /* инициализация статуса,
//обнуление числа ошибок */
int InitChannelStatus_PIV();

//ФУНКЦИЯ ЦЕЛ  GetChannelStatus_PIV  (ПУСТО);  /* чтение статуса канала 0/1 */
int GetChannelStatus_PIV();

//ФУНКЦИЯ ЦЕЛ  GetErrorNumberCS_PIV  (ПУСТО);  /* чтение числа ошибок КС */
int GetErrorNumberCS_PIV();

//ФУНКЦИЯ ЦЕЛ  GetErrorNumberTO_PIV  (ПУСТО);  /* чтение числа ошибок по тайм ауту */
int GetErrorNumberTO_PIV();

float GetFP_P_BAK_COMPRESSOR();     
float GetFP_P_PATRUBKA();     			
float GetFP_T_RUBACHKA();     			   
float GetFP_T_BAK();     				 
float GetFP_P_TRUBA();  

#endif