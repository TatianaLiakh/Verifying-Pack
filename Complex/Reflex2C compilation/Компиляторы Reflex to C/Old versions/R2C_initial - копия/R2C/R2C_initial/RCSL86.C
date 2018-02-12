/*===================================================================*/
/*====== Наименование программы: ====================================*/
/*====== Транслятор языка REFLEX. ===================================*/
/*====== Язык ориентирован на описание алгоритмов работы ============*/
/*====== сложных объектов автоматизации. ============================*/
/*====== Теоретическая основа языка описана в соответсвующих ========*/
/*====== статьях. Синтаксис языка приведен в документации. ==========*/
/*====== Все права принадлежат Институту Автоматики и Электрометрии =*/
/*====== СО РАН. ====================================================*/
/*====== Автор: Зюбин Владимир Евгеньевич ===========================*/
/*====== 1989-1997, 2002 ============================================*/
/*====== Язык программирования: Си ==================================*/
/*===================================================================*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys\types.h>
#include <sys\stat.h>
#include "const.h"           /* описание констант */
#include "typedef.h"         /* описание используемых типов */
#include "prototyp.h"        /* описание прототипов функций */
#include "glob_var.h"        /* описание глобальных переменных */

/*============== ARGV and ARGC ==============*/
INT16S main (INT16S argc, INT8U **argv)
{
  char string[BUFFER_LENGTH];

  void hello(int, INT8U * *);
  void success_err(void);

/*    putenv("DOS4G=QUIET"); */
    hello(argc, argv);                           /* разбор командной строки */

    error_count = 0; /* обнуляем счетчик ошибок */
    warning_count = 0; /* обнуляем счетчик предупреждений */

    Flag_PASS = ZERO; /* указываем процедуре select_unit, что это первый проход */

    strcpy(string, InputFileName);     /* открываем источник */
    Open_File_R(&fptr_RCS, string);
    if (Flag_LIS) {                      /* открываем листинг */
         strcpy(string, BaseOutputFileName);
         strcat(string, ".lis");
         Open_File_W(&fptr_LIS, string);
    }

    error_count = synt_anal_of_pr_cntr_86();   /* Call syntax parser */
    check_err(error_count, 1);                 /* Check error */
    printf("\n PASS ONE COMPLETE.");

    Create_Headers();        /* проверяем наличие и создаем болванки для хедер-файлов */

    Flag_PASS = !ZERO; /* указываем процедуре select_unit, что это второй проход */

    fskptr(fptr_RCS);                  /* отмотаем исходный файл на начало */

    if (Flag_LIS) {                    /* отматываем листинг */
         fclose(fptr_LIS);
         strcpy(string, BaseOutputFileName);
         strcat(string, ".lis");
         Open_File_W(&fptr_LIS, string);
         fskptr(fptr_LIS);             /* отмотаем листинг на начало */
    }


/*    strcpy(string, BaseOutputFileName);          /* открываем C-file файл */
/*    strcat(string, ".c");
/*    Open_File_W(&fptr_C, string);
*/

    error_count = sem_anal_of_pr_cntr_86(); /* Call semantical analizator */
    check_err(error_count, 2);              /* Check error */
    printf("\n PASS TWO COMPLETE.");
    exit(File_Number);
    return(!ZERO);
    /*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/*    exit(ZERO);*/
};

/****************************************
* проверка на существование файла с именем-параметром
* ВХОД - имя файла
* ВЫХОД - 0 - нет такого файла
*         1 - файл обнаружен
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
* создание файла NAMEext.inc
*   файл с необходимыми стандартными
*   includ'ами h-файлов
*   и всех недостающих файлов
* ВХОД - void
* ВЫХОД - в случае ошибки - диагностика и exit
******************************************/
int Create_Headers (void)
{
char string[BUFFER_LENGTH];

    strcpy(string, BaseOutputFileName);     /* конструируем имя NAMEext.h */
    strcat(string, "ext.inc");
    if (!Is_File_Exist(string)) {             /* существует ли такой файл ? */
         Open_File_W(&fptr_C, string);
         sprintf(string, "#ifndef _%sext_inc\n#define _%sext_inc 1\n", BaseOutputFileName, BaseOutputFileName); /* пользовательский хедер */
         fputs(string, fptr_C);
         sprintf(string, "#include \"%susr1.h\" /* User-defined top include file */\n", BaseOutputFileName); /* пользовательский хедер */
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
         fclose(fptr_C);
    }

    strcpy(string, BaseOutputFileName);     /* конструируем имя NAMEusr1.h */
    strcat(string, "usr1.h");
    if (!Is_File_Exist(string)) {             /* существует ли такой файл ? */
         Open_File_W(&fptr_C, string);
         sprintf(string, "#ifndef _%susr1_h\n#define _%susr1_h 1\n", BaseOutputFileName, BaseOutputFileName); /* пользовательский хедер */
         fputs(string, fptr_C);
         sprintf(string, "/* %sUSR1.H file. Place your code here. */\n/* It will be included at the top of all include-files in every generated file. */\n", BaseOutputFileName); /* пользовательский хедер */
         fputs(string, fptr_C);
         fputs("#endif", fptr_C);
         fclose(fptr_C);
    }

    strcpy(string, BaseOutputFileName);     /* конструируем имя NAMEusr2.h */
    strcat(string, "usr2.h");
    if (!Is_File_Exist(string)) {             /* существует ли такой файл ? */
         Open_File_W(&fptr_C, string);
         sprintf(string, "#ifndef _%susr2_h\n#define _%susr2_h 1\n", BaseOutputFileName, BaseOutputFileName); /* пользовательский хедер */
         fputs(string, fptr_C);
         sprintf(string, "/* %sUSR2.H file. Place your code here. */\n/* It will be included at the bottom of all include-files in every generated file. */\n", BaseOutputFileName); /* пользовательский хедер */
         fputs(string, fptr_C);
         fputs("#endif", fptr_C);
         fclose(fptr_C);
    }

    strcpy(string, BaseOutputFileName);     /* конструируем имя NAMEio.h */
    strcat(string, "io.h");
    if (!Is_File_Exist(string)) {             /* существует ли такой файл ? */
         Open_File_W(&fptr_C, string);
         sprintf(string, "#ifndef _%sio_h\n#define _%sio_h 1\n", BaseOutputFileName, BaseOutputFileName);
         fputs(string, fptr_C);
         sprintf(string, "void Input(void);  /* Reading IO func */\nvoid Output(void); /* Writing IO func */\n", BaseOutputFileName, BaseOutputFileName);
         fputs(string, fptr_C);
         fputs("#endif", fptr_C);
         fclose(fptr_C);
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
    if (error_count != ZERO) { /* если были ошибки при синтаксическом анализе */
         printf("\n%%RCSL-I-NC, No C file produced.");
         if (Flag_LIS) fprintf(fptr_LIS, "\n%%RCSL-I-NC, No C file produced.");
         exit(!ZERO);     /* при ошибке - выход */
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
     fclose(fptr_RCS);                        /* Close files */
	 fclose(fptr_C);
	 fclose(fptr_SYM);
    }
    if (Flag_LIS) {
	 fprintf(fptr_LIS,
	      "\n\n %%RCSL-I-SUMMARY, Completed with %d error(s).",
	      error_count);
	 fclose(fptr_LIS);
    }
    fclose(fptr_RCS);                        /* Close files */
    fclose(fptr_C);
    fclose(fptr_SYM);
    if (error_count != ZERO) exit(ZERO);
    break;
default:
    break;
}
return(!ZERO);
};

