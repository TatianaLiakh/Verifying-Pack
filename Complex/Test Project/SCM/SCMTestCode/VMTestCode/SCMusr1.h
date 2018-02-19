#ifndef _SCMusr1_h
#define _SCMusr1_h 1

int GetOutMsgNumber_VM(void);

/************************/
/*VM Input msg queue*/
/************************/
//тсмйжхъ жек GetNextMsgFromVM(осярн);
int GetNextMsgFromVM(void);
//тсмйжхъ жек  GetMsgCodeFromVM        (осярн);  /*ВРЕМХЕ ХГ ОЮЛЪРХ ЙНДЮ ЯНАШРХЪ */
int GetMsgCodeFromVM();
//тсмйжхъ окюб GetFloatParamFromVM     (осярн);  /*ВРЕМХЕ ХГ ОЮЛЪРХ ОЮПЮЛЕРПЮ ЯНАШРХЪ */
float GetFloatParamFromVM();
//тсмйжхъ джек GetLongParamFromVM      (осярн);
long GetLongParamFromVM();

/************************/
/*  Output VP msg queue*/
/************************/
//тсмйжхъ жек  SendMessageToVirtualPlantCode       (жек);
int SendMsgToVirtualPlantCode(int code);
//тсмйжхъ жек  SendMsgFloatParamToVirtualPlant (жек, окюб);
int SendMsgFloatParamToVirtualPlant(int code, float param);
/* тсмйжхъ жек  SendMsgShortParamToVirtualPlant (жек, йжек); */
int SendMsgShortParamToVirtualPlant(int code, short param);
/* тсмйжхъ жек  SendMsgIntParamToVirtualPlant   (жек, жек); */
int SendMsgIntParamToVirtualPlant(int code, int param);
//тсмйжхъ жек  SendMsgLongParamToVirtualPlant  (жек, джек);
int SendMsgLongParamToVirtualPlant(int code, long param);


/********/
/*CA  Output msg queue*/
/********/

//тсмйжхъ жек  SendMsgToControlAlgorythmCode       (жек);
int SendMsgToControlAlgorythmCode(int code);
//тсмйжхъ жек  SendMsgFloatParamToControlAlgorythm (жек, окюб);
int SendMsgFloatParamToControlAlgorythm(int code, float param);
/* тсмйжхъ жек  SendMsgShortParamToControlAlgorythm (жек, йжек); */
int SendMsgShortParamToControlAlgorythm(int code, short param);
/* тсмйжхъ жек  SendMsgIntParamToControlAlgorythm   (жек, жек); */
int SendMsgIntParamToControlAlgorythm(int code, int param);
//тсмйжхъ жек  SendMsgLongParamToControlAlgorythm  (жек, джек);
int SendMsgLongParamToControlAlgorythm(int code, long param);



/********/
/*VM  Output msg queue*/
/********/

//тсмйжхъ жек  SendMsgToVerificationModuleCode       (жек);
int SendMsgToVerificationModuleCode(int code);
//тсмйжхъ жек  SendMsgFloatParamToVerificationModule (жек, окюб);
int SendMsgFloatParamToVerificationModule(int code, float param);
/* тсмйжхъ жек  SendMsgShortParamToVerificationModule (жек, йжек); */
int SendMsgShortParamToVerificationModule(int code, short param);
/* тсмйжхъ жек  SendMsgIntParamToVerificationModule   (жек, жек); */
int SendMsgIntParamToVerificationModule(int code, int param);
//тсмйжхъ жек  SendMsgLongParamToVerificationModule  (жек, джек);
int SendMsgLongParamToVerificationModule(int code, long param);


#endif