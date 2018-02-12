#include "const.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "typedef.h"
#include "prototyp.h"
#include "glob_ext.h"


/*------------ syntaxical analizator ------------------------------*/

INT16S synt_anal_of_pr_cntr_86 (void) {
    synt_anal();
    return(error_count);
};

void synt_anal (void) {
    InitStructures(); /* ������������� �������� �������� ������������ */
    cl_unit();     /*  ���������� unit (��� ���������� ������ rewunit) */
    cl_spaces();   /*  ���������� spaces (��� ���������� ������ rewunit) */
    if (Flag_LIS) fskptr(fptr_LIS); /* ���������� �� ������ ���� �������� */
    line_count=0;
    Flag_Unexpect=TRUE;

/*  TEST ==  while (select_unit()) {};
/*    return; */

    if (Program()) {
         Flag_Unexpect = FALSE;
         if (select_unit()) {
              printf("\n%%RCSL-WARING: Skip unexpected symbols after string number %d.",
              line_count);
              while (select_unit()) {}  /* All string of file write into LIS-file */
         }
    }
};

/******************************************************
*  ��������� ��������� ������� �� ������������
*  ����: name1 - �������� ������
*        name2 - ���� ���������, ��� ���� ��������� �� �����
*                ���� ���������, ��� ���� ��������� �� ���
*                ���� ������ ��� ���������
********************************************************/

int compare (char  *name1, char  *name2) {
/*  �����:  �������� �� ���������� ���� ����� */

    if (!strncmp(name1, name2, NAME_LENGTH-1))
         return(!ZERO);
    return(ZERO);
};

/*=====================================================*/
/*==== ��������� ������� � ��������������� ������ =====*/
/*==== ���� - ������� =================================*/
/*==== ����� - 0 - ������ �� ������� ==================*/
/*===        - !0 - ����� ���������������� ����� ======*/
int compare_RW (char  *name) {
    int i;
    for (i = 0; i < RWNUM; i++) {
         if(!strncmp(name, rezword[i], RWLEN)) return(i);
    }
    return(ZERO);
};

/*------------- �������� �� ����� ----------------------*/
int check_digit (char  *name1) {
    int i;
    char *endptr;

    if(!Check_Name_Constant(name1)){ /* ���� ���� � ������ �������� */
         Con_Value(name1); /* ������� ����� �� ���������� */
         return(TRUE);
    }

    strtod(name1, &endptr); /* ������� ������������� unit � ���� */
    if (endptr[0] == ZERO) return(TRUE); /* �������? - ������� */

    if (name1[0] != '0'){     /* ���� ���������� - �������� "nnnn[L]"*/

         if (!isdigit((int)name1[0])) return (FALSE); /* �� ������ ������ */
                                                    /* ������ �� �������� */
         if (name1[0] < 0) return(FALSE); /* �� ������ ������ */
                                                    /* ������ �� �������� */
         for(i=0;((name1[i]!=0)&&((name1[i+1]!=0)&&(name1[i]!='L')));i++){
	      if(!isdigit((int)name1[i]))
                   return(FALSE);
         }
    }else{                 /* ���� ������������ - �������� "0nnn[L]" */
         if((name1[1]!='X')&&(name1[1]!='x')){
              for(i=0;((name1[i]!=0)&&((name1[i+1]!=0)&&(name1[i]!='L')));i++){
                   if((!isdigit((int)name1[i]))||
                      ((INT8U)name1[i]>(INT8U)'7'))
                             return(FALSE);
              }
            /*  sscanf(name1,"%o",&j); /* �� ������ ������ */
            /*  sprintf(name1,"%d",j); */
         }else{   /* "0Xnnn[L]" */
              for(i=2;((name1[i]!=0)&&((name1[i+1]!=0)&&(name1[i]!='L')));i++){
                   if(!isxdigit((int)name1[i]))
                        return(FALSE);
              }
         }
    }
 return(!ZERO);
}

/*-------------- name unit examination -------------------------------------*/
int check_name (char *name)
{
    if (isalpha(name[0]) ||
        (!isascii(name[0])) ||
        (name[0] == '_'))
         return(TRUE);
    return(FALSE);
};

/*-------------- �������� ����������� ����� --------------------------------*/
int check_eng_name (char *name)
{
    int i, j;
    if (isalpha(name[0]) || (name[0] == '_')) {
         j = strlen(name);
         for (i = 1; i < j; i++) {
              if (!(isalpha(name[0]) || (name[0] == '_')))
                   return(FALSE);
         }
         return(TRUE);
    } else {
         return(FALSE);
    }
};

/*-------- work up error -------------------------*/
/* level 1 - }PROC
	 2 - }STATE
	 3 - ...; */
INT16S error_msg (INT16S n, INT16S line_count, char  *unit, INT16S level)
{
    error_count++;
    if (unit[0] != ZERO) {
         printf("\n%s \"%s\".", error_array[n], unit);
         if(Flag_LIS) fprintf(fptr_LIS, "\n%s \"%s\".", error_array[n], unit);
    } else {
         printf("\n%s.", error_array[n]);
         if(Flag_LIS) fprintf(fptr_LIS, "\n%s.", error_array[n]);
    }
    if (line_count != 0) printf("%s %d.", error_array[0], line_count);

    switch (level) {              /* �������� ���������� ������ */
    case PROCESS:
         while (!compare(unit, rezword[RW_PROC])) {   /*  ���� �� ���������� ���� */
              while (!compare(unit, "}")) {           /*  ���� �� ���������� } */
                   if (!select_unit()) return(ZERO);  /*  ����� ����� */
              }
              if (!select_unit()) return(ZERO);       /*  ����� ����� */
         }
         rewunit();
         break;                                       /*  ����� ������ �������� */
    case STATE:
         while (!compare(unit, rezword[RW_STATE])) {  /*  ���� �� ���������� ���� */
              while (!compare(unit, "}")) {           /*  ���� �� ���������� } */
                   if (!select_unit()) return(ZERO);  /*  ����� ����� */
              }
              if (!select_unit()) return(ZERO);       /*  ����� ����� */
         }
         rewunit();
         break;                                       /*  ����� ������ ��������� */
    case SEMICOLON:
         while (!compare(unit, rezword[RW_SEMICOLON])) {
              if (!select_unit()) return(ZERO);
         }
         break;                                       /*  ����� ������ ������ */
    case NONE:
/* printf("NONE ");*/
         break;
    default:
         printf("\n REFLEX-FATERR. FUNC: error_msg. Unknown Error Level.");
         exit(ZERO);
    }
         return(!ZERO);
};

/*-------- Find position -------------------------*/
/* level 1 - }PROC
	 2 - }STATE
	 3 - ...; */
INT16S Find_Position (INT16S level)
{
    switch (level) {              /* �������� ���������� ������ */
    case PROCESS:
         while (!compare(unit, rezword[RW_PROC])) {   /*  ���� �� ���������� ���� */
              while (!compare(unit, "}")) {           /*  ���� �� ���������� } */
                   if (!select_unit()) return(ZERO);  /*  ����� ����� */
              }
              if (!select_unit()) return(ZERO);       /*  ����� ����� */
         }
         rewunit();
         break;                                       /*  ����� ������ �������� */
    case STATE:
         while (!compare(unit, rezword[RW_STATE])) {  /*  ���� �� ���������� ���� */
              while (!compare(unit, "}")) {           /*  ���� �� ���������� } */
                   if (!select_unit()) return(ZERO);  /*  ����� ����� */
              }
              if (!select_unit()) return(ZERO);       /*  ����� ����� */
         }
         rewunit();
         break;                                       /*  ����� ������ ��������� */
    case SEMICOLON:
         while (!compare(unit, rezword[RW_SEMICOLON])) {
              if (!select_unit()) return(ZERO);
         }
         break;                                       /*  ����� ������ ������ */
    case NONE:
/* printf("NONE ");*/
         break;
    default:
         printf("\n REFLEX-FATERR. FUNC: Find_Position. Unknown Position Identifier.");
         exit(ZERO);
    }
         return(!ZERO);
};
/*-------- work up warning -------------------------*/
INT16S warning_msg (INT16S n, INT16S line_count, char  *unit)
{
    warning_count++;
    if (unit[0] != ZERO) {
         printf("\n%s \"%s\".", warning_array[n], unit);
         if(Flag_LIS) fprintf(fptr_LIS, "\n%s \"%s\".", warning_array[n], unit);
    } else {
         printf("\n%s.", warning_array[n]);
         if(Flag_LIS) fprintf(fptr_LIS, "\n%s.", warning_array[n]);
    }
    if (line_count != 0) printf("%s %d.", warning_array[0], line_count);
    return(!ZERO);
};

/*---------------Work up PROGRAM -------------------------*/
int Program (void)
{
int i;
#ifdef TEST_MODE
        printf("\n= Program");
#endif

     if (!select_unit()) return(ZERO);
     if (compare(unit, ALT_rezword[RW_PROGR])) { /*  ��-������? - �������������� ������� */
         for (i=0; i < RWNUM; i++) {
              strncpy(rezword[i], ALT_rezword[i], RWLEN);
         }
         for (i=0; i < ERRMSGNUM; i++) {
              strncpy(error_array[i], ALT_error_array[i], ERRMSGLEN);
         }
     } else {         /* ����� �������������� ����������: */
         for (i = 0; i < ERRMSGNUM; i++) {
              strncpy(error_array[i], ALT_error_array[i], ERRMSGLEN);
         }
         if (compare(unit, ENG_rezword[RW_PROGR])) { /* ����� ����� �� ���������? */
              for (i=0; i < RWNUM; i++) {               /* - �������������� ���������� */
                   strncpy(rezword[i], ENG_rezword[i], RWLEN);
              }
         } else {
              error_msg(1, line_count, unit, NONE); /* �� ���������� ����� ����� */
              while (!compare(unit, rezword[RW_PROGR])) /* ���� ����� "�����"*/
                   if (!select_unit()) return(ZERO);
         }
     }

    if (!select_unit()) return(ZERO);   /* program Name */
    if (!check_name(unit)) {
         if (!error_msg(3, line_count, unit, SEMICOLON)) return(ZERO);
         return(!ZERO);
    }
    if (!select_unit()) return(ZERO);   /* { */
    if (!compare(unit, "{")) {
         if (!error_msg(18, line_count, unit, SEMICOLON)) return(ZERO);
         return(!ZERO);
    }
    if (!Tact()) return(ZERO);
    if (!Constant()) return(ZERO);
    if (!Function()) return(ZERO);
    if (!Port()) return(ZERO);
    if (!Process()) return(ZERO);
    if (!select_unit()) return(ZERO);
    if (!compare(unit, "}")) {
         error_msg(58, line_count, unit, NONE);
         while (!compare(unit,"}"))
              if (!select_unit()) return(ZERO);
    }
    return(!ZERO);
};

/************************************************
 *               --- Tact ---
 * �������: 0 - ����� �����
 *         !0 - ����������, �������� ������.
 ************************************************/
INT16S Tact (void)
{
#ifdef TEST_MODE
        printf("\n= Tact");
#endif
if (!select_unit()) return(ZERO);
if (compare(unit, rezword[RW_TACT])){       /* select reserved word "TAKT"*/
    if (!select_unit())  return(ZERO);
    if (!check_digit(unit)) {            /* value of tact */
         if (!error_msg(4, line_count, unit, SEMICOLON)) return(ZERO);
         return(!ZERO);
    }
    if (!select_unit()) return(ZERO);
    if (!compare(unit, rezword[RW_SEMICOLON])) {
         if (!error_msg(10, line_count, unit, SEMICOLON)) return(ZERO);
         return(!ZERO);
    }
} else {
    rewunit();
    return(!ZERO);
} /* if unit is not equal "TAKT" */
return(!ZERO);
};

/************************************************
 *             --- Constant ---
 * ��������� �������� �������� � ������������
 * �������: 0 - ����� �����
 *         !0 - ����������, �������� ������.
 *
 ************************************************/
INT16S Constant (void)
{
#ifdef TEST_MODE
        printf("\n= Constant");
#endif
for (;;) {
    if (!select_unit()) return(ZERO);
    switch (compare_RW(unit)) {
         case RW_CONST:  /* "CONST" */
              if (!select_unit()) return(ZERO);
              if (!check_name(unit)) {                /* constant name */
                   if (!error_msg(5, line_count, unit, SEMICOLON)) return(ZERO);
                   continue;
              }
              if (!Check_Constant(unit)) {            /* exist ? */
                   if (!error_msg(39, line_count, unit, SEMICOLON)) return(ZERO);
                   continue;
              }
              if (!select_unit()) return(ZERO);
              switch (Constant_Expression_Body()) {  /* ������ ��������� */
                   case ERROR:         /* Error */
                        if (!Find_Position(SEMICOLON)) return(ZERO);
                        continue;
                   case ZERO:          /* EOF */
                        return(ZERO);
                   default:
                        break;
              } /* end of switch */

              if (!compare(unit, rezword[RW_SEMICOLON])) {
                   if (!error_msg(10, line_count, unit, SEMICOLON)) return(ZERO);
              }
              continue;
         case RW_ENUM:  /* "������������" */
              if (!select_unit()) return(ZERO);   /* { */
              if (!compare(unit, "{")) {
                   if (!error_msg(18, line_count, unit, SEMICOLON)) return(ZERO);
                   continue;
              }
              switch (Constant_Enum_Body()) {  /* ������ ������������ */
                   case ERROR:         /* Error */
                        if (!Find_Position(SEMICOLON)) return(ZERO);
                        continue;
                   case ZERO:          /* EOF */
                        return(ZERO);
                   default:
                        break;
              } /* end of switch */

              if (!select_unit()) return(ZERO);   /* { */
              if (!compare(unit, "}")) {
                   if (!error_msg(19, line_count, unit, SEMICOLON)) return(ZERO);
                   continue;
              }
              if (!select_unit()) return(ZERO);   /* { */
              if (!compare(unit, rezword[RW_SEMICOLON])) {
                   if (!error_msg(10, line_count, unit, SEMICOLON)) return(ZERO);
              }
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

int Constant_Enum_Body (void)
{
#ifdef TEST_MODE
        printf("\n== Constant_Enum");
#endif
    for (;;) {
         if (!select_unit()) return(ZERO);
         if (!check_name(unit)) {                /* constant name */
              if (!error_msg(5, line_count, unit, SEMICOLON)) return(ZERO);
              continue;
         }
         if (!Check_Constant(unit)) {            /* exist ? */
              if (!error_msg(39, line_count, unit, SEMICOLON)) return(ZERO);
              continue;
         }
         if (!select_unit()) return(ZERO);
         switch (compare_RW(unit)) {
              case RW_EQU:  /* "=" */ /* ������������ �������� ��������� */
                   if (!select_unit()) return(ZERO);
                   switch (Constant_Expression_Body()) {  /* ������ ��������� */
                        case ERROR:         /* Error */
                             return(ERROR);
                        case ZERO:          /* EOF */
                             return(ZERO);
                        default:
                             if (!compare(unit, ",")) {
                                  rewunit();
                                  return(!ZERO);
                             }
                             continue;
                   } /* end of switch */
              case RW_COMMA:  /* "," */ /* ����� ��������� � ������������ */
                   continue;
              default:       /* ���-�� ����������... ����� ������������ ? */
                   rewunit();
                   return(!ZERO);
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
/* ��������� �������� ��������� */
int    Constant_Expression_Body (void)
{
#ifdef TEST_MODE
    printf("\n==== Constant_Expression_Body");
#endif
    for (;;) {          /* ��������! �� ����� � unit ��� ���-�� ��������� */
         for (;;) {     /* ��������� �������� */
              switch (Constant_Prefix_Body()) {
                   case ZERO:               /* EOF */
                        return(ZERO);
                   case ERROR:              /* Error */
                        return(ERROR);
                   default:                 /* ��� ��� ���������� (�������) */
                        if (!select_unit()) return(ZERO);  /* �������� unit */
                        continue;           /* � ����� ��������� �������� */
                   case NONSTATEMENT:       /* ��� �� ������� (� ����) */
                        break;
              }
              break;                        /* ����� �� ����� ��������� ��������� */
         }

         switch (Constant_Term_Body()) {        /* ��������� ����� - ������ ���� */
              case ZERO:               /* EOF */
                   return(ZERO);
              case ERROR:              /* Error */
                   return(ERROR);
              default:                 /* ��� � ������� */
                   break;
         }

         if (!select_unit()) return(ZERO);  /* �������� unit */
         switch (Constant_Infix_Body()) {       /* ��������� ������� */
              case ZERO:               /* EOF */
                   return(ZERO);
              case ERROR:              /* Error */
                   return(ERROR);
              default:                 /* ��� � ������� */
                   if (!select_unit()) return(ZERO);  /* �������� unit */
                   break;
              case NONSTATEMENT:       /* ��� �� ������ */
                   return (!ZERO);
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
int Constant_Infix_Body (void) {
#ifdef TEST_MODE
    printf("\n===== Constant_Infix_Body");
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
int Constant_Term_Body (void) {
#ifdef TEST_MODE
    printf("\n===== Constant_Term_Body");
#endif
    if (compare(unit, rezword[RW_OPEN_PARENTESIS])) { /* ( ��������� ) ? */
         if (!select_unit()) return(ZERO);            /* �������� unit */
         switch (Constant_Expression_Body()) {                 /* ������ ��������� */
              case ERROR:         /* Error */
                   return(ERROR);
              case ZERO:          /* EOF */
                   return(ZERO);
              default:
                   break;
         } /* end of switch */
         if (!compare(unit, rezword[RW_CLOSE_PARENTESIS])) {
              error_msg(21, line_count, unit, NONE);       /* �.�. ) */
              return(ERROR);
         }
    } else {
          /* ����� ��������� ��� ��������� */
         if (!check_digit(unit)) {
              error_msg(45, line_count, unit, NONE);
         }
    }


#ifdef TEST_MODE
    printf("\nTEST: END OF CONST-TERM!!! ");
#endif

    return(!ZERO);
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
int Constant_Prefix_Body (void) {
#ifdef TEST_MODE
    printf("\n===== Constant_Prefix_Body");
#endif
    switch (compare_RW(unit)) {
         case RW_BW_COMPLEMENT:     /* "~",   */
         case RW_NOT:               /* "!",   */
         case RW_PLUS:              /* "+",   */
         case RW_MINUS:             /* "-",   */
              return(!ZERO);
         default:
              return(NONSTATEMENT);
    }
};

/************************************************
 *             --- Function ---
 * ��������� �������� �������� � ������������
 * �������: 0 - ����� �����
 *         !0 - ����������, �������� ������.
 *
 ************************************************/
int Function (void)
{
#ifdef TEST_MODE
        printf("\n= Function");
#endif
    for (;;) {
         if (!select_unit()) return(ZERO);
         if (compare(unit, rezword[RW_FUNCTION])) { /* �������� ������� ? */

              switch (Func_Declarator_Body()) { /* ��� ������� */
                   case ZERO:               /* EOF */
                        return(ZERO);
                   case ERROR:              /* Error */
                        if(!Find_Position(SEMICOLON)) return(ZERO);
                        continue;
                   case NONSTATEMENT:       /* ��� �� ����������? - ������ */
                        if(!error_msg(73, line_count, unit, SEMICOLON)) return(ZERO); /* ��������� ���������� */
                        continue;
                   default:                 /* ��� ��� ���������� */
                        break;
              } /* end of switch */

              if (!select_unit()) return(ZERO);
              if (!check_eng_name(unit)) {          /* ��� C-������� ? */
                   if (!error_msg(69, line_count, unit, SEMICOLON)) return(ZERO);
                   continue;
              }
              if (!CheckFunc(unit)) {              /* exist ? */
                   if (!error_msg(70, line_count, unit, NONE)) return(ZERO);
              }

              if (!select_unit()) return(ZERO); /* ����������� ������ */
              if (!compare(unit, "(")) {
                   if(!error_msg(20, line_count, unit, SEMICOLON)) return(ZERO);
                   continue;
              }

              switch (Func_Args_Declarator_Body()) {
                   case ZERO:               /* EOF */
                        return(ZERO);
                   case ERROR:              /* Error */
                        if(!Find_Position(SEMICOLON)) return(ZERO);
                        continue;
                   default:                 /* ��� ��� ���������� */
                        break;
              } /* end of switch */

              if (!select_unit()) return(ZERO); /* ����������� ������ */
              if (!compare(unit, ")")) {
                   if(!error_msg(21, line_count, unit, SEMICOLON)) return(ZERO);
                   continue;
              }

              if (!select_unit()) return(ZERO);  /* ; */
              if (!compare(unit, rezword[RW_SEMICOLON]))
                   error_msg(10, line_count, unit, SEMICOLON); /* �� ��������� ����� ������ */
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
 *
 *  RETURN: EOF   (��������� ����� �����)
 *          OK    (���������� ��� ������)
 *          ERROR (NONE) ����� ���������� �/� Find_Position
 ************************************************/
int Func_Args_Declarator_Body (void)
{
#ifdef TEST_MODE
        printf("\n== Func_Args_Declarator_Body");
#endif
    for (;;) {
         if (!select_unit()) return(ZERO);
         switch (compare_RW(unit)) {
              case RW_SEMICOLON:         /* rezword[RW_SEMICOLON] */ /* ������������ �������� ��������� */
              case RW_CLOSE_PARENTESIS:  /* ")" */ /* ������������ �������� ��������� */
                   rewunit();
                   return(!ZERO);
              case RW_COMMA:     /* "," */ /* ����� ��������� � ������������ */
                   continue;
              default:       /* ���-�� ����������... ����� ������������ ? */
                   rewunit();
                   switch (Func_Declarator_Body()) {  /* ������ ����������� */
                        case ERROR:         /* Error */
                             return(ERROR);
                        case ZERO:          /* EOF */
                             return(ZERO);
                        case NONSTATEMENT:       /* ��� �� ����������? - ������ */
                             error_msg(73, line_count, unit, NONE); /* ��������� ���������� */
                             return(ERROR);
                        default:
                             if (!select_unit()) return(ZERO);
                             if (compare(unit, ")") &&
                                 compare(prev_unit, rezword[RW_VOID])
                                 && (GetCurFuncArgNum() == 0)) {
/* TEST !!!  printf("! void func - \n%s \n unit is %s - \nprev is %s", buffer1, unit, prev_unit);        /* ���� (void) - ����� ���������� - 0 */
                             } else {
                                  AddNewArgInCurFunc(); /* ������� �������� */
                             }
                             rewunit();
                             continue;
                   } /* end of switch */
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
int Func_Declarator_Body (void)
{
#ifdef TEST_MODE
    printf("\n===== Func_Declarator_Body");
#endif
    if (!select_unit()) return(ZERO);  /* */
    switch (compare_RW(unit)) {
         case RW_SHORT:                /* SHORT */
         case RW_LONG:                 /* LONG */
         case RW_INT:                  /* INT */
              return(Func_Sign_Body());
         case RW_FLOAT:
         case RW_DOUBLE:
         case RW_VOID:
              return(Func_Mul_Body());
         case RW_SIGN:
         case RW_UNSIGN:
              return(Func_Int_Body());
         default:             /*  ��� �� ���������� */
              rewunit();
              return(NONSTATEMENT);
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
int Func_Mul_Body (void)
{
#ifdef TEST_MODE
    printf("\n======= Func_Mul_Body");
#endif
    for (;;) {
        if (!select_unit()) return(ZERO);
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
int Func_Sign_Body (void)
{
#ifdef TEST_MODE
    printf("\n====== Func_Sign_Body");
#endif
    if (!select_unit()) return(ZERO);
    switch (compare_RW(unit)) {
	 case RW_UNSIGN:                         /* UNSIGNED */
	 case RW_SIGN:                           /* SIGNED */
	 case RW_MUL:                            /* SIGNED */
	      return(Func_Mul_Body());
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
int Func_Int_Body (void)
{
#ifdef TEST_MODE
    printf("\n====== Func_Int_Body");
#endif
    if (!select_unit()) return(ZERO);
    switch (compare_RW(unit)) {
	 case RW_SHORT:                          /* SHORT */
	 case RW_INT:                            /* INT */
	 case RW_LONG:                           /* LONG */
	      return(Func_Mul_Body());
	 default:
	      rewunit();
	      return(!ZERO);
    }
};


/************************************************
 *              --- Port ---
 * �������: 0 - ����� �����
 *         !0 - ����������, �������� ������.
 ************************************************/
INT16S Port (void)
{
#ifdef TEST_MODE
        printf("\n= Port");
#endif
if (!select_unit()) return(ZERO);
while ((compare(unit, rezword[RW_INPUT])) ||
         (compare(unit, rezword[RW_OUTPUT])) ||
	 (compare(unit, rezword[RW_RAM]))) {          /* while port */
    if (compare(unit, rezword[RW_INPUT])) {           /* if INPUT */
         if (!InputPort()) return(ZERO);
    } else { /* end of INPUT */
         if (compare(unit, rezword[RW_OUTPUT])) {                   /* if OUTPUT */
              if (!OutputPort()) return(ZERO);
         } else {
              if (!RAMPort()) return(ZERO);
         }
    }
    if (!compare(unit, rezword[RW_SEMICOLON]))
         if (!error_msg(10, line_count, unit, SEMICOLON)) return(ZERO);
    if (!select_unit()) return(ZERO);
} /* end of while I/O PORTS*/
rewunit(); /* rewunit if neither INPUT, OUTPUT nor RAM */
return(!ZERO);
};

/*************************************************
* ������ ������-�������� �������� ��������
* �� ������ - 0 - ����� �����,
*             !0 - ��������� �� ;
***************************************************/

INT16S InputPort (void)
{
#ifdef TEST_MODE
        printf("\n== Input Port");
#endif
    if (!select_unit()) return(ZERO);
    if (!check_name(unit)) {                  /* name ? */
         if (!error_msg(6, line_count, unit, SEMICOLON)) return(ZERO);
         return(!ZERO);
    }
    if (!Check_Input_Group(unit)) {                   /* exist ? */
         if(!error_msg(40, line_count, unit, SEMICOLON)) return(ZERO);
         return(!ZERO);
    }
    if(!select_unit()) return(ZERO);
    if(!check_digit(unit)){                       /* ����� �� �� */
         if(!error_msg(7, line_count, unit, SEMICOLON)) return(ZERO);
         return(!ZERO);
    }
    Input_Group_MB_Address(unit);
    if (!select_unit()) return(ZERO);
    if (!check_digit(unit)) {                    /* port address */
         if (!error_msg(7, line_count, unit, SEMICOLON)) return(ZERO);
         return(!ZERO);
    }
    Input_Group_Address(unit);
    if (!select_unit()) return(ZERO);
    if ((!compare(unit, "8")) && (!compare(unit, "16"))) {
         if (!error_msg(8, line_count, unit, SEMICOLON)) return(ZERO);
         return(!ZERO);
    }
    Input_Group_Size(unit);                         /* set port size */
    if (!select_unit()) return(ZERO);
    return(!ZERO);
};

/* ������ ������-�������� ��������� ��������
* �� ������ - 0 - ����� �����,
*             !0 - ��������� �� ;
*/
INT16S OutputPort (void)
{
#ifdef TEST_MODE
        printf("\n== Output Port");
#endif
    if (!select_unit()) return(ZERO);
    if (!check_name(unit)){
     if (!error_msg(6, line_count, unit, SEMICOLON)) return(ZERO);
	 return(!ZERO);
    }
    if (!Check_Output_Group(unit)) {                  /* name */
     if(!error_msg(40,line_count,unit,SEMICOLON)) return(ZERO);
	 return(!ZERO);
    }
    if (!select_unit()) return(ZERO);
    if (!check_digit(unit)) {
     if (!error_msg(7, line_count, unit, SEMICOLON)) return(ZERO);
	 return(!ZERO);
    }
    Output_Group_MB_Address(unit);             /* ���. ������ �� �� */
    if (!select_unit()) return(ZERO);
    if (!check_digit(unit)){
     if(!error_msg(7, line_count, unit, SEMICOLON)) return(ZERO);
	 return(!ZERO);
    }
    Output_Group_Address(unit);                     /* set address */
    if (!select_unit()) return(ZERO);
    if ((!compare(unit, "8")) && (!compare(unit, "16"))) {
     if(!error_msg(8, line_count, unit, SEMICOLON)) return(ZERO);
	 return(!ZERO);
    }
    Output_Group_Size(unit);                        /* set size */
    if (!select_unit()) return(ZERO);
    return(!ZERO);
};

/******************************************
* ������ ������-�������� �������� � ���
*  �� ������ - 0 - ����� �����,
*             !0 - ��������� �� ;
*******************************************/
INT16S RAMPort (void)
{
#ifdef TEST_MODE
        printf("\n== RAM Port");
#endif
    if (!select_unit()) return(ZERO);
    if (!check_name(unit)) {                        /* name */
     if (!error_msg(6, line_count, unit, SEMICOLON)) return(ZERO);
	 return(!ZERO);
    }
    if (!Check_RAM_Group(unit)) {
     if(!error_msg(40,line_count,unit,SEMICOLON)) return(ZERO);
	 return(!ZERO);
    }
    if (!select_unit()) return(ZERO);
    if (!check_digit(unit)) {
     if(!error_msg(51, line_count, unit, SEMICOLON)) return(ZERO);
	 return(!ZERO);
    }
    RAM_Group_Segment(unit);                /* set memory cell segment */
    if (!select_unit()) return(ZERO);
    if (!check_digit(unit)){
     if (!error_msg(52, line_count, unit, SEMICOLON)) return(ZERO);
	 return(!ZERO);
    }
    RAM_Group_Offset(unit);                 /* set memory cell offset */
    if (!select_unit()) return(ZERO);
    if (!check_digit(unit)) {
     if (!error_msg(53, line_count, unit, SEMICOLON)) return(ZERO);
	 return(!ZERO);
    }
    RAM_Group_Address(unit);                /* set memory cell VME-address */
    if (!select_unit()) return(ZERO);
    if ((!compare(unit, "8")) && (!compare(unit, "16"))) {
     if (!error_msg(8, line_count, unit, SEMICOLON)) return(ZERO);
	 return(!ZERO);
    }
    RAM_Group_Size(unit);                   /* set memory cell size */
    if(!select_unit()) return(ZERO);
    return(!ZERO);
};

/************************************************
 *              --- Process ---
 * �������: 0 - ����� �����
 *         !0 - ����������, �������� ������.
 ************************************************/
int Process (void)
{
#ifdef TEST_MODE
        printf("\n= Process, unit is \n%s\n, spaces is \n%s\n, buffer is \n%s", unit, spaces, buffer1);
#endif
if (!select_unit())  return(ZERO);
while (compare(unit, rezword[RW_PROC])) {   /* while PROC */
#ifdef TEST_MODE
        printf("\n== Process");
#endif
    if (!select_unit()) return(ZERO);
    if (!check_name(unit)) {
         if (!error_msg(11, line_count, unit, PROCESS)) return(ZERO);
         if (!select_unit()) return(ZERO);
         continue;
    }
    if (!Check_Process(unit)) {               /* process name */
         error_msg(36, line_count, unit, NONE); /* ������������ ����� !*/
    }
    if (!select_unit())  return(ZERO);
    if (!compare(unit, "{")) {
         if (!error_msg(18, line_count, unit, PROCESS)) return(ZERO);
         if (!select_unit()) return(ZERO);
         continue;
    }
    if (!Variable_List()) return(ZERO);    /* work up variables list */
    if (!State())         return(ZERO);           /* work up states */
    if (!Check_Number_Of_State()) /* if state number 0 - error */
         error_msg(48, line_count, "\0", NONE);
    if (Check_Number_Of_State() > 127) /* if state number > 127 - error */
         error_msg(78, line_count, "\0", NONE);
    if (!select_unit())  return(ZERO);
    if (!compare(unit, "}"))               /* "}" ( close process body) */
         if (!error_msg(59, line_count, unit, PROCESS)) return(ZERO);
    if(!select_unit())  return(ZERO);
} /* end of while */
rewunit(); /* rewunit if not PROC */
return(!ZERO);
};

/************************************************
 *           --- VariableList ---
 * �������: 0 - ����� �����
 *         !0 - ����������, �������� ������.
 ************************************************/
int Variable_List (void) {
int i;
#ifdef TEST_MODE
        printf("\n== Variable_List");
#endif
    for (;;) {                              /* ���������� ��� ���������� */
         if (!select_unit()) return(ZERO);
         switch (i = compare_RW(unit)) {
	      case RW_LOG:
              case RW_INT:
              case RW_SHORT:
              case RW_LONG:
              case RW_DOUBLE:
              case RW_FLOAT:
                   if (!Discr_Var(i)) return(ZERO);
                   break;
              case RW_FROM:
                   if (!From_Var()) return(ZERO);
                   break;
              default:
                   rewunit(); /* if next word neither LOG, INT nor FROM */
                   return(!ZERO);
         } /* end of switch */
         if (!compare(unit, rezword[RW_SEMICOLON])) { /* ����� ������ ? */
              if (!error_msg(10, line_count, unit, SEMICOLON)) return(ZERO);
              return(!ZERO);
         }
    } /* end of for */
};

/************************************************
 *             --- Local_Var ---
 * �������: 0 - ����� �����
 *         !0 - ����������, �������� ������.
 *          ��������� �� ; unit = ";"
 ************************************************/
int Local_Var (void)
{
#ifdef TEST_MODE
        printf("\n==== Local_Var");
#endif
    ForProc_LOCAL();   /* ������������� ���� ������� */
    MakeBeforeFor();   /* ������������ ���� ������� ���� ���������� ������ */
    if (!select_unit()) return(ZERO); /* for ; simbol */
    if (!compare(unit, rezword[RW_SEMICOLON]))
         if (!error_msg(10, line_count, unit, SEMICOLON)) return(ZERO);
    return(!ZERO);
};

/************************************************
 *              --- ForVar ---
 * �������: 0 - ����� �����
 *         !0 - ����������, �������� ������.
 ************************************************/
int For_Var (void)
{
#ifdef TEST_MODE
        printf("\n==== For_Var");
#endif
    if (!select_unit()) return(ZERO);
    switch (compare_RW(unit)) {
         case RW_PROC:                           /* if FOR + PROC */
              for (;;) {
                   if (!select_unit()) return(ZERO);
                   if (!check_name(unit)) {        /* ��� ��������? */
                        if (!error_msg(27, line_count, unit, SEMICOLON)) return(ZERO);
                        return(!ZERO);
		   }
                   ForProc(unit);                     /* ������ � ������ ����������� */
                   if (!select_unit()) return(ZERO);
                   if (!compare(unit, ",")) break;    /* ����� ������������ ? */
              }
              /* if (!select_unit()) return(ZERO); ??????? */
              break;
         case RW_ALL:    /* if FOR+ALL */
              ForProc_ALL();
              if (!select_unit()) return(ZERO);
              break;
         default:
              if (!error_msg(26, line_count, unit, SEMICOLON)) return(ZERO);
              break;
    }
    MakeBeforeFor();
    if (!compare(unit, rezword[RW_SEMICOLON]))
         if (!error_msg(10, line_count, unit, SEMICOLON)) return(ZERO);
    return(!ZERO);
};
/************************************************
 *             --- Discr_Var ---
 * ��������� ����� - �������� ���������� ��������
 * LOG INT LONG SHORT FLOAT DOUBLE
 * RETURN: ERROR - set on ';'
 * RETURN: ZERO  - EOF
 * RETURN: !ZERO - OK
 * ����� - ��������� �� ;
 ************************************************/
int Discr_Var (int var_type)
{
char  port_name[BUFFER_LENGTH];
#ifdef TEST_MODE
        printf("\n=== Discr_Var");
#endif
    if (!select_unit()) return(ZERO);
    if (!check_name(unit)) {                  /* ��������� �� ��� */
         if (!error_msg(54, line_count, unit, SEMICOLON)) return(ZERO);
         return(ERROR);
    }
    if (!CheckVariable(unit, var_type)) {       /* ��������� �� ������������� */
         if (!error_msg(38, line_count, unit, SEMICOLON)) return(ZERO);
         return(ERROR);
    }
    if (!select_unit()) return(ZERO);
    if (compare(unit, "=")) {  /* ���� �����. ����� - ������ ���. ������ */
         if ((var_type == RW_FLOAT) ||
              (var_type == RW_DOUBLE)) {   /*  �� ������ ���������� ������� */
              error_msg(65, line_count, unit, SEMICOLON);
              return(ERROR);
         }
         if (!select_unit()) return(ZERO);
         if (!compare(unit, "{")){
              if (!error_msg(18, line_count, unit, SEMICOLON)) return(ZERO);
              return(ERROR);
         }
         for (;;) {                         /* ������ �������� � ���. ������ */
              if (!select_unit()) return(ZERO);
              if (!check_name(unit)) {
                   if (!error_msg(6, line_count, unit, SEMICOLON)) return(ZERO);
                   return(ERROR);
              }
              strcpy(port_name, unit);
              if (!select_unit()) return(ZERO);
              if (!compare(unit, "[")) {
                   if (!error_msg(30, line_count, unit, SEMICOLON)) return(ZERO);
                   return(ERROR);
              }
              if (!select_unit()) return(ZERO);
              if (!check_digit(unit)) {
                   if (!error_msg(55, line_count, unit, SEMICOLON)) return(ZERO);
                   return(ERROR);
              }
              if (!InitVariable(port_name, atoi(unit))) { /*  ���� ��-������� */
                   if (!error_msg(35, line_count, unit, SEMICOLON)) return(ZERO);
                   return(ERROR);
              }
              if (!select_unit()) return(ZERO);
              if (!compare(unit, "]")) {
                   if (!error_msg(31, line_count, unit, SEMICOLON)) return(ZERO);
                   return(ERROR);
              }
              if (!select_unit()) return(ZERO);
              if (!compare(unit, ",")) break;    /* ����� �������� ���������� � ������ */
         }
         if (!compare(unit, "}")) {              /* ���������� �������� ������ */
              if (!error_msg(61, line_count, unit, SEMICOLON)) return(ZERO);
              return(ERROR);
         }
         if (!select_unit()) return(ZERO);  /* for LOCAL or FOR */
    }   /* ����� ������� ���-������. ����� ������ ������ ������� ������� */
    switch (compare_RW(unit)) {
         case RW_LOCAL:       /* if local variables LOCAL */
              return(Local_Var());
         case RW_FOR:         /* if for all or for FOR */
              return(For_Var());       /* not all variables */
         default:
              if (!error_msg(34, line_count, unit, SEMICOLON)) return(ZERO);
              return(!ZERO);
    }
};

/************************************************
 *              --- FromVar ---
 * ��������� �������� ����������, ��������� � ������ ���������
 * ���� -> ��� �������� -> ��� ���������� ->
 *                       <----- , -------/
 * RETURN: ERROR - set on ';'
 * RETURN: ZERO  - EOF
 * RETURN: !ZERO - OK
 * ����� - ��������� �� ;
 ************************************************/
int From_Var (void)
{
#ifdef TEST_MODE
        printf("\n==== From_Var");
#endif
/*printf("\n========================= FROMVAR");*/
    if (!select_unit()) return(ZERO);
    if (!compare(unit, rezword[RW_PROC])) {              /* for PROC */
         if (!error_msg(23, line_count, unit, SEMICOLON)) return(ZERO);
         return(ERROR);
    }
    if (!select_unit()) return(ZERO);
    if (!check_name(unit)){                    /* for Process Name */
         if (!error_msg(11, line_count, unit, SEMICOLON)) return(ZERO);
         return(ERROR);
    }
    for (;;) {
         if (!select_unit()) return(ZERO);
         if (!check_name(unit)) {
              if (!error_msg(54, line_count, unit, SEMICOLON)) return(ZERO);
              return(ERROR);
         }
         if (!CheckVariable(unit, RW_FROM))
              error_msg(38, line_count, unit, NONE);
         if (!select_unit()) return(ZERO);
         if (!compare(unit, ",")) return(!ZERO);
    }
};
/************************************************
 *               --- State ---
 * �������: 0 - ����� �����
 *         !0 - ����������, �������� ������.
 ************************************************/
INT16S State (void)
{
#ifdef TEST_MODE
        printf("\n== State");
#endif
    if (!select_unit()) return(ZERO);
    while (compare(unit, rezword[RW_STATE])) {   /* ����� ����? */
         if (!select_unit()) return(ZERO);
         if (!check_name(unit)) {             /* ��� ��c������? */
              if (!error_msg(22, line_count, unit, STATE)) return(ZERO);
              continue;
         }
         if (!Check_State(unit)) {               /* ���������� �����? */
              error_msg(37, line_count, unit, NONE);
         }
         if (!select_unit()) return(ZERO);
         if (!compare(unit, "{")) {  /* body of state */
              if (!error_msg(18, line_count, unit, STATE)) return(ZERO);
              if (!select_unit()) return(ZERO);
              continue;                /* ����� ����� ��������� */
         }
         JmpFlag = ZERO;               /*  ���� ������� ������� �� ��������� */
         if (!select_unit()) return(ZERO);
         if (compare(unit, rezword[RW_TIMEOUT])) {    /* ������� ?*/
              switch (Time_Out()) {
                   case ERROR:              /* Error in string set on new STATE */
                        if (!select_unit()) return(ZERO);
                        continue;           /* check next state */
                   case ZERO:               /* EOF */
                        return(ZERO);
                   default:                 /* NO ERROR */
                        if (!select_unit()) return(ZERO);       /* } */
                        break;              /* check for next state */
              } /* end of switch */
         } else {                           /* ���� �� ������� */
              rewunit();
              switch (State_Body()) {       /* State {} */
                   case ERROR:              /* Error in string set on new STATE */
                        Find_Position(STATE);
                        if (!select_unit()) return(ZERO);
                        continue;           /* check next state */
                   case ZERO:               /* EOF */
                        return(ZERO);
                   default:                 /* NO ERROR */
                        break;              /* check for next state */
              } /* end of switch */
              if (!select_unit()) return(ZERO);   /* */
              if (compare(unit, rezword[RW_TIMEOUT])) {
                   switch (Time_Out()) {
                        case ERROR:              /* Error in string set on new STATE */
                             if (!select_unit()) return(ZERO);
                             continue;           /* check next state */
                        case ZERO:               /* EOF */
                             return(ZERO);
                        default:                 /* NO ERROR */
                             if (!select_unit()) return(ZERO);
                             break;              /* check for next state */
                   } /* end of switch */
              }
         }

         if (!compare(unit, "}")) {  /* body of state */
              if (!error_msg(60, line_count, unit, STATE)) return(ZERO);
              if (!select_unit()) return(ZERO);
              continue;                /* ����� ����� ��������� */
         }
         if (JmpFlag == ZERO) { /* �������� ������������ � �������������� */
               if (!error_msg(79, line_count, "\0", NONE))
                   return(ZERO);
         }
         if (!select_unit()) return(ZERO); /*  ��� ���������� ����� �.�. ����� ���� */
    } /* end of while STATE */
    rewunit();
    return(!ZERO);
};
/************************************************
 *             --- State_Body ---
 *  RETURN: EOF   ()
 *          OK    (})
 *          ERROR (NONE) ����� ���������� �/� Find_Position
 ************************************************/
INT16S State_Body (void)
{
#ifdef TEST_MODE
	printf("\n== State_Body");
#endif
    for (;;) {
         switch (Statement_Body()) {       /* Statement  */
              case ERROR:              /* Error in string set on new STATE */
                   return(ERROR);
              case ZERO:               /* EOF */
                   return(ZERO);
              case NONSTATEMENT:       /* ����������� ������������� -  ����� */
                   return(!ZERO);
              default:                 /* NO ERROR */
                   break;              /* check for next state */
         } /* end of switch */
    }
};

/************************************************
 *  ������ �����������
 *  RETURN: EOF   (��������� ����� �����)
 *          OK    (���������� ��� ������)
 *          NONSTATEMENT  (��� �� �����������)
 *          ERROR (NONE) ����� ���������� �/� Find_Position
 ************************************************/
INT16S Statement_Body (void)
{
#ifdef TEST_MODE
    printf("\n=== Statement_Body. String is/n%s", buffer1);
#endif
    if (!select_unit()) return(ZERO);
    switch (compare_RW(unit)) {
         case RW_SEMICOLON:       /* ";" - next unit  */
              break;
         case RW_OPEN_BRACE:      /* "{" - State_Body - "}"  */
              switch (State_Body()) {       /* State {} */
                   case ERROR:              /* Error in string set on new STATE */
                        return(ERROR);
                   case ZERO:               /* EOF */
                        return(ZERO);
              } /* end of switch */
              if (!select_unit()) return(ZERO);
              if (!compare(unit, rezword[RW_CLOSE_BRACE])){   /* "}" */
                   if (!error_msg(60, line_count, unit, NONE))
                        return(ZERO);
                   return(ERROR);
              }
              break;
         case RW_SWITCH:
              switch (Switch_Body()) {      /* SWITCH ( expression ) statement */
                   case ERROR:              /* Error */
                        return(ERROR);
                   case ZERO:               /* EOF */
                        return(ZERO);
                   default:
                        break;
              } /* end of switch */
              break;
         case RW_IF:
              switch (Condition_Body()) {   /* IF ( expression ) ... */
                   case ERROR:              /* Error */
                        return(ERROR);
                   case ZERO:               /* EOF */
                        return(ZERO);
                   default:
                        break;
              } /* end of switch */
              if (!select_unit()) return(ZERO);
              if (compare(unit, rezword[RW_ELSE])) {  /* ����-�������? */
                   switch (Post_Condition_Body()) {   /* ELSE statement */
                        case ERROR:              /* Error */
                             return(ERROR);
                        case ZERO:               /* EOF */
                             return(ZERO);
                   default:
                        break;
                   } /* end of switch */
              } else {
                   rewunit(); /* ���� �� ����-������� - ���������� ����� */
              }
              break;
         case RW_STOP:
              switch (Stop_Body()) {   /* STOP ; | PROC ��� �������� ; */
                   case ERROR:         /* Error */
                        return(ERROR);
                   case ZERO:          /* EOF */
                        return(ZERO);
                   default:
                        break;
              } /* end of switch */
              break;
         case RW_LOOP:
              switch (Loop_Body()) {   /* LOOP ; */
                   case ERROR:         /* Error */
                        return(ERROR);
                   case ZERO:          /* EOF */
                        return(ZERO);
                   default:
                        break;
              } /* end of switch */
              break;
         case RW_ERROR:
              switch (Error_Body()) {  /* ERROR ; | PROC ��� �������� ; */
                   case ERROR:         /* Error */
                        return(ERROR);
                   case ZERO:          /* EOF */
                        return(ZERO);
                   default:            /* NO ERROR */
                        break;
              } /* end of switch */
              break;
         case RW_START:
              switch (Start_Body()) {  /* START PROC ��� �������� ; */
                   case ERROR:         /* Error */
                        return(ERROR);
                   case ZERO:          /* EOF */
                        return(ZERO);
                   default:
                        break;
              } /* end of switch */
              break;
         case RW_IN:
              switch (In_Body()) {     /* IN STATE NEXT | ��� ��������� ; */
                   case ERROR:         /* Error */
                        return(ERROR);
                   case ZERO:          /* EOF */
                        return(ZERO);
                   default:
                        break;
              } /* end of switch */
              break;
         case RW_TIMEOUT:              /*  ���� ������� */
         case RW_CLOSE_BRACE:          /* ��� "}" */
         case RW_BREAK:                /* ��� ����� (� �������) */
         case RW_DEFAULT:              /* ��� ��������� (� �������) */
         case RW_CASE:                 /* ��� ������ (� �������) */
              rewunit();               /* ���������� -  � ����� */
              return(NONSTATEMENT);
         default: /*  � ���������� ������ - �������� ��������� ��������� */
              switch (Expression_Body()) {  /* ������ ��������� */
                   case ERROR:         /* Error */
                        return(ERROR);
                   case ZERO:          /* EOF */
                        return(ZERO);
                   default:
                        if (!compare(unit, rezword[RW_SEMICOLON])) {
                             error_msg(10, line_count, unit, NONE);
                             return(ERROR);
                        }
                        break;
              } /* end of switch */
              break;
    } /* end of switch */
    return(!ZERO);
};


/********************************************
 *  ��������� �������� �������
 *  ���� - ����� ����������� ���.����� ����
 *  unit V
 *  ���� ( ��������� ) �����������
 *  RETURN: EOF   (��������� ����� �����)
 *          OK    (���������� ��� ������)
 *          ERROR (NONE) ����� ���������� �/� Find_Position
 ************************************************/
int    Condition_Body (void) {
    int i;
#ifdef TEST_MODE
    printf("\n==== Condition_Body");
#endif
    if (!select_unit()) return(ZERO);                 /* for ( symbol */
    if (!compare(unit, "(")) {
         error_msg(20, line_count, unit, NONE);
         return(ERROR);
    }

    if (!select_unit()) return(ZERO);            /* �������� unit */
    if ((i = Expression_Body()) != !ZERO) return(i);  /* if IF ( ��������� ) */
    if (!compare(unit,")")){
         error_msg(21, line_count, unit, NONE);
         return(ERROR);
    }
    switch (Statement_Body()) {       /* Statement  */
         case ZERO:               /* EOF */
              return(ZERO);
         case ERROR:              /* Error in string set on new STATE */
         case NONSTATEMENT:       /* ����������� ������������� */
              error_msg(68, line_count, unit, NONE);
              return(ERROR);
         default:                 /* NO ERROR */
              return(!ZERO);
    } /* end of switch */
}

/********************************************
 * ��������� �������� ����-�������
 *  ���� - ����� ����������� ���.����� �����
 *  unit  V
 *  ����� �����������
 *  RETURN: EOF   (��������� ����� �����)
 *          OK    (���������� ��� ������)
 *          ERROR (NONE) ����� ���������� �/� Find_Position
 ************************************************/
int    Post_Condition_Body (void)
{
#ifdef TEST_MODE
    printf("\n==== Post_Condition_Body");
#endif
    switch (Statement_Body()) {       /* Statement  */
         case ZERO:               /* EOF */
              return(ZERO);
         case ERROR:              /* Error in string set on new STATE */
         case NONSTATEMENT:       /* ����������� ������������� */
              error_msg(68, line_count, unit, NONE);
              return(ERROR);
         default:                 /* NO ERROR */
#ifdef TEST_MODE
    printf("\n==== TEST: END OF Post_Condition_Body");
#endif
              return(!ZERO);
    } /* end of switch */
};

/********************************************
 * ��������� �������� ����
 *  ���� - ����� ����������� ���.����� ����
 *  unit V
 *  ����  <���� (��� ��������)> ; (���� ������ ����; - ��� ��������)
 *  RETURN: EOF   (��������� ����� �����)
 *          OK    (���������� ��� ������)
 *          ERROR (NONE) ����� ���������� �/� Find_Position
 ************************************************/
int    Stop_Body (void)
{
#ifdef TEST_MODE
    printf("\n==== Stop_Body");
#endif
    if (!select_unit()) return(ZERO);
    switch (compare_RW(unit)) {
         case RW_PROC:                           /* ���� */
              if (!select_unit()) return(ZERO);
              if (!check_name(unit)) {        /* ��� �������� */
                   error_msg(11, line_count, unit, NONE);
                   return(ERROR);
              }
              if (!select_unit()) return(ZERO);   /* ; */
              if (!compare(unit, rezword[RW_SEMICOLON])) {
                   error_msg(10, line_count, unit, NONE);
                   return(ERROR);
              }
              break;
         case RW_SEMICOLON:            /* ���� ";" => ��� �������� �������� */
                   JmpFlag = !ZERO;     /*  ���� ������� ������� �� ��������� */
              break;
         default:                 /*  ����� - ������ ������������ �������� */
              error_msg(23, line_count, unit, NONE);
              return(ERROR);
    } /* end of switch */
    return(!ZERO);
};

/********************************************
 * ��������� �������� ���������
 *  ���� - ����� ����������� ���.����� ���������
 *  unit V
 *  ���������  ; 
 *  RETURN: EOF   (��������� ����� �����)
 *          OK    (���������� ��� ������)
 *          ERROR (NONE) ����� ���������� �/� Find_Position
 ************************************************/
int    Loop_Body (void)
{
#ifdef TEST_MODE
    printf("\n==== Loop_Body");
#endif
    if (!select_unit()) return(ZERO);
    switch (compare_RW(unit)) {
         case RW_SEMICOLON:            /* ���� ";" => ��� �������� �������� */
                   JmpFlag = !ZERO;     /*  ���� ������� ������� �� ��������� */
              break;
         default:                 /*  ����� - ������ ������������ �������� */
              error_msg(10, line_count, unit, NONE);
              return(ERROR);
    } /* end of switch */
    return(!ZERO);
};

/********************************************
 * ��������� �������� ������
 *  ���� - ����� ����������� ���.����� ������
 *  unit   V
 *  ������  <���� (��� ��������)> ; (���� ������ ������; - ��� ��������)
 *  RETURN: EOF   (��������� ����� �����)
 *          OK    (���������� ��� ������)
 *          ERROR (NONE) ����� ���������� �/� Find_Position
 ************************************************/
int    Error_Body (void)
{
#ifdef TEST_MODE
    printf("\n==== Error_Body");
#endif
    if (!select_unit()) return(ZERO);
    switch (compare_RW(unit)) {
         case RW_PROC:                           /* ���� */
              if (!select_unit()) return(ZERO);
              if (!check_name(unit)) {        /* ��� �������� */
                   error_msg(11, line_count, unit, NONE);
                   return(ERROR);
              }
              if (!select_unit()) return(ZERO);   /* ; */
              if (!compare(unit, rezword[RW_SEMICOLON])) {
                   error_msg(10, line_count, unit, NONE);
                   return(ERROR);
              }
              break;
         case RW_SEMICOLON:       /* ���� ";" => ��� �������� �������� */
                   JmpFlag = !ZERO;     /*  ���� ������� ������� �� ��������� */
              break;
         default:                 /*  ����� - ������ ������������ �������� */
              error_msg(23, line_count, unit, NONE);
              return(ERROR);
    } /* end of switch */
    return(!ZERO);
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
int    Start_Body (void)
{
#ifdef TEST_MODE
    printf("\n==== Start_Body");
#endif
    if (!select_unit()) return(ZERO);
    switch (compare_RW(unit)) {
         case RW_PROC:                           /* ���� */
              if (!select_unit()) return(ZERO);
              if (!check_name(unit)) {        /* ��� �������� */
                   error_msg(11, line_count, unit, NONE);
                   return(ERROR);
              }
              if (!select_unit()) return(ZERO);   /* ; */
              if (!compare(unit, rezword[RW_SEMICOLON])) {
                   error_msg(10, line_count, unit, NONE);
                   return(ERROR);
              }
              break;
         case RW_SEMICOLON:       /* ���� ";" => ��� �������� �������� */
                   JmpFlag = !ZERO;     /*  ���� ������� ������� �� ��������� */
              break;
         default:                 /*  ����� - ������ ������������ �������� */
              error_msg(23, line_count, unit, NONE);
              return(ERROR);
    } /* end of switch */
    return(!ZERO);
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
int    In_Body (void)
{
#ifdef TEST_MODE
    printf("\n==== In_Body");
#endif
    JmpFlag = !ZERO;     /*  ���� ������� ������� �� ��������� */
    if (!select_unit()) return(ZERO);
    switch (compare_RW(unit)) {
         case RW_STATE:                           /* ���� */
              if (!select_unit()) return(ZERO);
              if (!check_name(unit)) {        /* ��� ��������� */
                   error_msg(22, line_count, unit, NONE);
                   return(ERROR);
              }
              if (!select_unit()) return(ZERO);   /* ; */
              if (!compare(unit, rezword[RW_SEMICOLON])) {
                   error_msg(10, line_count, unit, NONE);
                   return(ERROR);
              }
              break;
	 case RW_NEXT:       /* ��������� => ��������� ��������� �������� */
              if (!select_unit()) return(ZERO);   /* ; */
              if (!compare(unit, rezword[RW_SEMICOLON])) {
                   error_msg(10, line_count, unit, NONE);
                   return(ERROR);
              }
              break;
         default:                 /*  ����� - ������ ������������ ��������� */
              error_msg(56, line_count, unit, NONE);
              return(ERROR);
    } /* end of switch */
    return(!ZERO);
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
int    Switch_Body (void)
{
    int i;
#ifdef TEST_MODE
    printf("\n==== Switch_Body");
#endif
    if (!select_unit()) return(ZERO);                 /* for ( symbol */
    if (!compare(unit, "(")) {
	 error_msg(20, line_count, unit, NONE);
	 return(ERROR);
    }

    if (!select_unit()) return(ZERO);            /* �������� unit */
    if ((i= Expression_Body()) != !ZERO) return(i);  /* ������ ( ��������� ) */
    if (!compare(unit,")")){
         error_msg(21, line_count, unit, NONE);
         return(ERROR);
    }
    if (!select_unit()) return(ZERO);                 /* for { symbol */
    if (!compare(unit, "{")) {
         error_msg(18, line_count, unit, NONE);
         return(ERROR);
    }

    for (;;) {         /* ������ ������������� ������ () */
         switch (Case_Body()) {        /* ������������ ������� */
              case ZERO:               /* EOF */
                   return(ZERO);
              case ERROR:              /* Error in string set on new STATE */
                   return(ERROR);
              case NONSTATEMENT:       /* ����������� ������������� - } */
		   break;
	      default:                 /* NO ERROR - ���������� ��������� ������������� */
		   continue;
	 } /* end of switch */
	 break;
    }

    if (!select_unit()) return(ZERO);                 /* for } symbol */
    if (!compare(unit, "}")) {
         error_msg(19, line_count, unit, NONE);
         return(ERROR);
    }

    return(!ZERO);

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
 *  RETURN: EOF   (��������� ����� �����)
 *          OK    (���������� ��� ������)
 *          ERROR (NONE) ����� ���������� �/� Find_Position
 ************************************************/
 int Case_Body (void)
 {
#ifdef TEST_MODE
    printf("\n==== Case_Body");
#endif
    if (!select_unit()) return(ZERO);
    switch (compare_RW(unit)) {
         case RW_CASE:                           /* ������ */
              if (!select_unit()) return(ZERO);  /* ��������� */
              if (!check_digit(unit)) {       /* ? */
                   error_msg(50, line_count, unit, NONE);
                   return(ERROR);
              }
              if (!select_unit()) return(ZERO);
              if (!compare(unit, ":")) {        /* ��������� */
                   error_msg(66, line_count, unit, NONE);
                   return(ERROR);
              }

              switch (State_Body()) {       /* State {} */
                   case ERROR:              /* Error */
                        return(ERROR);
                   case ZERO:               /* EOF */
                        return(ZERO);
                   default:                 /* ���� ������ */
                        break;
              } /* end of switch */
              if (!select_unit()) return(ZERO);       /* ��������, ��� ������ */
              if (compare(unit, rezword[RW_BREAK])) { /* ����� (break) */
                   if (!select_unit()) return(ZERO);  /* ; */
                   if (!compare(unit, rezword[RW_SEMICOLON])) {
                        error_msg(10, line_count, unit, NONE);
                        return(ERROR);
                   }
              } else {                      /* ����� ������ ��� �� ����� */
                   rewunit();
              }
              break;
         case RW_DEFAULT:                        /* ��������� */
              if (!select_unit()) return(ZERO);
              if (!compare(unit, ":")) {        /* ��������� */
                   error_msg(66, line_count, unit, NONE);
                   return(ERROR);
              }

              switch (State_Body()) {       /* State {} */
                   case ERROR:              /* Error */
                        return(ERROR);
                   case ZERO:               /* EOF */
                        return(ZERO);
                   default:                 /* ���� ������ */
                        break;
              } /* end of switch */

              if (!select_unit()) return(ZERO);       /* ��������, ��� ������ */
              if (compare(unit, rezword[RW_BREAK])) { /* ����� (break) */
                   if (!select_unit()) return(ZERO);  /* ; */
                   if (!compare(unit, rezword[RW_SEMICOLON])) {
                        error_msg(10, line_count, unit, NONE);
                        return(ERROR);
                   }
              } else {                      /* ����� ������ ��� �� ����� */
                   rewunit();
              }
              break;
         default:                 /*  ����� - ������ ������������ ��������� */
              rewunit();
              return(NONSTATEMENT);       /* ����������� ���-�� ���������� */
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
 *  RETURN: EOF   (��������� ����� �����)
 *          OK    (���������� ��� ������)
 *          ERROR (NONE) ����� ���������� �/� Find_Position
 ************************************************/
/* ��������� �������� ��������� */
int    Expression_Body (void)
{
#ifdef TEST_MODE
    printf("\n==== Expression_Body");
#endif
    for (;;) {          /* ��������! �� ����� � unit ��� ���-�� ��������� */
         for (;;) {     /* ��������� �������� */
              switch (Prefix_Body()) {
                   case ZERO:               /* EOF */
                        return(ZERO);
                   case ERROR:              /* Error */
                        return(ERROR);
                   default:                 /* ��� ��� ���������� (�������) */
                        if (!select_unit()) return(ZERO);  /* �������� unit */
                        continue;           /* � ����� ��������� �������� */
                   case NONSTATEMENT:       /* ��� �� ������� (� ����) */
                        break;
              }
              break;                        /* ����� �� ����� ��������� ��������� */
         }

         switch (Term_Body()) {        /* ��������� ����� - ������ ���� */
              case ZERO:               /* EOF */
                   return(ZERO);
              case ERROR:              /* Error */
                   return(ERROR);
              default:                 /* ��� � ������� */
                   break;
         }

         if (!select_unit()) return(ZERO);  /* �������� unit */
         switch (Postfix_Body()) {
              case ZERO:               /* EOF */
                   return(ZERO);
              case ERROR:              /* Error */
                   return(ERROR);
              default:                 /* ��� ��� �������� */
                   if (!select_unit()) return(ZERO);  /* �������� unit */
                   break;
              case NONSTATEMENT:       /* ��� �� �������� */
                   break;
         }

         switch (Infix_Body()) {       /* ��������� ������� */
              case ZERO:               /* EOF */
                   return(ZERO);
              case ERROR:              /* Error */
                   return(ERROR);
              default:                 /* ��� � ������� */
                   if (!select_unit()) return(ZERO);  /* �������� unit */
                   break;
              case NONSTATEMENT:       /* ��� �� ������ */
                   return (!ZERO);
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
 *  RETURN: EOF   (��������� ����� �����)
 *          OK    (���������� ��� ������, ��� ������)
 *          ERROR (NONE) ����� ���������� �/� Find_Position (?)
 *          NONSTATEMENT  - ��� �� ������ (����� ���������)
 ************************************************/
int Infix_Body (void) {
#ifdef TEST_MODE
    printf("\n===== Infix_Body");
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
 *  RETURN: EOF   (��������� ����� �����)
 *          OK    (���������� ��� ������, ��� ��������)
 *          ERROR (NONE) ����� ���������� �/� Find_Position (?)
 *          NONSTATEMENT  - ��� �� ��������
 ************************************************/
int Postfix_Body (void) {
#ifdef TEST_MODE
    printf("\n===== Postfix_Body");
#endif
    switch (compare_RW(unit)) {
         case RW_INC:                  /* "++",   */
              return(!ZERO);
         case RW_DEC:                  /* "--",   */
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
 *  RETURN: EOF   (��������� ����� �����)
 *          OK    (���������� ��� ������, ��� ����)
 *          ERROR (NONE) ����� ���������� �/� Find_Position
 *          NONSTATEMENT  - ��� �� ���� (?)
 ************************************************/
int Term_Body (void) {
#ifdef TEST_MODE
    printf("\n===== Term_Body");
#endif
    if (compare(unit, rezword[RW_PROC])) {            /* ���� ��� � ���� ��� ? */
         if (!select_unit()) return(ZERO);            /* ��� �������� ? */
         if (!check_name(unit)) {                  /* ��� ��� ? */
              error_msg(11, line_count, unit, NONE);  /* �.�. ��� �������� */
              return(ERROR);
         }
         if (!select_unit()) return(ZERO);            /* ����� � */
         if (!compare(unit, rezword[RW_IN])) {        /* ��� ����� "�" ? */
              error_msg(33, line_count, unit, NONE);  /* �.�. ����� "�" */
              return(ERROR);
         }
         if (!select_unit()) return(ZERO);            /* ����� COCT */
         if (!compare(unit, rezword[RW_STATE])) {     /* ��� ����� "����" ? */
              error_msg(47, line_count, unit, NONE);  /* �.�. ����� "����" */
              return(ERROR);
         }
         if (!select_unit()) return(ZERO);            /* ��������� */
         switch (compare_RW(unit)) {                  /* ��� �� ��������� ? */
              case RW_STOP:                           /* ���� */
                   break;
              case RW_ERROR:                          /* ������ */
                   break;
              case RW_ACTIVE:                         /* �������� */
                   break;
              case RW_PASSIVE:                        /* ��������� */
                   break;
              case RW_NULL:                           /* ���������� ��� ��������� */
                   break;
              default:
                   error_msg(22, line_count, unit, NONE);  /* �.�. ��� ��������� */
                   return(ERROR);
         }
    } else {                                               /* ��� �� �������� */
         if (compare(unit, rezword[RW_OPEN_PARENTESIS])) { /* ( ��������� ) ? */
              if (!select_unit()) return(ZERO);            /* �������� unit */
              switch (Expression_Body()) {                 /* ������ ��������� */
                   case ERROR:         /* Error */
                        return(ERROR);
                   case ZERO:          /* EOF */
                        return(ZERO);
                   default:
                        break;
              } /* end of switch */
              if (!compare(unit, rezword[RW_CLOSE_PARENTESIS])) {
                   error_msg(21, line_count, unit, NONE);       /* �.�. ) */
                   return(ERROR);
              }
         } else {
                        /* ����� ��������� ��� ����������, �������, ��������� */
              if ((CheckNameVariable(unit)) &&
                  (!check_digit(unit)) &&
                  (CheckNameFunc(unit))) {
                   error_msg(45, line_count, unit, NONE);
              } else {
                   if (!CheckNameFunc(unit)) { /* ��� ������� ? */
                        switch (Check_Func_Args()) {
                             case ERROR:         /* Error */
                                  return(ERROR);
                             case ZERO:          /* EOF */
                                  return(ZERO);
                             default:
                                  break;
                        } /* end of switch */
                   }
              }
         }
    }

/*    printf("\nTEST: END OF TERM!!! ");
*/

    return(!ZERO);
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
int Check_Func_Args (void)
{
int i, arg_num;
#ifdef TEST_MODE
        printf("\n== Check_Func_Args");
#endif
    if (!select_unit()) return(ZERO);            /* �������� ( */
    if (!compare(unit, rezword[RW_OPEN_PARENTESIS])) {
         error_msg(20, line_count, unit, NONE);  /* �.�. ����� "�" */
         return(ERROR);
    }
    arg_num = GetCurFuncArgNum();           /* ����� ���������� ���������� */
    if (arg_num == 0) {
         if (!select_unit()) return(ZERO);            /* �������� unit */
    } else {
        for (i = 0; i < arg_num; i++) {         /* ������� ���������� ���������� */
             if (!select_unit()) return(ZERO);            /* �������� unit */
             switch (Expression_Body()) {                 /* ������ ��������� */
                  case ERROR:         /* Error */
                       return(ERROR);
                  case ZERO:          /* EOF */
                       return(ZERO);
                  default:
                       break;
             } /* end of switch */
             if (i < (arg_num - 1)) {             /* � ��������� ������ - �� ���, � ) */
                  if (!compare(unit, rezword[RW_COMMA])) {
                       error_msg(74, line_count, unit, NONE);  /* �.�. , */
                       return(ERROR);
                  }
             }
        } /* end of for */
    }
    if (!compare(unit, rezword[RW_CLOSE_PARENTESIS])) {
         error_msg(21, line_count, unit, NONE);  /* �.�. ) */
         return(ERROR);
    }
    return(!ZERO);
};

/********************************************
 *  ��������� ��������
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
int Prefix_Body (void) {
#ifdef TEST_MODE
    printf("\n===== Prefix_Body");
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
              return(!ZERO);
         case RW_OPEN_PARENTESIS:   /* "(" - ���������, �������������� ����� ?*/
              switch (Declarator_Body()) {
                   case ZERO:               /* EOF */
                        return(ZERO);
                   case ERROR:              /* Error in string set on new STATE */
                        return(ERROR);
                   case NONSTATEMENT:       /* ��� �� ���������� */
                        return(NONSTATEMENT);
                   default:                 /* ��� ��� ���������� (�������) */
                        if (!select_unit()) return(ZERO);  /* ) */
			if (!compare(unit, ")")) {
			     error_msg(21, line_count, unit, NONE); /* �� ��������� ����� ����������� */
			     return(ERROR);
                        }
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
 *  RETURN: EOF   (��������� ����� �����)
 *          OK    (��������� ����������)
 *          ERROR (NONE) ����� ���������� �/� Find_Position
 *          NONSTATEMENT - ��� �� ���������� unit = (
 *
 ************************************************/
int Declarator_Body (void)
{
#ifdef TEST_MODE
    printf("\n===== Declarator_Body");
#endif
    if (!select_unit()) return(ZERO);  /* */
    switch (compare_RW(unit)) {
         case RW_SHORT:                /* SHORT */
         case RW_LONG:                 /* LONG */
         case RW_INT:                  /* INT */
              return(Sign_Body());
         case RW_FLOAT:
         case RW_DOUBLE:
	 case RW_VOID:
              return(Mul_Body());
         case RW_SIGN:
         case RW_UNSIGN:
              return(Int_Body());
         default:             /*  ��� �� ���������� */
              rewunit();
              return(NONSTATEMENT);
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
int Mul_Body (void)
{
#ifdef TEST_MODE
    printf("\n======= Mul_Body");
#endif
    for (;;) {
        if (!select_unit()) return(ZERO);
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
int Sign_Body (void)
{
#ifdef TEST_MODE
    printf("\n====== Sign_Body");
#endif
    if (!select_unit()) return(ZERO);
    switch (compare_RW(unit)) {
         case RW_UNSIGN:                         /* UNSIGNED */
         case RW_SIGN:                           /* SIGNED */
         case RW_MUL:                            /* SIGNED */
          return(Mul_Body());
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
int Int_Body (void)
{
#ifdef TEST_MODE
    printf("\n====== Int_Body");
#endif
    if (!select_unit()) return(ZERO);
    switch (compare_RW(unit)) {
	 case RW_SHORT:                          /* SHORT */
	 case RW_INT:                            /* INT */
	 case RW_LONG:                           /* LONG */
          return(Mul_Body());
         default:
              rewunit();
              return(!ZERO);
    }
};

/************************************************
 *             --- Time_Out ---
 *  RETURN: OK
 *          EOF
 *          ERROR
 ************************************************/
int Time_Out (void)
{    /* PAUSE nn StateName; */
#ifdef TEST_MODE
        printf("\n== Time_Out");
#endif
/* 03/18/04 08:27pm - ��������� �������� */
/*    JmpFlag = !ZERO;
*/
    if (!select_unit()) return(ZERO);
    if ((!check_digit(unit)) && (!check_name(unit))) {  /* check for const */
         if(!error_msg(15, line_count, unit, STATE)) return(ZERO);
         return(ERROR);
    }
/* 03/18/04 08:27pm - ��������� �������� */
    switch (Statement_Body()) {       /* Statement  */
         case ZERO:               /* EOF */
              return(ZERO);
         case ERROR:              /* Error in string set on new STATE */
         case NONSTATEMENT:       /* ����������� ������������� */
              error_msg(68, line_count, unit, NONE);
              return(ERROR);
         default:                 /* NO ERROR */
              return(!ZERO);
    } /* end of switch */
/* 03/18/04 08:27pm - ��������� ��������
/* ����:
/*     if(!select_unit()) return(ZERO);
/*     if (!check_name(unit)) {                      /* check for state name */
/*          if(!error_msg(16,line_count,unit,STATE)) return(ZERO);
/*          return(ERROR);
/*     }
/*     if(!select_unit()) return(ZERO);
/*     if(!compare(unit, rezword[RW_SEMICOLON])){
/*          if(!error_msg(10,line_count,unit,STATE)) return(ZERO);
/*          return(ERROR);
/*     }
/*     return(!ZERO);
*/
};
