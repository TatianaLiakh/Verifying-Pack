#ifndef _canonusr1_h
#define _canonusr1_h 1
/* canonUSR1.H file. Place your code here. */
/* It will be included at the top of all include-files in every generated file. */

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


#endif