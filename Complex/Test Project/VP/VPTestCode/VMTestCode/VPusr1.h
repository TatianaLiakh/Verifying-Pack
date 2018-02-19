#ifndef _VPusr1_h
#define _VPusr1_h 1
/* VPUSR1.H file. Place your code here. */
/* It will be included at the top of all include-files in every generated file. */

int GetOutMsgNumberFromScenariousBlock(void);

//������� ��� GetMessageFromScenariousBlock(�����);
int GetMessageFromScenariousBlock(void);

//������� ���  GetMessageCodeFromScenariousBlock        (�����);  /*������ �� ������ ���� ������� */
int GetMessageCodeFromScenariousBlock();

//������� ���� GetFloatParamFromScenariousBlock     (�����);  /*������ �� ������ ��������� ������� */
float GetFloatParamFromScenariousBlock();

/* ������� ���� GetShortParamFromScenariousBlock     (�����); */
short GetShortParamFromScenariousBlock();

//������� ���  GetIntParamFromScenariousBlock       (�����);
int GetIntParamFromScenariousBlock();

//������� ���� GetLongParamFromScenariousBlock      (�����);
long GetLongParamFromScenariousBlock();

//������� ���  SendMsgFromScenariousBlockCode       (���);
int SendMsgFromScenariousBlockCode(int code);

//������� ���  SendMsgFloatParamFromScenariousBlock (���, ����);
int SendMsgFloatParamFromScenariousBlock(int code, float param);

/* ������� ���  SendMsgShortParamFromScenariousBlock (���, ����); */
int SendMsgShortParamFromScenariousBlock(int code, short param);

/* ������� ���  SendMsgIntParamFromScenariousBlock   (���, ���); */
int SendMsgIntParamFromScenariousBlock(int code, int param);

//������� ���  SendMsgLongParamFromScenariousBlock  (���, ����);
int SendMsgLongParamFromScenariousBlock(int code, long param);

//������� ���  GetInpMsgNumber_FromScenariousBlock (�����);  /* ������ ����� �����. �� �����. ������ */
int GetInpMsgNumber_FromScenariousBlock();

//������� ���  GetOutMsgNumber_FromScenariousBlock (�����); /* ������ ����� �����. � ������. ������ */*/
int GetOutMsgNumber_FromScenariousBlock();



#endif