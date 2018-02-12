/*===================================================================*/
/*====== ������������ ���������: ====================================*/
/*====== ���������� ����� REFLEX. ===================================*/
/*====== ���� ������������ �� �������� ���������� ������ ============*/
/*====== ������� �������� �������������. ============================*/
/*====== ������������� ������ ����� ������� � �������������� ========*/
/*====== �������. ��������� ����� �������� � ������������. ==========*/
/*====== ��� ����� ����������� ��������� ���������� � ������������� =*/
/*====== �� ���. ====================================================*/
/*====== �����: ����� �������� ���������� ===========================*/
/*====== 1989-1997, 2002 ============================================*/
/*====== ���� ����������������: �� ==================================*/
/*===================================================================*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "const.h"           /* �������� �������� */
#include "typedef.h"         /* �������� ������������ ����� */
#include "prototyp.h"        /* �������� ���������� ������� */
#include "glob_var.h"        /* �������� ���������� ���������� */

/*============== ARGV and ARGC ==============*/
INT16S main (INT16S argc, INT8U **argv)
{
  char string[BUFFER_LENGTH];

  void hello(int, INT8U * *);
  void success_err(void);

/*    putenv("DOS4G=QUIET"); */
    hello(argc, argv);                           /* ������ ��������� ������ */

    error_count = 0; /* �������� ������� ������ */
    warning_count = 0; /* �������� ������� �������������� */

    Flag_PASS = ZERO; /* ��������� ��������� select_unit, ��� ��� ������ ������ */

    strcpy(string, InputFileName);     /* ��������� �������� */
    Open_File_R(&fptr_RCS, string);
    if (Flag_LIS) {                      /* ��������� ������� */
         strcpy(string, BaseOutputFileName);
         strcat(string, ".lis");
         Open_File_W(&fptr_LIS, string);
    }


    error_count = synt_anal_of_pr_cntr_86();   /* Call syntax parser */
    check_err(error_count, 1);                 /* Check error */
    printf("\n PASS ONE COMPLETE.");

    Create_Headers();        /* ��������� ������� � ������� �������� ��� �����-������ */

    Flag_PASS = !ZERO; /* ��������� ��������� select_unit, ��� ��� ������ ������ */

    fskptr(fptr_RCS);                  /* �������� �������� ���� �� ������ */

    if (Flag_LIS) {                    /* ���������� ������� */
         if ( fptr_LIS!=NULL ) {
           fclose(fptr_LIS);
           fptr_LIS = NULL;
         }
         strcpy(string, BaseOutputFileName);
         strcat(string, ".lis");
         Open_File_W(&fptr_LIS, string);
         fskptr(fptr_LIS);             /* �������� ������� �� ������ */
    }


/*    strcpy(string, BaseOutputFileName);          /* ��������� C-file ���� */
/*    strcat(string, ".c");
/*    Open_File_W(&fptr_C, string);
*/

    error_count = sem_anal_of_pr_cntr_86(); /* Call semantical analizator */
    check_err(error_count, 2);              /* Check error */
    printf("\n PASS TWO COMPLETE.\n");
    exit(File_Number);
    return(!ZERO);
    /*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/*    exit(ZERO);*/
};

/****************************************
* �������� �� ������������� ����� � ������-����������
* ���� - ��� �����
* ����� - 0 - ��� ������ �����
*         1 - ���� ���������
******************************************/
int Is_File_Exist (char * filename)
{
    FILE *fptr;
    if((fptr = fopen(filename, "r")) == ZERO) {
         return(ZERO);
    }
    fclose(fptr);
    return(!ZERO);
}


/****************************************
* �������� ����� NAMEext.h
*   ���� � ������������ ������������
*   includ'��� h-������
*   � ���� ����������� ������
* ���� - void
* ����� - � ������ ������ - ����������� � exit
******************************************/
int Create_Headers (void)
{
char string[BUFFER_LENGTH];

    strcpy(string, BaseOutputFileName);     /* ������������ ��� NAMEext.h */
    strcat(string, "ext.h");
    if (!Is_File_Exist(string)) {             /* ���������� �� ����� ���� ? */
         Open_File_W(&fptr_C, string);
         sprintf(string, "#ifndef _%sext_inc\n#define _%sext_inc 1\n", BaseOutputFileName, BaseOutputFileName); /* ���������������� ����� */
         fputs(string, fptr_C);
         sprintf(string, "#include \"%susr1.h\" /* User-defined top include file */\n", BaseOutputFileName); /* ���������������� ����� */
         fputs(string, fptr_C);
         sprintf(string, "#include \"r_cnst.h\" /* Internal constants */\n"); /* r_cnst.h */
         fputs(string, fptr_C);
         sprintf(string, "#include \"r_io.h\"   /* IO-functions typedef */\n"); /* r_io.h */
         fputs(string, fptr_C);
         sprintf(string, "#include \"r_lib.h\"  /* Internal functions typedef */\n"); /* r_lib.h */
         fputs(string, fptr_C);
         sprintf(string, "#include \"%scnst.h\" /* Application-defined constant */\n", BaseOutputFileName); /* NAMEcnst.h */
         fputs(string, fptr_C);
         sprintf(string, "#include \"%susr2.h\" /* User-defined bottom include file */\n", BaseOutputFileName); /* NAMEusr2.h */
         fputs(string, fptr_C);
         fputs("#endif", fptr_C);
         if (fptr_C != NULL ) {
           fclose(fptr_C);
           fptr_C = NULL;
         }
    }

    strcpy(string, BaseOutputFileName);     /* ������������ ��� NAMEusr1.h */
    strcat(string, "usr1.h");
    if (!Is_File_Exist(string)) {             /* ���������� �� ����� ���� ? */
         Open_File_W(&fptr_C, string);
         sprintf(string, "#ifndef _%susr1_h\n#define _%susr1_h 1\n", BaseOutputFileName, BaseOutputFileName); /* ���������������� ����� */
         fputs(string, fptr_C);
         sprintf(string, "/* %sUSR1.H file. Place your code here. */\n/* It will be included at the top of all include-files in every generated file. */\n", BaseOutputFileName); /* ���������������� ����� */
         fputs(string, fptr_C);
         fputs("#endif", fptr_C);
         if (fptr_C != NULL) {
           fclose(fptr_C);
           fptr_C = NULL;
         }
    }

    strcpy(string, BaseOutputFileName);     /* ������������ ��� NAMEusr2.h */
    strcat(string, "usr2.h");
    if (!Is_File_Exist(string)) {             /* ���������� �� ����� ���� ? */
         Open_File_W(&fptr_C, string);
         sprintf(string, "#ifndef _%susr2_h\n#define _%susr2_h 1\n", BaseOutputFileName, BaseOutputFileName); /* ���������������� ����� */
         fputs(string, fptr_C);
         sprintf(string, "/* %sUSR2.H file. Place your code here. */\n/* It will be included at the bottom of all include-files in every generated file. */\n", BaseOutputFileName); /* ���������������� ����� */
         fputs(string, fptr_C);
         fputs("#endif", fptr_C);
         if (fptr_C != NULL ) {
           fclose(fptr_C);
           fptr_C = NULL;
         }
    }

    strcpy(string, BaseOutputFileName);     /* ������������ ��� NAMEio.h */
    strcat(string, "io.h");
    if (!Is_File_Exist(string)) {             /* ���������� �� ����� ���� ? */
         Open_File_W(&fptr_C, string);
         sprintf(string, "#ifndef _%sio_h\n#define _%sio_h 1\n", BaseOutputFileName, BaseOutputFileName);
         fputs(string, fptr_C);
         sprintf(string, "void Input(void);  /* Reading IO func */\nvoid Output(void); /* Writing IO func */\n", BaseOutputFileName, BaseOutputFileName);
         fputs(string, fptr_C);
         fputs("#endif", fptr_C);
         if (fptr_C != NULL ) {
           fclose(fptr_C);
           fptr_C = NULL;
         }
    }

	/* 23.11.2017
	*	
	- incude file
	*/
	if (Flag_TEST)
	{
		FILE * procHeaderFile;
		Open_File_W(&procHeaderFile, "proc.h");
		fputs("/* AUTO GENERATED HEADER FILE */ \n", procHeaderFile);
		fputs("#pragma once \n", procHeaderFile);
		sprintf(string, "#include \"%sproc.h\"\n", BaseOutputFileName);
		fputs(string, procHeaderFile);

		sprintf(string, "#include \"%sxvar.h\"\n\n", BaseOutputFileName);
		fputs(string, procHeaderFile);

		if (procHeaderFile != NULL)
		{
			fclose(procHeaderFile);
		}
	}


    return(!ZERO);
};

/*================ Check error routine ================*/
INT16S check_err (INT16S error_count, INT16S n)
{
switch (n) {
case 1:  /*============ Check error in syntax parser ================*/
    if (error_count)
         printf("\n%%RCSL-I-SUMMARY, Completed with %d error(s).", error_count);
    if (warning_count)
         printf("\n%%RCSL-I-SUMMARY, Completed with %d warning(s).", warning_count);
    if (Flag_LIS) {
         fprintf(fptr_LIS, "\n%%RCSL-I-SUMMARY, Completed with %d error(s).", error_count);
         fprintf(fptr_LIS, "\n%%RCSL-I-SUMMARY, Completed with %d warning(s).", warning_count);
    }
    if (error_count != ZERO) { /* ���� ���� ������ ��� �������������� ������� */
         printf("\n%%RCSL-I-NC, No C file produced.");
         if (Flag_LIS) fprintf(fptr_LIS, "\n%%RCSL-I-NC, No C file produced.");
         exit(!ZERO);     /* ��� ������ - ����� */
	}
	break;
case 2: /* ============ Check error in semantical analizator ================ */
    if (error_count)
         printf("\n%%RCSL-I-SUMMARY, Completed with %d error(s).", error_count);
    if (warning_count)
         printf("\n%%RCSL-I-SUMMARY, Completed with %d warning(s).", warning_count);
    if (Flag_LIS) {
         fprintf(fptr_LIS, "\n%%RCSL-I-SUMMARY, Completed with %d error(s).", error_count);
         fprintf(fptr_LIS, "\n%%RCSL-I-SUMMARY, Completed with %d warning(s).", warning_count);
    }
    if (error_count != ZERO) {
         printf("\n%%RCSL-I-NC, No C file produced.");
         if (Flag_LIS) fprintf(fptr_LIS, "\n%%RCSL-I-NC, No C file produced.");
    } else {
         if (fptr_RCS != NULL ) {
           fclose(fptr_RCS);                        /* Close files */
           fptr_RCS=NULL;
         }
	 if (fptr_C != NULL ) {
           fclose(fptr_C);
           fptr_C = NULL;
         }
         if(fptr_SYM != NULL) {
           fclose(fptr_SYM);
           fptr_SYM = NULL;
         }
    }
    if (Flag_LIS) {
	 fprintf(fptr_LIS,
	      "\n\n %%RCSL-I-SUMMARY, Completed with %d error(s).",
	      error_count);
	 if ( fptr_LIS != NULL ) {
            fclose(fptr_LIS);
            fptr_LIS = NULL;
         }
    }
    if (fptr_RCS != NULL ) {
        fclose(fptr_RCS);                        /* Close files */
        fptr_RCS=NULL;
    }
    if (fptr_C != NULL) {
        fclose(fptr_C);
        fptr_C = NULL;
    }
    if(fptr_SYM!=NULL) {
        fclose(fptr_SYM);
        fptr_SYM = NULL;
    }
    if (error_count != ZERO) exit(ZERO);
    break;
default:
    break;
}
return(!ZERO);
};
