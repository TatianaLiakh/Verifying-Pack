ifndef _CAusr1_h
#define _CAusr1_h 1
/* CAUSR1.H file. Place your code here. */
/* It will be included at the top of all include-files in every generated file. */

int GetOutGUIMsgNumber_GUI(void);
int GetOutSCMMsgNumber_GUI(void);


/************************/
/*CA Input msg queue*/ 
/************************/

//������� ��� GetNextMsgFromCA(�����);
int GetNextMsgFromCA(void);

//������� ���  GetMsgCodeFromCA        (�����);  /*������ �� ������ ���� ������� */
int GetMsgCodeFromCA();

//������� ���� GetFloatParamFromCA     (�����);  /*������ �� ������ ��������� ������� */
float GetFloatParamFromCA();

//������� ���� GetLongParamFromCA      (�����);
long GetLongParamFromCA();


/************************/
/*SCM Input msg queue*/
/************************/

//������� ��� GetNextMsgFromSCM(�����);
int GetNextMsgFromSCM(void);

//������� ���  GetMsgCodeFromSCM        (�����);  /*������ �� ������ ���� ������� */
int GetMsgCodeFromSCM();

//������� ���� GetFloatParamFromSCM     (�����);  /*������ �� ������ ��������� ������� */
float GetFloatParamFromSCM();

//������� ���� GetLongParamFromSCM      (�����);
long GetLongParamFromSCM();



/************************/
/*  Output GUI msg queue*/
/************************/

//������� ���  SendMsgGUICode       (���);
int SendMsgGUICode(int code);

//������� ���  SendMsgFloatParamGUI (���, ����);
int SendMsgFloatParamGUI(int code, float param);

/* ������� ���  SendMsgShortParamPIV (���, ����); */
int SendMsgShortParamGUI(int code, short param);

/* ������� ���  SendMsgIntParamPIV   (���, ���); */
int SendMsgIntParamGUI(int code, int param);

//������� ���  SendMsgLongParamGUI  (���, ����);
int SendMsgLongParamGUI(int code, long param);

/********/
/*SCM  Output msg queue*/
/********/
/*������� ���  SendMsgToSCM(���); */ 
int SendMsgToSCM(int code);

//������� ���  SendMsgFloatToSCM (���, ����);
int SendMsgFloatToSCM(int code, float param);

/* ������� ���  SendMsgShortToSCM(���, ����); */
int SendMsgShortToSCM(int code, short param);

/* ������� ���  SendMsgIntToSCM  (���, ���); */
int SendMsgIntToSCM(int code, int param);

//������� ���  SendMsgLongParamGUI  (���, ����);
int SendMsgLongToSCM(int code, long param);


#endif