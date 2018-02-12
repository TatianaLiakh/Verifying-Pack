#ifndef _canonusr1_h
#define _canonusr1_h 1
/* canonUSR1.H file. Place your code here. */
/* It will be included at the top of all include-files in every generated file. */

int GetOutMsgNumber_GUI(void);

//������� ��� GetNextMsgGUI(�����);
int GetNextMsgGUI (void); 

//������� ���  GetMsgGUICode        (�����);  /*������ �� ������ ���� ������� */
int GetMsgGUICode();

//������� ���� GetFloatParamPIV     (�����);  /*������ �� ������ ��������� ������� */
float GetFloatParamGUI();

/* ������� ���� GetShortParamPIV     (�����); */
short GetShortParamPIV();

//������� ���  GetIntParamPIV       (�����);
int GetIntParamPIV();

//������� ���� GetLongParamPIV      (�����);
long GetLongParamGUI();

//������� ���  SendMsgGUICode       (���);
int SendMsgGUICode(int code);

//������� ���  SendMsgFloatParamGUI (���, ����);
int SendMsgFloatParamGUI(int code, float param);

/* ������� ���  SendMsgShortParamPIV (���, ����); */
int SendMsgShortParamPIV(int code, short param);

/* ������� ���  SendMsgIntParamPIV   (���, ���); */
int SendMsgIntParamPIV(int code, int param);

//������� ���  SendMsgLongParamGUI  (���, ����);
int SendMsgLongParamGUI(int code, long param);

//������� ���  GetInpMsgNumber_PIV (�����);  /* ������ ����� �����. �� �����. ������ */
int GetInpMsgNumber_PIV();

//������� ���  GetOutMsgNumber_PIV (�����); /* ������ ����� �����. � ������. ������ */*/
int GetOutMsgNumber_PIV();


#endif