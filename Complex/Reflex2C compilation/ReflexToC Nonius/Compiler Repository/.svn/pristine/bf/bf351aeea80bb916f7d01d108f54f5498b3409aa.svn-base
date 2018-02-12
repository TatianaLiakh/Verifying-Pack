/*======================================================*/
/*======= ОПИСАНИЕ ФУНКЦИЙ ТРАНСЛЯТОРА ЯЗЫКА ===========*/
/*======= REFLEX =======================================*/
/*======= ИСПОЛЬЗУЮТСЯ ПРИ ГЕНЕРАЦИИ ТРАНСЛЯТОРА =======*/
/*======================================================*/
#include "typedef.h"

#ifndef _R_PROTO_H
#define _R_PROTO_H 1


/*****************************************/
/*    ПРОЦЕДУРЫ ГЕНЕРАЦИИ С-ПРОГРАММЫ    */
/*****************************************/

int Is_File_Exist(char *);    /* проверка файла на существование */
int Create_Headers(void);     /* создание вспомогательных h-файлов */

void GenHeadersInProc(void);  /* генерация заголовка в NAMEproc.c файле */
void GenMain(void);           /* генерация NAMEmain.c файла */
void GenVarDescription(void); /* создание файла NAMEgvar.h и файла NAMExvar.h */
void GenSYMFile(void);
void GenDebugFile(void);      /* создание файла с именами процессов и состояний */



void GenTact(char *);           /* генерация строчки о такте */
void GenInputOutput(void);      /* генерация NAMEinp.c и NAMEoutp.c */
void Gen_Ports_Reading(void);   /* генерация чтения Ф-портов */
void Gen_Ports_Writing(void);   /* генерация записи Ф-портов */
void Gen_Conversion_I_O(void);  /* генерация (для тек.переменной) преобразование физики в логику и обратно */

void GenDgt(char *);        /* перевод числа в лексему и запись лексемы в т-файл */
void GenUnit(char *);       /* генерация разделителя и лексемы в т-файле */
void GenSpaces(void);       /* генерация разделителя в т-файле */


void GenDefConstant(char *);    /* Генерация начала описания константы */
void GenBeginEnum(int);
void GenProcess(char *);        /* Генерация начала описания процесса */
void GenEndOfProcess(void);     /* Генерация конца описания процесса */
void GenBeginOfState(char *);   /* Генерация начала описания состояния */
void GenEndOfState(void);       /* Генерация конца описания состояния */
int  GenStop (char *);          /* Генерация перехода в сост СТОП */
void GenStopForCurrentProc(void);   /* Генерация перехода в сост СТОП для т-процесса */
int  GenError(char *);              /* Генерация перехода в сост ОШИБКА */
void GenErrorForCurrentProc(void);  /* Генерация перехода в сост ОШИБКА для т-процесса */
int  GenStart(char *);              /* Генерация запуски процесса по имени */
void GenStartForCurrentProc(void);  /* Генерация запуска для т-процесса */
int  GenJMP(char *);            /* Генерация перехода текущего процесса в состояние по имени */
int  GenJMPInNextState(void);   /* Генерация перехода в след-состояние за т-состоянием */
void GenBeginOfIf(void);        /* Генерация начала условия */
void GenCaseInSwitch(void);     /* Генерация строчки о начале case */
void GenBreakInSwitch(void);    /* Генерация строчки о конце case (break) */
void GenDefaultInSwitch(void);  /* Генерация строчки о начале default */
int GenSituationProcInSTOP (char *);          /* ситуация ПРОЦ в СТОП */
int GenSituationProcInERROR(char *);          /* ситуация ПРОЦ в ОШИБКА */
int GenSituationProcInACTIVE(char *);         /* ситуация ПРОЦ активен */
int GenSituationProcInPASSIVE(char *);         /* ситуация ПРОЦ пассивен */
int GenSituationProcInState(char *, char *);  /* ситуация ПРОЦ активен */
void GenRezWord(int);           /* Генерация С-аналога резервированного слова */
int GenTimeOut(char *); /* Генерация таймаута */
void GenVariable(char *);       /* Генерация внутреннего имени переменной/числа/константы и запись его в файл */
int Gen_Var(char *, INT16S);    /* преобразование пользовательского ID во внутреннее C-ID Input: unit-string, unit_case: destin OR source */
int Convrt(char *);             /* преобразование лексемы в C-число (константу или число) */
int Gen_Port(char *);           /* преобразование лексемы во внутренний C_ID порта */


void Cyr2Lat(char *);           /* преобразование из кириллицы в латиницу */
void GenUnit_ID(char *);        /* запись лексемы в файл С-идентификаторов */
void GenDgt_ID(char *);         /* запись числа в файл С-идентификаторов */
void GenDgtWithCyrName_ID(char *);  /* то же но + оригинальное имя */
void GenDgtWithCyrName_IDC(char *);  /* то же но + оригинальное имя + для значений констант */
void GenSpaces_ID(void);        /* запись форматирующей строки в файл С-идентификаторов */




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

void Sem_Process(void);         /* Обработка процессов */
void Sem_Variable_List(void);   /* Обработка переменных процесса */
void Sem_Discr_Var(void);       /* Обработка "явного" описания переменной */
void Sem_From_Var(void);        /* Обработка ссылки на описание переменной */
void Sem_Local_Var(void);       /* Обработка типа доступа переменной ЛОКАЛ */
void Sem_For_Var(void);         /* Обработка типа доступа переменной ДЛЯ */



void Sem_State(void);               /* обработка описаний состояний процесса */
void Sem_State_Body(void);          /* обработка тела состояния - блока */
int Sem_Statement_Body(void);       /* Разбор утверждения */
void Sem_Switch_Body(void);         /* обработка описания РАЗБОР */
int Sem_Case_Body(void);            /* обработка описания СЛУЧАЙ/УМОЛЧАНИЕ */
void Sem_Check_Func_Args(void);     /* обработка описания аргументов функции при ее вхождении в качестве терма */
int Sem_Declarator_Body(void);      /* обработка декларатора */
void Sem_Mul_Body(void);            /*  обработка сылки после целочисленного декларатора */
void Sem_Sign_Body(void);           /* обработка префикса после целочисленного декларатора */
void Sem_Int_Body(void);            /* обработка префикса после знакового декларатора */


void Sem_Condition_Body(void);      /*  обработка описания условия */
void Sem_Post_Condition_Body(void); /* обработка описания пост-условия */
void Sem_Stop_Body(void);           /* обработка описания СТОП */
void Sem_Loop_Body(void);           /* обработка описания ЗАЦИКЛИТЬ */
void Sem_Error_Body(void);          /* обработка описания ОШИБКА */
void Sem_Start_Body(void);          /* обработка описания СТАРТ */
void Sem_In_Body(void);             /* обработка описания перехода В СОСТ */
void Sem_Expression_Body(void);     /* обработка описания выражения */
int Sem_Prefix_Body(void);          /*  обработка префикса */
int Sem_Infix_Body(void);           /*  обработка инфикса */
int Sem_Postfix_Body(void);         /*  обработка постфикса */
void Sem_Term_Body(void);           /*  обработка терма */

void Sem_Time_Out(void);            /*  Разбор ТАЙМАУТа */



int CheckVariableInProc(char *, char *);  /* Проверка существования в процессе process_name описания
                                           * переменной variable_name и инициализация настоящего имени
                                           * переменной */





INT16S Open_File_W(FILE * *,char *); /* открыть файл на запись (w+) */
INT16S Open_File_R(FILE * *,char *); /* открыть файл на чтение (r) */
INT16S Gen_Extern1(FILE *);
void   fskptr (FILE *);                 /* отмотать файл на начало */

void ini_ptrt1(void);
void fskptrt1(void);
void fskptr1(void);

INT16S select_unit(void);
INT16S select_unit2(void);

int compare_RW(char *); /* поиск номера резервированного слова */

int    Get_Identifier(void);
int    Get_Pragma(void);
int    Get_xFix(void);
int    Get_Number(void);

INT16S InputPort(void);     /* Входной регистр */
INT16S OutputPort(void);    /* Выходной регистр */
INT16S RAMPort(void);       /* Регистр ОЗУ */

/* INT16S Gen_Variable(void);  /* Generation Of Variables Discribe */
/* void   Gen_SYM_File (void); /* Generation File *.SIM */


int    compare(char *, char *);

/* === INT16S Gen_Main(char *);
/* === INT16S Gen_IncludeFile(FILE *fptr, char *name);   /* вставляет строку #include "name" */
INT16S rewunit(void);
void   cl_unit(void);
void   cl_spaces(void);
INT16S Gen_St_Word(void);
INT16S Gen_Define(char *);
INT16S Check_From_Proc(char *, char *);
INT16S error_msg(INT16S, INT16S, char *, INT16S);
INT16S warning_msg(INT16S, INT16S, char *);
void   InitStructures(void); /* Инициализация логических имен структур -1, для идентификации отсутствия факта инициализации */


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
int    State_Body(void);          /* обработка описания состояния */
int    Statement_Body(void);      /* обработка описания утверждения */
int    Condition_Body(void);      /* обработка описания условия */
int    Post_Condition_Body(void); /* обработка описания пост-условия */
int    Stop_Body(void);           /* обработка описания СТОП */
int    Loop_Body(void);           /* обработка описания ЗАЦИКЛИТЬ */
int    Error_Body(void);          /* обработка описания ОШИБКА */
int    Start_Body(void);          /* обработка описания СТАРТ */
int    In_Body(void);             /* обработка описания В СОСТ */
int    Expression_Body(void);     /* обработка описания выражения */
int    Switch_Body(void);         /* обработка описания РАЗБОР */
int    Case_Body(void);           /* обработка описания СЛУЧАЙ */
int    Prefix_Body(void);         /* обработка описания префикса */
int    Term_Body(void);           /* обработка описания терма */
int    Postfix_Body(void);        /* обработка описания постфикса */
int    Infix_Body(void);          /* обработка описания инфикса */
int    Declarator_Body(void);     /* обработка описания декларатора */
int    Sign_Body(void);           /* обработка описания знаковости */
int    Int_Body(void);            /* обработка описания целочисленного типа */
int    Mul_Body(void);            /* обработка описания целочисленного типа */

int    Func_Declarator_Body(void);      /* обработка описания декларатора */
int    Func_Args_Declarator_Body(void);/* обработка описания декларатора */
int    Func_Sign_Body(void);            /* обработка описания знаковости */
int    Func_Int_Body(void);             /* обработка описания целочисленного типа */
int    Func_Mul_Body(void);             /* обработка описания целочисленного типа */
int    Check_Func_Args(void);           /* обработка аргументов функции-терма */


int    Constant_Expression_Body(void);     /* обработка описания Constant_выражения */
int    Constant_Prefix_Body(void);         /* обработка описания Constant_префикса */
int    Constant_Term_Body(void);           /* обработка описания Constant_терма */
int    Constant_Infix_Body(void);          /* обработка описания Constant_инфикса */
int    Constant_Enum_Body(void);           /* обработка описания ПЕРЧИСЛЕНИЯ */


INT16S Time_Out(void);

INT16S VarValue(void);

int    check_name(char *);
INT16S check_digit(char *);

INT16S CheckNameFunc(char *);
INT16S CheckFunc(char *);
INT16S N_Struct_Func(char *);
int GetCurFuncArgNum(void);    /* количество аргументов для текущей функции */
int AddNewArgInCurFunc(void); /* добавить аргумент в текущую функцию */

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
