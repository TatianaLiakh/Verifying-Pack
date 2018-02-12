/*======================================================*/
/*=======  ВНУТРЕННИЕ КОНСТАНЫ R-ТРАНСЛЯТОРА  ==========*/
/*======= ИСПОЛЬЗУЮТСЯ ПРИ ГЕНЕРАЦИИ ТРАНСЛЯТОРА =======*/
/*======================================================*/

#ifndef _R_CONST_H
#define _R_CONST_H 1

#define WIN32 1

#define ZERO 0

#define TRUE   (!ZERO)
#define FALSE  ZERO

#define ON    (!ZERO)
#define OFF   ZERO

/*=============  ДЛЯ Compare  ===============*/
#define DIGIT  "\1"     /* проверить на число */
#define NAME   "\0"     /* проверить на имя */

/*========= ТИП ПЕРЕМЕННОЙ (РЕГИСТРА) ===========================*/
/* #define INT   0  /* целое 16 битов */
/* #define LOG   1  /* логическая 1 бит */
/* #define LONG  2  /* длинное целое 32 бита */
/* #define SHORT 3  /* короткое целое 8 битов */


/*========= КОДЫ ОШИБОК ОПИСАНИЯ ДОСТУПА ПЕРЕМЕННОЙ ===============*/
#define RESULT_OK     1
#define NO_PROCESS    2   /* отсутствует процесс */
#define NO_VARIABLE   3   /* нет переменной */
#define NO_ACCESS     4   /* доступ запрещен */
#define NO_VALUE      5   /* нет искомого значения */
#define NO_STATE      6   /* нет искомого состояния */

#define NAME_LENGTH   64    /* количество различаемых символов в идентификаторе */
#define BUFFER_LENGTH 1024 /* длина строковых переменных */


#define DESTINATION 0
#define SOURCE 1

/*=============  ТИПЫ ПОРТОВ (ПО ЛОГИЧЕСКОЙ ПРИРОДЕ) ===============*/
/*======For IO_Type */
#define INP 1  /* доступ только на чтение */
#define OUT 2  /* - на чтение/запись */
#define NOI 0  /* - ни читать ни писать */

/*=============  УНИЧТОЖЕНИЕ НАВЕДЕННЫХ ОШИБОК ===============*/
#define PROCESS     1 /* for msg_error find }PROC */
#define STATE       2 /* find }STATE */
#define SEMICOLON  3 /* find ; */
#define NONE        4 /* don't find anything */

/*=============  ЗНАЧЕНИЕ ЯЧЕЕК logname ===============*/

#define NOT_INITIALIZE -1  /* не проинициализировано, не было вхождений */
#define FIRST_LOGNAME 0    /* начальный номер для всех языковых компонентов - 0 */

/* КОДЫ ВОЗВРАТА ИЗ ФУНКЦИЙ ОБРАБОТКИ */
/* ZERO              -     код возврата - конец файла */
/* !ZERO - O'K       -     код возврата - без ошибок */
#define ERROR        2  /* код возврата - если была ошибка ERROR */
#define NONSTATEMENT 3  /* код возврата - если неутверждение */

#define ERRMSGNUM   100  /* число сообщений об ошибках */
#define ERRMSGLEN   80  /* длина сообщений об ошибках */
#define WRNMSGNUM   20  /* число сообщений об ошибках */
#define WRNMSGLEN   80  /* длина сообщений об ошибках */

/*=============  РЕЗЕРВИРОВАННЫЕ СЛОВА ===============*/
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
RWLAST, /* число резервированных слов */
NODEF                /* используется, чтобы пометить временно неинициализированную переменную */
};
#define RWLEN       16          /* длина резервированных слов */
#define RWNUM       (RWLAST+1)  /* число резервированных слов */

/* #define TEST_MODE 1          /* тестирование функции синтаксического анализа */
/* #define TEST_MODE_SELECT 1   /*  тестирование функции выбора лексемы */
/* #define TEST_MODE_SEM 1      /*  тестирование функции семантического разбора */

#define GEN_ID 1                /*  генерация файла С-идентификаторов NAME_ID.H*/

#endif
