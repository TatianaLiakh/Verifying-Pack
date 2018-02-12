/*======================================================*/
/*======= �������� ������� ����������� ����� ===========*/
/*======= REFLEX =======================================*/
/*======= ������������ ��� ��������� ����������� =======*/
/*======================================================*/
#include "typedef.h"

#ifndef _R_PROTO_H
#define _R_PROTO_H 1


/*****************************************/
/*    ��������� ��������� �-���������    */
/*****************************************/

int Is_File_Exist(char *);    /* �������� ����� �� ������������� */
int Create_Headers(void);     /* �������� ��������������� h-������ */

void GenHeadersInProc(void);  /* ��������� ��������� � NAMEproc.c ����� */
void GenMain(void);           /* ��������� NAMEmain.c ����� */
void GenVarDescription(void); /* �������� ����� NAMEgvar.h � ����� NAMExvar.h */
void GenSYMFile(void);
void GenDebugFile(void);      /* �������� ����� � ������� ��������� � ��������� */



void GenTact(char *);           /* ��������� ������� � ����� */
void GenInputOutput(void);      /* ��������� NAMEinp.c � NAMEoutp.c */
void Gen_Ports_Reading(void);   /* ��������� ������ �-������ */
void Gen_Ports_Writing(void);   /* ��������� ������ �-������ */
void Gen_Conversion_I_O(void);  /* ��������� (��� ���.����������) �������������� ������ � ������ � ������� */

void GenDgt(char *);        /* ������� ����� � ������� � ������ ������� � �-���� */
void GenUnit(char *);       /* ��������� ����������� � ������� � �-����� */
void GenSpaces(void);       /* ��������� ����������� � �-����� */


void GenDefConstant(char *);    /* ��������� ������ �������� ��������� */
void GenBeginEnum(int);
void GenProcess(char *);        /* ��������� ������ �������� �������� */
void GenEndOfProcess(void);     /* ��������� ����� �������� �������� */
void GenBeginOfState(char *);   /* ��������� ������ �������� ��������� */
void GenEndOfState(void);       /* ��������� ����� �������� ��������� */
int  GenStop (char *);          /* ��������� �������� � ���� ���� */
void GenStopForCurrentProc(void);   /* ��������� �������� � ���� ���� ��� �-�������� */
int  GenError(char *);              /* ��������� �������� � ���� ������ */
void GenErrorForCurrentProc(void);  /* ��������� �������� � ���� ������ ��� �-�������� */
int  GenStart(char *);              /* ��������� ������� �������� �� ����� */
void GenStartForCurrentProc(void);  /* ��������� ������� ��� �-�������� */
int  GenJMP(char *);            /* ��������� �������� �������� �������� � ��������� �� ����� */
int  GenJMPInNextState(void);   /* ��������� �������� � ����-��������� �� �-���������� */
void GenBeginOfIf(void);        /* ��������� ������ ������� */
void GenCaseInSwitch(void);     /* ��������� ������� � ������ case */
void GenBreakInSwitch(void);    /* ��������� ������� � ����� case (break) */
void GenDefaultInSwitch(void);  /* ��������� ������� � ������ default */
int GenSituationProcInSTOP (char *);          /* �������� ���� � ���� */
int GenSituationProcInERROR(char *);          /* �������� ���� � ������ */
int GenSituationProcInACTIVE(char *);         /* �������� ���� ������� */
int GenSituationProcInPASSIVE(char *);         /* �������� ���� �������� */
int GenSituationProcInState(char *, char *);  /* �������� ���� ������� */
void GenRezWord(int);           /* ��������� �-������� ���������������� ����� */
int GenTimeOut(char *); /* ��������� �������� */
void GenVariable(char *);       /* ��������� ����������� ����� ����������/�����/��������� � ������ ��� � ���� */
int Gen_Var(char *, INT16S);    /* �������������� ����������������� ID �� ���������� C-ID Input: unit-string, unit_case: destin OR source */
int Convrt(char *);             /* �������������� ������� � C-����� (��������� ��� �����) */
int Gen_Port(char *);           /* �������������� ������� �� ���������� C_ID ����� */


void Cyr2Lat(char *);           /* �������������� �� ��������� � �������� */
void GenUnit_ID(char *);        /* ������ ������� � ���� �-��������������� */
void GenDgt_ID(char *);         /* ������ ����� � ���� �-��������������� */
void GenDgtWithCyrName_ID(char *);  /* �� �� �� + ������������ ��� */
void GenDgtWithCyrName_IDC(char *);  /* �� �� �� + ������������ ��� + ��� �������� �������� */
void GenSpaces_ID(void);        /* ������ ������������� ������ � ���� �-��������������� */




/***********************************
 * Syntax parcer function
 ***********************************/


void synt_anal(void);
INT16S synt_anal_of_pr_cntr_86(void);
INT16S check_err(INT16S,INT16S);      /* Check error */

/***********************************
 * Semantic parcer functions
 ***********************************/

INT16S sem_anal_of_pr_cntr_86(void);  /* Call semantical analizator */
void sem_anal(void);
INT16S Sem_Program(void);
INT16S Sem_Tact(void);          /* Takt */
INT16S Sem_Constant(void);      /* Constant */
void Sem_Constant_Expression_Body(void);
void Sem_Constant_Enum_Body (int);
void Sem_Constant_Expression_Body(void);


int Sem_Constant_Infix_Body(void);
void Sem_Constant_Term_Body(void);
int Sem_Constant_Prefix_Body(void);


INT16S Sem_Port(void);          /* Port Discribe */
int Sem_Function(void);
int Sem_Func_Args_Declarator_Body(void);
int Sem_Func_Declarator_Body(void);
int Sem_Func_Mul_Body(void);
int Sem_Func_Sign_Body(void);
int Sem_Func_Int_Body(void);

void Sem_Process(void);         /* ��������� ��������� */
void Sem_Variable_List(void);   /* ��������� ���������� �������� */
void Sem_Discr_Var(void);       /* ��������� "������" �������� ���������� */
void Sem_From_Var(void);        /* ��������� ������ �� �������� ���������� */
void Sem_Local_Var(void);       /* ��������� ���� ������� ���������� ����� */
void Sem_For_Var(void);         /* ��������� ���� ������� ���������� ��� */



void Sem_State(void);               /* ��������� �������� ��������� �������� */
void Sem_State_Body(void);          /* ��������� ���� ��������� - ����� */
int Sem_Statement_Body(void);       /* ������ ����������� */
void Sem_Switch_Body(void);         /* ��������� �������� ������ */
int Sem_Case_Body(void);            /* ��������� �������� ������/��������� */
void Sem_Check_Func_Args(void);     /* ��������� �������� ���������� ������� ��� �� ��������� � �������� ����� */
int Sem_Declarator_Body(void);      /* ��������� ����������� */
void Sem_Mul_Body(void);            /*  ��������� ����� ����� �������������� ����������� */
void Sem_Sign_Body(void);           /* ��������� �������� ����� �������������� ����������� */
void Sem_Int_Body(void);            /* ��������� �������� ����� ��������� ����������� */


void Sem_Condition_Body(void);      /*  ��������� �������� ������� */
void Sem_Post_Condition_Body(void); /* ��������� �������� ����-������� */
void Sem_Stop_Body(void);           /* ��������� �������� ���� */
void Sem_Loop_Body(void);           /* ��������� �������� ��������� */
void Sem_Error_Body(void);          /* ��������� �������� ������ */
void Sem_Start_Body(void);          /* ��������� �������� ����� */
void Sem_In_Body(void);             /* ��������� �������� �������� � ���� */
void Sem_Expression_Body(void);     /* ��������� �������� ��������� */
int Sem_Prefix_Body(void);          /*  ��������� �������� */
int Sem_Infix_Body(void);           /*  ��������� ������� */
int Sem_Postfix_Body(void);         /*  ��������� ��������� */
void Sem_Term_Body(void);           /*  ��������� ����� */

void Sem_Time_Out(void);            /*  ������ �������� */



int CheckVariableInProc(char *, char *);  /* �������� ������������� � �������� process_name ��������
                                           * ���������� variable_name � ������������� ���������� �����
                                           * ���������� */





INT16S Open_File_W(FILE * *,char *); /* ������� ���� �� ������ (w+) */
INT16S Open_File_R(FILE * *,char *); /* ������� ���� �� ������ (r) */
INT16S Gen_Extern1(FILE *);
void   fskptr (FILE *);                 /* �������� ���� �� ������ */

void ini_ptrt1(void);
void fskptrt1(void);
void fskptr1(void);

INT16S select_unit(void);
INT16S select_unit2(void);

int compare_RW(char *); /* ����� ������ ���������������� ����� */

int    Get_Identifier(void);
int    Get_Pragma(void);
int    Get_xFix(void);
int    Get_Number(void);

INT16S InputPort(void);     /* ������� ������� */
INT16S OutputPort(void);    /* �������� ������� */
INT16S RAMPort(void);       /* ������� ��� */

/* INT16S Gen_Variable(void);  /* Generation Of Variables Discribe */
/* void   Gen_SYM_File (void); /* Generation File *.SIM */


int    compare(char *, char *);

/* === INT16S Gen_Main(char *);
/* === INT16S Gen_IncludeFile(FILE *fptr, char *name);   /* ��������� ������ #include "name" */
INT16S rewunit(void);
void   cl_unit(void);
void   cl_spaces(void);
INT16S Gen_St_Word(void);
INT16S Gen_Define(char *);
INT16S Check_From_Proc(char *, char *);
INT16S error_msg(INT16S, INT16S, char *, INT16S);
INT16S warning_msg(INT16S, INT16S, char *);
void   InitStructures(void); /* ������������� ���������� ���� �������� -1, ��� ������������� ���������� ����� ������������� */


INT16S Program(void);
INT16S Tact(void);                /* Takt */
INT16S Constant(void);            /* Constant */
int    Function(void);            /* Function */
INT16S Port(void);                /* Port Discribe */
INT16S Process(void);             /* Process */
INT16S Variable_List(void);       /* work up variables list */
INT16S Discr_Var(INT16S);
INT16S State(void);               /* work up states */
INT16S From_Var(void);
INT16S Local_Var(void);
INT16S For_Var(void);
int    State_Body(void);          /* ��������� �������� ��������� */
int    Statement_Body(void);      /* ��������� �������� ����������� */
int    Condition_Body(void);      /* ��������� �������� ������� */
int    Post_Condition_Body(void); /* ��������� �������� ����-������� */
int    Stop_Body(void);           /* ��������� �������� ���� */
int    Loop_Body(void);           /* ��������� �������� ��������� */
int    Error_Body(void);          /* ��������� �������� ������ */
int    Start_Body(void);          /* ��������� �������� ����� */
int    In_Body(void);             /* ��������� �������� � ���� */
int    Expression_Body(void);     /* ��������� �������� ��������� */
int    Switch_Body(void);         /* ��������� �������� ������ */
int    Case_Body(void);           /* ��������� �������� ������ */
int    Prefix_Body(void);         /* ��������� �������� �������� */
int    Term_Body(void);           /* ��������� �������� ����� */
int    Postfix_Body(void);        /* ��������� �������� ��������� */
int    Infix_Body(void);          /* ��������� �������� ������� */
int    Declarator_Body(void);     /* ��������� �������� ����������� */
int    Sign_Body(void);           /* ��������� �������� ���������� */
int    Int_Body(void);            /* ��������� �������� �������������� ���� */
int    Mul_Body(void);            /* ��������� �������� �������������� ���� */

int    Func_Declarator_Body(void);      /* ��������� �������� ����������� */
int    Func_Args_Declarator_Body(void);/* ��������� �������� ����������� */
int    Func_Sign_Body(void);            /* ��������� �������� ���������� */
int    Func_Int_Body(void);             /* ��������� �������� �������������� ���� */
int    Func_Mul_Body(void);             /* ��������� �������� �������������� ���� */
int    Check_Func_Args(void);           /* ��������� ���������� �������-����� */


int    Constant_Expression_Body(void);     /* ��������� �������� Constant_��������� */
int    Constant_Prefix_Body(void);         /* ��������� �������� Constant_�������� */
int    Constant_Term_Body(void);           /* ��������� �������� Constant_����� */
int    Constant_Infix_Body(void);          /* ��������� �������� Constant_������� */
int    Constant_Enum_Body(void);           /* ��������� �������� ����������� */


INT16S Time_Out(void);

INT16S VarValue(void);

int    check_name(char *);
INT16S check_digit(char *);

INT16S CheckNameFunc(char *);
INT16S CheckFunc(char *);
INT16S N_Struct_Func(char *);
int GetCurFuncArgNum(void);    /* ���������� ���������� ��� ������� ������� */
int AddNewArgInCurFunc(void); /* �������� �������� � ������� ������� */

INT16S Check_Name_Constant(char *);
INT16S Con_Value(char *);
INT16S Check_Constant(char *);
INT16S N_Struct_Constant(char *);
INT16S ConstantValue(char *);
INT16S Con_Value(char *);
INT16S Check_RAM_Group(char *);
INT16S N_Struct_RAM_Group(char *);
INT16S Check_Name_RAM_Group(char *);
INT16S RAM_Group_Segment(char *);
INT16S RAM_Group_Offset(char *);
INT16S RAM_Group_Address(char *);
INT16S RAM_Group_Size(char *);
INT16S Check_Input_Group(char *);
INT16S N_Struct_Input_Group(char *);
INT16S Check_Name_Input_Group(char *);
INT16S Input_Group_MB_Address(char *);
INT16S Input_Group_Address(char *);
INT16S Input_Group_Size(char *);
INT16S Check_Output_Group(char *);
INT16S N_Struct_Output_Group(char *);
INT16S Check_Name_Output_Group(char *);
INT16S Output_Group_MB_Address(char *);
INT16S Output_Group_Address(char *);
INT16S Output_Group_Size(char *);
INT16S Check_Process(char *);
INT16S N_Struct_Process(char *);
INT16S Check_Name_Process(char *);
INT16S Check_State(char *);
INT16S Check_Name_State(char *);
INT16S Check_Number_Of_State(void);
INT16S CheckVariable(char *, INT16S);
INT16S N_Struct_Variable(char *,INT16S);
INT16S CheckNameVariable(char *);
INT16S InitVariable(char *, INT16S);
INT16S N_Part_Of_Var(void);
INT16S ForProc(char *);
INT16S ForProc_LOCAL(void);
INT16S ForProc_ALL(void);
INT16S Check_Name_For_Proc(char *);
INT16S MakeBeforeFor(void);
INT16S Check_From_Proc(char *,char *);


/* INT16S Gen_Main(char *);
INT16S Gen_Define(char *);
INT16S Gen_St_Word(void);
INT16S Gen_Open(void);
INT16S Gen_Close(void);
INT16S Gen_Pause(char *,char *);
INT16S Convrt(char *);
INT16S Gen_Var(char *,INT16S ); /* Input: unit-string, unit_case: destin OR source */
/*INT16S Gen_Port(char *);     /* Input: unit-string */
/*INT16S Gen_Stop(char *);
INT16S Gen_Error(char *);
INT16S Gen_Continue(char *);
INT16S Gen_Start(char *);
INT16S Gen_Name_Of_Var(char *);
INT16S Gen_Variable(void);
INT16S Gen_Input_Port_Image(void);
INT16S Gen_Output_Port_Image(void);
INT16S Gen_Initial_I_O_Port(void);
INT16S Gen_If(void);
INT16S Gen_Fi(void);
INT16S Gen_Situation(char *,char *);
INT16S Gen_LF(void);
INT16S Gen_Vrbls(char *,INT16S);
INT16S Gen_JMP(char *);
*/
INT16S Hard_Copy_Port(void);
INT16S H_C_Constant(void);
INT16S H_C_Input(void);
INT16S H_C_Output(void);
INT16S H_C_RAM(void);
INT16S H_C_States(void);
INT16S H_C_Variables(void);
INT16S H_C_Image(void);
INT16S H_C_For_Proc(void);
INT16S Gen_Init_Input(void);
INT16S Gen_Init_Output(void);
INT16S Gen_Init_RAM(void);
INT16S Gen_Extern(FILE *, char *);
INT16S Gen_Extern1(FILE *);
INT16S N_Struct_State(char *);
void enfilname(void);
void openfil(void);
INT16S  select_unit2(void);
INT16S newstring(void);
INT16S Skip_Space(void);

#endif
