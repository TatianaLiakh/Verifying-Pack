#ifndef _SCMusr1_h
#define _SCMusr1_h 1

int GetOutMsgNumber_VM(void);

/************************/
/*VM Input msg queue*/
/************************/
//������� ��� GetNextMsgFromVM(�����);
int GetNextMsgFromVM(void);
//������� ���  GetMsgCodeFromVM        (�����);  /*������ �� ������ ���� ������� */
int GetMsgCodeFromVM();
//������� ���� GetFloatParamFromVM     (�����);  /*������ �� ������ ��������� ������� */
float GetFloatParamFromVM();
//������� ���� GetLongParamFromVM      (�����);
long GetLongParamFromVM();

/************************/
/*  Output VP msg queue*/
/************************/
//������� ���  SendMessageToVirtualPlantCode       (���);
int SendMsgToVirtualPlantCode(int code);
//������� ���  SendMsgFloatParamToVirtualPlant (���, ����);
int SendMsgFloatParamToVirtualPlant(int code, float param);
/* ������� ���  SendMsgShortParamToVirtualPlant (���, ����); */
int SendMsgShortParamToVirtualPlant(int code, short param);
/* ������� ���  SendMsgIntParamToVirtualPlant   (���, ���); */
int SendMsgIntParamToVirtualPlant(int code, int param);
//������� ���  SendMsgLongParamToVirtualPlant  (���, ����);
int SendMsgLongParamToVirtualPlant(int code, long param);


/********/
/*CA  Output msg queue*/
/********/

//������� ���  SendMsgToControlAlgorythmCode       (���);
int SendMsgToControlAlgorythmCode(int code);
//������� ���  SendMsgFloatParamToControlAlgorythm (���, ����);
int SendMsgFloatParamToControlAlgorythm(int code, float param);
/* ������� ���  SendMsgShortParamToControlAlgorythm (���, ����); */
int SendMsgShortParamToControlAlgorythm(int code, short param);
/* ������� ���  SendMsgIntParamToControlAlgorythm   (���, ���); */
int SendMsgIntParamToControlAlgorythm(int code, int param);
//������� ���  SendMsgLongParamToControlAlgorythm  (���, ����);
int SendMsgLongParamToControlAlgorythm(int code, long param);



/********/
/*VM  Output msg queue*/
/********/

//������� ���  SendMsgToVerificationModuleCode       (���);
int SendMsgToVerificationModuleCode(int code);
//������� ���  SendMsgFloatParamToVerificationModule (���, ����);
int SendMsgFloatParamToVerificationModule(int code, float param);
/* ������� ���  SendMsgShortParamToVerificationModule (���, ����); */
int SendMsgShortParamToVerificationModule(int code, short param);
/* ������� ���  SendMsgIntParamToVerificationModule   (���, ���); */
int SendMsgIntParamToVerificationModule(int code, int param);
//������� ���  SendMsgLongParamToVerificationModule  (���, ����);
int SendMsgLongParamToVerificationModule(int code, long param);


#endif