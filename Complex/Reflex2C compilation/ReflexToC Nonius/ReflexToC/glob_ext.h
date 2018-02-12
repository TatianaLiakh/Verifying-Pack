/*===================================================================*/
/*====== Institute Of Automation And Electrometry SB RAS ============*/
/*====== Pr. Acad. Koptyuga, 1. Novosibirsk. Russia =================*/
/*===================================================================*/
/*====== (c) Copyright 2002, IA&E, NSK, RU ==========================*/
/*===================================================================*/
/*===================================================================*/
/*===================================================================*/
/*====== ��� �����: glob_ext.h=======================================*/
/*====== �����    : ����� �������� ���������� =======================*/
/*====== ����     : 2002/07/16 ======================================*/
/*====== �������� : ���� �������� �������� ������ �� ���������� =====*/
/*======            ����������, ����������� � ��������� ���������� ==*/
/*======            Reflex ==========================================*/
/*===================================================================*/

#ifndef _GLOB_EXT_H
#define _GLOB_EXT_H 1

/*============ Global Variables ==========*/
extern char InputFileName[FLENGTH];   /* ��� �������� ����� */
extern char BaseOutputFileName[FLENGTH];  /* ������ ���� �������� ������ */

extern FILE *fptr_RCS;     /* ��������� �� �������� ���� */
extern FILE *fptr_LIS;     /* ��������� �� ���� �������� */
extern FILE *fptr_SYM;     /* ��������� �� ���� �������� */
extern FILE *fptr_INP;     /* ��������� �� ���� � ���������� ���������� ������� �������� */
extern FILE *fptr_OUTP;    /* ��������� �� ���� � ���������� ������ �������� �������� */
extern FILE *fptr_C;       /* ��������� �� ������� �-����, ��������� ���� */
#ifdef GEN_ID
extern FILE *fptr_ID;      /* ��������� �� ���� �-��������������� */
extern FILE *fptr_IDC;      /* ��������� �� ���� �-��������������� */


#endif
/*��� ������������ - 2015*/
extern FILE * fptr_VARIABLES_FOR_TEST;


extern INT16S str_count, line_count;
extern char unit[BUFFER_LENGTH];
extern char prev_unit[BUFFER_LENGTH];
extern char spaces[BUFFER_LENGTH];         /* ����-����������� ������� ������� */
extern char prev_spaces[BUFFER_LENGTH];

extern char buffer1[BUFFER_LENGTH];
/* extern char buffer2[BUFFER_LENGTH]; */


extern INT16S File_Number;
extern INT16S Flag_PASS;
extern INT16S Flag_CASE;
extern INT16S Flag_LIS;      /* ���� �������� */
extern INT16S Flag_MAP;      /* ���� ����� �������� ������� */
extern INT32S CFileMAXLen;   /* ����������� �� ����� �-����� */
extern INT16S Flag_LF;              /* for line feed in spec comment */
extern INT16S Flag_SP;              /* for spacebar in spec comment */
extern INT16S Flag_Unexpect;        /* For No error when skip unexpected simbol after EOF */
extern INT16S Flag_CString;         /* flag for C-string */
extern INT16S Flag_Comment;         /* flag for usual comment */
extern INT16S Flag_TEST;        /* ���� ������������� �������� ����� ���������� */
extern INT16S Flag_CONFIG;        /* ���� ������������� �������� ����� .cnfg */
extern INT16S Flag_CPP;        /* ���� ������������� ��������� CPP ������ */
extern INT16S Flag_PROC_DESCR ; /* ���� ������������� ��������� �����- �������� ������*/


extern INT16S err_flag, error_count, line_count, warning_count;
extern INT16S JmpFlag;  /* ���� ��� �������� ��������� �� ��������� */

/*============= Arrays for diagnostic message ===============*/

extern char ENG_error_array[ERRMSGNUM][ERRMSGLEN];
extern char error_array[ERRMSGNUM][ERRMSGLEN];
extern char warning_array[WRNMSGNUM][WRNMSGLEN];
extern char BUL_error_array[ERRMSGNUM][ERRMSGLEN];
extern char ALT_error_array[ERRMSGNUM][ERRMSGLEN];
extern char VMS_error_array[ERRMSGNUM][ERRMSGLEN];
extern char BAS_error_array[ERRMSGNUM][ERRMSGLEN];

/*============== Reserved word for RCSL86 ==============*/
extern char rezword[RWNUM][RWLEN];
extern char ALT_rezword[RWNUM][RWLEN];
extern char ENG_rezword[RWNUM][RWLEN];

#endif
