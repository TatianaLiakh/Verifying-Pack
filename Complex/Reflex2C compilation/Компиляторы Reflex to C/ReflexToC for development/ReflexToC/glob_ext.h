/*===================================================================*/
/*====== Institute Of Automation And Electrometry SB RAS ============*/
/*====== Pr. Acad. Koptyuga, 1. Novosibirsk. Russia =================*/
/*===================================================================*/
/*====== (c) Copyright 2002, IA&E, NSK, RU ==========================*/
/*===================================================================*/
/*===================================================================*/
/*===================================================================*/
/*====== Имя файла: glob_ext.h=======================================*/
/*====== Автор    : Зюбин Владимир Евгеньевич =======================*/
/*====== Дата     : 2002/07/16 ======================================*/
/*====== Описание : файл содержит описание ссылок на глобальные =====*/
/*======            переменные, испольуемые в программе транслятор ==*/
/*======            Reflex ==========================================*/
/*===================================================================*/

#ifndef _GLOB_EXT_H
#define _GLOB_EXT_H 1

/*============ Global Variables ==========*/
extern char InputFileName[FLENGTH];   /* имя входного файла */
extern char BaseOutputFileName[FLENGTH];  /* шаблон имен выходных файлов */

extern FILE *fptr_RCS;     /* указатель на исходный файл */
extern FILE *fptr_LIS;     /* указатель на файл листинга */
extern FILE *fptr_SYM;     /* указатель на файл привязки */
extern FILE *fptr_INP;     /* указатель на файл с процедурой считывания входных значений */
extern FILE *fptr_OUTP;    /* указатель на файл с процедурой записи выходных значений */
extern FILE *fptr_C;       /* указатель на текущий С-файл, временный файл */
#ifdef GEN_ID
extern FILE *fptr_ID;      /* указатель на файл С-идентификаторов */
extern FILE *fptr_IDC;      /* указатель на файл С-идентификаторов */


#endif


extern INT16S str_count, line_count;
extern char unit[BUFFER_LENGTH];
extern char prev_unit[BUFFER_LENGTH];
extern char spaces[BUFFER_LENGTH];         /* пред-разделитель текущей лексемы */
extern char prev_spaces[BUFFER_LENGTH];

extern char buffer1[BUFFER_LENGTH];
/* extern char buffer2[BUFFER_LENGTH]; */


extern INT16S File_Number;
extern INT16S Flag_PASS;
extern INT16S Flag_CASE;
extern INT16S Flag_LIS;      /* флаг листинга */
extern INT16S Flag_MAP;      /* флаг файла привязки перемен */
extern INT32S CFileMAXLen;   /* Ограничение на длину С-файла */
extern INT16S Flag_LF;              /* for line feed in spec comment */
extern INT16S Flag_SP;              /* for spacebar in spec comment */
extern INT16S Flag_Unexpect;        /* For No error when skip unexpected simbol after EOF */
extern INT16S Flag_CString;         /* flag for C-string */
extern INT16S Flag_Comment;         /* flag for usual comment */
extern INT16S Flag_TEST;        /* Флаг необходимости создания файла теста */
extern INT16S Flag_CPP;        /* Флаг необходимости геренации CPP файлов */
extern INT16S Flag_PROC_DESCR ; /* Флаг необходимости геренации файла- описания портов*/


extern INT16S err_flag, error_count, line_count, warning_count;
extern INT16S JmpFlag;  /* флаг для контроля переходов из состояния */

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
