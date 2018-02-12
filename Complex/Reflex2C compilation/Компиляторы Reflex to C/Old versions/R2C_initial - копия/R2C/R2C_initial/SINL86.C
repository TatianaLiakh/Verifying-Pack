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
    InitStructures(); /* Инициализация структур языковых компонентови */
    cl_unit();     /*  инициируем unit (для правильной работы rewunit) */
    cl_spaces();   /*  инициируем spaces (для правильной работы rewunit) */
    if (Flag_LIS) fskptr(fptr_LIS); /* отматываем на начало файл листинга */
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
*  Процедура сравнения лексемы на соответствие
*  вход: name1 - исходная строка
*        name2 - либо указатель, что надо проверять на число
*                либо указатель, что надо проверять на имя
*                либо строка для сравнения
********************************************************/

int compare (char  *name1, char  *name2) {
/*  иначе:  проверка на СОВПАДЕНИЕ двух строк */

    if (!strncmp(name1, name2, NAME_LENGTH-1))
         return(!ZERO);
    return(ZERO);
};

/*=====================================================*/
/*==== сравнение лексемы с резервированным словом =====*/
/*==== вход - лексема =================================*/
/*==== выход - 0 - ничего не найдено ==================*/
/*===        - !0 - номер резервированного слова ======*/
int compare_RW (char  *name) {
    int i;
    for (i = 0; i < RWNUM; i++) {
         if(!strncmp(name, rezword[i], RWLEN)) return(i);
    }
    return(ZERO);
};

/*------------- ПРОВЕРКА НА ЧИСЛО ----------------------*/
int check_digit (char  *name1) {
    int i;
    char *endptr;

    if(!Check_Name_Constant(name1)){ /* если есть в списке констант */
         Con_Value(name1); /* подмена имени на логическое */
         return(TRUE);
    }

    strtod(name1, &endptr); /* попытка преобразовать unit в плав */
    if (endptr[0] == ZERO) return(TRUE); /* удалось? - возврат */

    if (name1[0] != '0'){     /* если десятичное - проверка "nnnn[L]"*/

         if (!isdigit((int)name1[0])) return (FALSE); /* на всякий случай */
                                                    /* ОШИБКА на КРАСМАШЕ */
         if (name1[0] < 0) return(FALSE); /* на всякий случай */
                                                    /* ОШИБКА на КРАСМАШЕ */
         for(i=0;((name1[i]!=0)&&((name1[i+1]!=0)&&(name1[i]!='L')));i++){
	      if(!isdigit((int)name1[i]))
                   return(FALSE);
         }
    }else{                 /* если восьмеричное - проверка "0nnn[L]" */
         if((name1[1]!='X')&&(name1[1]!='x')){
              for(i=0;((name1[i]!=0)&&((name1[i+1]!=0)&&(name1[i]!='L')));i++){
                   if((!isdigit((int)name1[i]))||
                      ((INT8U)name1[i]>(INT8U)'7'))
                             return(FALSE);
              }
            /*  sscanf(name1,"%o",&j); /* НЕ МЕНЯЕМ НИЧЕГО */
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

/*-------------- проверка английского имени --------------------------------*/
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

    switch (level) {              /* промотка наведенных ошибок */
    case PROCESS:
         while (!compare(unit, rezword[RW_PROC])) {   /*  пока не встретится ПРОЦ */
              while (!compare(unit, "}")) {           /*  пока не встретится } */
                   if (!select_unit()) return(ZERO);  /*  конец файла */
              }
              if (!select_unit()) return(ZERO);       /*  конец файла */
         }
         rewunit();
         break;                                       /*  нашли начало процесса */
    case STATE:
         while (!compare(unit, rezword[RW_STATE])) {  /*  пока не встретится СОСТ */
              while (!compare(unit, "}")) {           /*  пока не встретится } */
                   if (!select_unit()) return(ZERO);  /*  конец файла */
              }
              if (!select_unit()) return(ZERO);       /*  конец файла */
         }
         rewunit();
         break;                                       /*  нашли начало состояния */
    case SEMICOLON:
         while (!compare(unit, rezword[RW_SEMICOLON])) {
              if (!select_unit()) return(ZERO);
         }
         break;                                       /*  нашли начало строки */
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
    switch (level) {              /* промотка наведенных ошибок */
    case PROCESS:
         while (!compare(unit, rezword[RW_PROC])) {   /*  пока не встретится ПРОЦ */
              while (!compare(unit, "}")) {           /*  пока не встретится } */
                   if (!select_unit()) return(ZERO);  /*  конец файла */
              }
              if (!select_unit()) return(ZERO);       /*  конец файла */
         }
         rewunit();
         break;                                       /*  нашли начало процесса */
    case STATE:
         while (!compare(unit, rezword[RW_STATE])) {  /*  пока не встретится СОСТ */
              while (!compare(unit, "}")) {           /*  пока не встретится } */
                   if (!select_unit()) return(ZERO);  /*  конец файла */
              }
              if (!select_unit()) return(ZERO);       /*  конец файла */
         }
         rewunit();
         break;                                       /*  нашли начало состояния */
    case SEMICOLON:
         while (!compare(unit, rezword[RW_SEMICOLON])) {
              if (!select_unit()) return(ZERO);
         }
         break;                                       /*  нашли начало строки */
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
     if (compare(unit, ALT_rezword[RW_PROGR])) { /*  по-русски? - инициализируем русским */
         for (i=0; i < RWNUM; i++) {
              strncpy(rezword[i], ALT_rezword[i], RWLEN);
         }
         for (i=0; i < ERRMSGNUM; i++) {
              strncpy(error_array[i], ALT_error_array[i], ERRMSGLEN);
         }
     } else {         /* иначе инициализируем английским: */
         for (i = 0; i < ERRMSGNUM; i++) {
              strncpy(error_array[i], ALT_error_array[i], ERRMSGLEN);
         }
         if (compare(unit, ENG_rezword[RW_PROGR])) { /* слово Прогр по английски? */
              for (i=0; i < RWNUM; i++) {               /* - инициализируем английским */
                   strncpy(rezword[i], ENG_rezword[i], RWLEN);
              }
         } else {
              error_msg(1, line_count, unit, NONE); /* не обнаружено слово Прогр */
              while (!compare(unit, rezword[RW_PROGR])) /* ищем слово "Прогр"*/
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
 * ВОЗВРАТ: 0 - Конец файла
 *         !0 - Обработано, Возможно Ошибка.
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
 * Обработка описаний констант и перечислений
 * ВОЗВРАТ: 0 - Конец файла
 *         !0 - Обработано, Возможно Ошибка.
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
              switch (Constant_Expression_Body()) {  /* разбор выражения */
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
         case RW_ENUM:  /* "ПЕРЕЧИСЛЕНИЕ" */
              if (!select_unit()) return(ZERO);   /* { */
              if (!compare(unit, "{")) {
                   if (!error_msg(18, line_count, unit, SEMICOLON)) return(ZERO);
                   continue;
              }
              switch (Constant_Enum_Body()) {  /* разбор перечисления */
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
 * обработка описания тела ПЕРЕЧИСЛЕНИЯ
 *  ВХОД - по умолчанию
 *  unit V
 *   {     имя константы  ------------------->
 *                       -> = выражение ->
 *       <----------------- , <------------
 *  RETURN: EOF   (обнаружен конец файла)
 *          OK    (обработано без ошибки)
 *          ERROR (NONE) Нужно отматывать ч/з Find_Position
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
              case RW_EQU:  /* "=" */ /* присваивание значения константе */
                   if (!select_unit()) return(ZERO);
                   switch (Constant_Expression_Body()) {  /* разбор выражения */
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
              case RW_COMMA:  /* "," */ /* новая константа в перечислении */
                   continue;
              default:       /* что-то непонятное... конец перечисления ? */
                   rewunit();
                   return(!ZERO);
         } /* end of switch */
    } /* end of for */
};


/********************************************
 * обработка описания выражения для константы
 *  ВХОД - по умолчанию
 *  unit      V
 *  что-то
 *   префикс терм постфикс
 *          инфикс
 *  RETURN: EOF   (обнаружен конец файла)
 *          OK    (обработано без ошибки)
 *          ERROR (NONE) Нужно отматывать ч/з Find_Position
 ************************************************/
/* обработка описания выражения */
int    Constant_Expression_Body (void)
{
#ifdef TEST_MODE
    printf("\n==== Constant_Expression_Body");
#endif
    for (;;) {          /* ВНИМАНИЕ! по входу в unit уже что-то загружено */
         for (;;) {     /* обработка префикса */
              switch (Constant_Prefix_Body()) {
                   case ZERO:               /* EOF */
                        return(ZERO);
                   case ERROR:              /* Error */
                        return(ERROR);
                   default:                 /* это был декларатор (префикс) */
                        if (!select_unit()) return(ZERO);  /* заряжаем unit */
                        continue;           /* и снова обработка префикса */
                   case NONSTATEMENT:       /* это не префикс (а терм) */
                        break;
              }
              break;                        /* выход из цикла обработки префиксов */
         }

         switch (Constant_Term_Body()) {        /* Обработка терма - всегда один */
              case ZERO:               /* EOF */
                   return(ZERO);
              case ERROR:              /* Error */
                   return(ERROR);
              default:                 /* все в порядке */
                   break;
         }

         if (!select_unit()) return(ZERO);  /* заряжаем unit */
         switch (Constant_Infix_Body()) {       /* Обработка инфикса */
              case ZERO:               /* EOF */
                   return(ZERO);
              case ERROR:              /* Error */
                   return(ERROR);
              default:                 /* все в порядке */
                   if (!select_unit()) return(ZERO);  /* заряжаем unit */
                   break;
              case NONSTATEMENT:       /* это не инфикс */
                   return (!ZERO);
         }
    }    /* end of for */
};

/********************************************
 *  обработка Constant_инфикса
 *  ВХОД - по умолчанию
 *  unit      V
 *  что-то
 *   префикс терм постфикс
 *          инфикс
 *  RETURN: EOF   (обнаружен конец файла)
 *          OK    (обработано без ошибки, это инфикс)
 *          ERROR (NONE) Нужно отматывать ч/з Find_Position (?)
 *          NONSTATEMENT  - это не инфикс (конец выражения)
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
 *  обработка Constant_терма
 *  ВХОД - по умолчанию
 *  unit          V
 *  константа | ( выражение )
 *
 *
 *  RETURN: EOF   (обнаружен конец файла)
 *          OK    (обработано без ошибки, это терм)
 *          ERROR (NONE) Нужно отматывать ч/з Find_Position
 *          NONSTATEMENT  - это не терм (?)
 ************************************************/
int Constant_Term_Body (void) {
#ifdef TEST_MODE
    printf("\n===== Constant_Term_Body");
#endif
    if (compare(unit, rezword[RW_OPEN_PARENTESIS])) { /* ( выражение ) ? */
         if (!select_unit()) return(ZERO);            /* заряжаем unit */
         switch (Constant_Expression_Body()) {                 /* разбор выражения */
              case ERROR:         /* Error */
                   return(ERROR);
              case ZERO:          /* EOF */
                   return(ZERO);
              default:
                   break;
         } /* end of switch */
         if (!compare(unit, rezword[RW_CLOSE_PARENTESIS])) {
              error_msg(21, line_count, unit, NONE);       /* д.б. ) */
              return(ERROR);
         }
    } else {
          /* иначе проверяем имя константы */
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
 *  обработка Constant_префикса
 *  ВХОД - по умолчанию
 *  unit      V
 *  что-то
 *   префикс терм постфикс
 *          инфикс
 *  RETURN: EOF   (обнаружен конец файла)
 *          OK    (обработано без ошибки, это префикс)
 *          ERROR (NONE) Нужно отматывать ч/з Find_Position (?)
 *          NONSTATEMENT  - это не префикс
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
 * Обработка описаний констант и перечислений
 * ВОЗВРАТ: 0 - Конец файла
 *         !0 - Обработано, Возможно Ошибка.
 *
 ************************************************/
int Function (void)
{
#ifdef TEST_MODE
        printf("\n= Function");
#endif
    for (;;) {
         if (!select_unit()) return(ZERO);
         if (compare(unit, rezword[RW_FUNCTION])) { /* описание функции ? */

              switch (Func_Declarator_Body()) { /* тип функции */
                   case ZERO:               /* EOF */
                        return(ZERO);
                   case ERROR:              /* Error */
                        if(!Find_Position(SEMICOLON)) return(ZERO);
                        continue;
                   case NONSTATEMENT:       /* это не декларатор? - ошибка */
                        if(!error_msg(73, line_count, unit, SEMICOLON)) return(ZERO); /* ожидается декларатор */
                        continue;
                   default:                 /* это был декларатор */
                        break;
              } /* end of switch */

              if (!select_unit()) return(ZERO);
              if (!check_eng_name(unit)) {          /* имя C-функции ? */
                   if (!error_msg(69, line_count, unit, SEMICOLON)) return(ZERO);
                   continue;
              }
              if (!CheckFunc(unit)) {              /* exist ? */
                   if (!error_msg(70, line_count, unit, NONE)) return(ZERO);
              }

              if (!select_unit()) return(ZERO); /* открывающая скобка */
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
                   default:                 /* это был декларатор */
                        break;
              } /* end of switch */

              if (!select_unit()) return(ZERO); /* закрывающая скобка */
              if (!compare(unit, ")")) {
                   if(!error_msg(21, line_count, unit, SEMICOLON)) return(ZERO);
                   continue;
              }

              if (!select_unit()) return(ZERO);  /* ; */
              if (!compare(unit, rezword[RW_SEMICOLON]))
                   error_msg(10, line_count, unit, SEMICOLON); /* не обнаружен конец строки */
              continue;
         } else {
              rewunit();
              return(!ZERO);
         }
    } /* end of for */
};

/********************************************
 * обработка описания аргументов функции
 *  ВХОД - по умолчанию
 *  unit        V
 *   АРГУМЕНТЫ ------>    декларатор ------------------->
 *              <----------------- , <------------
 *
 *  RETURN: EOF   (обнаружен конец файла)
 *          OK    (обработано без ошибки)
 *          ERROR (NONE) Нужно отматывать ч/з Find_Position
 ************************************************/
int Func_Args_Declarator_Body (void)
{
#ifdef TEST_MODE
        printf("\n== Func_Args_Declarator_Body");
#endif
    for (;;) {
         if (!select_unit()) return(ZERO);
         switch (compare_RW(unit)) {
              case RW_SEMICOLON:         /* rezword[RW_SEMICOLON] */ /* присваивание значения константе */
              case RW_CLOSE_PARENTESIS:  /* ")" */ /* присваивание значения константе */
                   rewunit();
                   return(!ZERO);
              case RW_COMMA:     /* "," */ /* новая константа в перечислении */
                   continue;
              default:       /* что-то непонятное... конец перечисления ? */
                   rewunit();
                   switch (Func_Declarator_Body()) {  /* разбор декларатора */
                        case ERROR:         /* Error */
                             return(ERROR);
                        case ZERO:          /* EOF */
                             return(ZERO);
                        case NONSTATEMENT:       /* это не декларатор? - ошибка */
                             error_msg(73, line_count, unit, NONE); /* ожидается декларатор */
                             return(ERROR);
                        default:
                             if (!select_unit()) return(ZERO);
                             if (compare(unit, ")") &&
                                 compare(prev_unit, rezword[RW_VOID])
                                 && (GetCurFuncArgNum() == 0)) {
/* TEST !!!  printf("! void func - \n%s \n unit is %s - \nprev is %s", buffer1, unit, prev_unit);        /* если (void) - число аргументов - 0 */
                             } else {
                                  AddNewArgInCurFunc(); /* добавим аргумент */
                             }
                             rewunit();
                             continue;
                   } /* end of switch */
         } /* end of switch */
    } /* end of for */
};

/********************************************
 * обработка декларатора функции
 *  ВХОД - по умолчанию
 *  unit V
 *        SHORT | LONG | INT | FLOAT | DOUBLE ...
 *
 * decl_case - случай декларатора
 *   RW_TYPE - декларатор типа функции
 *   RW_ARGUMENTS - декларатор аргумента функции
 *
 * указатель Current_Function указывает на текущую функцию
 *
 *  RETURN: EOF   (обнаружен конец файла)
 *          OK    (обработан декларатор)
 *          ERROR (NONE) Нужно отматывать ч/з Find_Position
 *          NONSTATEMENT - это не декларатор unit = (
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
         default:             /*  это не декларатор */
              rewunit();
              return(NONSTATEMENT);
    }
}
/********************************************
 *  обработка сылки после целочисленного декларатора
 *  ВХОД - по умолчанию
 *                     unit   V
 *  (     SHORT | LONG | INT    * ) | )
 *
 *  RETURN: EOF   (обнаружен конец файла)
 *          OK    (обработан декларатор)
 *          ERROR (NONE) Нужно отматывать ч/з Find_Position
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
 * обработка префикса после целочисленного декларатора
 *  ВХОД - по умолчанию
 *                     unit   V
 *  (     SHORT | LONG | INT    SIGN ) | UNSIGN ) | ) | SIGN *) | UNSIGN *)
 *
 *  RETURN: EOF   (обнаружен конец файла)
 *          OK    (обработан декларатор)
 *          ERROR (NONE) Нужно отматывать ч/з Find_Position
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
 * обработка префикса после знакового декларатора
 *  ВХОД - по умолчанию
 *         unit       V
 *  (  SIGN | UNSIGN   SHORT) | LONG) | INT)
 *
 *  RETURN: EOF   (обнаружен конец файла)
 *          OK    (обработан декларатор)
 *          ERROR (NONE) Нужно отматывать ч/з Find_Position
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
 * ВОЗВРАТ: 0 - Конец файла
 *         !0 - Обработано, Возможно Ошибка.
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
* Разбор строки-описания входного регистра
* на выходе - 0 - конец файла,
*             !0 - указатель на ;
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
    if(!check_digit(unit)){                       /* адрес по СШ */
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

/* Разбор строки-описания выходного регистра
* на выходе - 0 - конец файла,
*             !0 - указатель на ;
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
    Output_Group_MB_Address(unit);             /* уст. адреса по СШ */
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
* Разбор строки-описания регистра в ОЗУ
*  на выходе - 0 - конец файла,
*             !0 - указатель на ;
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
 * ВОЗВРАТ: 0 - Конец файла
 *         !0 - Обработано, Возможно Ошибка.
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
         error_msg(36, line_count, unit, NONE); /* дублирование имени !*/
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
 * ВОЗВРАТ: 0 - Конец файла
 *         !0 - Обработано, Возможно Ошибка.
 ************************************************/
int Variable_List (void) {
int i;
#ifdef TEST_MODE
        printf("\n== Variable_List");
#endif
    for (;;) {                              /* обработаем все переменные */
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
         if (!compare(unit, rezword[RW_SEMICOLON])) { /* конец строки ? */
              if (!error_msg(10, line_count, unit, SEMICOLON)) return(ZERO);
              return(!ZERO);
         }
    } /* end of for */
};

/************************************************
 *             --- Local_Var ---
 * ВОЗВРАТ: 0 - Конец файла
 *         !0 - Обработано, Возможно Ошибка.
 *          указатель на ; unit = ";"
 ************************************************/
int Local_Var (void)
{
#ifdef TEST_MODE
        printf("\n==== Local_Var");
#endif
    ForProc_LOCAL();   /* инициализация типа доступа */
    MakeBeforeFor();   /* иницализация типа доступа всех переменных строки */
    if (!select_unit()) return(ZERO); /* for ; simbol */
    if (!compare(unit, rezword[RW_SEMICOLON]))
         if (!error_msg(10, line_count, unit, SEMICOLON)) return(ZERO);
    return(!ZERO);
};

/************************************************
 *              --- ForVar ---
 * ВОЗВРАТ: 0 - Конец файла
 *         !0 - Обработано, Возможно Ошибка.
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
                   if (!check_name(unit)) {        /* имя процесса? */
                        if (!error_msg(27, line_count, unit, SEMICOLON)) return(ZERO);
                        return(!ZERO);
		   }
                   ForProc(unit);                     /* внесем в список разрешенных */
                   if (!select_unit()) return(ZERO);
                   if (!compare(unit, ",")) break;    /* конец перечислению ? */
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
 * Обработка строк - описаний переменных процесса
 * LOG INT LONG SHORT FLOAT DOUBLE
 * RETURN: ERROR - set on ';'
 * RETURN: ZERO  - EOF
 * RETURN: !ZERO - OK
 * ВЫХОД - указатель на ;
 ************************************************/
int Discr_Var (int var_type)
{
char  port_name[BUFFER_LENGTH];
#ifdef TEST_MODE
        printf("\n=== Discr_Var");
#endif
    if (!select_unit()) return(ZERO);
    if (!check_name(unit)) {                  /* проверяем на имя */
         if (!error_msg(54, line_count, unit, SEMICOLON)) return(ZERO);
         return(ERROR);
    }
    if (!CheckVariable(unit, var_type)) {       /* проверяем на существование */
         if (!error_msg(38, line_count, unit, SEMICOLON)) return(ZERO);
         return(ERROR);
    }
    if (!select_unit()) return(ZERO);
    if (compare(unit, "=")) {  /* если физич. образ - разбор физ. образа */
         if ((var_type == RW_FLOAT) ||
              (var_type == RW_DOUBLE)) {   /*  не бывает физических образов */
              error_msg(65, line_count, unit, SEMICOLON);
              return(ERROR);
         }
         if (!select_unit()) return(ZERO);
         if (!compare(unit, "{")){
              if (!error_msg(18, line_count, unit, SEMICOLON)) return(ZERO);
              return(ERROR);
         }
         for (;;) {                         /* разбор привязки к физ. портам */
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
              if (!InitVariable(port_name, atoi(unit))) { /*  Пока по-старому */
                   if (!error_msg(35, line_count, unit, SEMICOLON)) return(ZERO);
                   return(ERROR);
              }
              if (!select_unit()) return(ZERO);
              if (!compare(unit, "]")) {
                   if (!error_msg(31, line_count, unit, SEMICOLON)) return(ZERO);
                   return(ERROR);
              }
              if (!select_unit()) return(ZERO);
              if (!compare(unit, ",")) break;    /* конец привязки переменной к портам */
         }
         if (!compare(unit, "}")) {              /* замыкающая фигурная скобка */
              if (!error_msg(61, line_count, unit, SEMICOLON)) return(ZERO);
              return(ERROR);
         }
         if (!select_unit()) return(ZERO);  /* for LOCAL or FOR */
    }   /* конец разбора физ-образа. далее просто разбор степени доступа */
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
 * Обработка описания переменных, описанных в других процессах
 * ПРОЦ -> имя процесса -> имя переменной ->
 *                       <----- , -------/
 * RETURN: ERROR - set on ';'
 * RETURN: ZERO  - EOF
 * RETURN: !ZERO - OK
 * ВЫХОД - указатель на ;
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
 * ВОЗВРАТ: 0 - Конец файла
 *         !0 - Обработано, Возможно Ошибка.
 ************************************************/
INT16S State (void)
{
#ifdef TEST_MODE
        printf("\n== State");
#endif
    if (!select_unit()) return(ZERO);
    while (compare(unit, rezword[RW_STATE])) {   /* слово СОСТ? */
         if (!select_unit()) return(ZERO);
         if (!check_name(unit)) {             /* имя соcтояния? */
              if (!error_msg(22, line_count, unit, STATE)) return(ZERO);
              continue;
         }
         if (!Check_State(unit)) {               /* существует такое? */
              error_msg(37, line_count, unit, NONE);
         }
         if (!select_unit()) return(ZERO);
         if (!compare(unit, "{")) {  /* body of state */
              if (!error_msg(18, line_count, unit, STATE)) return(ZERO);
              if (!select_unit()) return(ZERO);
              continue;                /* новый виток состояния */
         }
         JmpFlag = ZERO;               /*  Флаг наличия выходов из состояния */
         if (!select_unit()) return(ZERO);
         if (compare(unit, rezword[RW_TIMEOUT])) {    /* ТАЙМАУТ ?*/
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
         } else {                           /* если не ТАЙМАУТ */
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
              continue;                /* новый виток состояния */
         }
         if (JmpFlag == ZERO) { /* проверка зацикливания и предупреждение */
               if (!error_msg(79, line_count, "\0", NONE))
                   return(ZERO);
         }
         if (!select_unit()) return(ZERO); /*  для следующего витка д.б. слово СОСТ */
    } /* end of while STATE */
    rewunit();
    return(!ZERO);
};
/************************************************
 *             --- State_Body ---
 *  RETURN: EOF   ()
 *          OK    (})
 *          ERROR (NONE) Нужно отматывать ч/з Find_Position
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
              case NONSTATEMENT:       /* встретилось неутверждение -  конец */
                   return(!ZERO);
              default:                 /* NO ERROR */
                   break;              /* check for next state */
         } /* end of switch */
    }
};

/************************************************
 *  Разбор утверждения
 *  RETURN: EOF   (обнаружен конец файла)
 *          OK    (обработано без ошибки)
 *          NONSTATEMENT  (это не утверждение)
 *          ERROR (NONE) Нужно отматывать ч/з Find_Position
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
              if (compare(unit, rezword[RW_ELSE])) {  /* Пост-условие? */
                   switch (Post_Condition_Body()) {   /* ELSE statement */
                        case ERROR:              /* Error */
                             return(ERROR);
                        case ZERO:               /* EOF */
                             return(ZERO);
                   default:
                        break;
                   } /* end of switch */
              } else {
                   rewunit(); /* если не пост-условие - отматываем назад */
              }
              break;
         case RW_STOP:
              switch (Stop_Body()) {   /* STOP ; | PROC имя процесса ; */
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
              switch (Error_Body()) {  /* ERROR ; | PROC имя процесса ; */
                   case ERROR:         /* Error */
                        return(ERROR);
                   case ZERO:          /* EOF */
                        return(ZERO);
                   default:            /* NO ERROR */
                        break;
              } /* end of switch */
              break;
         case RW_START:
              switch (Start_Body()) {  /* START PROC имя процесса ; */
                   case ERROR:         /* Error */
                        return(ERROR);
                   case ZERO:          /* EOF */
                        return(ZERO);
                   default:
                        break;
              } /* end of switch */
              break;
         case RW_IN:
              switch (In_Body()) {     /* IN STATE NEXT | имя состояния ; */
                   case ERROR:         /* Error */
                        return(ERROR);
                   case ZERO:          /* EOF */
                        return(ZERO);
                   default:
                        break;
              } /* end of switch */
              break;
         case RW_TIMEOUT:              /*  если ТАЙМАУТ */
         case RW_CLOSE_BRACE:          /* или "}" */
         case RW_BREAK:                /* или КОНЕЦ (в РАЗБОРе) */
         case RW_DEFAULT:              /* или УМОЛЧАНИЕ (в РАЗБОРе) */
         case RW_CASE:                 /* или СЛУЧАЙ (в РАЗБОРе) */
              rewunit();               /* отматываем -  и выход */
              return(NONSTATEMENT);
         default: /*  в непонятном случае - пытаемся разобрать выражение */
              switch (Expression_Body()) {  /* разбор выражения */
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
 *  обработка описания условия
 *  ВХОД - после обнаружения рез.слова ЕСЛИ
 *  unit V
 *  ЕСЛИ ( выражение ) утверждение
 *  RETURN: EOF   (обнаружен конец файла)
 *          OK    (обработано без ошибки)
 *          ERROR (NONE) Нужно отматывать ч/з Find_Position
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

    if (!select_unit()) return(ZERO);            /* заряжаем unit */
    if ((i = Expression_Body()) != !ZERO) return(i);  /* if IF ( выражение ) */
    if (!compare(unit,")")){
         error_msg(21, line_count, unit, NONE);
         return(ERROR);
    }
    switch (Statement_Body()) {       /* Statement  */
         case ZERO:               /* EOF */
              return(ZERO);
         case ERROR:              /* Error in string set on new STATE */
         case NONSTATEMENT:       /* встретилось неутверждение */
              error_msg(68, line_count, unit, NONE);
              return(ERROR);
         default:                 /* NO ERROR */
              return(!ZERO);
    } /* end of switch */
}

/********************************************
 * обработка описания пост-условия
 *  ВХОД - после обнаружения рез.слова ИНАЧЕ
 *  unit  V
 *  ИНАЧЕ утверждение
 *  RETURN: EOF   (обнаружен конец файла)
 *          OK    (обработано без ошибки)
 *          ERROR (NONE) Нужно отматывать ч/з Find_Position
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
         case NONSTATEMENT:       /* встретилось неутверждение */
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
 * обработка описания СТОП
 *  ВХОД - после обнаружения рез.слова СТОП
 *  unit V
 *  СТОП  <ПРОЦ (имя процесса)> ; (если просто СТОП; - для текущего)
 *  RETURN: EOF   (обнаружен конец файла)
 *          OK    (обработано без ошибки)
 *          ERROR (NONE) Нужно отматывать ч/з Find_Position
 ************************************************/
int    Stop_Body (void)
{
#ifdef TEST_MODE
    printf("\n==== Stop_Body");
#endif
    if (!select_unit()) return(ZERO);
    switch (compare_RW(unit)) {
         case RW_PROC:                           /* ПРОЦ */
              if (!select_unit()) return(ZERO);
              if (!check_name(unit)) {        /* имя процесса */
                   error_msg(11, line_count, unit, NONE);
                   return(ERROR);
              }
              if (!select_unit()) return(ZERO);   /* ; */
              if (!compare(unit, rezword[RW_SEMICOLON])) {
                   error_msg(10, line_count, unit, NONE);
                   return(ERROR);
              }
              break;
         case RW_SEMICOLON:            /* знак ";" => для текущего процесса */
                   JmpFlag = !ZERO;     /*  Флаг наличия выходов из состояния */
              break;
         default:                 /*  иначе - ошибка спецификации процесса */
              error_msg(23, line_count, unit, NONE);
              return(ERROR);
    } /* end of switch */
    return(!ZERO);
};

/********************************************
 * обработка описания ЗАЦИКЛИТЬ
 *  ВХОД - после обнаружения рез.слова ЗАЦИКЛИТЬ
 *  unit V
 *  ЗАЦИКЛИТЬ  ; 
 *  RETURN: EOF   (обнаружен конец файла)
 *          OK    (обработано без ошибки)
 *          ERROR (NONE) Нужно отматывать ч/з Find_Position
 ************************************************/
int    Loop_Body (void)
{
#ifdef TEST_MODE
    printf("\n==== Loop_Body");
#endif
    if (!select_unit()) return(ZERO);
    switch (compare_RW(unit)) {
         case RW_SEMICOLON:            /* знак ";" => для текущего процесса */
                   JmpFlag = !ZERO;     /*  Флаг наличия выходов из состояния */
              break;
         default:                 /*  иначе - ошибка спецификации процесса */
              error_msg(10, line_count, unit, NONE);
              return(ERROR);
    } /* end of switch */
    return(!ZERO);
};

/********************************************
 * обработка описания ОШИБКА
 *  ВХОД - после обнаружения рез.слова ОШИБКА
 *  unit   V
 *  ОШИБКА  <ПРОЦ (имя процесса)> ; (если просто ОШИБКА; - для текущего)
 *  RETURN: EOF   (обнаружен конец файла)
 *          OK    (обработано без ошибки)
 *          ERROR (NONE) Нужно отматывать ч/з Find_Position
 ************************************************/
int    Error_Body (void)
{
#ifdef TEST_MODE
    printf("\n==== Error_Body");
#endif
    if (!select_unit()) return(ZERO);
    switch (compare_RW(unit)) {
         case RW_PROC:                           /* ПРОЦ */
              if (!select_unit()) return(ZERO);
              if (!check_name(unit)) {        /* имя процесса */
                   error_msg(11, line_count, unit, NONE);
                   return(ERROR);
              }
              if (!select_unit()) return(ZERO);   /* ; */
              if (!compare(unit, rezword[RW_SEMICOLON])) {
                   error_msg(10, line_count, unit, NONE);
                   return(ERROR);
              }
              break;
         case RW_SEMICOLON:       /* знак ";" => для текущего процесса */
                   JmpFlag = !ZERO;     /*  Флаг наличия выходов из состояния */
              break;
         default:                 /*  иначе - ошибка спецификации процесса */
              error_msg(23, line_count, unit, NONE);
              return(ERROR);
    } /* end of switch */
    return(!ZERO);
};

/********************************************
 * обработка описания СТАРТ
 *  ВХОД - после обнаружения рез.слова СТАРТ
 *  unit   V
 *  СТАРТ   <ПРОЦ (имя процесса)> ; (если просто СТАРТ; - для текущего)
 *  RETURN: EOF   (обнаружен конец файла)
 *          OK    (обработано без ошибки)
 *          ERROR (NONE) Нужно отматывать ч/з Find_Position
 ************************************************/
int    Start_Body (void)
{
#ifdef TEST_MODE
    printf("\n==== Start_Body");
#endif
    if (!select_unit()) return(ZERO);
    switch (compare_RW(unit)) {
         case RW_PROC:                           /* ПРОЦ */
              if (!select_unit()) return(ZERO);
              if (!check_name(unit)) {        /* имя процесса */
                   error_msg(11, line_count, unit, NONE);
                   return(ERROR);
              }
              if (!select_unit()) return(ZERO);   /* ; */
              if (!compare(unit, rezword[RW_SEMICOLON])) {
                   error_msg(10, line_count, unit, NONE);
                   return(ERROR);
              }
              break;
         case RW_SEMICOLON:       /* знак ";" => для текущего процесса */
                   JmpFlag = !ZERO;     /*  Флаг наличия выходов из состояния */
              break;
         default:                 /*  иначе - ошибка спецификации процесса */
              error_msg(23, line_count, unit, NONE);
              return(ERROR);
    } /* end of switch */
    return(!ZERO);
};

/********************************************
 * обработка описания В СОСТ
 *  ВХОД - после обнаружения рез.слова В
 *  unit  V
 *  В      <СОСТ   имя состояния>|<СЛЕДУЮЩЕЕ> ;
 *  RETURN: EOF   (обнаружен конец файла)
 *          OK    (обработано без ошибки)
 *          ERROR (NONE) Нужно отматывать ч/з Find_Position
 ************************************************/
int    In_Body (void)
{
#ifdef TEST_MODE
    printf("\n==== In_Body");
#endif
    JmpFlag = !ZERO;     /*  Флаг наличия выходов из состояния */
    if (!select_unit()) return(ZERO);
    switch (compare_RW(unit)) {
         case RW_STATE:                           /* СОСТ */
              if (!select_unit()) return(ZERO);
              if (!check_name(unit)) {        /* имя состояния */
                   error_msg(22, line_count, unit, NONE);
                   return(ERROR);
              }
              if (!select_unit()) return(ZERO);   /* ; */
              if (!compare(unit, rezword[RW_SEMICOLON])) {
                   error_msg(10, line_count, unit, NONE);
                   return(ERROR);
              }
              break;
	 case RW_NEXT:       /* СЛЕДУЮЩЕЕ => следующее состояние процесса */
              if (!select_unit()) return(ZERO);   /* ; */
              if (!compare(unit, rezword[RW_SEMICOLON])) {
                   error_msg(10, line_count, unit, NONE);
                   return(ERROR);
              }
              break;
         default:                 /*  иначе - ошибка спецификации состояния */
              error_msg(56, line_count, unit, NONE);
              return(ERROR);
    } /* end of switch */
    return(!ZERO);
};


/********************************************
 * обработка описания РАЗБОР
 *  ВХОД - после обнаружения рез.слова РАЗБОР
 *  unit   V
 *  РАЗБОР   ( выражение ) {
 *      СЛУЧАЙ константа :
 *             утверждение
 *             КОНЕЦ;
 *      УМОЛЧАНИЕ:
 *             утверждение
 *             КОНЕЦ;
 *  }
 *  RETURN: EOF   (обнаружен конец файла)
 *          OK    (обработано без ошибки)
 *          ERROR (NONE) Нужно отматывать ч/з Find_Position
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

    if (!select_unit()) return(ZERO);            /* заряжаем unit */
    if ((i= Expression_Body()) != !ZERO) return(i);  /* РАЗБОР ( выражение ) */
    if (!compare(unit,")")){
         error_msg(21, line_count, unit, NONE);
         return(ERROR);
    }
    if (!select_unit()) return(ZERO);                 /* for { symbol */
    if (!compare(unit, "{")) {
         error_msg(18, line_count, unit, NONE);
         return(ERROR);
    }

    for (;;) {         /* разбор внутренностей РАЗБОР () */
         switch (Case_Body()) {        /* внутренности РАЗБОРа */
              case ZERO:               /* EOF */
                   return(ZERO);
              case ERROR:              /* Error in string set on new STATE */
                   return(ERROR);
              case NONSTATEMENT:       /* встретилось неутверждение - } */
		   break;
	      default:                 /* NO ERROR - продолжаем обработку внутренностей */
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
 * обработка описания РАЗБОР
 *  ВХОД - после обнаружения {
 *                        unit   V
 *  РАЗБОР   ( выражение ) {
 *      СЛУЧАЙ константа :
 *             утверждение
 *             КОНЕЦ;
 *      УМОЛЧАНИЕ:
 *             утверждение
 *             КОНЕЦ;
 *
 *  }
 *  RETURN: EOF   (обнаружен конец файла)
 *          OK    (обработано без ошибки)
 *          ERROR (NONE) Нужно отматывать ч/з Find_Position
 ************************************************/
 int Case_Body (void)
 {
#ifdef TEST_MODE
    printf("\n==== Case_Body");
#endif
    if (!select_unit()) return(ZERO);
    switch (compare_RW(unit)) {
         case RW_CASE:                           /* СЛУЧАЙ */
              if (!select_unit()) return(ZERO);  /* константа */
              if (!check_digit(unit)) {       /* ? */
                   error_msg(50, line_count, unit, NONE);
                   return(ERROR);
              }
              if (!select_unit()) return(ZERO);
              if (!compare(unit, ":")) {        /* двоеточие */
                   error_msg(66, line_count, unit, NONE);
                   return(ERROR);
              }

              switch (State_Body()) {       /* State {} */
                   case ERROR:              /* Error */
                        return(ERROR);
                   case ZERO:               /* EOF */
                        return(ZERO);
                   default:                 /* идем дальше */
                        break;
              } /* end of switch */
              if (!select_unit()) return(ZERO);       /* проверим, что дальше */
              if (compare(unit, rezword[RW_BREAK])) { /* КОНЕЦ (break) */
                   if (!select_unit()) return(ZERO);  /* ; */
                   if (!compare(unit, rezword[RW_SEMICOLON])) {
                        error_msg(10, line_count, unit, NONE);
                        return(ERROR);
                   }
              } else {                      /* иначе вернем все на место */
                   rewunit();
              }
              break;
         case RW_DEFAULT:                        /* УМОЛЧАНИЕ */
              if (!select_unit()) return(ZERO);
              if (!compare(unit, ":")) {        /* двоеточие */
                   error_msg(66, line_count, unit, NONE);
                   return(ERROR);
              }

              switch (State_Body()) {       /* State {} */
                   case ERROR:              /* Error */
                        return(ERROR);
                   case ZERO:               /* EOF */
                        return(ZERO);
                   default:                 /* идем дальше */
                        break;
              } /* end of switch */

              if (!select_unit()) return(ZERO);       /* проверим, что дальше */
              if (compare(unit, rezword[RW_BREAK])) { /* КОНЕЦ (break) */
                   if (!select_unit()) return(ZERO);  /* ; */
                   if (!compare(unit, rezword[RW_SEMICOLON])) {
                        error_msg(10, line_count, unit, NONE);
                        return(ERROR);
                   }
              } else {                      /* иначе вернем все на место */
                   rewunit();
              }
              break;
         default:                 /*  иначе - ошибка спецификации состояния */
              rewunit();
              return(NONSTATEMENT);       /* встретилось что-то непонятное */
    } /* end of switch */
    return(!ZERO);
 };

/********************************************
 * обработка описания выражение
 *  ВХОД - по умолчанию
 *  unit      V
 *  что-то
 *   префикс терм постфикс
 *          инфикс
 *  RETURN: EOF   (обнаружен конец файла)
 *          OK    (обработано без ошибки)
 *          ERROR (NONE) Нужно отматывать ч/з Find_Position
 ************************************************/
/* обработка описания выражения */
int    Expression_Body (void)
{
#ifdef TEST_MODE
    printf("\n==== Expression_Body");
#endif
    for (;;) {          /* ВНИМАНИЕ! по входу в unit уже что-то загружено */
         for (;;) {     /* обработка префикса */
              switch (Prefix_Body()) {
                   case ZERO:               /* EOF */
                        return(ZERO);
                   case ERROR:              /* Error */
                        return(ERROR);
                   default:                 /* это был декларатор (префикс) */
                        if (!select_unit()) return(ZERO);  /* заряжаем unit */
                        continue;           /* и снова обработка префикса */
                   case NONSTATEMENT:       /* это не префикс (а терм) */
                        break;
              }
              break;                        /* выход из цикла обработки префиксов */
         }

         switch (Term_Body()) {        /* Обработка терма - всегда один */
              case ZERO:               /* EOF */
                   return(ZERO);
              case ERROR:              /* Error */
                   return(ERROR);
              default:                 /* все в порядке */
                   break;
         }

         if (!select_unit()) return(ZERO);  /* заряжаем unit */
         switch (Postfix_Body()) {
              case ZERO:               /* EOF */
                   return(ZERO);
              case ERROR:              /* Error */
                   return(ERROR);
              default:                 /* это был постфикс */
                   if (!select_unit()) return(ZERO);  /* заряжаем unit */
                   break;
              case NONSTATEMENT:       /* это не постфикс */
                   break;
         }

         switch (Infix_Body()) {       /* Обработка инфикса */
              case ZERO:               /* EOF */
                   return(ZERO);
              case ERROR:              /* Error */
                   return(ERROR);
              default:                 /* все в порядке */
                   if (!select_unit()) return(ZERO);  /* заряжаем unit */
                   break;
              case NONSTATEMENT:       /* это не инфикс */
                   return (!ZERO);
         }
    }    /* end of for */
};
/********************************************
 *  обработка инфикса
 *  ВХОД - по умолчанию
 *  unit      V
 *  что-то
 *   префикс терм постфикс
 *          инфикс
 *  RETURN: EOF   (обнаружен конец файла)
 *          OK    (обработано без ошибки, это инфикс)
 *          ERROR (NONE) Нужно отматывать ч/з Find_Position (?)
 *          NONSTATEMENT  - это не инфикс (конец выражения)
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
 *  обработка постфикса
 *  ВХОД - по умолчанию
 *  unit      V
 *  что-то
 *   префикс терм постфикс
 *          инфикс
 *  RETURN: EOF   (обнаружен конец файла)
 *          OK    (обработано без ошибки, это постфикс)
 *          ERROR (NONE) Нужно отматывать ч/з Find_Position (?)
 *          NONSTATEMENT  - это не постфикс
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
 *  обработка терма
 *  ВХОД - по умолчанию
 *  unit                                     V
 *  функция|константа|переменная|ситуация | ( выражение )
 *
 *
 *  RETURN: EOF   (обнаружен конец файла)
 *          OK    (обработано без ошибки, это терм)
 *          ERROR (NONE) Нужно отматывать ч/з Find_Position
 *          NONSTATEMENT  - это не терм (?)
 ************************************************/
int Term_Body (void) {
#ifdef TEST_MODE
    printf("\n===== Term_Body");
#endif
    if (compare(unit, rezword[RW_PROC])) {            /* ПРОЦ имя В СОСТ имя ? */
         if (!select_unit()) return(ZERO);            /* имя процесса ? */
         if (!check_name(unit)) {                  /* это имя ? */
              error_msg(11, line_count, unit, NONE);  /* д.б. имя процесса */
              return(ERROR);
         }
         if (!select_unit()) return(ZERO);            /* слово В */
         if (!compare(unit, rezword[RW_IN])) {        /* это слово "В" ? */
              error_msg(33, line_count, unit, NONE);  /* д.б. слово "В" */
              return(ERROR);
         }
         if (!select_unit()) return(ZERO);            /* слово COCT */
         if (!compare(unit, rezword[RW_STATE])) {     /* это слово "СОСТ" ? */
              error_msg(47, line_count, unit, NONE);  /* д.б. слово "СОСТ" */
              return(ERROR);
         }
         if (!select_unit()) return(ZERO);            /* состояние */
         switch (compare_RW(unit)) {                  /* что за состояние ? */
              case RW_STOP:                           /* СТОП */
                   break;
              case RW_ERROR:                          /* ОШИБКА */
                   break;
              case RW_ACTIVE:                         /* АКТИВНОЕ */
                   break;
              case RW_PASSIVE:                        /* ПАССИВНОЕ */
                   break;
              case RW_NULL:                           /* конкретное имя состояния */
                   break;
              default:
                   error_msg(22, line_count, unit, NONE);  /* д.б. имя состояния */
                   return(ERROR);
         }
    } else {                                               /* это не ситуация */
         if (compare(unit, rezword[RW_OPEN_PARENTESIS])) { /* ( выражение ) ? */
              if (!select_unit()) return(ZERO);            /* заряжаем unit */
              switch (Expression_Body()) {                 /* разбор выражения */
                   case ERROR:         /* Error */
                        return(ERROR);
                   case ZERO:          /* EOF */
                        return(ZERO);
                   default:
                        break;
              } /* end of switch */
              if (!compare(unit, rezword[RW_CLOSE_PARENTESIS])) {
                   error_msg(21, line_count, unit, NONE);       /* д.б. ) */
                   return(ERROR);
              }
         } else {
                        /* иначе проверяем имя переменной, функции, константы */
              if ((CheckNameVariable(unit)) &&
                  (!check_digit(unit)) &&
                  (CheckNameFunc(unit))) {
                   error_msg(45, line_count, unit, NONE);
              } else {
                   if (!CheckNameFunc(unit)) { /* это функция ? */
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
 * обработка описания аргументов функции при ее вхождении в качестве терма
 *  ВХОД - по умолчанию
 *  unit        V
 *                 ( ----> выражение ----> )
 *                    <----- , <-------
 *
 * CurrentFunc - указывает на текущую функцию
 *
 *  RETURN: EOF   (обнаружен конец файла)
 *          OK    (обработано без ошибки)
 *          ERROR (NONE) Нужно отматывать ч/з Find_Position
 ************************************************/
int Check_Func_Args (void)
{
int i, arg_num;
#ifdef TEST_MODE
        printf("\n== Check_Func_Args");
#endif
    if (!select_unit()) return(ZERO);            /* открытие ( */
    if (!compare(unit, rezword[RW_OPEN_PARENTESIS])) {
         error_msg(20, line_count, unit, NONE);  /* д.б. слово "В" */
         return(ERROR);
    }
    arg_num = GetCurFuncArgNum();           /* берем количество аргументов */
    if (arg_num == 0) {
         if (!select_unit()) return(ZERO);            /* заряжаем unit */
    } else {
        for (i = 0; i < arg_num; i++) {         /* сверяем количество аргументов */
             if (!select_unit()) return(ZERO);            /* заряжаем unit */
             switch (Expression_Body()) {                 /* разбор выражения */
                  case ERROR:         /* Error */
                       return(ERROR);
                  case ZERO:          /* EOF */
                       return(ZERO);
                  default:
                       break;
             } /* end of switch */
             if (i < (arg_num - 1)) {             /* в последнем случае - не ЗПТ, а ) */
                  if (!compare(unit, rezword[RW_COMMA])) {
                       error_msg(74, line_count, unit, NONE);  /* д.б. , */
                       return(ERROR);
                  }
             }
        } /* end of for */
    }
    if (!compare(unit, rezword[RW_CLOSE_PARENTESIS])) {
         error_msg(21, line_count, unit, NONE);  /* д.б. ) */
         return(ERROR);
    }
    return(!ZERO);
};

/********************************************
 *  обработка префикса
 *  ВХОД - по умолчанию
 *  unit      V
 *  что-то
 *   префикс терм постфикс
 *          инфикс
 *  RETURN: EOF   (обнаружен конец файла)
 *          OK    (обработано без ошибки, это префикс)
 *          ERROR (NONE) Нужно отматывать ч/з Find_Position (?)
 *          NONSTATEMENT  - это не префикс
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
         case RW_OPEN_PARENTESIS:   /* "(" - проверяем, преобразование типов ?*/
              switch (Declarator_Body()) {
                   case ZERO:               /* EOF */
                        return(ZERO);
                   case ERROR:              /* Error in string set on new STATE */
                        return(ERROR);
                   case NONSTATEMENT:       /* это не декларатор */
                        return(NONSTATEMENT);
                   default:                 /* это был декларатор (префикс) */
                        if (!select_unit()) return(ZERO);  /* ) */
			if (!compare(unit, ")")) {
			     error_msg(21, line_count, unit, NONE); /* не обнаружен конец декларатора */
			     return(ERROR);
                        }
                        return(!ZERO);
              } /* end of switch */
         default:
              return(NONSTATEMENT);
    }
};

/********************************************
 * обработка декларатора
 *  ВХОД - по умолчанию
 *  unit V
 *  (     SHORT | LONG | INT | FLOAT | DOUBLE ...
 *
 *  RETURN: EOF   (обнаружен конец файла)
 *          OK    (обработан декларатор)
 *          ERROR (NONE) Нужно отматывать ч/з Find_Position
 *          NONSTATEMENT - это не декларатор unit = (
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
         default:             /*  это не декларатор */
              rewunit();
              return(NONSTATEMENT);
    }
}
/********************************************
 *  обработка сылки после целочисленного декларатора
 *  ВХОД - по умолчанию
 *                     unit   V
 *  (     SHORT | LONG | INT    * ) | )
 *
 *  RETURN: EOF   (обнаружен конец файла)
 *          OK    (обработан декларатор)
 *          ERROR (NONE) Нужно отматывать ч/з Find_Position
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
 * обработка префикса после целочисленного декларатора
 *  ВХОД - по умолчанию
 *                     unit   V
 *  (     SHORT | LONG | INT    SIGN ) | UNSIGN ) | ) | SIGN *) | UNSIGN *)
 *
 *  RETURN: EOF   (обнаружен конец файла)
 *          OK    (обработан декларатор)
 *          ERROR (NONE) Нужно отматывать ч/з Find_Position
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
 * обработка префикса после знакового декларатора
 *  ВХОД - по умолчанию
 *         unit       V
 *  (  SIGN | UNSIGN   SHORT) | LONG) | INT)
 *
 *  RETURN: EOF   (обнаружен конец файла)
 *          OK    (обработан декларатор)
 *          ERROR (NONE) Нужно отматывать ч/з Find_Position
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
/* 03/18/04 08:27pm - коррекция таймаута */
/*    JmpFlag = !ZERO;
*/
    if (!select_unit()) return(ZERO);
    if ((!check_digit(unit)) && (!check_name(unit))) {  /* check for const */
         if(!error_msg(15, line_count, unit, STATE)) return(ZERO);
         return(ERROR);
    }
/* 03/18/04 08:27pm - коррекция таймаута */
    switch (Statement_Body()) {       /* Statement  */
         case ZERO:               /* EOF */
              return(ZERO);
         case ERROR:              /* Error in string set on new STATE */
         case NONSTATEMENT:       /* встретилось неутверждение */
              error_msg(68, line_count, unit, NONE);
              return(ERROR);
         default:                 /* NO ERROR */
              return(!ZERO);
    } /* end of switch */
/* 03/18/04 08:27pm - коррекция таймаута
/* БЫЛО:
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
