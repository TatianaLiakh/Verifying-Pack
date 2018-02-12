/*======================================================*/
/*=======  ���������� �������� R-�����������  ==========*/
/*======= ������������ ��� ��������� ����������� =======*/
/*======================================================*/

#ifndef _R_CONST_H
#define _R_CONST_H 1

#define ZERO 0

#define TRUE   (!ZERO)
#define FALSE  ZERO

#define ON    (!ZERO)
#define OFF   ZERO

/*=============  ��� Compare  ===============*/
#define DIGIT  "\1"     /* ��������� �� ����� */
#define NAME   "\0"     /* ��������� �� ��� */

/*========= ��� ���������� (��������) ===========================*/
/* #define INT   0  /* ����� 16 ����� */
/* #define LOG   1  /* ���������� 1 ��� */
/* #define LONG  2  /* ������� ����� 32 ���� */
/* #define SHORT 3  /* �������� ����� 8 ����� */


/*========= ���� ������ �������� ������� ���������� ===============*/
#define RESULT_OK     1
#define NO_PROCESS    2   /* ����������� ������� */
#define NO_VARIABLE   3   /* ��� ���������� */
#define NO_ACCESS     4   /* ������ �������� */
#define NO_VALUE      5   /* ��� �������� �������� */
#define NO_STATE      6   /* ��� �������� ��������� */

#define NAME_LENGTH   64    /* ���������� ����������� �������� � �������������� */
#define BUFFER_LENGTH 132 /* ����� ��������� ���������� */


#define DESTINATION 0
#define SOURCE 1

/*=============  ���� ������ (�� ���������� �������) ===============*/
/*======For IO_Type */
#define INP 1  /* ������ ������ �� ������ */
#define OUT 2  /* - �� ������/������ */
#define NOI 0  /* - �� ������ �� ������ */

/*=============  ����������� ���������� ������ ===============*/
#define PROCESS     1 /* for msg_error find }PROC */
#define STATE       2 /* find }STATE */
#define SEMICOLON  3 /* find ; */
#define NONE        4 /* don't find anything */

/*=============  �������� ����� logname ===============*/

#define NOT_INITIALIZE -1  /* �� �������������������, �� ���� ��������� */
#define FIRST_LOGNAME 0    /* ��������� ����� ��� ���� �������� ����������� - 0 */

/* ���� �������� �� ������� ��������� */
/* ZERO              -     ��� �������� - ����� ����� */
/* !ZERO - O'K       -     ��� �������� - ��� ������ */
#define ERROR        2  /* ��� �������� - ���� ���� ������ ERROR */
#define NONSTATEMENT 3  /* ��� �������� - ���� ������������� */

#define ERRMSGNUM   100  /* ����� ��������� �� ������� */
#define ERRMSGLEN   80  /* ����� ��������� �� ������� */
#define WRNMSGNUM   20  /* ����� ��������� �� ������� */
#define WRNMSGLEN   80  /* ����� ��������� �� ������� */

/*=============  ��������������� ����� ===============*/
enum RW_REFLEX {
RW_NULL=0,
RW_PROGR,
RW_TACT,
RW_CONST,
RW_INPUT,
RW_OUTPUT,
RW_PROC,
RW_LOCAL,
RW_FOR,
RW_ALL,
RW_FROM,
RW_LOG,
RW_INT,
RW_STATE,
RW_STOP,
RW_CONT,
RW_START,
RW_TIMEOUT,
RW_IF,
RW_THEN,
RW_ELSE,
RW_IN,
RW_NEXT,
RW_RAM,
RW_ERROR,
RW_SHORT,
RW_LONG,
RW_SWITCH,
RW_CASE,
RW_BREAK,
RW_FLOAT,
RW_DOUBLE,
RW_DEFAULT,
RW_ACTIVE,
RW_PASSIVE,
RW_LOOP,
RW_SIGN,
RW_UNSIGN,
RW_ENUM,
RW_FUNCTION,
RW_TYPE,
RW_VOID,
RW_ARGUMENTS,
RW_CSTRING,

RW_POINT,             /* ".",   */
RW_COMMA,             /* ",",   */
RW_COLON,             /* ":",   */
RW_SEMICOLON,         /* ";",   */
RW_OPEN_BRACKET,      /* "[",   */
RW_CLOSE_BRACKET,     /* "]",   */
RW_OPEN_PARENTESIS,   /* "(",   */
RW_CLOSE_PARENTESIS,  /* ")",   */
RW_OPEN_BRACE,        /* "{",   */
RW_CLOSE_BRACE,       /* "}",   */

RW_BW_COMPLEMENT,     /* "~",   */
RW_NOT,               /* "!",   */
RW_INC,               /* "++",  */
RW_DEC,               /* "--",  */

RW_PLUS,              /* "+",   */
RW_MINUS,             /* "-",   */
RW_MUL,               /* "*",   */
RW_DIV,               /* "/",   */
RW_REMINDER,          /* "%",   */
RW_SHFT_LFT,          /* "<<",  */
RW_SHFT_RGHT,         /* ">>",  */
RW_BW_AND,            /* "&",   */
RW_BW_XOR,            /* "^",   */
RW_BW_OR,             /* "|",   */
RW_AND,               /* "&&",  */
RW_OR,                /* "||",  */
RW_EQU,               /* "=",   */
RW_MUL_EQU,           /* "*=",  */
RW_DIV_EQU,           /* "/=",  */
RW_REM_EQU,           /* "%=",  */
RW_PLUS_EQU,          /* "+=",  */
RW_MINUS_EQU,         /* "-=",  */
RW_SHFT_LFT_EQU,      /* "<<=", */
RW_SHFT_RGHT_EQU,     /* ">>=", */
RW_BW_AND_EQU,        /* "&=",  */
RW_BW_XOR_EQU,        /* "^=",  */
RW_BW_OR_EQU,         /* "|=",  */
RW_LESS,              /* "<",   */
RW_GREATER,           /* ">",   */
RW_LESS_EQU,          /* "<=",  */
RW_GREATER_EQU,       /* ">=",  */
RW_EQU_EQU,           /* "==",  */
RW_NOT_EQU,           /* "!=",  */
RWLAST, /* ����� ��������������� ���� */
NODEF                /* ������������, ����� �������� �������� �������������������� ���������� */
};
#define RWLEN       16          /* ����� ��������������� ���� */
#define RWNUM       (RWLAST+1)  /* ����� ��������������� ���� */

#define FLENGTH 255

/* #define TEST_MODE 1          /* ������������ ������� ��������������� ������� */
/* #define TEST_MODE_SELECT 1   /*  ������������ ������� ������ ������� */
/* #define TEST_MODE_SEM 1      /*  ������������ ������� �������������� ������� */

#define GEN_ID 1                /*  ��������� ����� �-��������������� NAME_ID.H*/

#endif
