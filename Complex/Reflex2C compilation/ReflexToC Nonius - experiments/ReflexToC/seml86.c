#include "const.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "typedef.h"
#include "prototyp.h"
#include "glob_ext.h"

char  Head_Process[BUFFER_LENGTH];

/*------------ semantical analizator ------------------------------*/

int sem_anal_of_pr_cntr_86 (void) {
    sem_anal();                        /* Call Analizator */
    return(error_count);
};

/*------------ semantical analizator ---------------------------------------*/

void sem_anal(void) {
    line_count = 0;
    str_count  = 0;
    buffer1[0] = 0;
    Flag_CASE  = ZERO;   /* for select_unit ( write to Var(0) or to State(1)) */
    Sem_Program();
};


/*--------------- PROGRAM -------------------------*/

INT16S Sem_Program (void)
{
    char string[BUFFER_LENGTH];
    char str[BUFFER_LENGTH];

    select_unit();       /* for PROGRAM */
    select_unit();       /* For Program NAME */
    select_unit();       /* For { simbol */

    strcpy(string, BaseOutputFileName);     /* �������� ���� NAMEcnst.h*/
    strcat(string, "cnst.h");
    Open_File_W(&fptr_C, string);

#ifdef GEN_ID
    strcpy(string, BaseOutputFileName);     /* �������� ���� NAME_id.h*/
    strcat(string, "_id.h");
    Open_File_W(&fptr_ID, string);

    strcpy(string, BaseOutputFileName);     /* �������� ���� NAME_id.c */
    if(Flag_CPP)
	{
		strcat(string, "_id.cpp");
	}
	else
	{
		strcat(string, "_id.c");
	}
		
    Open_File_W(&fptr_IDC, string);

    strcpy(string, BaseOutputFileName);     /* �������� ���� NAME_id.h*/
    strcat(string, "_id.h");
    Open_File_W(&fptr_ID, string);
	
	fputs("#include <stdio.h>\n", fptr_IDC);

    fputs("#include \"", fptr_IDC);
    fputs(string, fptr_IDC);
    fputs("\"\n", fptr_IDC);
    fputs("main () {\n\tint i;\n", fptr_IDC);

	if (Flag_CONFIG)
	{
		fputs("\tFILE * file;\n", fptr_IDC);
		sprintf(string, "\tchar string[2 * %d];\n", BUFFER_LENGTH);
		fputs(string, fptr_IDC);

		strcpy(string, BaseOutputFileName);   
		strcat(string, "_constants.cfg");
		fputs("\tfile = fopen(\"", fptr_IDC);
		fputs(string, fptr_IDC);
		fputs("\",\"w\");\n", fptr_IDC);
	}

#endif

    Sem_Tact();                   /* ��������� �������� ����� */

    Sem_Constant();               /* ��������� �������� � ��������� NAMEcnst.h */
    if ( fptr_C != NULL ) {
        fclose(fptr_C);               /* ������� ���� NAMEcnst.h*/
        fptr_C = NULL; 
    }
#ifdef GEN_ID
    if (fptr_ID != NULL ) {
        fclose(fptr_ID);              /* ������� ���� NAME_id.h*/
        fptr_ID = NULL;
    }
    fputs("\tfclose(file);\n}\n", fptr_IDC);
    if (fptr_IDC != NULL) {
        fclose(fptr_IDC);             /* ������� ���� NAME_id.c*/
        fptr_IDC = NULL;
    }
#endif

    Sem_Function();               /* ��������� ������� */

    Sem_Port();                   /* Port Discribe */
    File_Number = 0;
    File_Number++;
    strcpy(string, BaseOutputFileName);     /* �������� ���� NAMEproc.h*/
	if (Flag_CPP)
	{
		sprintf(str,"%04d.cpp", File_Number);
	}
	else
	{
		sprintf(str,"%04d.c", File_Number);
	}
    strcat(string, str);
    Open_File_W(&fptr_C, string);
    GenHeadersInProc();
    Sem_Process();                /* Process */

    select_unit();                /* For } simbol */

    if (fptr_C != NULL) {
        fclose(fptr_C);            /* ������� ���� NAMEproc.h*/
        fptr_C = NULL;
    }

#ifdef TEST_MODE_SEM
    printf("\n=== GEN_MAIN.C");
#endif
    GenMain();               /* �������� NAMEmain.c � NAMEproc.h (main � �������� ������� - ������� ���������) */
#ifdef TEST_MODE_SEM
    printf("\n=== GEN_VARDESCRIPTION");
#endif
    GenVarDescription();     /* �������� NAMEgvar.h � NAMExvar.h (���������������� ����������) */
#ifdef TEST_MODE_SEM
    printf("\n=== GEN_INPUT_OUTPUT");
#endif
    GenInputOutput();        /* �������� NAMEinp.c NAMEoutp.c */
#ifdef TEST_MODE_SEM
    printf("\n=== GEN_SYM_FILE");
#endif
    GenSYMFile();            /* Generation Of Port Discribe In File *.SIM */
#ifdef TEST_MODE_SEM
    printf("\n=== GEN_DEBUG_FILE");
#endif
#ifdef GEN_ID
    GenDebugFile();          /* ���� � ��������� ��������� � ��������� */
#endif
#ifdef TEST_MODE_SEM
    printf("\n=== RETURN!!!");
#endif

    return(!ZERO);
};



/***************************************
* ������������ �������� �����
* � ���������� � ����� �������� ����������
* ������ #define Tact_Value nn
* nn - �����
*****************************************/

int Sem_Tact (void)
{
    select_unit();
    if (compare(unit, rezword[RW_TACT])) {  /* TACT */
         select_unit();                     /* TACT Value */
         GenTact(unit);
         select_unit();                     /* For ; simbol */
    } else {
         rewunit();          /* if TACT not exist */
         strcpy(unit, "10"); /* Default 12 ms */
         GenTact(unit);
    }
    return(!ZERO);
};

/************************************************
 *             --- Constant ---
 * ��������� �������� �������� � ������������
 * �������: 0 - ����� �����
 *         !0 - ����������, �������� ������.
 *
 ************************************************/
int Sem_Constant (void)
{

    int enum_number; /* ��� ������������ ��������� */
#ifdef TEST_MODE_SEM
	printf("\n= Sem_Constant");
#endif
    enum_number = 0; /* ��� ������������ ��������� */

    for (;;) {
         select_unit();
         switch (compare_RW(unit)) {
              case RW_CONST:  /* "CONST" */
                   GenSpaces();          /* ��������� ������������� ����� */
#ifdef GEN_ID
                   GenSpaces_ID();
#endif
                   select_unit();        /* ��� */
                   GenDefConstant(unit); /* #define Cxx */
                   select_unit();
                   Sem_Constant_Expression_Body(); /* �������� ����������� ; */
                   continue;
              case RW_ENUM:  /* "������������" */
                   GenSpaces();          /* ��������� ������������� ����� */
#ifdef GEN_ID
                   GenSpaces_ID();
#endif
                   select_unit();   /* { */
                   Sem_Constant_Enum_Body(enum_number++);
                   GenSpaces();          /* ��������� ������������� ����� */
#ifdef GEN_ID
                   GenSpaces_ID();
#endif
                   select_unit();   /* } */
                   GenUnit(unit);
#ifdef GEN_ID
                   GenUnit_ID(unit);
#endif
                   select_unit();   /* ; */
                   GenUnit(unit);
#ifdef GEN_ID
                   GenUnit_ID(unit);
#endif
                   continue;
              default:
                   rewunit();
                   return(!ZERO);
         } /* end of switch */
    } /* end of for */
};

/********************************************
 * ��������� �������� ���� ������������
 *  ���� - �� ���������
 *  unit V
 *   {     ��� ���������  ------------------->
 *                       -> = ��������� ->
 *       <----------------- , <------------
 *  RETURN: EOF   (��������� ����� �����)
 *          OK    (���������� ��� ������)
 *          ERROR (NONE) ����� ���������� �/� Find_Position
 ************************************************/
void Sem_Constant_Enum_Body (int log_name)
{
#ifdef TEST_MODE_SEM
        printf("\n== Sem_Constant_Enum");
#endif
    GenBeginEnum(log_name);

    for (;;) {
         select_unit();  /* name */
         GenDgt(unit);
#ifdef GEN_ID
         GenDgtWithCyrName_ID(unit);
         GenDgtWithCyrName_IDC(unit);
#endif
         select_unit();
         switch (compare_RW(unit)) {
              case RW_EQU:  /* "=" */ /* ������������ �������� ��������� */
                   GenUnit(unit);
#ifdef GEN_ID
                   GenUnit_ID(unit);
#endif
                   select_unit();
                   Sem_Constant_Expression_Body();  /* ������ ��������� */
                   if (!compare(unit, ",")) {
                        rewunit();
                        return;
                   }
                   GenUnit(unit);
#ifdef GEN_ID
                   GenUnit_ID(unit);
#endif
                   continue;
              case RW_COMMA:  /* "," */ /* ����� ��������� � ������������ */
                   GenUnit(unit);
#ifdef GEN_ID
                   GenUnit_ID(unit);
#endif
                   continue;
              default:       /* ���-�� ����������... ����� ������������ ? */
                   rewunit();
                   return;
         } /* end of switch */
    } /* end of for */
};


/********************************************
 * ��������� �������� ��������� ��� ���������
 *  ���� - �� ���������
 *  unit      V
 *  ���-��
 *   ������� ���� ��������
 *          ������
 *  RETURN: EOF   (��������� ����� �����)
 *          OK    (���������� ��� ������)
 *          ERROR (NONE) ����� ���������� �/� Find_Position
 ************************************************/
void Sem_Constant_Expression_Body (void)
{
#ifdef TEST_MODE_SEM
    printf("\n==== Sem_Constant_Expression_Body");
#endif
    for (;;) {          /* ��������! �� ����� � unit ��� ���-�� ��������� */
         for (;;) {     /* ��������� �������� */
              switch (Sem_Constant_Prefix_Body()) {
                   default:                 /* ��� ��� ���������� (�������) */
                        select_unit();  /* �������� unit */
                        continue;           /* � ����� ��������� �������� */
                   case NONSTATEMENT:       /* ��� �� ������� (� ����) */
                        break;
              }
              break;                        /* ����� �� ����� ��������� ��������� */
         }

         Sem_Constant_Term_Body();        /* ��������� ����� - ������ ���� */
         select_unit();  /* �������� unit */
         switch (Sem_Constant_Infix_Body()) {       /* ��������� ������� */
              default:                 /* ��� � ������� */
                   select_unit();  /* �������� unit */
                   break;
              case NONSTATEMENT:       /* ��� �� ������ */
                   return;
         }
    }    /* end of for */
};

/********************************************
 *  ��������� Constant_�������
 *  ���� - �� ���������
 *  unit      V
 *  ���-��
 *   ������� ���� ��������
 *          ������
 *  RETURN: EOF   (��������� ����� �����)
 *          OK    (���������� ��� ������, ��� ������)
 *          ERROR (NONE) ����� ���������� �/� Find_Position (?)
 *          NONSTATEMENT  - ��� �� ������ (����� ���������)
 ************************************************/
int Sem_Constant_Infix_Body (void) {
#ifdef TEST_MODE_SEM
    printf("\n===== Sem_Constant_Infix_Body");
#endif
    switch (compare_RW(unit)) {
         case RW_PLUS:              /* "+",   */
         case RW_MINUS:             /* "-",   */
         case RW_MUL:               /* "*",   */
         case RW_DIV:               /* "/",   */
         case RW_REMINDER:          /* "%",   */
         case RW_SHFT_LFT:          /* "<<",  */
         case RW_SHFT_RGHT:         /* ">>",  */
         case RW_BW_AND:            /* "&",   */
         case RW_BW_XOR:            /* "^",   */
         case RW_BW_OR:             /* "|",   */
         case RW_AND:               /* "&&",  */
         case RW_OR:                /* "||",  */
              GenUnit(unit);
#ifdef GEN_ID
              GenUnit_ID(unit);
#endif

              return(!ZERO);
         default:
              return(NONSTATEMENT);
    }
};

/********************************************
 *  ��������� Constant_�����
 *  ���� - �� ���������
 *  unit          V
 *  ��������� | ( ��������� )
 *
 *
 *  RETURN: EOF   (��������� ����� �����)
 *          OK    (���������� ��� ������, ��� ����)
 *          ERROR (NONE) ����� ���������� �/� Find_Position
 *          NONSTATEMENT  - ��� �� ���� (?)
 ************************************************/
void Sem_Constant_Term_Body (void)
{

#ifdef TEST_MODE_SEM
    printf("\n===== Sem_Constant_Term_Body");
#endif
    if (compare(unit, rezword[RW_OPEN_PARENTESIS])) 
	{ /* ( ��������� ) ? */
         GenUnit(unit);
#ifdef GEN_ID
              GenUnit_ID(unit);
#endif
         select_unit();            /* �������� unit */
         Sem_Constant_Expression_Body();   /* ������ ��������� */
         GenUnit(unit);   /* �� ������ �.�. ) */

#ifdef GEN_ID
              GenUnit_ID(unit);
#endif
    } else {
		
         GenDgt(unit);  /* ����� - ��� ��������� */
#ifdef GEN_ID
         GenDgt_ID(unit);
#endif
    }


#ifdef TEST_MODE_SEM
    printf("\nTEST: END OF CONST-TERM!!! ");
#endif
    return;
};

/********************************************
 *  ��������� Constant_��������
 *  ���� - �� ���������
 *  unit      V
 *  ���-��
 *   ������� ���� ��������
 *          ������
 *  RETURN: EOF   (��������� ����� �����)
 *          OK    (���������� ��� ������, ��� �������)
 *          ERROR (NONE) ����� ���������� �/� Find_Position (?)
 *          NONSTATEMENT  - ��� �� �������
 ************************************************/
int Sem_Constant_Prefix_Body (void)
{
#ifdef TEST_MODE_SEM
    printf("\n===== Sem_Constant_Prefix_Body");
#endif
    switch (compare_RW(unit)) {
         case RW_BW_COMPLEMENT:     /* "~",   */
         case RW_NOT:               /* "!",   */
         case RW_PLUS:              /* "+",   */
         case RW_MINUS:             /* "-",   */
              GenUnit(unit);   /* �� ������ �.�. ) */
#ifdef GEN_ID
              GenUnit_ID(unit);
#endif
              return(!ZERO);
         default:
              return(NONSTATEMENT);
    }
};

/************************************************
 * ��������� �������� �������
 ************************************************/
int Sem_Function (void)
{
#ifdef TEST_MODE_SEM
        printf("\n= Sem_Function");
#endif
    for (;;) {
         select_unit();
         if (compare(unit, rezword[RW_FUNCTION])) { /* �������� ������� ? */
              Sem_Func_Declarator_Body();
              select_unit();                          /* ��� C-������� */
              select_unit();                          /* ����������� ������ */
              Sem_Func_Args_Declarator_Body();        /* ��������� */
              select_unit();                          /* ����������� ������ */
              select_unit();                          /* ; */
              continue;
         } else {
              rewunit();
              return(!ZERO);
         }
    } /* end of for */
};

/********************************************
 * ��������� �������� ���������� �������
 *  ���� - �� ���������
 *  unit        V
 *   ��������� ------>    ���������� ------------------->
 *              <----------------- , <------------
 *  ��� ��������� - ������ ��������
 *  RETURN: ������  OK    (���������� ��� ������)
 ************************************************/
int Sem_Func_Args_Declarator_Body (void)
{
#ifdef TEST_MODE_SEM
        printf("\n== Sem_Func_Args_Declarator_Body");
#endif
    for (;;) {
         select_unit();
         switch (compare_RW(unit)) {
              case RW_SEMICOLON:         /* ";" */ /* ������������ �������� ��������� */
              case RW_CLOSE_PARENTESIS:  /* ")" */ /* ������������ �������� ��������� */
                   rewunit();
                   return(!ZERO);
              case RW_COMMA:     /* "," */ /* ����� ��������� � ������������ */
                   continue;
              default:       /* ���-�� ����������... ���������� ? */
                   rewunit();
                   Sem_Func_Declarator_Body();    /* ������ ����������� */
                   continue;
         } /* end of switch */
    } /* end of for */
};

/********************************************
 * ��������� ����������� �������
 *  ���� - �� ���������
 *  unit V
 *        SHORT | LONG | INT | FLOAT | DOUBLE ...
 *
 * decl_case - ������ �����������
 *   RW_TYPE - ���������� ���� �������
 *   RW_ARGUMENTS - ���������� ��������� �������
 *
 * ��������� Current_Function ��������� �� ������� �������
 *
 *  RETURN: EOF   (��������� ����� �����)
 *          OK    (��������� ����������)
 *          ERROR (NONE) ����� ���������� �/� Find_Position
 *          NONSTATEMENT - ��� �� ���������� unit = (
 *
 ************************************************/
int Sem_Func_Declarator_Body (void)
{
#ifdef TEST_MODE_SEM
    printf("\n===== Sem_Func_Declarator_Body");
#endif
    select_unit();  /* */
    switch (compare_RW(unit)) {
         case RW_SHORT:                /* SHORT */
         case RW_LONG:                 /* LONG */
         case RW_INT:                  /* INT */
              return(Sem_Func_Sign_Body());
         case RW_FLOAT:
         case RW_DOUBLE:
         case RW_VOID:
              return(Sem_Func_Mul_Body());
         case RW_SIGN:
         case RW_UNSIGN:
              return(Sem_Func_Int_Body());
         default:             /*  ��� �� ���������� */
              printf("\n FATAL ERROR. SFDB.");
	      exit(ZERO);
	      return(!ZERO);
    }
}
/********************************************
 *  ��������� ����� ����� �������������� �����������
 *  ���� - �� ���������
 *                     unit   V
 *  (     SHORT | LONG | INT    * ) | )
 *
 *  RETURN: EOF   (��������� ����� �����)
 *          OK    (��������� ����������)
 *          ERROR (NONE) ����� ���������� �/� Find_Position
 ************************************************/
int Sem_Func_Mul_Body (void)
{
#ifdef TEST_MODE_SEM
    printf("\n======= Sem_Func_Mul_Body");
#endif
    for (;;) {
        select_unit();
        switch (compare_RW(unit)) {
             case RW_MUL:                  /* SIGNED ****** */
                  continue;
             default:
                  rewunit();
                  return(!ZERO);
        }
    }
};

/********************************************
 * ��������� �������� ����� �������������� �����������
 *  ���� - �� ���������
 *                     unit   V
 *  (     SHORT | LONG | INT    SIGN ) | UNSIGN ) | ) | SIGN *) | UNSIGN *)
 *
 *  RETURN: EOF   (��������� ����� �����)
 *          OK    (��������� ����������)
 *          ERROR (NONE) ����� ���������� �/� Find_Position
 ************************************************/
int Sem_Func_Sign_Body (void)
{
#ifdef TEST_MODE_SEM
    printf("\n====== Sem_Func_Sign_Body");
#endif
    select_unit();
    switch (compare_RW(unit)) {
         case RW_UNSIGN:                         /* UNSIGNED */
         case RW_SIGN:                           /* SIGNED */
         case RW_MUL:                            /* SIGNED */
              return(Sem_Func_Mul_Body());
         default:
              rewunit();
              return(!ZERO);
    }
};

/********************************************
 * ��������� �������� ����� ��������� �����������
 *  ���� - �� ���������
 *         unit       V
 *  (  SIGN | UNSIGN   SHORT) | LONG) | INT)
 *
 *  RETURN: EOF   (��������� ����� �����)
 *          OK    (��������� ����������)
 *          ERROR (NONE) ����� ���������� �/� Find_Position
 ************************************************/
int Sem_Func_Int_Body (void)
{
#ifdef TEST_MODE_SEM
    printf("\n====== Sem_Func_Int_Body");
#endif
    select_unit();
    switch (compare_RW(unit)) {
         case RW_SHORT:                          /* SHORT */
         case RW_INT:                            /* INT */
         case RW_LONG:                           /* LONG */
              return(Sem_Func_Mul_Body());
         default:
              rewunit();
              return(!ZERO);
    }
};

/************************************************
 *            --- Sem_Port ---
 * �������: 0 - ����� �����
 *         !0 - ����������
 ************************************************/
Sem_Port() /* Work Up And Generation Port-Imerge */
{
/*--------------- INPUT OR  OUTPUT OR RAM -----------------------*/
 select_unit();                     /* init. while */
 while((compare(unit,rezword[RW_INPUT]))||(compare(unit,rezword[RW_OUTPUT]))
        ||(compare(unit, rezword[RW_RAM]))){      /* while port */
    if(compare(unit,rezword[RW_INPUT])){            /* if INPUT */
     select_unit();                     /* For Name */
     select_unit();                     /* ��� ������ �� �� */
     select_unit();                     /* For Address */
     select_unit();                     /* For Size */
     select_unit();                     /* For ; simbol */
     goto reg1;
    } /* end of INPUT */
    if(compare(unit,rezword[RW_OUTPUT])){ /* OUTPUT */
         select_unit();                     /* For Name */
         select_unit();                     /* ��� ������ �� �� */
         select_unit();                     /* For Address */
         select_unit();                     /* For Size */
         select_unit();                     /* For ; simbol */
         goto reg1;
    }else{             /* RAM */
         select_unit();                     /* For Name */
         select_unit();                     /* For Segment */
         select_unit();                     /* For Offset */
         select_unit();                     /* For VME Address */
         select_unit();                     /* For Size */
         select_unit();                     /* For ; simbol */
    }/* end of if - else (OUTPUT/RAM) */
reg1:
    select_unit();                          /* select new word */
} /* end of while */
rewunit(); /* rewunit if not INPUT/OUTPUT/RAM */
return(!ZERO);
};


/************************************************
 * ������������� ��������� ��������
 ************************************************/
void Sem_Process (void)
{
#ifdef TEST_MODE_SEM
        printf("\n= Sem_Process = %s", buffer1);
#endif

    select_unit();
    while (compare(unit, rezword[RW_PROC])) {   /* while PROC */
#ifdef TEST_MODE_SEM
        printf("\n== Sem_Process");
#endif
         select_unit();           /* ��� �������� */
         Flag_CASE = !ZERO;       /* ��� select_unit (����� ������ � fptr_C(�������� ���������)) */
         GenProcess(unit);        /* ��������� ������ �������� */
         select_unit();           /* { */
         Sem_Variable_List();     /* work up variables list */
         Sem_State();             /* work up states */
         GenEndOfProcess();       /* ��������� ����� �������� */
         select_unit();           /* for } */
         select_unit();           /* next word */
    } /* end of while */
    rewunit(); /* rewunit if not PROC */
    return;
};



/************************************************
 *    ��������� �������� ���������� ��������
 ************************************************/
void Sem_Variable_List (void)
{
#ifdef TEST_MODE_SEM
        printf("\n== Sem_Variable_List");
#endif
    for (;;) {                              /* ���������� ��� ���������� */
         select_unit();
         switch (compare_RW(unit)) {
              case RW_LOG:
              case RW_INT:
              case RW_SHORT:
              case RW_LONG:
              case RW_DOUBLE:
              case RW_FLOAT:
                   Sem_Discr_Var();
                   break;
              case RW_FROM:
                   Sem_From_Var();
                   break;
              default:
                   rewunit(); /* if next word neither LOG, INT nor FROM */
                   return;
         } /* end of switch */ /* ������ ����� ������ ������������ ������ */
    } /* end of for */
};


/************************************************
 * ��������� ����� - �������� ���������� ��������
 * LOG INT LONG SHORT FLOAT DOUBLE
 * RETURN: NONE
 * ����� - ��������� �� ;
 ************************************************/
void Sem_Discr_Var (void)
{
#ifdef TEST_MODE_SEM
        printf("\n=== Sem_Discr_Var");
#endif
    select_unit();                /* ��� ���������� */
    select_unit();
    if (compare(unit, "=")) {     /* ���� �����. ����� - ������ ���. ������ */
         select_unit();           /* ������ { */
         for (;;) {               /* ������ �������� � ���. ������ */
              select_unit();      /* ��� ����� */
              select_unit();      /* ������ [ */
              select_unit();      /* ����� */
              select_unit();      /* ������ ] */
              select_unit();
              if (!compare(unit, ",")) break;    /* ����� �������� ���������� � ������ */
         }                        /* �� ������ - ���������� ���.������ */
         select_unit();           /* �������� ������� ������� (LOCAL or FOR) */
    }   /* ����� ������� ���-������. ����� ������ ������ ������� ������� */

    switch (compare_RW(unit)) {
         case RW_LOCAL:           /* if local variables LOCAL */
              Sem_Local_Var();
              break;
         default:                 /* if FOR */
              Sem_For_Var();
    }
    return;
};

/************************************************
 * ������������� ��������� �������� ����������,
 * ��������� � ������ ���������
 * ���� -> ��� �������� -> ��� ���������� ->
 *                       <----- , -------/
 * RETURN: NONE
 * ����� - ��������� �� ;
 ************************************************/
void Sem_From_Var (void)
{
    char process_name[BUFFER_LENGTH]; /* ����� ����� ��������-������� ���������� */
#ifdef TEST_MODE_SEM
        printf("\n==== Sem_From_Var");
#endif
/*printf("\n========================= FROMVAR");*/
    select_unit();                /* for ���� */
    select_unit();                /* ��� �������� */
    strcpy(process_name, unit);   /* �������� ��� �������� */
    for (;;) {
         select_unit();           /* ��� ���������� */
         switch (CheckVariableInProc(process_name, unit)) {
              case NO_PROCESS:
                   error_msg(75, line_count, unit, NONE); /* ����������� ������� */
                   break;
              case NO_VARIABLE:
                   error_msg(76, line_count, unit, NONE); /* ��� ���������� */
                   break;
              case NO_ACCESS:
                   error_msg(49, line_count, unit, NONE); /* ������ �������� */
                   break;
              default:
                   break;

         }
         select_unit();
         if (!compare(unit, ",")) return;
    }
};


/************************************************
 *         ��������� ���� ������� ��������� ����������
 *          ��������� �� ; unit = ";"
 ************************************************/
void Sem_Local_Var (void)
{
#ifdef TEST_MODE_SEM
        printf("\n==== Sem_Local_Var");
#endif
    select_unit(); /* for ; symbol */
    return;
};

/************************************************
 *              --- ForVar ---
 * �������: 0 - ����� �����
 *         !0 - ����������, �������� ������.
 ************************************************/
void Sem_For_Var (void)
{
#ifdef TEST_MODE_SEM
        printf("\n==== Sem_For_Var");
#endif
    select_unit();
    switch (compare_RW(unit)) {
         case RW_PROC:                      /* if FOR + PROC */
              for (;;) {
                   select_unit();           /* ��� �������� */
                   select_unit();
                   if (!compare(unit, ",")) break;    /* ����� ������������ ? */
              }
              /* select_unit(); ???????*/
              break;
         case RW_ALL:        /* if FOR+ALL */
         default:
              select_unit(); /* ; */
              break;
    }
    return;
};

/************************************************
 *       ��������� ���������
 ************************************************/
void Sem_State (void)
{
#ifdef TEST_MODE_SEM
        printf("\n== Sem_State = %s", buffer1);
#endif
    select_unit();
    while (compare(unit, rezword[RW_STATE])) {   /* ����� ����? */
         select_unit();                /* ��� ��������� */
         GenBeginOfState(unit);        /* ���������� ������ ��������� */
         select_unit();                /* "{" */
         select_unit();                /* ������ ����� */
         if (compare(unit, rezword[RW_TIMEOUT])) {    /* ������� ?*/
              Sem_Time_Out();
              select_unit();                /* } */
         } else {                           /* ���� �� ������� */
              rewunit();
              Sem_State_Body();             /* State {} */
              select_unit();                /* */
              if (compare(unit, rezword[RW_TIMEOUT])) {
                   Sem_Time_Out();
                   select_unit();           /* } */
              }
         }

         GenEndOfState();    /* ����� ����������(���������������) ��������� */
         select_unit();      /* ����� ����� ��������� */
    }                        /* end of while STATE */
    rewunit();
    return;
};

/************************************************
 *             --- State_Body ---
 *  RETURN: EOF   ()
 *          OK    (})
 *          ERROR (NONE) ����� ���������� �/� Find_Position
 ************************************************/
void Sem_State_Body (void)
{
#ifdef TEST_MODE_SEM
    printf("\n== Sem_State_Body");
#endif
    for (;;) {
         switch (Sem_Statement_Body()) {       /* Statement  */
              case NONSTATEMENT:       /* ����������� ������������� -  ����� */
                   return;
              default:                 /* NO ERROR */
                   break;              /* check for next state */
         } /* end of switch */
    }
};

/************************************************
 *  ������ �����������
 *  RETURN: OK    (���������� ��� ������)
 *          NONSTATEMENT  (��� �� �����������)
 ************************************************/
int Sem_Statement_Body (void)
{
#ifdef TEST_MODE_SEM
    printf("\n=== Sem_Statement_Body. string is \n%s", buffer1);
#endif
    select_unit();
    switch (compare_RW(unit)) {
         case RW_SEMICOLON:            /* ";" - next unit  */
              GenUnit(unit);
              break;
         case RW_OPEN_BRACE:           /* "{" - State_Body - "}"  */
              GenUnit(unit);
              Sem_State_Body();
              select_unit();           /* "}" */
              GenUnit(unit);
              break;
         case RW_SWITCH:
              Sem_Switch_Body();       /* SWITCH ( expression ) statement */
              break;
         case RW_IF:
              Sem_Condition_Body();    /* IF ( expression ) ... */
              select_unit();
              if (compare(unit, rezword[RW_ELSE])) {  /* ����-�������? */
                   GenRezWord(RW_ELSE);          /* ��������� ������� � ������ else */
                   Sem_Post_Condition_Body();    /* ELSE statement */
              } else {
                   rewunit(); /* ���� �� ����-������� - ���������� ����� */
              }
              break;
         case RW_STOP:
              Sem_Stop_Body();    /* STOP ; | PROC ��� �������� ; */
              break;
         case RW_LOOP:
              Sem_Loop_Body();    /* STOP ; | PROC ��� �������� ; */
              break;
         case RW_ERROR:
              Sem_Error_Body();   /* ERROR ; | PROC ��� �������� ; */
              break;
         case RW_START:
              Sem_Start_Body();   /* START PROC ��� �������� ; */
              break;
         case RW_IN:
              Sem_In_Body();      /* IN STATE NEXT | ��� ��������� ; */
              break;
         case RW_TIMEOUT:              /*  ���� ������� */
         case RW_CLOSE_BRACE:          /* ��� "}" */
         case RW_BREAK:                /* ��� ����� (� �������) */
         case RW_DEFAULT:              /* ��� ��������� (� �������) */
         case RW_CASE:                 /* ��� ������ (� �������) */
              rewunit();               /* ���������� -  � ����� */
              return(NONSTATEMENT);
         default: /*  � ���������� ������ - �������� ��������� ��������� */
              Sem_Expression_Body();   /* ������ ��������� */
              break;
    } /* end of switch */
    return(!ZERO);
};


/********************************************
 *  ��������� �������� �������
 *  ���� - ����� ����������� ���.����� ����
 *  unit V
 *  ���� ( ��������� ) �����������
 *  RETURN: NONE
 ************************************************/
void Sem_Condition_Body (void) {
#ifdef TEST_MODE_SEM
    printf("\n==== Sem_Condition_Body");
#endif

    GenRezWord(RW_IF);            /* ��������� ������� � ������ if */
    select_unit();                /* for ( symbol */
    GenUnit(unit);                /* ��������� ������������� ����� */
    select_unit();                /* �������� unit */
    Sem_Expression_Body();        /* IF ( ��������� ) �������� � ����������� ������ */
    Sem_Statement_Body();         /* Statement  */
    return;
}

/********************************************
 * ��������� �������� ����-�������
 *  ���� - ����� ����������� ���.����� �����
 *  unit  V
 *  ����� �����������
 *  RETURN: NONE
 ************************************************/
void Sem_Post_Condition_Body (void)
{
#ifdef TEST_MODE_SEM
    printf("\n==== Sem_Post_Condition_Body");
#endif
    Sem_Statement_Body();         /* Statement  */
#ifdef TEST_MODE_SEM
    printf("\n==== TEST: END OF Post_Condition_Body");
#endif
    return;
};


/********************************************
 * ��������� �������� ����
 *  ���� - ����� ����������� ���.����� ����
 *  unit V
 *  ����  <���� (��� ��������)> ; (���� ������ ����; - ��� ��������)
 *  RETURN: NONE
 ************************************************/
void Sem_Stop_Body (void)
{
#ifdef TEST_MODE_SEM
    printf("\n==== Sem_Stop_Body");
#endif
    GenSpaces();              /* ��������� ������������� ����� */
    select_unit();
    switch (compare_RW(unit)) {
         case RW_PROC:            /* ���� */
              select_unit();      /* ��� �������� */
              if(!GenStop(unit))
                   error_msg(41, line_count, unit, NONE); /* ���� ������ */
              select_unit();      /* ; */
              break;
         case RW_SEMICOLON:       /* ���� ";" => ��� �������� �������� */
              GenStopForCurrentProc();
              break;
         default:                 /*  ����� - ������ ������������ �������� */
              error_msg(23, line_count, unit, NONE);
              return;
    } /* end of switch */
    return;
};

/********************************************
 * ��������� �������� ���������
 *  ���� - ����� ����������� ���.����� ���������
 *  unit V
 *  ��������� ; 
 *  RETURN: NONE
 ************************************************/
void Sem_Loop_Body (void)
{
#ifdef TEST_MODE_SEM
    printf("\n==== Sem_Loop_Body");
#endif
    GenSpaces();              /* ��������� ������������� ����� */
    select_unit();            /*;*/
    return;
};

/********************************************
 * ��������� �������� ������
 *  ���� - ����� ����������� ���.����� ������
 *  unit   V
 *  ������  <���� (��� ��������)> ; (���� ������ ������; - ��� ��������)
 *  RETURN: NONE
 ************************************************/
void    Sem_Error_Body (void)
{
#ifdef TEST_MODE_SEM
    printf("\n==== Sem_Error_Body");
#endif
    GenSpaces();              /* ��������� ������������� ����� */
    select_unit();
    switch (compare_RW(unit)) {
         case RW_PROC:            /* ���� */
              select_unit();      /* ��� �������� */
              if(!GenError(unit))
                   error_msg(41, line_count, unit, NONE); /* ���� ������ */
              select_unit();      /* ; */
              break;
         case RW_SEMICOLON:       /* ���� ";" => ��� �������� �������� */
              GenErrorForCurrentProc();
              break;
         default:                 /*  ����� - ������ ������������ �������� */
              error_msg(23, line_count, unit, NONE);
              return;
    } /* end of switch */
    return;
};

/********************************************
 * ��������� �������� �����
 *  ���� - ����� ����������� ���.����� �����
 *  unit   V
 *  �����   <���� (��� ��������)> ; (���� ������ �����; - ��� ��������)
 *  RETURN: EOF   (��������� ����� �����)
 *          OK    (���������� ��� ������)
 *          ERROR (NONE) ����� ���������� �/� Find_Position
 ************************************************/
void Sem_Start_Body (void)
{
#ifdef TEST_MODE_SEM
    printf("\n==== Sem_Start_Body");
#endif
    GenSpaces();              /* ��������� ������������� ����� */
    select_unit();
    switch (compare_RW(unit)) {
         case RW_PROC:            /* ���� */
              select_unit();      /* ��� �������� */
              if(!GenStart(unit))
                   error_msg(41, line_count, unit, NONE); /* ���� ������ */
              select_unit();      /* ; */
              break;
         case RW_SEMICOLON:       /* ���� ";" => ��� �������� �������� */
              GenStartForCurrentProc();
              break;
         default:                 /*  ����� - ������ ������������ �������� */
              error_msg(23, line_count, unit, NONE);
              return;
    } /* end of switch */
    return;
};

/********************************************
 * ��������� �������� � ����
 *  ���� - ����� ����������� ���.����� �
 *  unit  V
 *  �      <����   ��� ���������>|<���������> ;
 *  RETURN: EOF   (��������� ����� �����)
 *          OK    (���������� ��� ������)
 *          ERROR (NONE) ����� ���������� �/� Find_Position
 ************************************************/
void Sem_In_Body (void)
{
#ifdef TEST_MODE_SEM
    printf("\n==== Sem_In_Body");
#endif
    GenSpaces();              /* ��������� ������������� ����� */
    select_unit();
    switch (compare_RW(unit)) {
         case RW_STATE:                           /* ���� */
              select_unit();
              if(!GenJMP(unit))
                   error_msg(42, line_count, unit, NONE);  /* ���� ������ ��������� */
              select_unit();   /* ; */
              break;
         case RW_NEXT:       /* ��������� => ��������� ��������� �������� */
              if(!GenJMPInNextState())
                   error_msg(42, line_count, unit, NONE);  /* ���� ������ ��������� */
              select_unit();   /* ; */
              break;
         default:                 /*  ����� - ������ ������������ ��������� */
              error_msg(56, line_count, unit, NONE);
              return;
    } /* end of switch */
    return;
};


/********************************************
 * ��������� �������� ������
 *  ���� - ����� ����������� ���.����� ������
 *  unit   V
 *  ������   ( ��������� ) {
 *      ������ ��������� :
 *             �����������
 *             �����;
 *      ���������:
 *             �����������
 *             �����;
 *  }
 *  RETURN: EOF   (��������� ����� �����)
 *          OK    (���������� ��� ������)
 *          ERROR (NONE) ����� ���������� �/� Find_Position
 ************************************************/
void Sem_Switch_Body (void)
{
#ifdef TEST_MODE_SEM
    printf("\n==== Switch_Body");
#endif
    GenRezWord(RW_SWITCH);
    select_unit();                /* for ( symbol */
    GenUnit(unit);                /* ����� ������� ( � ��������������� */
    select_unit();                /* �������� unit */
    Sem_Expression_Body();        /* ������ ( ��������� ) - �������� ) */
 /*   GenUnit(unit);                /* ����� ������� ) � ��������������� */
    select_unit();                /* for { symbol */
    GenUnit(unit);                /* ����� ������� { � ��������������� */
    for (;;) {                    /* ������ ������������� ������ () */
         switch (Sem_Case_Body()) {    /* ������������ ������� */
              case NONSTATEMENT:       /* ����������� ������������� - } */
                   break;
              default:                 /* NO ERROR - ���������� ��������� ������������� */
                   continue;
         } /* end of switch */
         break;
    }

    select_unit();                /* for } symbol */
    GenUnit(unit);                /* ����� ������� } � ��������������� */
    return;
};

/********************************************
 * ��������� �������� ������
 *  ���� - ����� ����������� {
 *                        unit   V
 *  ������   ( ��������� ) {
 *      ������ ��������� :
 *             �����������
 *             �����;
 *      ���������:
 *             �����������
 *             �����;
 *
 *  }
 *  RETURN: NONESTATEMENT -  ��������� �� ��������
 *          OK               (���������� ��� ������)
 *          ERROR (NONE) ����� ���������� �/� Find_Position
 ************************************************/
int Sem_Case_Body (void)
{
#ifdef TEST_MODE_SEM
    printf("\n==== Sem_Case_Body");
#endif
    select_unit();
    switch (compare_RW(unit)) {
         case RW_CASE:                      /* ������ */
              GenRezWord(RW_CASE);          /* ��������� ������� � ������ case */
              select_unit();                /* ��������� */
              GenDgt(unit);
              select_unit();                /* ��������� */
              GenUnit(unit);                /* ����� ������� : � ��������������� */
              Sem_State_Body();             /* State {} */
              select_unit();                /* ��������, ��� ������ */
              if (compare(unit, rezword[RW_BREAK])) { /* ����� (break) */
                   GenRezWord(RW_BREAK);    /* ��������� ������� � ������ case */
                   select_unit();           /* ; */
                   GenUnit(unit);           /* ����� ������� ; � ��������������� */
              } else {                      /* ����� ������ ��� �� ����� */
                   rewunit();
              }
              break;
         case RW_DEFAULT:                   /* ��������� */
              GenRezWord(RW_DEFAULT);       /* ��������� ������� � ������ default */
              select_unit();                /* : */
              GenUnit(unit);                /* ����� ������� : � ��������������� */
              Sem_State_Body();             /* State {} */
              select_unit();                /* ��������, ��� ������ */
              if (compare(unit, rezword[RW_BREAK])) { /* ����� (break) */
                   GenRezWord(RW_BREAK);    /* ��������� ������� � ������ case */
                   select_unit();           /* ; */
                   GenUnit(unit);           /* ����� ������� ; � ��������������� */
              } else {                      /* ����� ������ ��� �� ����� */
                   rewunit();
              }
              break;
         default:                           /*  ����� - ������ ������������ ��������� */
              rewunit();
              return(NONSTATEMENT);         /* ����������� ���-�� ���������� */
    } /* end of switch */
    return(!ZERO);
 };

/********************************************
 * ��������� �������� ���������
 *  ���� - �� ���������
 *  unit      V
 *  ���-��
 *   ������� ���� ��������
 *          ������
 *  RETURN: NONE
 ************************************************/
/* ��������� �������� ��������� */
void Sem_Expression_Body (void)
{
#ifdef TEST_MODE_SEM
    printf("\n==== Sem_Expression_Body");
#endif
    for (;;) {          /* ��������! �� ����� � unit ��� ���-�� ��������� */
         for (;;) {     /* ��������� �������� */
              switch (Sem_Prefix_Body()) {
                   default:                 /* ��� ��� ���������� (�������) */
                        select_unit();      /* �������� unit */
                        continue;           /* � ����� ��������� �������� */
                   case NONSTATEMENT:       /* ��� �� ������� (� ����) */
                        break;
              }
              break;                        /* ����� �� ����� ��������� ��������� */
         }
         Sem_Term_Body();                   /* ��������� ����� - ������ ���� */
         select_unit();                     /* �������� unit */
         switch (Sem_Postfix_Body()) {
              default:                      /* ��� ��� �������� */
                   select_unit();           /* �������� unit */
                   break;
              case NONSTATEMENT:            /* ��� �� �������� */
                   break;
         }

         switch (Sem_Infix_Body()) {        /* ��������� ������� */
              default:                      /* ��� � ������� */
                   select_unit();           /* �������� unit ) */
                   break;
              case NONSTATEMENT:            /* ��� �� ������ => ����� */
                   GenUnit(unit);           /* ��� ������ ���������� ������, ������������� ����. �������� */
                   return;
         }
    }    /* end of for */
};
/********************************************
 *  ��������� �������
 *  ���� - �� ���������
 *  unit      V
 *  ���-��
 *   ������� ���� ��������
 *          ������
 *  RETURN:
 *          OK    (���������� ��� ������, ��� ������)
 *          NONSTATEMENT  - ��� �� ������ (����� ���������)
 ************************************************/
int Sem_Infix_Body (void) {
#ifdef TEST_MODE_SEM
    printf("\n===== Sem_Infix_Body");
#endif
    switch (compare_RW(unit)) {
         case RW_PLUS:              /* "+",   */
         case RW_MINUS:             /* "-",   */
         case RW_MUL:               /* "*",   */
         case RW_DIV:               /* "/",   */
         case RW_REMINDER:          /* "%",   */
         case RW_SHFT_LFT:          /* "<<",  */
         case RW_SHFT_RGHT:         /* ">>",  */
         case RW_BW_AND:            /* "&",   */
         case RW_BW_XOR:            /* "^",   */
         case RW_BW_OR:             /* "|",   */
         case RW_AND:               /* "&&",  */
         case RW_OR:                /* "||",  */
         case RW_EQU:               /* "=",   */
         case RW_MUL_EQU:           /* "*=",  */
         case RW_DIV_EQU:           /* "/=",  */
         case RW_REM_EQU:           /* "%=",  */
         case RW_PLUS_EQU:          /* "+=",  */
         case RW_MINUS_EQU:         /* "-=",  */
         case RW_SHFT_LFT_EQU:      /* "<<=", */
         case RW_SHFT_RGHT_EQU:     /* ">>=", */
         case RW_BW_AND_EQU:        /* "&=",  */
         case RW_BW_XOR_EQU:        /* "^=",  */
         case RW_BW_OR_EQU:         /* "|=",  */
         case RW_LESS:              /* "<",   */
         case RW_GREATER:           /* ">",   */
         case RW_LESS_EQU:          /* "<=",  */
         case RW_GREATER_EQU:       /* ">=",  */
         case RW_EQU_EQU:           /* "==",  */
         case RW_NOT_EQU:           /* "!=",  */
              GenUnit(unit);        /* ����� ������� ; � ��������������� */
              return(!ZERO);
         default:
              return(NONSTATEMENT);
    }
};

/********************************************
 *  ��������� ���������
 *  ���� - �� ���������
 *  unit      V
 *  ���-��
 *   ������� ���� ��������
 *          ������
 *  RETURN:
 *          OK    (���������� ��� ������, ��� ��������)
 *          NONSTATEMENT  - ��� �� ��������
 ************************************************/
int Sem_Postfix_Body (void) {
#ifdef TEST_MODE_SEM
    printf("\n===== Sem_Postfix_Body");
#endif
    switch (compare_RW(unit)) {
         case RW_INC:                  /* "++",   */
         case RW_DEC:                  /* "--",   */
              GenUnit(unit);           /* ����� ������� ; � ��������������� */
              return(!ZERO);
         default:
              return(NONSTATEMENT);
    }
};

/********************************************
 *  ��������� �����
 *  ���� - �� ���������
 *  unit                                     V
 *  �������|���������|����������|�������� | ( ��������� )
 *
 *
 *  RETURN: NONE
 ************************************************/
void Sem_Term_Body (void)
{
    char proc_name[BUFFER_LENGTH];

#ifdef TEST_MODE_SEM
    printf("\n===== Sem_Term_Body");
#endif
    if (compare(unit, rezword[RW_PROC])) {            /* ���� ��� � ���� ��� ? */
         GenSpaces();              /* ��������� ������������� ����� */
         select_unit();            /* ��� �������� ? */
         strcpy(proc_name, unit);  /* �������� ��� �������� */
         select_unit();            /* ����� � */
         select_unit();            /* ����� COCT */
         select_unit();            /* ��� ��������� */
         switch (compare_RW(unit)) {                            /* ��� �� ��������� ? */
              case RW_STOP:                                     /* ���� */
                   if (!GenSituationProcInSTOP(proc_name))      /* �������� ���� � ���� */
                        error_msg(41, line_count, proc_name, NONE);
                   break;
              case RW_ERROR:                                    /* ������ */
                   if (!GenSituationProcInERROR(proc_name))     /* �������� ���� � ������ */
                        error_msg(41, line_count, proc_name, NONE);
                   break;
              case RW_ACTIVE:                                   /* �������� */
                   if (!GenSituationProcInACTIVE(proc_name))    /* �������� ���� ������� */
                        error_msg(41, line_count, proc_name, NONE);
                   break;
              case RW_PASSIVE:                                   /* ��������� */
                   if (!GenSituationProcInPASSIVE(proc_name))    /* �������� ���� �������� */
                        error_msg(41, line_count, proc_name, NONE);
                   break;
              case RW_NULL:                           /* ���������� ��� ��������� */
                   if (!GenSituationProcInState(proc_name, unit)) /* �������� ���� ������� */
                        error_msg(57, line_count, "\0", NONE);
                   break;
              default:
                   error_msg(22, line_count, unit, NONE);  /* �.�. ��� ��������� */
                   return;
         }
    } else {                                               /* ��� �� �������� */
         if (compare(unit, rezword[RW_OPEN_PARENTESIS])) { /* ( ��������� ) ? */
              select_unit();                               /* �������� unit */
              Sem_Expression_Body();    /* ������ ���������, � ������� ) */
         } else {   /* ����� ��������� ��� ����������, �������, ��������� */
              if (!CheckNameFunc(unit)) {   /* ��� ������� ? */
                   GenUnit(unit);           /* ��� ������� + ������������� ����� */
                   Sem_Check_Func_Args();   /* ��? - ������ ������� */
              } else GenVariable(unit);       /* ��� ����������/��������� */
         }
    }
    return;
};


/********************************************
 *  ��������� ��������
 *  ���� - �� ���������
 *  unit      V
 *  ���-��
 *   ������� ���� ��������
 *          ������
 *  RETURN:
 *          OK    (���������� ��� ������, ��� �������)
 *          NONSTATEMENT  - ��� �� �������
 ************************************************/
int Sem_Prefix_Body (void) {
#ifdef TEST_MODE_SEM
    printf("\n===== Sem_Prefix_Body");
#endif
    switch (compare_RW(unit)) {
         case RW_BW_COMPLEMENT:     /* "~",   */
         case RW_NOT:               /* "!",   */
         case RW_INC:               /* "++",  */
         case RW_DEC:               /* "--",  */
         case RW_PLUS:              /* "+",   */
         case RW_MINUS:             /* "-",   */
         case RW_MUL:               /* "*",   */
         case RW_BW_AND:            /* "&",   */
              GenUnit(unit);        /* ����� �������-������� � ��������������� */
              return(!ZERO);
         case RW_OPEN_PARENTESIS:   /* "(" - ���������, �������������� ����� ?*/
              GenUnit(unit);        /* ����� ������� ( � ��������������� */
              switch (Sem_Declarator_Body()) {
                   case NONSTATEMENT:            /* ��� �� ���������� */
                        return(NONSTATEMENT);
                   default:                      /* ��� ��� ���������� (�������) */
                        select_unit();           /* ) */
                        GenUnit(unit);           /* ����� ������� ) � ��������������� */
                        return(!ZERO);
              } /* end of switch */
         default:
              return(NONSTATEMENT);
    }
};

/********************************************
 * ��������� �����������
 *  ���� - �� ���������
 *  unit V
 *  (     SHORT | LONG | INT | FLOAT | DOUBLE ...
 *
 *  RETURN:
 *          OK    (��������� ����������)
 *          NONSTATEMENT - ��� �� ���������� unit = (
 *
 ************************************************/
int Sem_Declarator_Body (void)
{
#ifdef TEST_MODE_SEM
    printf("\n===== Sem_Declarator_Body");
#endif
    select_unit();  /* */
    switch (compare_RW(unit)) {
         case RW_SHORT:                /* SHORT */
              GenRezWord(RW_SHORT);
              Sem_Sign_Body();
              break;
         case RW_LONG:                 /* LONG */
              GenRezWord(RW_LONG);
              Sem_Sign_Body();
              break;
         case RW_INT:                  /* INT */
              GenRezWord(RW_INT);
              Sem_Sign_Body();
              break;
         case RW_FLOAT:
              GenRezWord(RW_FLOAT);
              Sem_Mul_Body();
              break;
         case RW_DOUBLE:
              GenRezWord(RW_DOUBLE);
              Sem_Mul_Body();
              break;
         case RW_VOID:
              GenRezWord(RW_FLOAT);
              Sem_Mul_Body();
              break;
         case RW_SIGN:
	      GenRezWord(RW_SIGN);
	      Sem_Int_Body();
	      break;
	 case RW_UNSIGN:
	      GenRezWord(RW_UNSIGN);
	      Sem_Int_Body();
	      break;
	 default:             /*  ��� �� ���������� */
	      rewunit();
	      return(NONSTATEMENT);
    }
    return(!ZERO);
}

/********************************************
 *  ��������� ����� ����� �������������� �����������
 *  ���� - �� ���������
 *                     unit   V
 *  (     SHORT | LONG | INT    * ) | )
 *
 *  RETURN: NONE
 ************************************************/
void Sem_Mul_Body (void)
{
#ifdef TEST_MODE_SEM
    printf("\n======= Sem_Mul_Body");
#endif
    for (;;) {
         select_unit();
         switch (compare_RW(unit)) {
              case RW_MUL:             /* SIGNED ****** */
                   GenUnit(unit);      /* ����� ������� * � ��������������� */
                   continue;
              default:
                   rewunit();
                   return;
         }
    }
};

/********************************************
 * ��������� �������� ����� �������������� �����������
 *  ���� - �� ���������
 *                     unit   V
 *  (     SHORT | LONG | INT    SIGN ) | UNSIGN ) | ) | SIGN *) | UNSIGN *)
 *
 *  RETURN: NONE
 ************************************************/
void Sem_Sign_Body (void)
{
#ifdef TEST_MODE_SEM
    printf("\n====== Sem_Sign_Body");
#endif
    select_unit();
    switch (compare_RW(unit)) {
         case RW_UNSIGN:                         /* UNSIGNED */
	      GenRezWord(RW_UNSIGN);
	      Sem_Mul_Body();
	      break;
	 case RW_SIGN:                           /* SIGNED */
              GenRezWord(RW_SIGN);
              Sem_Mul_Body();
              break;
         case RW_MUL:                            /* * */
              GenUnit(unit);                     /* ����� ������� * � ��������������� */
              Sem_Mul_Body();
              break;
         default:
              rewunit();
              return;
    }
};

/********************************************
 * ��������� �������� ����� ��������� �����������
 *  ���� - �� ���������
 *         unit       V
 *  (  SIGN | UNSIGN   SHORT) | LONG) | INT)
 *
 *  RETURN: EOF   (��������� ����� �����)
 *          OK    (��������� ����������)
 *          ERROR (NONE) ����� ���������� �/� Find_Position
 ************************************************/
void Sem_Int_Body (void)
{
#ifdef TEST_MODE_SEM
    printf("\n====== Sem_Int_Body");
#endif
    select_unit();
    switch (compare_RW(unit)) {
         case RW_SHORT:                          /* SHORT */
              GenRezWord(RW_SHORT);
              Sem_Mul_Body();
              break;
         case RW_INT:                            /* INT */
              GenRezWord(RW_INT);
              Sem_Mul_Body();
              break;
         case RW_LONG:                           /* LONG */
              GenRezWord(RW_LONG);
              Sem_Mul_Body();
              break;
         default:
              rewunit();
              return;
    }
};


/********************************************
 * ��������� �������� ���������� ������� ��� �� ��������� � �������� �����
 *  ���� - �� ���������
 *  unit        V
 *                 ( ----> ��������� ----> )
 *                    <----- , <-------
 *
 * CurrentFunc - ��������� �� ������� �������
 *
 *  RETURN: EOF   (��������� ����� �����)
 *          OK    (���������� ��� ������)
 *          ERROR (NONE) ����� ���������� �/� Find_Position
 ************************************************/
void Sem_Check_Func_Args (void)
{
int i, arg_num;
#ifdef TEST_MODE_SEM
        printf("\n== Sem_Check_Func_Args");
#endif
    select_unit();                /* �������� ( */
    GenUnit(unit);                /* ����� ������� ( � ��������������� */
    arg_num = GetCurFuncArgNum(); /* ����� ���������� ���������� */
    if (arg_num == 0) {
         select_unit();           /* �������� unit ) */
         GenUnit(unit);                /* ����� ������� ), � ��������������� */
    } else {
         for (i = 0; i < arg_num; i++) {         /* ������� ���������� ���������� */
              select_unit();                     /* �������� unit */
              Sem_Expression_Body();             /* ������ ���������, ����������� �� ���� ������� ������  */
              if (i < (arg_num - 1)) {           /* �� ���� ������� - ���, ����� ���������� - ) */
                   /* !!!!!!!!!!!!!!!!!! GenUnit(unit);                /* ����� ������� , � ��������������� */
              }
         } /* end of for */
    }
/*    GenUnit(unit);                /* ����� ������� ) � ��������������� */
    return;
};


/************************************************
 *  ������ ��������
 *  TIMEOUT nn StateName;
 ************************************************/
void Sem_Time_Out (void)
{
/*    char  num[BUFFER_LENGTH];     /* ���������� ������ */
#ifdef TEST_MODE_SEM
        printf("\n== Sem_Time_Out");
#endif
    GenSpaces();                  /* ��������� ������������� ����� */
    select_unit();                /* ����� ����� �������� */
/*    strcpy(num, unit); */
/* ��������� ��������: */
    if (GenTimeOut(unit) == NO_VALUE) {
         error_msg(15, line_count, unit, NONE);  /* �������� �������� ������� �������� */
    }
    Sem_Statement_Body();         /* Statement  */
/* ���� select_unit();                /* ����� ��� ��������� */
/* ����     switch (GenTimeOut(num, unit)) {
/* ����          case NO_VALUE:
/* ����               error_msg(15, line_count, num, NONE);  /* �������� �������� �������� */
/* ����               break;
/* ����          case NO_STATE:
/* ����               error_msg(42, line_count, unit, NONE); /* ���� ������ ��������� */
/* ����               break;
/* ����     }
/* ����     select_unit();                /* ; */


    return;
};
