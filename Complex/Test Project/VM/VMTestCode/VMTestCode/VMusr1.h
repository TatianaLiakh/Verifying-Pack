#ifndef _VMusr1_h
#define _VMusr1_h 1
/* CAUSR1.H file. Place your code here. */
/* It will be included at the top of all include-files in every generated file. */

int GetOutGUIMsgNumber_GUI(void);
int GetOutSCMMsgNumber_GUI(void);


/************************/
/*CA Input msg queue*/ 
/************************/

//тсмйжхъ жек GetNextMsgFromCA(осярн);
int GetNextMsgFromCA(void);

//тсмйжхъ жек  GetMsgCodeFromCA        (осярн);  /*ВРЕМХЕ ХГ ОЮЛЪРХ ЙНДЮ ЯНАШРХЪ */
int GetMsgCodeFromCA();

//тсмйжхъ окюб GetFloatParamFromCA     (осярн);  /*ВРЕМХЕ ХГ ОЮЛЪРХ ОЮПЮЛЕРПЮ ЯНАШРХЪ */
float GetFloatParamFromCA();

//тсмйжхъ джек GetLongParamFromCA      (осярн);
long GetLongParamFromCA();


/************************/
/*SCM Input msg queue*/
/************************/

//тсмйжхъ жек GetNextMsgFromSCM(осярн);
int GetNextMsgFromSCM(void);

//тсмйжхъ жек  GetMsgCodeFromSCM        (осярн);  /*ВРЕМХЕ ХГ ОЮЛЪРХ ЙНДЮ ЯНАШРХЪ */
int GetMsgCodeFromSCM();

//тсмйжхъ окюб GetFloatParamFromSCM     (осярн);  /*ВРЕМХЕ ХГ ОЮЛЪРХ ОЮПЮЛЕРПЮ ЯНАШРХЪ */
float GetFloatParamFromSCM();

//тсмйжхъ джек GetLongParamFromSCM      (осярн);
long GetLongParamFromSCM();



/************************/
/*  Output GUI msg queue*/
/************************/

//тсмйжхъ жек  SendMsgGUICode       (жек);
int SendMsgGUICode(int code);

//тсмйжхъ жек  SendMsgFloatParamGUI (жек, окюб);
int SendMsgFloatParamGUI(int code, float param);

/* тсмйжхъ жек  SendMsgShortParamPIV (жек, йжек); */
int SendMsgShortParamGUI(int code, short param);

/* тсмйжхъ жек  SendMsgIntParamPIV   (жек, жек); */
int SendMsgIntParamGUI(int code, int param);

//тсмйжхъ жек  SendMsgLongParamGUI  (жек, джек);
int SendMsgLongParamGUI(int code, long param);

/********/
/*SCM  Output msg queue*/
/********/
/*тсмйжхъ жек  SendMsgToSCM(жек); */ 
int SendMsgToSCM(int code);

//тсмйжхъ жек  SendMsgFloatToSCM (жек, окюб);
int SendMsgFloatToSCM(int code, float param);

/* тсмйжхъ жек  SendMsgShortToSCM(жек, йжек); */
int SendMsgShortToSCM(int code, short param);

/* тсмйжхъ жек  SendMsgIntToSCM  (жек, жек); */
int SendMsgIntToSCM(int code, int param);

//тсмйжхъ жек  SendMsgLongParamGUI  (жек, джек);
int SendMsgLongToSCM(int code, long param);


#endif