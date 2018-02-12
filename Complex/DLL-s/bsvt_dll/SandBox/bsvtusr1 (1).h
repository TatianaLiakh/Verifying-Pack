#ifndef _bcvtusr1_h
#define _bcvtusr1_h 1
/* bcvtUSR1.H file. Place your code here. */
/* It will be included at the top of all include-files in every generated file. */

float FP_T_BAK;
float FP_P_BAK_COMPRESSOR;
float FP_P_PATRUBKA;
float FP_T_RUBACHKA;
float FP_P_TRUBA;

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

/*
* ��������
*/

//������� ���  InitChannelStatus_PIV (�����); /* ������������� �������,
//��������� ����� ������ */
int InitChannelStatus_PIV();

//������� ���  GetChannelStatus_PIV  (�����);  /* ������ ������� ������ 0/1 */
int GetChannelStatus_PIV();

//������� ���  GetErrorNumberCS_PIV  (�����);  /* ������ ����� ������ �� */
int GetErrorNumberCS_PIV();

//������� ���  GetErrorNumberTO_PIV  (�����);  /* ������ ����� ������ �� ���� ���� */
int GetErrorNumberTO_PIV();

float GetFP_P_BAK_COMPRESSOR();     
float GetFP_P_PATRUBKA();     			
float GetFP_T_RUBACHKA();     			   
float GetFP_T_BAK();     				 
float GetFP_P_TRUBA();  

#endif