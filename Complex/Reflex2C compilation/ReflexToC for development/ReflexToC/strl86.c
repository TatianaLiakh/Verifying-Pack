#include "const.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "typedef.h"
#include "prototyp.h"
#include "glob_ext.h"

#define GenZERO(t)  ((t *) 0)

INT16S cur_part_bit, cur_reg_bit; /* Special Counters For In/Output Subroutine
								  * Generation */

/************************ STRUCTURES DISCRIBE BEGIN ***************/

struct disc_arg_type              /* структура-описание типа аргумента */
{
	char arg_type[NAME_LENGTH];       /* тип аргумента */
	struct disc_arg_type *next;       /* описание следующего аргумента */
};

struct disc_func                  /* структура-описание функции */
{
	char  name[NAME_LENGTH];          /* имя функции */
	char  func_type[NAME_LENGTH];     /* тип возвращаемого значения */
	int   arg_num;                    /* количество аргументов */
	struct disc_arg_type *arg;        /* список аргументов */
	struct disc_func *next;           /* следующее описание функции */
};

struct disc_port_type        /* структура-описание типа порта */
{
	char name[NAME_LENGTH];      /* имя типа порта */
	int type;                    /* разрядность порта */
	struct disc_func *input;     /* описание функции чтения */
	struct disc_func *output;    /* описание функции записи */
	struct disc_port_type *next; /* следующее описание типа порта */
};

struct disc_arg              /* структура-описание значенияа аргумента */
{
	long value;                  /* тип аргумента */
	struct disc_arg *arg;        /* описание значения следующего аргумента */
};

struct disc_port_                  /* структура-описание порта */
{
	char name[NAME_LENGTH];           /* имя порта */
	struct disc_port_type *pattern;   /* описание типа порта */
	struct disc_arg  *arg;            /* описание значений аргументов */
	struct disc_port_ *next;           /* описание порта */
};

struct disc_constant    /*=== For constants tree ===*/
{
	INT16S logname;
	char  name[NAME_LENGTH];
	char  value[15];
	struct disc_constant *before;
	struct disc_constant *next;
};

struct disc_RAM_group	/*=== For RAM port tree ===*/
{
	INT16S logname;
	char  name[NAME_LENGTH];
	char  segment[15];       /* For Segment Of Cell */
	char  offset[15];        /* For Offset Of Cell */
	char  VME_address[15];   /* For VME-Address Of Cell*/
	INT16S size;          /* For Size Of Cell */
	INT16S busy;          /* For Number Of Busy Bits */
	struct disc_RAM_group *before;
	struct disc_RAM_group *next;
};

struct disc_input_group	/*=== For input port tree ===*/
{
	INT16S logname;
	char  name[NAME_LENGTH];
	char  MB_address[15];  /* для адреса по СШ */
	char  address[15];  /* For Address */
	INT16S size;          /* For Size Of Port */
	INT16S busy;          /* For Number Of Busy Bits */
	struct disc_input_group *before;
	struct disc_input_group *next;
};

struct disc_output_group /*=== For output port tree ===*/
{
	INT16S logname;
	char   name[NAME_LENGTH];
	char   MB_address[15]; /* для адреса по СШ */
	char   address[15];    /* For Address */
	INT16S size;           /* For Size Of Port */
	INT16S busy;           /* For Number Of Busy Bits */
	struct disc_output_group *before;
	struct disc_output_group *next;
};


struct disc_forproc	/*=== For access variables from process tree ===*/
{
	INT16S logname;
	char  name[NAME_LENGTH];
	struct disc_forproc *before;
	struct disc_forproc *next;
};

struct disc_port	/*=== For correspond variables bits *
					* to port bits tree ===*/
{
	INT16S logname;
	INT16S type;                 /* For Type (0-Input, 1-Output) */
	INT16S logname_port;         /* For Logical Name  Of Port */
	INT16S size_port;            /* For Size Of Port */
	char  name[NAME_LENGTH];
	INT16S start_bit;            /* For start bit number */
	INT16S finish_bit;           /* For finish bit number */
	struct disc_port *before;
	struct disc_port *next;
};

struct disc_variable	/*=== For variables tree ===*/
{
	INT16S logname;
	char  name[NAME_LENGTH];
	INT16S IO_type;       /* For IO-Type (1-Input,2-Output,3-NoImage)*/
	INT16S type;          /* For Type 0-Logical,1-Integer,-1-Unknown
						  (If From Proc) */
	INT16S number_of_busy_bit; /* Number Of Busy Bits In Variable */
	char  name_from_proc[NAME_LENGTH]; /* Right Logical Name */
	struct disc_forproc *forproc;
	struct disc_port *port;
	struct disc_variable *before;
	struct disc_variable *next;
};

struct disc_process	/*=== For processes tree ===*/
{
	INT16S logname;
	char  name[NAME_LENGTH];
	struct disc_state *stat; /* States */
	struct disc_variable *var; /* Variables */
	struct disc_process *before;
	struct disc_process *next;
};

struct disc_state	/*=== For states tree ===*/
{
	INT16S logname;
	char  name[NAME_LENGTH];
	struct disc_state *before;
	struct disc_state *next;
};

/************************ STRUCTURES DISCRIBE END ***************/

struct disc_func        First_Func;
struct disc_func        *Current_Func = 0;

struct disc_constant First_Constant;
struct disc_constant *Current_Constant=0;
struct disc_RAM_group First_RAM_Group;
struct disc_RAM_group *Current_RAM_Group=0;
struct disc_input_group First_Input_Group;
struct disc_input_group *Current_Input_Group=0;
struct disc_output_group First_Output_Group;
struct disc_output_group *Current_Output_Group=0;
struct disc_process First_Process;
struct disc_process *Current_Process=0;
struct disc_state *Current_State=0;
struct disc_variable *Current_Variable=0;
struct disc_port *Current_Part_Of_Var=0;
struct disc_forproc *Current_For_Proc=0;


/*************************************************
* Инициализация логических имен структур
* -1, для идентификации отсутствия факта
* инициализации
*************************************************/

void InitStructures(void) {
	First_Constant.logname       = NOT_INITIALIZE;
	First_RAM_Group.logname      = NOT_INITIALIZE;
	First_Input_Group.logname    = NOT_INITIALIZE;
	First_Output_Group.logname   = NOT_INITIALIZE;
	First_Process.logname        = NOT_INITIALIZE;
}


/******************** FUNCTION SUBROUTINES **********************/

int CheckFunc (char *unit_name)
{
	if (!CheckNameFunc(unit_name))
		return(ZERO);
	N_Struct_Func(unit_name);
	return(!ZERO);
};

int N_Struct_Func (char  *unit_name)
{
	if (Current_Func == ZERO){
		Current_Func = &First_Func;
	} else {
		Current_Func->next = (struct disc_func *)calloc(1,sizeof(struct disc_func));
		if (Current_Func->next == ZERO) {
			printf("\n Not Enought Space Exist");
			exit(ZERO);
		}
		Current_Func = (Current_Func->next);
	}
	Current_Func->next = GenZERO(struct disc_func);             /* иниц. ссылки на следующую */
	strncpy(Current_Func->name, unit_name, (NAME_LENGTH-1));    /* иниц. имени */
	strcpy(Current_Func->func_type, "\0");                      /* иниц. тип возвращаемого значения */
	Current_Func->arg_num = ZERO;                               /* иниц. количество аргументов */
	Current_Func->arg = GenZERO(struct disc_arg_type);          /* иниц. список аргументов */

#ifdef TEST_MODE
	printf("\n NEW FUNC => %s",unit_name);
#endif
	return(!ZERO);
};

char * GetCurFuncTypePTR (void)
{
	return(Current_Func->func_type);
}
int GetCurFuncArgNum (void)
{
	return(Current_Func->arg_num);
}
int AddNewArgInCurFunc (void)
{
	Current_Func->arg_num++;  /* увеличим количество аргументов */
	return(Current_Func->arg_num);
}

char * NewArgInCurFunc (void)
{
	struct disc_arg_type *Current_Arg;       /* указатель на аргумент */

	for (Current_Arg = Current_Func->arg; ; Current_Arg = Current_Arg->next) {
		if (Current_Func->next == ZERO) break;
	}

	Current_Func->arg_num++;  /* увеличим количество аргументов */
	Current_Arg = (struct disc_arg_type *)calloc(1, sizeof(struct disc_arg_type));
	if (Current_Arg == ZERO) {
		printf("\n Not Enought Space Exist");
		exit(ZERO);
	}
	Current_Arg->next = GenZERO(struct disc_arg_type);  /* иниц. список аргументов */
	strcpy(Current_Arg->arg_type, "\0");                /* иниц. список аргументов */
	return(Current_Arg->arg_type);
}

/************************************************
*        --- Check_Name_Func ---
*  RETURN: NOT EXIST - !ZERO
*          EXIST     -  ZERO
************************************************/
int CheckNameFunc (char  *unit_name) {
	if (Current_Func == ZERO) return(!ZERO);
	for (Current_Func = &First_Func; ; Current_Func = Current_Func->next) {
		if (!strncmp(Current_Func->name, unit_name, NAME_LENGTH - 1)) return(ZERO);
		if (Current_Func->next == ZERO) break;
	}
	return(!ZERO);
};

/******************** CONSTANT SUBROUTINES **********************/

Check_Constant(unit_name)
	char  *unit_name;
{
	if(!Check_Name_Constant(unit_name))
		return(ZERO);
	N_Struct_Constant(unit_name);
	return(!ZERO);
};

N_Struct_Constant(char  *unit_name)
{
	if(Current_Constant==ZERO){
		Current_Constant = &First_Constant;
		Current_Constant->before=ZERO;
		Current_Constant->next=GenZERO(struct disc_constant);
		Current_Constant->logname = FIRST_LOGNAME;
	}else{
		Current_Constant->next=(struct disc_constant *)
			calloc(1,sizeof(struct disc_constant));
		if(Current_Constant->next == ZERO){
			printf("\n Not Enought Space Exist");
			exit(ZERO);
		}
		Current_Constant->next->logname=(Current_Constant->logname+1);
		(Current_Constant->next)->before=Current_Constant;
		Current_Constant=(Current_Constant->next);
		Current_Constant->next=GenZERO(struct disc_constant);
	}
	strncpy(Current_Constant->name,unit_name, (NAME_LENGTH - 1));
	/*printf("\n NEW CONST => %s",unit_name);*/
	return(!ZERO);
};
/************************************************
*        --- Check_Name_Constant ---
*  RETURN: NOT EXIST - !ZERO
*          EXIST     -  ZERO
************************************************/
Check_Name_Constant(char  *unit_name){
	INT16S i;
	if(Current_Constant == ZERO) return(!ZERO);
	Current_Constant = &First_Constant;
	for(i=0;;i=0){
		while((Current_Constant->name[i] == unit_name[i])&&
			(Current_Constant->name[i] != ZERO))
			i++;
		if((i==(NAME_LENGTH-1))||((unit_name[i]==ZERO)&&
			(Current_Constant->name[i] == ZERO)))
			return(ZERO);
		if(Current_Constant->next == ZERO)
			break;
		Current_Constant = Current_Constant->next;
	}
	return(!ZERO);
};
/*---------------------------- -------------------*/
int ConstantValue (char  *val)
{
	strcpy(Current_Constant->value, val); /* запись в структуру значения char * */
	return(!ZERO);
};

/*--- Вызывается из check_digit -------------------*/
Con_Value(char  *buf){
	sprintf(buf,"C_%d",Current_Constant->logname);
	return(!ZERO);
};
/******************** RAM GROUP SUBROUTINES **********************/

Check_RAM_Group(unit_name)
	char  *unit_name;
{
	if(/*!Check_Name_Constant(unit_name)||*/
		!Check_Name_Output_Group(unit_name)||
		!Check_Name_Input_Group(unit_name)||
		!Check_Name_RAM_Group(unit_name)) return(ZERO);
	N_Struct_RAM_Group(unit_name);
	return(!ZERO);
};

N_Struct_RAM_Group(unit_name)
	char  *unit_name;
{
	INT16S i;
	if(Current_RAM_Group==ZERO){
		Current_RAM_Group = &First_RAM_Group;
		Current_RAM_Group->before =ZERO;
		Current_RAM_Group->next=ZERO;
		Current_RAM_Group->logname = FIRST_LOGNAME;
	}else{
		Current_RAM_Group->next=(struct disc_RAM_group *)
			calloc(1,sizeof(struct disc_RAM_group));
		if(Current_RAM_Group->next==ZERO){
			printf("\n Not Enought Space Exist");
			exit(ZERO);
		}

		(Current_RAM_Group->next)->logname =
			(Current_RAM_Group->logname)+1;
		(Current_RAM_Group->next)->before =
			Current_RAM_Group;
		Current_RAM_Group=(Current_RAM_Group->next);
		Current_RAM_Group->next=ZERO;
	}
	for(i=0;i<(NAME_LENGTH-1);i++){
		Current_RAM_Group->name[i]=unit_name[i];
	}
	return(!ZERO);
};

/*----------------------------------------------------------------*/
Check_Name_RAM_Group(unit_name)
	char  *unit_name;
{
	INT16S i;
	if(Current_RAM_Group==ZERO)
		return(!ZERO);
	Current_RAM_Group = &First_RAM_Group;
	for(;;){
		i=0;
		while((Current_RAM_Group->name[i]==unit_name[i])&&
			(Current_RAM_Group->name[i]!=0)){
				i++;
		}
		if((i==(NAME_LENGTH-1))||((unit_name[i]==ZERO)&&
			(Current_RAM_Group->name[i]==ZERO))){
				return(ZERO);
		}
		if(Current_RAM_Group->next==0)
		{break;}
		Current_RAM_Group = Current_RAM_Group->next;
	}
	return(!ZERO);
};
/*---------------------------- -------------------*/
INT16S RAM_Group_Segment(char  *segment)
{
	Convrt(segment);
	strcpy(Current_RAM_Group->segment,segment);
	return(!ZERO);
};
/*---------------------------- -------------------*/
RAM_Group_Offset(char  *offset)
{
	Convrt(offset);
	strcpy(Current_RAM_Group->offset,offset);
	return(!ZERO);
};
/*---------------------------- -------------------*/
RAM_Group_Address(address)
	char  *address;
{
	Convrt(address);
	strcpy(Current_RAM_Group->VME_address,address);
	return(!ZERO);
};

/*---------------------------- -------------------*/
RAM_Group_Size(size)
	char  *size;
{
	Current_RAM_Group->size = atoi(size);
	return(!ZERO);
};
/******************** INPUT GROUP SUBROUTINES **********************/

Check_Input_Group(unit_name)
	char  *unit_name;
{
	if(/*!Check_Name_Constant(unit_name)||*/
		!Check_Name_RAM_Group(unit_name)||
		!Check_Name_Output_Group(unit_name)||
		!Check_Name_Input_Group(unit_name)) return(ZERO);
	N_Struct_Input_Group(unit_name);
	return(!ZERO);
};

N_Struct_Input_Group(unit_name)
	char  *unit_name;
{
	INT16S i;
	if(Current_Input_Group==ZERO){
		Current_Input_Group = &First_Input_Group;
		Current_Input_Group->before =ZERO;
		Current_Input_Group->next=ZERO;
		Current_Input_Group->logname = FIRST_LOGNAME;
	}else{
		Current_Input_Group->next=(struct disc_input_group *)
			calloc(1,sizeof(struct disc_input_group));
		if(Current_Input_Group->next==ZERO){
			printf("\n Not Enought Space Exist");
			exit(ZERO);
		}

		(Current_Input_Group->next)->logname =
			(Current_Input_Group->logname)+1;
		(Current_Input_Group->next)->before =
			Current_Input_Group;
		Current_Input_Group=(Current_Input_Group->next);
		Current_Input_Group->next=ZERO;
	}
	for(i=0;i<(NAME_LENGTH-1);i++){
		Current_Input_Group->name[i]=unit_name[i];
	}
	return(!ZERO);
};
/*----------------------------------------------------------------*/
Check_Name_Input_Group(unit_name)
	char  *unit_name;
{
	INT16S i;
	if(Current_Input_Group==ZERO)
		return(!ZERO);
	Current_Input_Group = &First_Input_Group;
	for(;;){
		i=0;
		while((Current_Input_Group->name[i]==unit_name[i])&&
			(Current_Input_Group->name[i]!=0)){
				i++;
		}
		if((i==(NAME_LENGTH-1))||((unit_name[i]==ZERO)&&
			(Current_Input_Group->name[i]==ZERO))){
				return(ZERO);
		}
		if(Current_Input_Group->next==0)
		{break;}
		Current_Input_Group = Current_Input_Group->next;
	}
	return(!ZERO);
};
/*---- Инициализация адреса порта по СШ ----------*/
Input_Group_MB_Address(char  *address)
{
	Convrt(address);
	strcpy(Current_Input_Group->MB_address,address);
	return(!ZERO);
};
/*---- Инициализация адреса порта ----------------*/
Input_Group_Address(char  *address)
{
	Convrt(address);
	strcpy(Current_Input_Group->address,address);
	return(!ZERO);
};
/*---------------------------- -------------------*/
Input_Group_Size(size)
	char  *size;
{
	Current_Input_Group->size = atoi(size);
	return(!ZERO);
};
/******************** OUTPUT GROUP SUBROUTINES **********************/

Check_Output_Group(unit_name)
	char  *unit_name;
{
	if(/*!Check_Name_Constant(unit_name)||*/
		!Check_Name_Output_Group(unit_name)||
		!Check_Name_RAM_Group(unit_name)||
		!Check_Name_Input_Group(unit_name)) return(ZERO);

	N_Struct_Output_Group(unit_name);

	return(!ZERO);
};

N_Struct_Output_Group(unit_name)
	char  *unit_name;
{
	INT16S i;

	if(Current_Output_Group==ZERO){
		Current_Output_Group = &First_Output_Group;
		Current_Output_Group->next=ZERO;
		Current_Output_Group->before = ZERO;
		Current_Output_Group->logname = FIRST_LOGNAME;
	}else{

		Current_Output_Group->next=(struct disc_output_group *)
			calloc(1,sizeof(struct disc_output_group));
		if(Current_Output_Group->next==ZERO){
			printf("\n Not Enought Space Exist");
			exit(ZERO);
		}

		(Current_Output_Group->next)->logname =
			(Current_Output_Group->logname)+1;
		(Current_Output_Group->next)->before =
			Current_Output_Group;
		Current_Output_Group=(Current_Output_Group->next);
		Current_Output_Group->next=ZERO;
	}

	for(i=0;i<(NAME_LENGTH-1);i++){
		Current_Output_Group->name[i]=unit_name[i];
	}
	return(!ZERO);
};
/*----------------------- ------------------------------*/
Check_Name_Output_Group(unit_name)
	char  *unit_name;
{
	INT16S i;
	if(Current_Output_Group==ZERO)
		return(!ZERO);

	Current_Output_Group = &First_Output_Group;

	for(;;){
		i=0;
		while((Current_Output_Group->name[i]==unit_name[i])&&
			(Current_Output_Group->name[i]!=0)){
				i++;
		}
		if((i==(NAME_LENGTH-1))||((unit_name[i]==ZERO)&&
			(Current_Output_Group->name[i]==ZERO))){

				return(ZERO);
		}
		if(Current_Output_Group->next==0)
		{break;}
		Current_Output_Group = Current_Output_Group->next;
	}
	return(!ZERO);
};
/*---------- Инициализация адреса вых. порта по СШ --*/
Output_Group_MB_Address(char  *address)
{
	Convrt(address);
	strcpy(Current_Output_Group->MB_address,address);
	return(!ZERO);
};
/*---------- Инициализация адреса вых. порта --*/
Output_Group_Address(char  *address)
{
	Convrt(address);
	strcpy(Current_Output_Group->address,address);
	return(!ZERO);
};
/*---------------------------- -------------------*/
Output_Group_Size(size)
	char  *size;
{
	Current_Output_Group->size = atoi(size);
	return(!ZERO);
};

/******************** PROCESS SUBROUTINES **********************/

Check_Process(unit_name)
	char  *unit_name;
{
	if(/*!Check_Name_Constant(unit_name)||
	   !Check_Name_Output_Group(unit_name)||
	   !Check_Name_RAM_Group(unit_name)||
	   !Check_Name_Input_Group(unit_name)||*/
	   !Check_Name_Process(unit_name)) return(ZERO);
	N_Struct_Process(unit_name);
	return(!ZERO);
};

N_Struct_Process(unit_name)
	char  *unit_name;
{
	INT16S i;
	if(Current_Process == ZERO){
		Current_Process = &First_Process;
		/*printf(" NEW PROCESS \n");*/
		Current_Process->logname = FIRST_LOGNAME;
		Current_Process->next=ZERO;
		Current_Process->before=ZERO;
	}else{
		Current_Process->next=(struct disc_process *)
			calloc(1,sizeof(struct disc_process));
		if(Current_Process->next==ZERO){
			printf("\n Not Enought Space Exist");
			exit(ZERO);
		}

		(Current_Process->next)->logname=(Current_Process->logname)+1;
		(Current_Process->next)->before=(Current_Process);
		Current_Process=(Current_Process->next);
		Current_Process->next=ZERO;
	}
	for(i=0;i<(NAME_LENGTH-1);i++){
		Current_Process->name[i]=unit_name[i];
	}
	return(!ZERO);
};
/*----------------------------------------------------------------*/
Check_Name_Process(unit_name)
	char  *unit_name;
{
	INT16S i;
	if(Current_Process == ZERO) return(!ZERO);
	Current_Process = &First_Process;
	for(;;){
		i=0;
		while((Current_Process->name[i]==unit_name[i])&&
			(Current_Process->name[i]!=0)){
				i++;
		}
		if((i==(NAME_LENGTH-1))||((unit_name[i]==ZERO)&&
			(Current_Process->name[i]==ZERO))){
				return(ZERO);
		}                              /* 11/15/94 08:03pm */
		if(Current_Process->next==(struct disc_process *)ZERO)
			break;
		Current_Process = Current_Process->next;
	}
	return(!ZERO);
};
/******************** STATE SUBROUTINES **********************/

Check_State(unit_name)
	char  *unit_name;
{

	if(!Check_Name_State(unit_name)/*||!Check_Name_Constant(unit_name)*/)
		return(ZERO);

	N_Struct_State(unit_name);
	return(!ZERO);
};

N_Struct_State(unit_name)
	char  *unit_name;
{
	INT16S i;
	if(Current_Process->stat  == ZERO){
		Current_Process->stat=(struct disc_state *)
			calloc(1,sizeof(struct disc_state));
		if(Current_Process->stat==ZERO){
			printf("\n Not Enought Space Exist");
			exit(ZERO);
		}

		Current_State = Current_Process->stat;
		Current_State->logname = FIRST_LOGNAME;
		/*printf(" NEW State \n");*/
		Current_State->next=ZERO;
		Current_State->before=ZERO;
	}else{
		Current_State->next=(struct disc_state *)
			calloc(1,sizeof(struct disc_state));
		if(Current_State->next==ZERO){
			printf("\n Not Enought Space Exist");
			exit(ZERO);
		}

		(Current_State->next)->logname=(Current_State->logname)+1;
		(Current_State->next)->before=(Current_State);
		Current_State=(Current_State->next);
		Current_State->next=ZERO;
	}
	for(i=0;i<(NAME_LENGTH-1);i++){
		Current_State->name[i]=unit_name[i];
	}
	return(!ZERO);
};

/*----------------------------------------------------------------*/
Check_Name_State(unit_name)
	char  *unit_name;
{
	INT16S i;

	if(Current_Process->stat == ZERO) return(!ZERO);
	Current_State = Current_Process->stat;
	for(;;){
		i=0;
		while((Current_State->name[i]==unit_name[i])&&
			(Current_State->name[i]!=0)){
				i++;
		}
		/*printf("\n CUR_STATE_NAME is %s \n Name is %s",
		Current_State->name,unit_name);
		*/
		if((i==(NAME_LENGTH-1))||((unit_name[i]==ZERO)&&
			(Current_State->name[i]==ZERO))){

				return(ZERO);
		}
		if(Current_State->next==0)
		{break;}
		Current_State = Current_State->next;
	}
	return(!ZERO);
};
/*************** ***********************/
Check_Number_Of_State()
{
	if(Current_Process->stat==ZERO)
		return(ZERO);
	return(Current_State->logname + 1 - FIRST_LOGNAME);
}

/******************** Port SUBROUTINES **********************/

int CheckVariable (char *unit_name, int n)
{
	if ((!CheckNameVariable(unit_name)) ||
		(!Check_Name_Constant(unit_name))) {
			return(ZERO);
	}
	N_Struct_Variable(unit_name, n);
	return(!ZERO);
};
/*-------------------------------------*/
N_Struct_Variable(unit_name, n)
	char  *unit_name;
INT16S n;
{
	if(Current_Process->var == GenZERO(struct disc_variable)){
		Current_Process->var=(struct disc_variable *)
			calloc(1,sizeof(struct disc_variable));
		if(Current_Process->var==ZERO){
			printf("\n Not Enought Space Exist");
			exit(ZERO);
		}
		Current_Variable = Current_Process->var;
		/*11/14/94 01:55pm*/
		Current_Variable->next=GenZERO(struct disc_variable);
		Current_Variable->before=ZERO;
		Current_Variable->logname = FIRST_LOGNAME;
	}else{
		Current_Variable->next = (struct disc_variable *)
			calloc(1,sizeof(struct disc_variable));
		if(Current_Variable->next==ZERO){
			printf("\n Not Enought Space Exist");
			exit(ZERO);
		}
		(Current_Variable->next)->logname=(Current_Variable->logname)+1;
		(Current_Variable->next)->before=(Current_Variable);
		Current_Variable=(Current_Variable->next);
		Current_Variable->next=GenZERO(struct disc_variable);
	}
	Current_Variable->IO_type = ZERO;
	Current_Variable->number_of_busy_bit=ZERO;
	Current_Variable->forproc = GenZERO(struct disc_forproc);
	Current_Variable->port = GenZERO(struct disc_port);
	strcpy(Current_Variable->name,unit_name);
	Current_Variable->type = n;

	return(!ZERO);
};
/*----------------------------------------------------------------*/
CheckNameVariable(unit_name)
	char  *unit_name;
{
	INT16S i;


	if(Current_Process->var == ZERO) return(!ZERO);
	Current_Variable = Current_Process->var;
	for(;;){
		i=0;
		while((Current_Variable->name[i]==unit_name[i])&&
			(Current_Variable->name[i]!=0)){
				i++;
		}
		if((i==(NAME_LENGTH-1))||((unit_name[i]==(char )ZERO)&&
			(Current_Variable->name[i]==(char )ZERO))){
				return(ZERO);
		}
		if(Current_Variable->next==0)
			break;
		Current_Variable = Current_Variable->next;
	}
	return(!ZERO);
};

/*-------------------------------------------------------*/
int InitVariable (char *port_name, int value)
{
	switch (Current_Variable->type) {
	case RW_LOG:
		if ((Current_Variable->type == RW_LOG) && /* Если переменная LOG */
			((Current_Variable->port != ZERO) ||
			(value != 1))){              /* и уже произошла инициализаия */
				return(ZERO);           /* - Ошибка */
		}
		Current_Variable->number_of_busy_bit += value;
		break;
	case RW_INT:
		Current_Variable->number_of_busy_bit += value;
		if (Current_Variable->number_of_busy_bit > 16) {/* Если после добавления*/
			/* не осталось свободных битов */
			return(ZERO);                             /* - Ошибка*/
		}
		break;
	case RW_LONG:
		Current_Variable->number_of_busy_bit += value;
		if (Current_Variable->number_of_busy_bit > 32) {/* Если после добавления*/
			/* не осталось свободных битов */
			return(ZERO);                             /* - Ошибка*/
		}
		break;
	default:                          /* иначе SHORT */
		Current_Variable->number_of_busy_bit += value;
		if (Current_Variable->number_of_busy_bit > 8) /* Если после добавления*/
		{                            /* не осталось свободных битов */
			return(ZERO);           /* - Ошибка*/
		}
		break;
	} /* End Of Switch */
	if (!Check_Name_Input_Group(port_name)) {  /* ЕСЛИ ПОРТ - ВХОДНОЙ */
		if ((Current_Variable->port != ZERO) &&
			(Current_Variable->IO_type != RW_INPUT))
			return(ZERO); /* если тип присвоен и он не входной - ОШИБКА*/
		else
			Current_Variable->IO_type = RW_INPUT;   /* иначе иниц. тип - входной*/
		N_Part_Of_Var();                             /* Позиционирование на новую часть */
		Current_Part_Of_Var->type = RW_INPUT;        /* Заносим имя порта в опис.регистра*/
		Current_Part_Of_Var->logname_port = Current_Input_Group->logname;
		Current_Part_Of_Var->size_port = Current_Input_Group->size;
		strncpy(Current_Part_Of_Var->name, port_name, (NAME_LENGTH - 1));
		Current_Part_Of_Var->start_bit = Current_Input_Group->busy + 1;
		if ((Current_Input_Group->busy + value) >
			(Current_Input_Group->size)) {          /* если в порту не хватает битов */
				Current_Part_Of_Var->finish_bit = (Current_Input_Group->size);
				Current_Input_Group->busy = Current_Part_Of_Var->finish_bit;
				return(ZERO);                           /* ОШИБКА */
		} else {                                     /* иначе берем */
			Current_Part_Of_Var->finish_bit =
				(Current_Part_Of_Var->start_bit + value);
			Current_Input_Group->busy += value;
			return(!ZERO);
		}
	}
	if (!Check_Name_RAM_Group(port_name)) {           /* ЕСЛИ ПОРТ - ОЗУ */
		if ((Current_Variable->port != ZERO) &&
			(Current_Variable->IO_type != RW_OUTPUT))
			return(ZERO);
		else
			Current_Variable->IO_type = RW_OUTPUT;
		N_Part_Of_Var();
		Current_Part_Of_Var->type = RW_RAM;
		Current_Part_Of_Var->logname_port = Current_RAM_Group->logname;
		Current_Part_Of_Var->size_port = Current_RAM_Group->size;
		strncpy(Current_Part_Of_Var->name, port_name, (NAME_LENGTH - 1));
		Current_Part_Of_Var->start_bit = Current_RAM_Group->busy + 1;
		if ((Current_RAM_Group->busy + value) >
			(Current_RAM_Group->size)) {  /* если в порту не хватает битов */
				Current_Part_Of_Var->finish_bit = (Current_RAM_Group->size);
				Current_RAM_Group->busy = Current_Part_Of_Var->finish_bit;
				return(ZERO);           /* ОШИБКА */
		} else {
			Current_Part_Of_Var->finish_bit = (Current_Part_Of_Var->start_bit + value);
			Current_RAM_Group->busy += value;
			return(!ZERO);
		}
	}
	if (!Check_Name_Output_Group(port_name)) {   /* ЕСЛИ ПОРТ ВЫХОДНОЙ */
		if ((Current_Variable->port != ZERO) &&
			(Current_Variable->IO_type != RW_OUTPUT))
			return(ZERO);
		else
			Current_Variable->IO_type = RW_OUTPUT;
		N_Part_Of_Var();
		Current_Part_Of_Var->type = RW_OUTPUT;
		Current_Part_Of_Var->logname_port = Current_Output_Group->logname;
		Current_Part_Of_Var->size_port = Current_Output_Group->size;
		strncpy(Current_Part_Of_Var->name, port_name, (NAME_LENGTH - 1));
		Current_Part_Of_Var->start_bit = Current_Output_Group->busy + 1;
		if ((Current_Output_Group->busy+value) >
			((Current_Output_Group->size))) { /* если в порту не хватает битов */
				Current_Part_Of_Var->finish_bit = (Current_Output_Group->size);
				Current_Output_Group->busy = Current_Part_Of_Var->finish_bit;
				return(ZERO);                     /* ОШИБКА */
		} else {
			Current_Part_Of_Var->finish_bit = (Current_Part_Of_Var->start_bit + value);
			Current_Output_Group->busy += value;
			return(!ZERO);
		}
	}
	return(ZERO);
};


/***********************************************************************/
int N_Part_Of_Var (void)   /* Position on process-> */
{
	if (Current_Variable->port == ZERO) {
		Current_Variable->port = (struct disc_port *)
			calloc(1, sizeof(struct disc_port));
		if (Current_Variable->port == ZERO) {
			printf("\n Not Enought Space Exist");
			exit(ZERO);
		}
		Current_Part_Of_Var = Current_Variable->port;
		/*printf(" NEW PART OF Port \n");*/
		Current_Part_Of_Var->next = ZERO;
		Current_Part_Of_Var->before = ZERO;
		Current_Part_Of_Var->logname = FIRST_LOGNAME;
	} else {
		Current_Part_Of_Var->next = (struct disc_port *)
			calloc(1,sizeof(struct disc_port));
		if (Current_Part_Of_Var->next == ZERO) {
			printf("\n Not Enought Space Exist");
			exit(ZERO);
		}
		/* 11/14/94 02:12pm */
		(Current_Part_Of_Var->next)->type = NODEF;
		(Current_Part_Of_Var->next)->size_port = ZERO;          /* For Size Of Port */
		(Current_Part_Of_Var->next)->start_bit = ZERO;          /* For start bit number */
		(Current_Part_Of_Var->next)->finish_bit = ZERO;         /* For finish bit number */
		(Current_Part_Of_Var->next)->logname = (Current_Part_Of_Var->logname) + 1;
		(Current_Part_Of_Var->next)->before = (Current_Part_Of_Var);
		Current_Part_Of_Var = Current_Part_Of_Var->next;
		Current_Part_Of_Var->next = ZERO;
	}
	return(!ZERO);
};

/*--------------------------------------------------*/

/************************************************
*             --- For_Proc ---
*
************************************************/
int ForProc_ALL (void)  /**/
{
	Current_Variable->forproc = (struct disc_forproc *)RW_ALL; /* If for All */
	return(!ZERO);
}

int ForProc_LOCAL (void)
{
	Current_Variable->forproc = (struct disc_forproc *)RW_LOCAL; /* If LOCAL */
	return(!ZERO);
}

int ForProc (char *proc_name)
{
	if (!Check_Name_For_Proc(proc_name)) return(ZERO); /* уже описан ? */
	if (Current_Variable->forproc == GenZERO(struct disc_forproc)) {
		Current_Variable->forproc = (struct disc_forproc *)
			calloc(1, sizeof(struct disc_forproc));
		if (Current_Variable->forproc == ZERO) {
			printf("\n Not Enought Space. Exist.");
			exit(ZERO);
		}
		Current_For_Proc = Current_Variable->forproc;
		Current_For_Proc->next = GenZERO(struct disc_forproc);
	} else {
		Current_For_Proc->next = (struct disc_forproc *)
			calloc(1, sizeof(struct disc_forproc));
		if (Current_For_Proc->next == ZERO) {
			printf("\n Not Enought Space Exist");
			exit(ZERO);
		}
		Current_For_Proc = Current_For_Proc->next;
		Current_For_Proc->next = GenZERO(struct disc_forproc);
	}
	strncpy(Current_For_Proc->name, proc_name, NAME_LENGTH-1);
	return(!ZERO);
};
/*----------------------------------------------------------------*/
int Check_Name_For_Proc (char *unit_name)
{
	if (Current_Variable->forproc == GenZERO(struct disc_forproc))
		return(!ZERO);

	Current_For_Proc = Current_Variable->forproc;

	for (;;) { /* ищем повторения - находим - возвращаем 0 */
		if (!strncmp(Current_For_Proc->name, unit_name, NAME_LENGTH - 1)) return(ZERO);
		if (Current_For_Proc->next == GenZERO(struct disc_forproc))
			break;
		Current_For_Proc = Current_For_Proc->next;
	}
	return(!ZERO);
};
/************************************************
*          --- MakeBeforeFor ---
*  Копирует тип доступа на все описанные в строке
*  переменные для случая: LOG x1, x2 LOCAL; (пример)
************************************************/
int MakeBeforeFor (void)
{
	struct disc_variable *Copy_Variable = 0;
#ifdef TEST_MODE
	printf("\n==== MAkeBeforeFor");
#endif

	Copy_Variable = Current_Variable;
	for (;;) {
		if ((Current_Variable->before == ZERO)) break;
		if ((Current_Variable->before)->forproc != ZERO) break;
		(Current_Variable->before)->forproc = Current_Variable->forproc;
		Current_Variable = (Current_Variable->before);
	}
	Current_Variable = Copy_Variable;
	return(!ZERO);
};

/******************************************************
* Проверка существования в процессе process_name описания
* переменной variable_name и инициализация настоящего имени
* переменной
******************************************************/
int CheckVariableInProc (char *process_name, char *variable_name)
{
	struct disc_process *Copy_Process = 0;
	struct disc_variable *Copy_Variable = 0;
	struct disc_variable *Variable_In_Current_Process = 0;

	Copy_Process  = Current_Process;
	Copy_Variable = Current_Variable;

	CheckNameVariable(variable_name);       /* находим т-перем в т-процессе */
	Variable_In_Current_Process = Current_Variable;

	if (Check_Name_Process(process_name)) {  /* устанавливаем т-процесс */
		Current_Process  = Copy_Process;
		Current_Variable = Copy_Variable;
		return(NO_PROCESS);
	}

	if (CheckNameVariable(variable_name)) {  /* устанавливаем т-переменную в т-процессе */
		Current_Process  = Copy_Process;
		Current_Variable = Copy_Variable;
		return(NO_VARIABLE);
	}

	/* printf ("\nНАйдена переменная Logname Of %s Of Pr.%s Is P%dV%d\nRW_LOCAL is %d, RW_ALL is %d, VAR->forproc is %d\n",
	Current_Variable->name,
	Current_Process->name,
	Current_Process->logname,
	Current_Variable->logname,
	RW_LOCAL,
	RW_ALL,
	Current_Variable->forproc);
	*/

	if (Current_Variable->forproc == (struct disc_forproc *)RW_LOCAL) { /* ЛОКАЛ? - ошибка */
		Current_Process  = Copy_Process;
		Current_Variable = Copy_Variable;
		return(NO_ACCESS);
	}

	if (Current_Variable->forproc == (struct disc_forproc *)RW_ALL) { /* для всех */
		sprintf(Variable_In_Current_Process->name_from_proc,"P%dV%d", /* инициируем имя */
			Current_Process->logname,
			Current_Variable->logname);
		Variable_In_Current_Process->IO_type = Current_Variable->IO_type; /* инициируем тип */
		Current_Process  = Copy_Process;
		Current_Variable = Copy_Variable;
		return(RESULT_OK);
	}

	if (!Check_Name_For_Proc(Copy_Process->name)) {
		/* printf ("\nLogname Of %s Of Pr.%s Is P%dV%d",
		Copy2_Variable->name,
		Copy_Process->name,
		Current_Process->logname,
		Current_Variable->logname); */
		sprintf(Variable_In_Current_Process->name_from_proc, "P%dV%d", /* инициируем имя */
			Current_Process->logname,
			Current_Variable->logname);
		Variable_In_Current_Process->IO_type = Current_Variable->IO_type; /* инициируем тип */
		Current_Process  = Copy_Process;
		Current_Variable = Copy_Variable;
		return(RESULT_OK);
	}

	Current_Process  = Copy_Process;
	Current_Variable = Copy_Variable;
	return (NO_ACCESS);
};

/*****************************************/
/*    ПРОЦЕДУРЫ ГЕНЕРАЦИИ С-ПРОГРАММЫ    */
/*****************************************/

/*****************************************
* Генерация строчки о такте в файле
* пользовательских констант
* #define Tact_Value nn
******************************************/
void GenTact (char *unit)
{
	char string[BUFFER_LENGTH];
	sprintf(string, "\n#define Tact_Value %s /* размер такта в миллисекундах */\n", unit);
	fputs(string, fptr_C);

	return;
}
/*****************************************
* Генерация строчки о начале описания константы
* в файле пользовательских констант
* #define Cnn ...
******************************************/
void GenDefConstant (char *unit)
{
	char string[2*BUFFER_LENGTH];
#ifdef GEN_ID
	char test_def[BUFFER_LENGTH];
	char lat_id[BUFFER_LENGTH];
#endif

	Check_Name_Constant(unit);    /* устанавливаем Current_Constant */
	sprintf(string, "#define C_%d /* %s */", Current_Constant->logname, Current_Constant->name);
	fputs(string, fptr_C);

#ifdef GEN_ID
	strcpy(lat_id, Current_Constant->name);
	Cyr2Lat(lat_id);                        /* преобразуем кириллицу в латиницу */
	fputs("#define ", fptr_ID);
	fputs(lat_id, fptr_ID);
	fputs(" /* ", fptr_ID);
	sprintf(string, "C_%d - %s", Current_Constant->logname, Current_Constant->name);
	fputs(string, fptr_ID);
	fputs(" */", fptr_ID);


	fputs("\ti = ", fptr_IDC);
	fputs(lat_id, fptr_IDC);
	fputs("; /* ", fptr_IDC);
	sprintf(string, "C_%d - %s", Current_Constant->logname, Current_Constant->name);
	fputs(string, fptr_IDC);
	fputs(" */\n", fptr_IDC);

	if (Flag_CONFIG)
	{
		sprintf(test_def, "\tfputs( \"%s = \" , file);\n" , Current_Constant->name);
		fputs(test_def, fptr_IDC);
		fputs("\tsprintf(string, \"%d\\n\", i );\n", fptr_IDC);
		fputs("\tfputs( string, file);\n\n ", fptr_IDC);

	}

#endif
	return;
};

/*****************************************
* Генерация строчки о начале перечисления
* в т-файле
******************************************/
void GenBeginEnum (int log_name)
{
	char string[BUFFER_LENGTH];

	sprintf(string, "enum EN%d {", log_name);
	fputs(string, fptr_C);
#ifdef GEN_ID
	fputs(string, fptr_ID);
#endif
	return;
};


/*****************************************
* Генерация числа в т-файле
* Cnn ...
******************************************/
void GenDgt (char *digit)
{
	char string[BUFFER_LENGTH];
	if(!Check_Name_Constant(digit))
		sprintf(string, "%sC_%d", spaces, Current_Constant->logname);
	else
		sprintf(string, "%s%s", spaces, digit);
	fputs(string, fptr_C);
	return;
};

/*****************************************
* Генерация spaces
* в файле пользовательских констант NAMEcnst.h
******************************************/
void GenSpaces (void)
{
	fputs(spaces, fptr_C);
	return;
};

/*****************************************
* Генерация unit в текущем файле
*****************************************/
void GenUnit (char *unit)
{
	char string[BUFFER_LENGTH];

	sprintf(string, "%s%s", spaces, unit);
	fputs(string, fptr_C);
	return;
};

#ifdef GEN_ID
/*****************************************
* Генерация unit в файле NAME_ID.h
*****************************************/
void GenUnit_ID (char *unit)
{
	fputs(spaces, fptr_ID);
	fputs(unit, fptr_ID);
	return;
};

/*****************************************
* Генерация числа
* в файле программы NAME_ID.h
* Cnn ...
******************************************/
void GenDgt_ID (char *digit)
{
	char lat_id[BUFFER_LENGTH];

	fputs(spaces, fptr_ID);
	if(!Check_Name_Constant(digit)) {
		strcpy(lat_id, Current_Constant->name);
		Cyr2Lat(lat_id);                        /* преобразуем кириллицу в латиницу */
	
		fputs(lat_id, fptr_ID);
	} else {
		fputs(digit, fptr_ID);
	}
};

/*****************************************
* Генерация идентификатора константы с оригинальным именем
* в файле программы NAME_ID.h
* Cnn ...
******************************************/
void GenDgtWithCyrName_ID (char *digit)
{
	char lat_id[BUFFER_LENGTH], string[BUFFER_LENGTH];

	fputs(spaces, fptr_ID);
	if(!Check_Name_Constant(digit)) {
		strcpy(lat_id, Current_Constant->name);
		Cyr2Lat(lat_id);                        /* преобразуем кириллицу в латиницу */
		fputs(lat_id, fptr_ID);
		fputs(" /* ", fptr_ID);
		fputs(Current_Constant->name, fptr_ID);
		fputs(" */", fptr_ID);

	} else {
		fputs(digit, fptr_ID);
	}
};

/*****************************************
* Генерация идентификатора константы с оригинальным именем
* в файле программы NAME_IDC.c
* Cnn ...
******************************************/
void GenDgtWithCyrName_IDC (char *digit)
{
	char lat_id[BUFFER_LENGTH];
	char test_def[BUFFER_LENGTH];


	if(!Check_Name_Constant(digit)) {
		strcpy(lat_id, Current_Constant->name);
		Cyr2Lat(lat_id);                        /* преобразуем кириллицу в латиницу */

		fputs("\ti = ", fptr_IDC);
		fputs(lat_id, fptr_IDC);
		fputs("; /* ", fptr_IDC);
		fputs(Current_Constant->name, fptr_IDC);
		fputs(" */\n", fptr_IDC);

			if (Flag_CONFIG)
			{
				sprintf(test_def, "\tfputs( \"%s = \" , file);\n" , Current_Constant->name);
				fputs(test_def, fptr_IDC);
				fputs("\tsprintf(string, \"%d\\n\", i );\n", fptr_IDC);
				fputs("\tfputs( string, file);\n\n ", fptr_IDC);

			}

	} else {
		fputs(digit, fptr_IDC);
	}
};
/*****************************************
* Генерация spaces
* в файле интерфейсных констант NAME_id.h
******************************************/
void GenSpaces_ID (void)
{
	fputs(spaces, fptr_ID);
	return;
};
#endif


/*****************************************
* Генерация числа
* в файле программы NAMEproc.c
* Cnn ...
******************************************/
void Gen_Dgt (char *digit)
{
	char string[BUFFER_LENGTH];

	if(!Check_Name_Constant(digit))
		sprintf(string, "C_%d", Current_Constant->logname);
	else
		sprintf(string, "%s", digit);
	fputs(string, fptr_C);
	return;
};

/*****************************************
* Генерация unit
* в файле пользовательских констант NAMEcnst.h
* Cnn ...
******************************************/
void Gen_unit (char  *unit)
{
	char string[BUFFER_LENGTH];
	sprintf(string, "%s",unit);
	fputs(string, fptr_C);
	return;
};

/***************************************
* генерация заголовка в файле
* NAMEproc.h
****************************************/
void GenHeadersInProc (void)
{
	char string[BUFFER_LENGTH];

	fputs("/* FILE OF PROC-IMAGES OF THE PROJECT */\n", fptr_C);
	sprintf(string, "#include \"%sext.h\" /* Common files for all generated c-files */\n", BaseOutputFileName);
	fputs(string, fptr_C);
	sprintf(string, "#include \"%sxvar.h\"  /* Var-images */\n", BaseOutputFileName);
	fputs(string, fptr_C);
}

/***************************************
* генерация NAMEmain.c файла
* и NAMEproc.h
****************************************/
void GenMain (void)
{
	char string[BUFFER_LENGTH];

	strcpy(string, BaseOutputFileName);     /* конструируем имя NAMEmain.c */
	if (Flag_CPP)
	{
		strcat(string, "main.cpp");
	}
	else
	{
		strcat(string, "main.c");
	}

	Open_File_W(&fptr_C, string);

	fputs("/* MAIN FILE OF THE PROJECT */\n", fptr_C);
	sprintf(string, "#include \"%sext.h\" /* Common files for all generated c-files */\n", BaseOutputFileName);
	fputs(string, fptr_C);
	sprintf(string, "#include \"%sproc.h\"  /* Process-functions desription */\n", BaseOutputFileName);
	fputs(string, fptr_C);
	sprintf(string, "#include \"%sgvar.h\"  /* Project variables images */\n", BaseOutputFileName);
	fputs(string, fptr_C);
	sprintf(string, "#include \"%sio.h\"    /* Scan-input/output functions */\n", BaseOutputFileName);
	fputs(string, fptr_C);
	sprintf(string, "void Control_Loop(void);  /* for r_main.h */\n");
	fputs(string, fptr_C);
	sprintf(string, "#include \"r_main.h\"  /* Codes of the main-function that calls Control_Loop */\n\n"); /* r_cnst.h */
	fputs(string, fptr_C);
	fputs("void Control_Loop (void)    /* Управляющий алгоритм */\n{\n\tInput();\n", fptr_C);
	Current_Process = &First_Process;
	for (;;) {
		sprintf(string, "\tP%d();  /* Process %s */\n",
			Current_Process->logname,
			Current_Process->name);
		fputs(string, fptr_C);
		if (Current_Process->next == ZERO) break;
		Current_Process = Current_Process->next;
	}
	fputs("\tOutput();\n\tPrepare_PSW((INT16S)(PROCESS_N1), (INT16S)PROCESS_Nn);\n}", fptr_C);
	if (fptr_C != NULL) {
            fclose(fptr_C);
            fptr_C = NULL;
        }


	strcpy(string, BaseOutputFileName);     /* создадим файл NAMEproc.h*/
	strcat(string, "proc.h");
	Open_File_W(&fptr_C, string);
	fputs("/* Process-Images functions prototypes */\n", fptr_C);
	sprintf(string, "#ifndef _%sproc_h\n#define _%sproc_h 1\n\n", BaseOutputFileName, BaseOutputFileName);
	fputs(string, fptr_C);
	Current_Process = &First_Process;
	for (;;) {
		sprintf(string, "void P%d(void);  /* Process %s */\n",
			Current_Process->logname,
			Current_Process->name);
		fputs(string, fptr_C);
		if (Current_Process->next == ZERO) break;
		Current_Process = Current_Process->next;
	}

	fputs("\n#define PROCESS_N1 0\n", fptr_C);
	sprintf(string, "#define PROCESS_Nn %d /* Number Of Proc */\n",
		Current_Process->logname);
	fputs(string, fptr_C);

	fputs("\n#endif", fptr_C);
	if (fptr_C != NULL) {
            fclose(fptr_C);            /* закроем файл NAMEproc.h*/
            fptr_C = NULL;
        }

	return;
};

/*****************************************
* создание файла NAMEgvar.h
*        и файла NAMExvar.h
*        и файла NAMEtest.test
* (пользовательские переменные)
******************************************/
void GenVarDescription (void)
{
	char string[BUFFER_LENGTH];
	char var_IO_type[NAME_LENGTH];

	FILE *fptr_GVAR; /* для указателя на файл образов переменных */
	FILE *fptr_XVAR; /* для указателя на файл extern переменных */
	FILE *fptr_test;     /* указатель на файл теста */
	FILE *fptr_dll;     /* указатель на файл теста */


	strcpy(string, BaseOutputFileName);     /* создадим файл NAMEgvar.h*/
	strcat(string, "gvar.h");
	Open_File_W(&fptr_GVAR, string);

	strcpy(string, BaseOutputFileName);     /* создадим файл NAMExvar.h*/
	strcat(string, "xvar.h");
	Open_File_W(&fptr_XVAR, string);

	if ( Flag_TEST )
	{		
		strcpy(string, BaseOutputFileName);     /* создадим файл NAME_test.test */
		strcat(string, "test.test");
		Open_File_W(&fptr_test, string);
	}

	Open_File_W(&fptr_dll, "dll_interface.h"); /* создадим файл dll_interface.h */
	fputs("#include \"", fptr_dll);
	fputs(BaseOutputFileName, fptr_dll);
	fputs("proc.h\"\n", fptr_dll);

	fputs("#include \"", fptr_dll);
	fputs(BaseOutputFileName, fptr_dll);
	fputs("usr1.h\"\n", fptr_dll);

	fputs("#include \"", fptr_dll);
	fputs(BaseOutputFileName, fptr_dll);
	fputs("usr2.h\"\n", fptr_dll);


	fclose(fptr_dll);
	

	strcpy(string, "/* ======= ПЕРЕМЕННЫЕ =============*/\n");
	fputs(string, fptr_GVAR);
	fputs(string, fptr_XVAR);

	sprintf(string, "/* %sGVAR.H = Global Variables Image-File. */\n", BaseOutputFileName); /* пользовательский хедер */
	fputs(string, fptr_GVAR);
	sprintf(string, "#ifndef _%sgvar_h\n#define _%sgvar_h 1\n", BaseOutputFileName, BaseOutputFileName); /* пользовательский хедер */
	fputs(string, fptr_GVAR);

	sprintf(string, "/* %sXVAR.H = Extern Variables Image-File. */\n", BaseOutputFileName); /* пользовательский хедер */
	fputs(string, fptr_XVAR);
	sprintf(string, "#ifndef _%sxvar_h\n#define _%sxvar_h 1\n", BaseOutputFileName, BaseOutputFileName); /* пользовательский хедер */
	fputs(string, fptr_XVAR);

	strcpy(string, "/* ======= ПЕРЕМЕННЫЕ ПРОЦЕССОВ ===*/\n");
	fputs(string, fptr_GVAR);
	fputs(string, fptr_XVAR);

	Current_Process = &First_Process;
	while (Current_Process != ZERO) {            /* по всем процессам */
		Current_Variable = Current_Process->var;
		while (Current_Variable != ZERO) {      /* по всем переменным */
			if (Current_Variable->type != RW_FROM) { /* если описана не в текущем процессе - пропускаем */
				fputs("extern ", fptr_XVAR);
				if (Current_Variable->IO_type == RW_OUTPUT)
					strcpy(var_IO_type, "[2];\n");
				else
					strcpy(var_IO_type, ";\n");
				switch (Current_Variable->type) {
				case RW_LOG:
				case RW_SHORT:
					sprintf(string, "char P%dV%d%s", Current_Process->logname, Current_Variable->logname, var_IO_type);
					break;
				case RW_INT:
					sprintf(string, "int P%dV%d%s", Current_Process->logname, Current_Variable->logname, var_IO_type);
					break;
				case RW_LONG:
					sprintf(string, "long P%dV%d%s", Current_Process->logname, Current_Variable->logname, var_IO_type);
					break;
				case RW_FLOAT:
					sprintf(string, "float P%dV%d%s", Current_Process->logname, Current_Variable->logname, var_IO_type);
					break;
				case RW_DOUBLE:
					sprintf(string, "double P%dV%d%s", Current_Process->logname, Current_Variable->logname, var_IO_type);
					break;
				default:
					/* !!!!!!!!!!!!!!!!! */
					break;
				} /* End Of Switch (пропускаем переменные описанные в других процессах) */
				fputs(string, fptr_GVAR);
				fputs(string, fptr_XVAR);
			}
			Current_Variable = Current_Variable->next;
		}
		Current_Process = Current_Process->next;
	}

	/* ====================== I/O Reg ===================== */

	if (First_Input_Group.name[0] != ZERO) {
		Current_Input_Group = &First_Input_Group;
		sprintf(string,"/*======= Input Ports =============*/\n");
		fputs(string, fptr_GVAR);
		fputs(string, fptr_XVAR);
		for (; Current_Input_Group->logname != NOT_INITIALIZE; ) {

			if ( Flag_TEST )
			{
				// test generation
				if ( 0 != strstr( Current_Input_Group->name , "СЦЕНАРИЙ"))
				{
					char str[3];
					sprintf(str, "%d", Current_Input_Group->logname);

					fputs("script_port: " , fptr_test);
					fputs( str, fptr_test);
					fputs(" /*index*/, 0 /* ", fptr_test);
					fputs(Current_Input_Group->name , fptr_test);
					fputs("*/ \n", fptr_test);
				}
			}

			fputs("extern ", fptr_XVAR);
			if (Current_Input_Group->size == 8) {
				sprintf(string, "char PI%d;\n", Current_Input_Group->logname);
			} else {
				sprintf(string, "int PI%d;\n", Current_Input_Group->logname);
			}
			fputs(string, fptr_GVAR);
			fputs(string, fptr_XVAR);
			if (Current_Input_Group->next == 0) break;
			Current_Input_Group = Current_Input_Group->next;
		}
	}

	if (First_Output_Group.name[0] != ZERO) {
		sprintf(string, "\n/*======= Output Ports =============*/\n");
		fputs(string, fptr_GVAR);
		fputs(string, fptr_XVAR);
		Current_Output_Group = &First_Output_Group;
		for (; Current_Output_Group->logname != NOT_INITIALIZE; ) {
			fputs("extern ", fptr_XVAR);
			if (Current_Output_Group->size == 8) {
				sprintf(string, "char  PO%d, FPO%d;\n",
					Current_Output_Group->logname,
					Current_Output_Group->logname);
			} else {
				sprintf(string, "int PO%d, FPO%d;\n",
					Current_Output_Group->logname,
					Current_Output_Group->logname);
			}
			fputs(string, fptr_GVAR);
			fputs(string, fptr_XVAR);
			if (Current_Output_Group->next == 0) break;
			Current_Output_Group = Current_Output_Group->next;
		}
	}

	if (First_RAM_Group.name[0] != ZERO) {
		sprintf(string, "\n\n/*======= RAM Ports ============*/");
		fputs(string, fptr_GVAR);
		fputs(string, fptr_XVAR);
		Current_RAM_Group = &First_RAM_Group;
		for( ;Current_RAM_Group->logname != NOT_INITIALIZE; ) {
			fputs("extern ", fptr_XVAR);
			if (Current_RAM_Group->size == 8) {
				sprintf(string, "char PR%d, FPR%d;\n",
					Current_RAM_Group->logname,
					Current_RAM_Group->logname);
			} else {
				sprintf(string, "int PR%d, FPR%d;\n",
					Current_RAM_Group->logname,
					Current_RAM_Group->logname);
			}
			fputs(string, fptr_GVAR);
			fputs(string, fptr_XVAR);
			if (Current_RAM_Group->next == 0) break;
			Current_RAM_Group = Current_RAM_Group->next;
		}
	}
	strcpy(string, "#endif");
	fputs(string, fptr_GVAR);
	fputs(string, fptr_XVAR);

	return;
};

/******************************************
* Генерация NAMEinp.c и NAMEoutp.c
*  (файлов связи с входными/выходными портами,
*  чтения/записи)
*******************************************/
void GenInputOutput (void)
{
	char string[BUFFER_LENGTH];

	if (Flag_TEST)
	{
		strcpy(string, BaseOutputFileName);
		strcat(string, "_variables.var");
		Open_File_W(&fptr_VARIABLES_FOR_TEST, string);
	}

	strcpy(string, BaseOutputFileName);     /* создадим файл NAMEinp.c*/
	if (Flag_CPP)
	{
		strcat(string, "inp.cpp");
	}
	else
	{
		strcat(string, "inp.c");
	}
	
	Open_File_W(&fptr_INP, string);

	strcpy(string, BaseOutputFileName);     /* создадим файл NAMEoutp.c*/
	if (Flag_CPP)
	{
		strcat(string, "outp.cpp");
	}
	else
	{
		strcat(string, "outp.c");
	}

	Open_File_W(&fptr_OUTP, string);

	Gen_Ports_Reading();                    /* генерация кода чтения портов */

	Current_Process = &First_Process;
	while (Current_Process != ZERO) { /* по всем процессам */
		Current_Variable = Current_Process->var;
		while(Current_Variable != ZERO){  /* по всем переменным */
			Gen_Conversion_I_O();      /* генерируем строки преобразование физики в логику и обратно */

			Current_Variable = Current_Variable->next;
		}
		Current_Process = Current_Process->next;
	}

	Gen_Ports_Writing();                   /* генерация кода записи портов */

        if (fptr_INP != NULL) {
            fclose(fptr_INP);             /* закроем файл NAMEinp.h */
            fptr_INP;
        }
        if (fptr_OUTP != NULL) {
            fclose(fptr_OUTP);            /* закроем файл NAMEoutp.h */
            fptr_OUTP = NULL;
        }
	return;
};

/******************************************
* Генерация NAMEinp.c и NAMEoutp.c
*  (часть считывания входных/выходных портов)
*******************************************/
void Gen_Ports_Reading (void)
{
	char string[BUFFER_LENGTH];
	char lat_id[BUFFER_LENGTH];

	FILE * fptr_ports_descr;
		
	if (Flag_PROC_DESCR)
	{
		strcpy(string, BaseOutputFileName);  
		strcat(string, "ports.h");
		Open_File_W(&fptr_ports_descr, string);
		fputs("/* INPUT PORTS */\n", fptr_ports_descr);
	}
	
		sprintf(string, "#include \"r_cnst.h\"\n#include \"r_io.h\"\n#include \"%scnst.h\"\n", BaseOutputFileName);
	fputs(string, fptr_INP);
	fputs(string, fptr_OUTP);
	/* 080112 - исправлено: использование констант в адресах портов вв/выв */

	sprintf(string, "#include \"%sxvar.h\"\n\n", BaseOutputFileName);
	fputs(string, fptr_INP);
	fputs(string, fptr_OUTP);

	fputs("void Input (void)\n{\n", fptr_INP);
	fputs("void Output (void)\n{\n", fptr_OUTP);
	if (First_Input_Group.name[0] != ZERO) {
		Current_Input_Group = &First_Input_Group;
		fputs("/*======= Input Ports Reading =============*/\n", fptr_INP);
		for (; Current_Input_Group->logname != NOT_INITIALIZE; ) {
			if (Current_Input_Group->size == 8) {
				sprintf(string,"\tPI%d = INBYTE((INT16U)%s, (INT16U)%s); /* чтение байта */\n",
					Current_Input_Group->logname,
					Current_Input_Group->MB_address,
					Current_Input_Group->address);
			} else {
				sprintf(string,"\tPI%d = INWORD((INT16U)%s, (INT16U)%s); /* чтение слова */\n",
					Current_Input_Group->logname,
					Current_Input_Group->MB_address,
					Current_Input_Group->address);
			}
			fputs(string, fptr_INP);

			if (Flag_PROC_DESCR)
			{
				strcpy(lat_id, Current_Input_Group->name);
				Cyr2Lat(lat_id);
				fputs("#define ", fptr_ports_descr);
				fputs(lat_id, fptr_ports_descr);
				sprintf(string," %d /*%s*/\n",
					Current_Input_Group->logname, Current_Input_Group->name);
				fputs(string, fptr_ports_descr);
			}
			if (Current_Input_Group->next == 0) break;
			Current_Input_Group = Current_Input_Group->next;
		} /* end of for */
	}

	if (Flag_PROC_DESCR)
	{
		fputs("\n/* OUTPUT PORTS */\n", fptr_ports_descr);	
	}

	if (First_Output_Group.name[0] != ZERO) {
		Current_Output_Group = &First_Output_Group;
		for (; Current_Output_Group->logname != NOT_INITIALIZE; ) {
			if (Current_Output_Group->size == 8) {
				sprintf(string, "\tFPO%d = OFF; PO%d = INBYTE((INT16U)%s, (INT16U)%s);\n",
					Current_Output_Group->logname,
					Current_Output_Group->logname,
					Current_Output_Group->MB_address,
					Current_Output_Group->address);
			} else {
				sprintf(string, "\tFPO%d = OFF; PO%d = INWORD((INT16U)%s, (INT16U)%s);\n",
					Current_Output_Group->logname,
					Current_Output_Group->logname,
					Current_Output_Group->MB_address,
					Current_Output_Group->address);
			}
			fputs(string, fptr_INP);

			if (Flag_PROC_DESCR)
			{
				strcpy(lat_id, Current_Output_Group->name);
				Cyr2Lat(lat_id);
				fputs("#define ", fptr_ports_descr);
				fputs(lat_id, fptr_ports_descr);
				sprintf(string," %d /*%s*/\n",
					Current_Output_Group->logname, Current_Output_Group->name);
				fputs(string, fptr_ports_descr);
			}

			if (Current_Output_Group->next == 0) break;
			Current_Output_Group = Current_Output_Group->next;
		} /* end of for */
	}

	if (First_RAM_Group.name[0] != ZERO) {
		Current_RAM_Group = &First_RAM_Group;
		for (; Current_RAM_Group->logname != NOT_INITIALIZE; ) {
			if (Current_RAM_Group->size == 8) {
				sprintf(string, "\tFPR%d = OFF; PR%d = IN_RAM_BYTE(%s, %s, %s);\n",
					Current_RAM_Group->logname,
					Current_RAM_Group->logname,
					Current_RAM_Group->segment,
					Current_RAM_Group->offset,
					Current_RAM_Group->VME_address);
			} else {
				sprintf(string, "\tFPR%d = OFF; PR%d = IN_RAM_WORD(%s, %s, %s);\n",
					Current_RAM_Group->logname,
					Current_RAM_Group->logname,
					Current_RAM_Group->segment,
					Current_RAM_Group->offset,
					Current_RAM_Group->VME_address);
			}
			fputs(string, fptr_INP);
			if (Current_RAM_Group->next == 0) break;
			Current_RAM_Group = Current_RAM_Group->next;
		}
	}

	if (Flag_PROC_DESCR)
	{
		fclose(fptr_ports_descr);
	}
	return;
}

/******************************************
* Генерация NAMEinp.c и NAMEoutp.c
* ВХОДНАЯ переменная
*  (часть преобразования физических портов
*  в логические переменные для входной переменной)
*******************************************/
void Gen_Input_Variable (void)
{
	char string[BUFFER_LENGTH];
	char string_for_test[BUFFER_LENGTH];


	switch (Current_Variable->type) {
	case RW_LOG: /* for input logical registr type */
		sprintf(string,
			"\tif (PI%d & MASK%d_S%d) P%dV%d = 1;\n\telse P%dV%d = 0;\n",
			Current_Part_Of_Var->logname_port,
			Current_Part_Of_Var->start_bit,
			Current_Part_Of_Var->size_port,
			Current_Process->logname,
			Current_Variable->logname,
			Current_Process->logname,
			Current_Variable->logname);
		fputs(string,  fptr_INP);

		if (Flag_TEST)
		{
			sprintf(string_for_test, "INPUT LOG %s /*name*/ %d /*owner_input_port*/ %d /*start_bit*/  \n", 
				Current_Variable->name,
				Current_Part_Of_Var->logname_port,
				Current_Part_Of_Var->start_bit);
			fputs(string_for_test, fptr_VARIABLES_FOR_TEST);

		}
		break;
	case RW_INT:
		if (Current_Variable->number_of_busy_bit ==
			Current_Part_Of_Var->size_port) { /* совпадает размер? */
				sprintf(string,  "\tP%dV%d = (INT16S)PI%d;\n", Current_Process->logname, Current_Variable->logname, Current_Part_Of_Var->logname_port);
				fputs(string,  fptr_INP);
		} else {
			cur_part_bit = 0;  /*==  if end part of var take next ==*/
			while ((Current_Part_Of_Var->start_bit + cur_part_bit) <
				(Current_Part_Of_Var->finish_bit)) {
					sprintf(string,
						"\tP%dV%d = 0;\n\tif (PI%d & MASK%d_S%d) P%dV%d |= MASK%d_S16;\n",
						Current_Process->logname,
						Current_Variable->logname,
						Current_Part_Of_Var->logname_port,
						(Current_Part_Of_Var->start_bit+cur_part_bit),
						Current_Part_Of_Var->size_port,
						Current_Process->logname,
						Current_Variable->logname,
						cur_reg_bit);
					cur_part_bit += 1;
					cur_reg_bit += 1;
					fputs(string, fptr_INP);
			}/* end of while */
		}/* end of else */


		if (Flag_TEST)
		{
			sprintf(string_for_test, "INPUT INT %s /*name*/ %d /*owner input port*/ %d /*start bit*/\n",
				Current_Variable->name,
				Current_Process->logname,
				Current_Part_Of_Var->start_bit);
			fputs(string_for_test, fptr_VARIABLES_FOR_TEST);

		}
		break;
	default:
		printf("\n%%Memory Error. Gen_Input_Variable.");
		exit(ZERO);
	}
	return;
};

/******************************************
* Генерация NAMEinp.c и NAMEoutp.c
* ВЫХОДНАЯ переменная
*  (часть преобразования физических портов
*  в логические переменные для входной переменной)
*******************************************/
void Gen_Output_Variable (void)
{
	char string[BUFFER_LENGTH];
	char string_for_test[BUFFER_LENGTH];

	switch (Current_Variable->type) {
	case RW_LOG:
		sprintf(string, "\tif (PO%d & MASK%d_S%d) P%dV%d[0] = 1;\n\telse P%dV%d[0] = 0;\n\tP%dV%d[1] = P%dV%d[0];\n",
			Current_Part_Of_Var->logname_port,
			Current_Part_Of_Var->start_bit,
			Current_Part_Of_Var->size_port,
			Current_Process->logname,
			Current_Variable->logname,
			Current_Process->logname,
			Current_Variable->logname,
			Current_Process->logname,
			Current_Variable->logname,
			Current_Process->logname,
			Current_Variable->logname);
		fputs(string, fptr_INP);
		sprintf(string,
			"\tif (P%dV%d[0] != P%dV%d[1]) {\n\t\tFPO%d = ON;\n\t\tif (!(P%dV%d[1] == ZERO)) PO%d |= MASK%d_S%d;\n\t\telse PO%d &= ~MASK%d_S%d;\n\t}\n",
			Current_Process->logname,
			Current_Variable->logname,
			Current_Process->logname,
			Current_Variable->logname,
			Current_Part_Of_Var->logname_port,
			Current_Process->logname,
			Current_Variable->logname,
			Current_Part_Of_Var->logname_port,
			Current_Part_Of_Var->start_bit,
			Current_Part_Of_Var->size_port,
			Current_Part_Of_Var->logname_port,
			Current_Part_Of_Var->start_bit,
			Current_Part_Of_Var->size_port);
		fputs(string, fptr_OUTP);
		if (Flag_TEST)
		{
			sprintf(string_for_test, "OUTPUT LOG %s /*name*/ %d /*owner_output_port*/ %d /*start_bit*/  \n", 
				Current_Variable->name,
				Current_Part_Of_Var->logname_port,
				Current_Part_Of_Var->start_bit);
			fputs(string_for_test, fptr_VARIABLES_FOR_TEST);

		}
		break;
	case RW_INT:
		if (Current_Variable->number_of_busy_bit ==
			Current_Part_Of_Var->size_port) { /* совпадают размеры переменной и порта? */
				sprintf(string,
					"\tP%dV%d[0] = (INT16S)PO%d;\n\tP%dV%d[1] = P%dV%d[0];\n",
					Current_Process->logname,
					Current_Variable->logname,
					Current_Part_Of_Var->logname_port,
					Current_Process->logname,
					Current_Variable->logname,
					Current_Process->logname,
					Current_Variable->logname);
				fputs(string, fptr_INP);
				sprintf(string,
					"\tif (P%dV%d[0] != P%dV%d[1]) {\n\t\tFPO%d = ON;\n\t\tPO%d = P%dV%d[1];\n\t}\n",
					Current_Process->logname,
					Current_Variable->logname,
					Current_Process->logname,
					Current_Variable->logname,
					Current_Part_Of_Var->logname_port,
					Current_Part_Of_Var->logname_port,
					Current_Process->logname,
					Current_Variable->logname);
				fputs(string, fptr_OUTP);

		} else { /* если переменная состоит из частей */
			cur_part_bit = 0;
			while ((Current_Part_Of_Var->start_bit + cur_part_bit) <
				(Current_Part_Of_Var->finish_bit)) {
					sprintf(string,
						"\tP%dV%d[0]=0;\n\tif (PO%d & MASK%d_S%d) P%dV%d[0] |= MASK%d_S16;\n\t P%dV%d[1] = P%dV%d[0];",
						Current_Process->logname,
						Current_Variable->logname,
						Current_Part_Of_Var->logname_port,
						(Current_Part_Of_Var->start_bit+cur_part_bit),
						Current_Part_Of_Var->size_port,
						Current_Process->logname,
						Current_Variable->logname,
						cur_reg_bit,
						Current_Process->logname,
						Current_Variable->logname,
						Current_Process->logname,
						Current_Variable->logname);
					fputs(string, fptr_INP);
					sprintf(string,
						"\tif (P%dV%d[0] != P%dV%d[1]) {\n\t\tFPO%d = ON;\n\t\tif (P%dV%d[1] & MASK%d_S16) PO%d |= MASK%d_S%d;\n\t\telse PO%d &= ~MASK%d_S%d;\n\t}\n",
						Current_Process->logname,
						Current_Variable->logname,
						Current_Process->logname,
						Current_Variable->logname,
						Current_Part_Of_Var->logname_port,
						Current_Process->logname,
						Current_Variable->logname,
						cur_reg_bit,
						Current_Part_Of_Var->logname_port,
						(Current_Part_Of_Var->start_bit+cur_part_bit),
						Current_Part_Of_Var->size_port,
						Current_Part_Of_Var->logname_port,
						(Current_Part_Of_Var->start_bit+cur_part_bit),
						Current_Part_Of_Var->size_port);
					fputs(string, fptr_OUTP);
					cur_part_bit += 1;
					cur_reg_bit += 1;
			}/* end of while */
		} /* end of else  */
		break;
	default:
		printf("\n%%Memory Error. Gen_Output_Variable.");
		exit(ZERO);
	}
	return;
};

/******************************************
* Генерация NAMEinp.c и NAMEoutp.c
* ОЗУ-переменная
*  (часть преобразования физических портов
*  в логические переменные для входной переменной)
*******************************************/
void Gen_RAM_Variable (void)
{
	char string[BUFFER_LENGTH];

	switch (Current_Variable->type) {
	case RW_LOG:
		sprintf(string, "\tif (PR%d & MASK%d_S%d) P%dV%d[0] = 1;\n\telse P%dV%d[0] = 0;\n\tP%dV%d[1] = P%dV%d[0];\n",
			Current_Part_Of_Var->logname_port,
			Current_Part_Of_Var->start_bit,
			Current_Part_Of_Var->size_port,
			Current_Process->logname,
			Current_Variable->logname,
			Current_Process->logname,
			Current_Variable->logname,
			Current_Process->logname,
			Current_Variable->logname,
			Current_Process->logname,
			Current_Variable->logname);
		fputs(string, fptr_INP);
		sprintf(string,
			"\tif (P%dV%d[0] != P%dV%d[1]) {\n\t\tFPR%d = ON;\n\t\tif (!(P%dV%d[1] == ZERO)) PR%d |= MASK%d_S%d;\n\t\telse PR%d &= ~MASK%d_S%d;\n\t}\n",
			Current_Process->logname,
			Current_Variable->logname,
			Current_Process->logname,
			Current_Variable->logname,
			Current_Part_Of_Var->logname_port,
			Current_Process->logname,
			Current_Variable->logname,
			Current_Part_Of_Var->logname_port,
			Current_Part_Of_Var->start_bit,
			Current_Part_Of_Var->size_port,
			Current_Part_Of_Var->logname_port,
			Current_Part_Of_Var->start_bit,
			Current_Part_Of_Var->size_port);
		fputs(string, fptr_OUTP);
		break;
	case RW_INT:
		if (Current_Variable->number_of_busy_bit ==
			Current_Part_Of_Var->size_port) { /* совпадают размеры переменной и порта? */
				sprintf(string,
					"\tP%dV%d[0] = (INT16S)PR%d;\n\tP%dV%d[1] = P%dV%d[0];\n",
					Current_Process->logname,
					Current_Variable->logname,
					Current_Part_Of_Var->logname_port,
					Current_Process->logname,
					Current_Variable->logname,
					Current_Process->logname,
					Current_Variable->logname);
				fputs(string, fptr_INP);
				sprintf(string,
					"\tif (P%dV%d[0] != P%dV%d[1]) {\n\t\tFPR%d = ON;\n\t\tPR%d = P%dV%d[1];\n\t}\n",
					Current_Process->logname,
					Current_Variable->logname,
					Current_Process->logname,
					Current_Variable->logname,
					Current_Part_Of_Var->logname_port,
					Current_Part_Of_Var->logname_port,
					Current_Process->logname,
					Current_Variable->logname);
				fputs(string, fptr_OUTP);

		} else { /* если переменная состоит из частей */
			cur_part_bit = 0;
			while ((Current_Part_Of_Var->start_bit + cur_part_bit) <
				(Current_Part_Of_Var->finish_bit)) {
					sprintf(string,
						"\tP%dV%d[0]=0;\n\tif (PR%d & MASK%d_S%d) P%dV%d[0] |= MASK%d_S16;\n\t P%dV%d[1] = P%dV%d[0];",
						Current_Process->logname,
						Current_Variable->logname,
						Current_Part_Of_Var->logname_port,
						(Current_Part_Of_Var->start_bit+cur_part_bit),
						Current_Part_Of_Var->size_port,
						Current_Process->logname,
						Current_Variable->logname,
						cur_reg_bit,
						Current_Process->logname,
						Current_Variable->logname,
						Current_Process->logname,
						Current_Variable->logname);
					fputs(string, fptr_INP);
					sprintf(string,
						"\tif (P%dV%d[0] != P%dV%d[1]) {\n\t\tFPR%d = ON;\n\t\tif (P%dV%d[1] & MASK%d_S16) PR%d |= MASK%d_S%d;\n\t\telse PR%d &= ~MASK%d_S%d;\n\t}\n",
						Current_Process->logname,
						Current_Variable->logname,
						Current_Process->logname,
						Current_Variable->logname,
						Current_Part_Of_Var->logname_port,
						Current_Process->logname,
						Current_Variable->logname,
						cur_reg_bit,
						Current_Part_Of_Var->logname_port,
						(Current_Part_Of_Var->start_bit+cur_part_bit),
						Current_Part_Of_Var->size_port,
						Current_Part_Of_Var->logname_port,
						(Current_Part_Of_Var->start_bit+cur_part_bit),
						Current_Part_Of_Var->size_port);
					fputs(string, fptr_OUTP);
					cur_part_bit += 1;
					cur_reg_bit += 1;
			}/* end of while */
		} /* end of else  */
		break;
	default:
		printf("\n%%Memory Error. Gen_RAM_Variable.");
		exit(ZERO);
	}
	return;
};

/* === ORIGIMAL == {
/* === ORIGIMAL ==     char string[BUFFER_LENGTH];
/* === ORIGIMAL ==
/* === ORIGIMAL ==      if(Current_Variable->type==LOG){
/* === ORIGIMAL == sprintf(string,
/* === ORIGIMAL == "\nif(PR%d & MASK%d_S%d){\n P%dV%d[0]=1;}else{P%dV%d[0] = 0;} P%dV%d[1]=P%dV%d[0];",
/* === ORIGIMAL ==     Current_Part_Of_Var->logname_port,
/* === ORIGIMAL ==     Current_Part_Of_Var->start_bit,
/* === ORIGIMAL ==     Current_Part_Of_Var->size_port,
/* === ORIGIMAL ==     Current_Process->logname,
/* === ORIGIMAL ==     Current_Variable->logname,
/* === ORIGIMAL ==     Current_Process->logname,
/* === ORIGIMAL ==     Current_Variable->logname,
/* === ORIGIMAL ==     Current_Process->logname,
/* === ORIGIMAL ==     Current_Variable->logname,
/* === ORIGIMAL ==     Current_Process->logname,
/* === ORIGIMAL ==     Current_Variable->logname);
/* === ORIGIMAL ==         fputs(string, fptrt_I);
/* === ORIGIMAL == sprintf(string,
/* === ORIGIMAL == "\nif(P%dV%d[0] != P%dV%d[1]){ FPR%d = ON; if(P%dV%d){\nPR%d |= MASK%d_S%d;}else{PR%d &= ~MASK%d_S%d;}}",
/* === ORIGIMAL ==     Current_Process->logname,
/* === ORIGIMAL ==     Current_Variable->logname,
/* === ORIGIMAL ==     Current_Process->logname,
/* === ORIGIMAL ==     Current_Variable->logname,
/* === ORIGIMAL ==     Current_Part_Of_Var->logname_port,
/* === ORIGIMAL ==     Current_Process->logname,
/* === ORIGIMAL ==     Current_Variable->logname,
/* === ORIGIMAL ==     Current_Part_Of_Var->logname_port,
/* === ORIGINAL ==     Current_Part_Of_Var->start_bit,
/* === ORIGINAL ==     Current_Part_Of_Var->size_port,
/* === ORIGINAL ==     Current_Part_Of_Var->logname_port,
/* === ORIGINAL ==     Current_Part_Of_Var->start_bit,
/* === ORIGINAL ==     Current_Part_Of_Var->size_port);
/* === ORIGINAL ==         fputs(string, fptrt_O);
/* === ORIGINAL ==
/* === ORIGINAL ==       }else{
/* === ORIGINAL ==         if(Current_Variable->type==INT){
/* === ORIGINAL ==          if(Current_Variable->number_of_busy_bit==
/* === ORIGINAL ==                    Current_Part_Of_Var->size_port){
/* === ORIGINAL == sprintf(string,
/* === ORIGINAL == "\n P%dV%d[0]=(INT16S)PR%d; P%dV%d[1]=P%dV%d[0];",
/* === ORIGINAL ==     Current_Process->logname,
/* === ORIGINAL ==     Current_Variable->logname,
/* === ORIGINAL ==     Current_Part_Of_Var->logname_port,
/* === ORIGINAL ==     Current_Process->logname,
/* === ORIGINAL ==     Current_Variable->logname,
/* === ORIGINAL ==     Current_Process->logname,
/* === ORIGINAL ==     Current_Variable->logname);
/* === ORIGINAL ==     fputs(string, fptrt_I);
/* === ORIGINAL == sprintf(string,
/* === ORIGINAL == "\nif(P%dV%d[0]!=P%dV%d[1]){FPR%d=ON; PR%d=P%dV%d[1];}",
/* === ORIGINAL ==     Current_Process->logname,
/* === ORIGINAL ==     Current_Variable->logname,
/* === ORIGINAL ==     Current_Process->logname,
/* === ORIGINAL ==     Current_Variable->logname,
/* === ORIGINAL ==     Current_Part_Of_Var->logname_port,
/* === ORIGINAL ==     Current_Part_Of_Var->logname_port,
/* === ORIGINAL ==     Current_Process->logname,
/* === ORIGINAL ==     Current_Variable->logname);
/* === ORIGINAL ==     fputs(string, fptrt_O);
/* === ORIGINAL ==
/* === ORIGINAL ==          }else{
/* === ORIGINAL == cur_part_bit = 0;
/* === ORIGINAL ==
/* === ORIGINAL == /*========  if end part of var take next ============*/
/* === ORIGINAL ==                while((Current_Part_Of_Var->start_bit + cur_part_bit) <
/* === ORIGINAL ==         (Current_Part_Of_Var->finish_bit)){
/* === ORIGINAL ==
/* === ORIGINAL == sprintf(string,
/* === ORIGINAL == /*12/02/92 05:08am for arithmetic*/
/* === ORIGINAL == "\nP%dV%d[0]=0;\nif(PR%d & MASK%d_S%d){\n P%dV%d[0] |= MASK%d_S16;}\n P%dV%d[1]=P%dV%d[0];",
/* === ORIGINAL ==     Current_Process->logname,
/* === ORIGINAL ==     Current_Variable->logname,
/* === ORIGINAL ==     Current_Part_Of_Var->logname_port,
/* === ORIGINAL ==     (Current_Part_Of_Var->start_bit+cur_part_bit),
/* === ORIGINAL ==     Current_Part_Of_Var->size_port,
/* === ORIGINAL ==     Current_Process->logname,
/* === ORIGINAL ==     Current_Variable->logname,
/* === ORIGINAL ==     cur_reg_bit,
/* === ORIGINAL ==     Current_Process->logname,
/* === ORIGINAL ==     Current_Variable->logname,
/* === ORIGINAL ==     Current_Process->logname,
/* === ORIGINAL ==     Current_Variable->logname);
/* === ORIGINAL ==     fputs(string, fptrt_I);
/* === ORIGINAL ==
/* === ORIGINAL == sprintf(string,
/* === ORIGINAL == "\nif(P%dV%d[0] != P%dV%d[1]){ FPR%d=ON; if(P%dV%d[1] & MASK%d_S16){\n PR%d |= MASK%d_S%d;}else{ PR%d &= ~MASK%d_S%d;}}",
/* === ORIGINAL ==     Current_Process->logname,
/* === ORIGINAL ==     Current_Variable->logname,
/* === ORIGINAL ==     Current_Process->logname,
/* === ORIGINAL ==     Current_Variable->logname,
/* === ORIGINAL ==     Current_Part_Of_Var->logname_port,
/* === ORIGINAL ==     Current_Process->logname,
/* === ORIGINAL ==     Current_Variable->logname,
/* === ORIGINAL ==     cur_reg_bit,
/* === ORIGINAL ==     Current_Part_Of_Var->logname_port,
/* === ORIGINAL ==     (Current_Part_Of_Var->start_bit+cur_part_bit),
/* === ORIGINAL ==     Current_Part_Of_Var->size_port,
/* === ORIGINAL ==     Current_Part_Of_Var->logname_port,
/* === ORIGINAL ==     (Current_Part_Of_Var->start_bit+cur_part_bit),
/* === ORIGINAL ==     Current_Part_Of_Var->size_port);
/* === ORIGINAL ==     fputs(string, fptrt_O);
/* === ORIGINAL ==     cur_part_bit += 1;
/* === ORIGINAL ==     cur_reg_bit += 1;
/* === ORIGINAL ==
/* === ORIGINAL ==     }/* end of while */
/* === ORIGINAL ==     }/* end of else*/
/* === ORIGINAL ==         }else{printf("\n%%ERR-Memory Error."); }
/* === ORIGINAL ==       }
/* === ORIGINAL == return(!ZERO);
/* === ORIGINAL == };
/* === ORIGINAL ==  */

/******************************************
* Генерация NAMEinp.c и NAMEoutp.c
*  Запись выходных портов (и ОЗУ-портов)
*******************************************/
void Gen_Ports_Writing (void)
{
	char string [BUFFER_LENGTH];

	if (First_Output_Group.name[0] != ZERO) {
		Current_Output_Group = &First_Output_Group;
		sprintf(string, "\n\n/*======= Output Port =============*/\n");
		fputs(string, fptr_OUTP);
		for (; Current_Output_Group->logname != NOT_INITIALIZE; ) {
			if (Current_Output_Group->size == 8) {
				sprintf(string,
					"\tif(FPO%d == ON) OUTBYTE((INT16U)%s, (INT16U)%s, (INT8U)~PO%d);\n",
					Current_Output_Group->logname,
					Current_Output_Group->MB_address,
					Current_Output_Group->address,
					Current_Output_Group->logname);
			} else {
				sprintf(string,
					"\tif(FPO%d == ON) OUTWORD((INT16U)%s, (INT16U)%s, (INT16U)~PO%d);\n",
					Current_Output_Group->logname,
					Current_Output_Group->MB_address,
					Current_Output_Group->address,
					Current_Output_Group->logname);
			}
			fputs(string, fptr_OUTP);
			if (Current_Output_Group->next == 0) break;
			Current_Output_Group = Current_Output_Group->next;
		} /* end of for */
	}
	if (First_RAM_Group.name[0] != ZERO) {
		Current_RAM_Group = &First_RAM_Group;
		for(; Current_RAM_Group->logname != NOT_INITIALIZE; ) {
			if (Current_RAM_Group->size == 8) {
				sprintf(string,
					"\tif (FPR%d == ON) OUT_RAM_BYTE(PR%d, %s, %s, %s);\n",
					Current_RAM_Group->logname,
					Current_RAM_Group->logname,
					Current_RAM_Group->segment,
					Current_RAM_Group->offset,
					Current_RAM_Group->VME_address);
			} else {
				sprintf(string,
					"\tif (FPR%d == ON) OUT_RAM_WORD(PR%d, %s, %s, %s);\n",
					Current_RAM_Group->logname,
					Current_RAM_Group->logname,
					Current_RAM_Group->segment,
					Current_RAM_Group->offset,
					Current_RAM_Group->VME_address);
			}
			fputs(string, fptr_OUTP);
			if (Current_RAM_Group->next == 0) break;
			Current_RAM_Group = Current_RAM_Group->next;
		}
	}
	sprintf(string, "}\n");
	fputs(string, fptr_INP);
	fputs(string, fptr_OUTP);
	return;
};

/******************************************
* Генерация NAMEinp.c и NAMEoutp.c
*
*  (для текущей пременной преобразования
*   физических портов в логику и обратно )
*******************************************/
void Gen_Conversion_I_O (void)      /* генерируем строки преобразование физики в логику и обратно */
{
	cur_reg_bit = 1;

	Current_Part_Of_Var = Current_Variable->port;
	while (Current_Part_Of_Var != ZERO) { /* If Connected With Port */


		switch (Current_Part_Of_Var->type) {
		case RW_INPUT:
			Gen_Input_Variable();
			break;
		case RW_OUTPUT:
			Gen_Output_Variable();
			break;
		case RW_RAM:
			Gen_RAM_Variable();
			break;
		default:
			printf("\n%% Gen_Convertion_IO Fatal Error.");
			exit(ZERO);
		}
		Current_Part_Of_Var = Current_Part_Of_Var->next;
	}
	return;
};


/********************************************
*  ГЕНЕРАЦИЯ С-КОДА ПРОЦЕССОВ
********************************************/


/* Gen_Define(unit)
/* char  *unit;
/* {
/*   Check_Constant(unit);
/*   sprintf(buffer2,"\n#define C_%d %s",Current_Constant->logname,
/*   Current_Constant->value);
/*   fputs(buffer2,fptrt_Var);
/* return(!ZERO);
/* };
*/

/* == Gen_St_Word()
/* == {
/* == /* == sprintf(buffer2,"\n#define NUMBER_OF_PROCESS %d",Current_Process->logname);*/
/* ==  fputs(buffer2,fptrt_Var);
/* ==  fputs("\n#define PROCESSOR_1  1 ",fptrt_Var);
/* ==  fputs("\n#ifdef PROCESSOR_1",fptrt_Var);
/* ==  fputs("\n#define PROCESS_N1 1",fptrt_Var);
/* ==  fputs("\n#define PROCESS_Nn 70",fptrt_Var);
/* ==  fputs("\n#endif",fptrt_Var);
/* ==  fputs("\n#ifdef PROCESSOR_2",fptrt_Var);
/* ==  fputs("\n#define PROCESS_N1 71",fptrt_Var);
/* ==  fputs("\n#define PROCESS_Nn 171",fptrt_Var);
/* ==  fputs("\n#endif",fptrt_Var);
/* == fputs("\n#ifdef PROCESSOR_3",fptrt_Var);
/* == fputs("\n#define PROCESS_N1 172",fptrt_Var);
/* == fputs("\n#define PROCESS_Nn 211",fptrt_Var);
/* == fputs("\n#endif",fptrt_Var);
/* == fputs("\n#ifdef PROCESSOR_4",fptrt_Var);
/* == fputs("\n#define PROCESS_N1 212",fptrt_Var);
/* == fputs("\n#define PROCESS_Nn 241",fptrt_Var);
/* == fputs("\n#endif",fptrt_Var);
/* == fputs("\n#include \"pragms.h\"",fptrt_Var);
/* == fputs("\n#include \"kr.h\"",fptrt_Var);
/* ==  fputs("\n#include \"ntsys.h\"",fptrt_Var);
/* ==  fputs("\n#include \"rconst.h\"",fptrt_Var);
/* ==  fputs("\n#include \"rio196.h\"",fptrt_Var);
/* ==  fputs("\n#include \"rlib196.h\"",fptrt_Var);
/* ==  fputs("\n#include \"crisCnst.h\"",fptrt_Var);
/* == return(!ZERO);
/* == };
*/

/*****************************************
*    Генерация начала процесса
*****************************************/
void GenProcess (char *unit)
{
	char string[BUFFER_LENGTH];
	char str[BUFFER_LENGTH];
	fpos_t       pos;             /* текущая длина конструируемого файла */

	Check_Name_Process(unit);     /* устанавливаем указатель на процесс */

	fgetpos(fptr_C, &pos);        /* проверим текущую длину файла */
        
#ifdef WIN32        
        if (pos >= (INT32S)CFileMAXLen) {
#else 
      //  if (pos.__pos >= (INT32S)CFileMAXLen) {
	if (pos >= (INT32S)CFileMAXLen) {
#endif                    
                if (fptr_C != NULL) {
                    fclose(fptr_C);            /* закроем файл NAMEp.h*/
                    fptr_C = NULL;
                }
		File_Number++;
		strcpy(string, BaseOutputFileName);     /* создадим новый файл NAME_pХХ.h*/
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
	}

	sprintf(string, "\nvoid P%d (void) /* ПРОЦЕСС: %s */\n{\n",
		Current_Process->logname,
		Current_Process->name);
	fputs(string, fptr_C);
	sprintf(string, "\tswitch (Check_State(%d)) {\n",
		Current_Process->logname);
	fputs(string, fptr_C);
	return;
};

/*****************************************
*    Генерация конца описания процесса
*****************************************/
void GenEndOfProcess (void)
{
	fputs("\n\t\tdefault:\n\t\t\tbreak;\n\t}\n}\n",fptr_C);
	return;
}


/*****************************************
*    Генерация начала описания состояния
*****************************************/
void GenBeginOfState (char  *unit)
{
	char string[BUFFER_LENGTH];
	Check_Name_State(unit);           /* настройка на состояние */
	/* sprintf(buffer2,"\n void P%dS%d(void) */  /* State %s *//*!!!!!",*/
	/* Current_Process->logname,                                         */
	/* Current_State->logname,                                           */
	/* Current_State->name);                                             */
	/* fputs(buffer2,fptr_C);                                       */
	sprintf(string,
		"\n\t\tcase %d:    /*  P%dS%d() - СОСТОЯНИЕ: %s */\n",
		Current_State->logname,
		Current_Process->logname,
		Current_State->logname,
		Current_State->name);
	fputs(string, fptr_C);
	return;
};

/*****************************************
*    Генерация конца описания состояния
*****************************************/
void GenEndOfState (void)
{
	fputs("\n\t\t\tbreak;", fptr_C);
	return;
};


/*****************************************
*    Генерация останова процесса по имени
*****************************************/
int GenStop (char  *unit)
{
	struct disc_process *Copy_Process = 0;
	char string[BUFFER_LENGTH];

	Copy_Process = Current_Process;
	if (Check_Name_Process(unit)) {
		Current_Process = Copy_Process;
		return(ZERO);
	}
	sprintf(string, "Set_Stop(%d);",
		Current_Process->logname);
	fputs(string, fptr_C);
	Current_Process = Copy_Process;
	return(!ZERO);
};

/*****************************************
*    Генерация останова текущего процесса
*****************************************/
void GenStopForCurrentProc (void)
{
	char string[BUFFER_LENGTH];

	sprintf(string, "Set_Stop(%d);",
		Current_Process->logname);
	fputs(string, fptr_C);
	return;
};

/*****************************************
*    Генерация ОШИБКИ процесса по имени
*****************************************/
int GenError (char  *unit)
{
	struct disc_process *Copy_Process = 0;
	char string[BUFFER_LENGTH];

	Copy_Process = Current_Process;
	if (Check_Name_Process(unit)) {
		Current_Process = Copy_Process;
		return(ZERO);
	}
	sprintf(string, "Set_Error(%d);",
		Current_Process->logname);
	fputs(string, fptr_C);
	Current_Process = Copy_Process;
	return(!ZERO);
};

/*****************************************
*    Генерация ОШИБКИ текущего процесса
*****************************************/
void GenErrorForCurrentProc (void)
{
	char string[BUFFER_LENGTH];

	sprintf(string, "Set_Error(%d);",
		Current_Process->logname);
	fputs(string, fptr_C);
	return;
};

/*****************************************
*    Генерация запуска процесса по имени
*****************************************/
int GenStart (char  *unit)
{
	struct disc_process *Copy_Process = 0;
	char string[BUFFER_LENGTH];

	Copy_Process = Current_Process;
	if (Check_Name_Process(unit)) {
		Current_Process = Copy_Process;
		return(ZERO);
	}
	sprintf(string, "Set_Start(%d);",
		Current_Process->logname);
	fputs(string, fptr_C);
	Current_Process = Copy_Process;
	return(!ZERO);
};

/*****************************************
*    Генерация запуска текущего процесса
*****************************************/
void GenStartForCurrentProc (void)
{
	char string[BUFFER_LENGTH];

	sprintf(string, "Set_Start(%d);",
		Current_Process->logname);
	fputs(string, fptr_C);
	return;
};


/*****************************************
*    Генерация перехода текущего процесса
* в состояние по имени
*****************************************/
int GenJMP (char *unit)
{
	struct disc_state *Copy_State = 0;
	char string[BUFFER_LENGTH];

	Copy_State = Current_State;
	if (Check_Name_State(unit)) {
		Current_State = Copy_State;
		return(ZERO);
	}
	sprintf(string, "Set_State(%d, %d);",
		Current_Process->logname,
		Current_State->logname);
	fputs(string, fptr_C);
	Current_State = Copy_State;
	return(!ZERO);
};

/*****************************************
*    Генерация перехода текущего процесса
* в следующее за текущим состояние
*****************************************/
int GenJMPInNextState (void)
{
	char string[BUFFER_LENGTH];

	if (Current_State->next == ZERO) {           /* проверка наличия след. состояния */
		return(ZERO);
	}
	sprintf(string, "Set_State(%d, %d);",
		Current_Process->logname,
		(Current_State->logname + 1));     /* +1 - значит в следующее */
	fputs(string, fptr_C);
	return(!ZERO);
};


/*****************************************
* Генерация ситуации процесс в сост СТОП
******************************************/
int GenSituationProcInSTOP (char *proc_name)  /* ситуация ПРОЦ в СТОП */
{
	struct disc_process *Copy_Process = 0;
	char string[BUFFER_LENGTH];

	Copy_Process = Current_Process;
	if (Check_Name_Process(proc_name)) {         /* нет такого? - ошибка */
		Current_Process = Copy_Process;
		return(ZERO);
	}
	sprintf(string, "(Check_State(%d) == STATE_OF_STOP)", Current_Process->logname);
	fputs(string, fptr_C);
	Current_Process = Copy_Process;
	return(!ZERO);
}
/*****************************************
* Генерация ситуации процесс в сост ОШИБКА
******************************************/
int GenSituationProcInERROR (char *proc_name)
{
	struct disc_process *Copy_Process = 0;
	char string[BUFFER_LENGTH];

	Copy_Process = Current_Process;
	if (Check_Name_Process(proc_name)) {         /* нет такого? - ошибка */
		Current_Process = Copy_Process;
		return(ZERO);
	}
	sprintf(string, "(Check_State(%d) == STATE_OF_ERROR)", Current_Process->logname);
	fputs(string, fptr_C);
	Current_Process = Copy_Process;
	return(!ZERO);
}
/*****************************************
* Генерация ситуации процесс в сост АКТИВНОЕ
* (не СТОП и не ОШИБКА)
******************************************/
int GenSituationProcInACTIVE (char *proc_name)
{
	struct disc_process *Copy_Process = 0;
	char string[BUFFER_LENGTH];

	Copy_Process = Current_Process;
	if (Check_Name_Process(proc_name)) {         /* нет такого? - ошибка */
		Current_Process = Copy_Process;
		return(ZERO);
	}
	sprintf(string, "(!(Check_State(%d) & MASK_OF_INACTIVITY))", Current_Process->logname);
	fputs(string, fptr_C);
	Current_Process = Copy_Process;
	return(!ZERO);
}
/*****************************************
* Генерация ситуации процесс в сост АКТИВНОЕ
* (не СТОП и не ОШИБКА)
******************************************/
int GenSituationProcInPASSIVE (char *proc_name)
{
	struct disc_process *Copy_Process = 0;
	char string[BUFFER_LENGTH];

	Copy_Process = Current_Process;
	if (Check_Name_Process(proc_name)) {         /* нет такого? - ошибка */
		Current_Process = Copy_Process;
		return(ZERO);
	}
	sprintf(string, "(Check_State(%d) & MASK_OF_INACTIVITY)", Current_Process->logname);
	fputs(string, fptr_C);
	Current_Process = Copy_Process;
	return(!ZERO);
}

/*****************************************
* Генерация ситуации процесс в состоянии
* <имя состояния>
******************************************/
int GenSituationProcInState(char *proc_name, char *state_name)
{
	struct disc_process *Copy_Process = 0;
	struct disc_state *Copy_State = 0;
	char string[BUFFER_LENGTH];

	Copy_Process = Current_Process;
	if (Check_Name_Process(proc_name)) {         /* нет такого процесса? - ошибка */
		Current_Process = Copy_Process;
		return(ZERO);
	}
	Copy_State   = Current_State;
	if (Check_Name_State(state_name)) {           /* нет такого состояния? - ошибка */
		Current_Process = Copy_Process;
		Current_State   = Copy_State;
		return(ZERO);
	}
	sprintf(string, "(Check_State(%d) == %d)",
		Current_Process->logname,
		Current_State->logname);
	fputs(string, fptr_C);
	Current_Process = Copy_Process;
	Current_State   = Copy_State;
	return(!ZERO);
}

/*****************************************
* Генерация С-аналога резервированного слова
* (пока только типы данных)
******************************************/
void GenRezWord (int data_type) {
	GenSpaces();                  /* формируем удобочитаемый текст */
	switch (data_type) {
	case RW_CASE:
		fputs("case", fptr_C);
		break;
	case RW_BREAK:
		fputs("break", fptr_C);
		break;
	case RW_DEFAULT:
		fputs("default", fptr_C);
		break;
	case RW_SWITCH:
		fputs("switch", fptr_C);
		break;
	case RW_ELSE:
		fputs("else", fptr_C);
		break;
	case RW_IF:
		fputs("if", fptr_C);
		break;
	case RW_SHORT:                /* SHORT */
		fputs("char", fptr_C);
		break;
	case RW_LONG:                 /* LONG */
		fputs("long", fptr_C);
		break;
	case RW_INT:                  /* INT */
		fputs("int", fptr_C);
		break;
	case RW_FLOAT:
		fputs("float", fptr_C);
		break;
	case RW_DOUBLE:
		fputs("double", fptr_C);
		break;
	case RW_VOID:
		fputs("void", fptr_C);
		break;
	case RW_SIGN:
		fputs("signed", fptr_C);
		break;
	case RW_UNSIGN:
		fputs("unsigned", fptr_C);
		break;
	default:
		printf("%%REFLEX-FATAL ERROR IN GENREZWORD FUNC. RW is %s", rezword[data_type]);
		exit(ZERO);
	}
}


/*****************************************
* Генерация таймаута 03/18/04 08:36pm - добавлено
******************************************/
int GenTimeOut (char *num)
{
	char string[BUFFER_LENGTH];

	if (!Gen_Var(num, SOURCE)) return(NO_VALUE);   /* new Function */
	sprintf(string, "if (Timeout(%d, %s)) ",
		Current_Process->logname,
		num);
	fputs(string, fptr_C);
	return(RESULT_OK);
};


/*****************************************
* Генерация внутреннего имени переменной
* и запись его во входную строку
* Input: unit-string,
*        unit_case: destin OR source
* return: 0 - Not Exist, 1-O'K)
*      unit = внутренний идентификатор переменной
******************************************/
int Gen_Var (char  *unit, INT16S unit_case)
{
	if (unit_case == SOURCE) {
		if(Convrt(unit)) return(!ZERO);  /* if digit or constant OK */
	}
	if (CheckNameVariable(unit)) { /* If Not Exist Then Error */
		return(ZERO);
	}
	if (Current_Variable->type != RW_FROM) {
		if (Current_Variable->IO_type == RW_OUTPUT) {
			if (unit_case == SOURCE) {
				sprintf(unit, "P%dV%d[0]",
					Current_Process->logname,
					Current_Variable->logname);
			} else {
				sprintf(unit, "P%dV%d[1]",
					Current_Process->logname,
					Current_Variable->logname);
			}
		} else {
			if ((Current_Variable->IO_type == RW_INPUT) && (unit_case != SOURCE))
				return(ZERO);
			sprintf(unit, "P%dV%d",
				Current_Process->logname,
				Current_Variable->logname);
		}
	} else {
		/*printf("\nPROCESS %s  LGNAME %s IS %s",Current_Process->name,
		*Current_Variable->name,
		*Current_Variable->name_from_proc);
		*/
		if (Current_Variable->IO_type==RW_OUTPUT) {
			if (unit_case == DESTINATION)
				sprintf(unit, "%s[1]", Current_Variable->name_from_proc);
			else
				sprintf(unit, "%s[0]", Current_Variable->name_from_proc);
		} else { /* for IO_Type */
			if ((Current_Variable->IO_type == RW_INPUT) && (unit_case == DESTINATION))
				return(ZERO);
			sprintf(unit, "%s", Current_Variable->name_from_proc);
		}
	}
	return(!ZERO);
};

/*****************************************
* Генерация числа
* Input: num (константа или число),
* return: 0 - Not Exist, 1-O'K)
*      unit = внутренний идентификатор числа
************************************************/
int Convrt (char  *num) {
	return(check_digit(num));
}


/*****************************************
* Генерация внутреннего имени переменной/числа/константы
* и запись его в файл
* Input: unit-string
* return: 0 - Not Exist, 1-O'K
*      unit = внутренний идентификатор переменной
******************************************/
void GenVariable (char *unit)
{

	char string[BUFFER_LENGTH];
	if (check_digit(unit)) {      /* число? */
		GenUnit(unit);           /* внутреннее имя числа + удобочитаемый текст */
		return;
	};
	CheckNameVariable(unit);      /* если не константа - то переменная */
	if (Current_Variable->type != RW_FROM) {        /* если описана в тек. процессе */
		if (Current_Variable->IO_type == RW_OUTPUT) { /* если переменная ВЫХОДНАЯ*/
			sprintf(string,"P%dV%d[1]",
				Current_Process->logname,
				Current_Variable->logname);
		} else {    /* если входная */
			/* === КОНТРОЛЬ ЗАПРЕТА ИЗМЕНЕНИЯ НУЖНО СДЕЛАТЬ !!!!!!! if((Current_Variable->IO_type==RW_INPUT)&&(unit_case==DESTINATION)) */
			sprintf(string, "P%dV%d",
				Current_Process->logname,
				Current_Variable->logname);
		}
	} else {            /* иначе описана в другом процессе (ИЗ) и ...*/
		if (Current_Variable->IO_type == RW_OUTPUT){ /* если ВЫХОДНАЯ */
			sprintf(string, "%s[1]",Current_Variable->name_from_proc);
		} else {       /* иначе ВХОДНАЯ */
			/* === КОНТРОЛЬ ЗАПРЕТА ИЗМЕНЕНИЯ НУЖНО СДЕЛАТЬ !!!!!!!    if ((Current_Variable->IO_type==RW_INPUT)&&(unit_case==DESTINATION)) */
			/*===                   return(ZERO); /* запись ? - ОШИБКА */
			sprintf(string, "%s", Current_Variable->name_from_proc);
		}
	}
	GenUnit(string);           /* внутреннее имя переменной + удобочитаемый текст */
	return;
};

/*****************************************************
* генерация внутреннего идентификатора образа порта
* по пользовательскому идентификатору
* для вставки в Си-строку
*****************************************************/
Gen_Port(char  *unit) /* Input: unit-string */
	/* return: 0 - Not Exist, 1-O'K and unit=Pc%d) */
{

	if(!Check_Name_Output_Group(unit)){ /* if find */
		sprintf(unit,"PO%d",Current_Output_Group->logname);
		return(!ZERO);
	}
	if(!Check_Name_Input_Group(unit)){ /* if find */
		sprintf(unit,"PI%d",Current_Input_Group->logname);
		return(!ZERO);
	}
	if(!Check_Name_RAM_Group(unit)){ /* if find */
		sprintf(unit,"PR%d",Current_RAM_Group->logname);
		return(!ZERO);
	}
	return(ZERO);
};


#ifdef GEN_ID
void GenDebugStates (void)
{
        
	char string[BUFFER_LENGTH];
	if (!Flag_MAP) return;

	Current_State = Current_Process->stat;
	if (Current_State != ZERO) {
		for (;;) {
			sprintf(string, "%s\n", Current_State->name);
			fputs(string,fptr_C);
			if (Current_State->next == 0)
				break;
			Current_State = Current_State->next;
		}
	}
	return;
};

/*************************************
* генерация файла с перечислением имен
* процессов/состояний (для отладки)
**************************************/
void GenDebugFile (void)
{
	char string[BUFFER_LENGTH];

	strcpy(string, BaseOutputFileName);   /* открываем SYM-file файл привязки */
	strcat(string, "_dps.dbg");
	Open_File_W(&fptr_C, string);

	/*======== Hard Copy Of Processes States ===========*/
	Current_Process = &First_Process;
	for (;;) {
		sprintf(string, " %s\n", Current_Process->name);
		fputs(string, fptr_C);
		GenDebugStates();
		if(Current_Process->next == 0) break;
		Current_Process = Current_Process->next;
	}
        if (fptr_C != NULL) {
            fclose(fptr_C);
            fptr_C = NULL;
        }
	return;
};

#endif


/*======== Hard Copy Of Constant ===========*/
void GenSYMFile (void)
{
	char string[BUFFER_LENGTH];

	if (!Flag_MAP) return;
	strcpy(string, BaseOutputFileName);   /* открываем SYM-file файл привязки */
	strcat(string, ".sym");
	Open_File_W(&fptr_SYM, string);

#ifdef TEST_MODE_SEM
	printf("\n=== CONSTANTS");
#endif
	fputs("\n/* КОНСТАНТЫ */",
		fptr_SYM);
	Current_Constant = &First_Constant;
	for (;;) {
		H_C_Constant();
		if (Current_Constant->next == 0) break;
		Current_Constant = Current_Constant->next;
	}
	/*======== Hard Copy Of Input Port ===========*/
#ifdef TEST_MODE_SEM
	printf("\n=== PORTS");
#endif
	fputs("\n/*= ПОРТЫ =*/",
		fptr_SYM);
	Current_Input_Group = &First_Input_Group;
	if (Current_Input_Group->name[0] == ZERO) goto SKIP_IG;
#ifdef TEST_MODE_SEM
	printf("\n=== I-PORTS");
#endif
	for (;;) {
		H_C_Input();
		if (Current_Input_Group->next == 0) break;
		Current_Input_Group = Current_Input_Group->next;
	}
SKIP_IG:
	/*======== Hard Copy Of Output Port ===========*/

	Current_Output_Group = &First_Output_Group;
	if (Current_Output_Group->name[0] == ZERO) goto SKIP_OG;
#ifdef TEST_MODE_SEM
	printf("\n=== O-PORTS");
#endif
	for (;;) {
		H_C_Output();
		if (Current_Output_Group->next == 0) break;
		Current_Output_Group = Current_Output_Group->next;
	}
SKIP_OG:
	/*======== Hard Copy Of RAM Port ===========*/

	Current_RAM_Group = &First_RAM_Group;
	if (Current_RAM_Group->name[0] == ZERO) goto SKIP_RG;
#ifdef TEST_MODE_SEM
	printf("\n=== RAM-PORTS");
#endif
	for(;;){
		H_C_RAM();
		if (Current_RAM_Group->next == 0) break;
		Current_RAM_Group = Current_RAM_Group->next;
	}
SKIP_RG:

#ifdef TEST_MODE_SEM
	printf("\n=== PROCESSES");
#endif
	/*======== Hard Copy Of Processes States ===========*/
	fputs("\n/*======================== ПРОЦЕССЫ =============================*/",
		fptr_SYM);
	Current_Process = &First_Process;
	for (;;) {
		sprintf(string,"\n### ИМЯ ПРОЦЕССА: %s, ЛОГ. ИМЯ : P%d",
			Current_Process->name,
			Current_Process->logname);
		fputs(string,fptr_SYM);
		sprintf(string, "\n###### СОСТОЯНИЯ ПРОЦЕСА: ");
		fputs(string, fptr_SYM);
		H_C_States();
		if(Current_Process->next == 0) break;
		Current_Process = Current_Process->next;
	}

#ifdef TEST_MODE_SEM
	printf("\n=== VARIABLES");
#endif
	fputs("\n/*======================= ПЕРЕМЕННЫЕ ============================*/",
		fptr_SYM);
	Current_Process = &First_Process;
	for (;;) {
		H_C_Variables();
		if(Current_Process->next == 0) break;
		Current_Process = Current_Process->next;
	}
	return;
};

H_C_Constant(){
	char string[BUFFER_LENGTH];
	sprintf(string,
		"\n ИМЯ КОНСТАНТЫ: %s,  ЗНАЧЕНИЕ: %s,    ЛОГ.ИМЯ: C_%d",
		Current_Constant->name,
		Current_Constant->value,
		Current_Constant->logname);

	fputs(string,fptr_SYM);
	return(!ZERO);
};

H_C_Input()
{
	char string[BUFFER_LENGTH];
	sprintf(string,"\n ИМЯ ПОРТА:    %s",
		Current_Input_Group->name);
	fputs(string,fptr_SYM);
	sprintf(string,"\n ТИП ПОРТА:    Input",
		Current_Input_Group->name);
	fputs(string,fptr_SYM);
	sprintf(string,"\n АДРЕС ПОРТА: %s",
		Current_Input_Group->address);
	fputs(string,fptr_SYM);
	if(Current_Input_Group->size == 16){
		sprintf(string,"\n РАЗМЕР:    Word",
			Current_Input_Group->name);
		fputs(string,fptr_SYM);
	}else{
		sprintf(string,"\n РАЗМЕР:    Byte",
			Current_Input_Group->name);
		fputs(string,fptr_SYM);
	}
	sprintf(string,"\n ЛОГ.ИМЯ: PI%d",
		Current_Input_Group->logname);
	fputs(string,fptr_SYM);
	return(!ZERO);
};

H_C_Output()
{
	char string[BUFFER_LENGTH];
	sprintf(string,"\n\n ИМЯ ПОРТА:    %s",
		Current_Output_Group->name);
	fputs(string,fptr_SYM);
	/*printf("%s",string);*/
	sprintf(string,"\n ТИП ПОРТА:    Output",
		Current_Output_Group->name);
	fputs(string,fptr_SYM);
	sprintf(string,"\n АДРЕС ПОРТА: %s",
		Current_Output_Group->address);
	fputs(string,fptr_SYM);
	if(Current_Output_Group->size == 16){
		sprintf(string,"\n РАЗМЕР:    Word",
			Current_Output_Group->name);
		fputs(string,fptr_SYM);
	}else{
		sprintf(string,"\n РАЗМЕР:    Byte",
			Current_Output_Group->name);
		fputs(string,fptr_SYM);
	}
	sprintf(string,"\n ЛОГ.ИМЯ: PO%d",
		Current_Output_Group->logname);
	fputs(string,fptr_SYM);
	return(!ZERO);
};

H_C_RAM()
{
	char string[BUFFER_LENGTH];
	sprintf(string,"\n\n ИМЯ ПОРТА:    %s",
		Current_RAM_Group->name);
	fputs(string,fptr_SYM);
	/*printf("%s",string);*/
	sprintf(string,"\n ТИП ПОРТА:    RAM",
		Current_RAM_Group->name);
	fputs(string,fptr_SYM);
	sprintf(string,"\n Segment:      %s",
		Current_RAM_Group->segment);
	fputs(string,fptr_SYM);
	sprintf(string,"\n Offset:       %s",
		Current_RAM_Group->offset);
	fputs(string,fptr_SYM);
	sprintf(string,"\n АДРЕС ПО СШ:  %s",
		Current_RAM_Group->VME_address);
	fputs(string,fptr_SYM);
	if(Current_RAM_Group->size == 16){
		sprintf(string,"\n РАЗМЕР:    Word",
			Current_RAM_Group->name);
		fputs(string,fptr_SYM);
	}else{
		sprintf(string,"\n РАЗМЕР:    Byte",
			Current_RAM_Group->name);
		fputs(string,fptr_SYM);
	}
	sprintf(string,"\n ЛОГ.ИМЯ: PR%d",
		Current_RAM_Group->logname);
	fputs(string,fptr_SYM);
	return(!ZERO);
};

H_C_States()
{
	char string[BUFFER_LENGTH];
	Current_State = Current_Process->stat;
	if(Current_State != ZERO){
		for(;;){
			sprintf(string,"\n      ИМЯ СОСТОЯНИЯ: %s,    ЛОГ.ИМЯ: P%dS%d",
				Current_State->name,
				Current_Process->logname,
				Current_State->logname);
			fputs(string,fptr_SYM);
			if(Current_State->next==0)
			{break;}
			Current_State = Current_State->next;
		}
	}
	return(!ZERO);
};

H_C_Variables()
{
	char string[BUFFER_LENGTH];

	Current_Variable = Current_Process->var;
	if (Current_Variable != ZERO) {
		for (;;) {
			if (Current_Variable->type != RW_FROM) {
				fputs("\n\n ИМЯ ПЕРЕМЕННОЙ: ", fptr_SYM);
				fputs(Current_Variable->name, fptr_SYM);
				sprintf(string, ",\tЛОГ.ИМЯ: P%dV%d",
					Current_Process->logname,
					Current_Variable->logname);
				fputs(string, fptr_SYM);

				switch (Current_Variable->type){
				case RW_INT:
					fputs("\n ТИП: Integer",fptr_SYM);
					break;
				case RW_LOG:
					fputs("\n ТИП: Logical",fptr_SYM);
					break;
				case RW_LONG:
					fputs("\n ТИП: Long Integer",fptr_SYM);
					break;
				case RW_SHORT:
					fputs("\n ТИП: Short Integer",fptr_SYM);
					break;
				default:
					fputs("\n ТИП: Float",fptr_SYM);
					break;
				}
				sprintf(string,"\n ТАБЛИЦА ФИЗ. ОБРАЗА:");
				fputs(string,fptr_SYM);
#ifdef TEST_MODE_SEM
				printf("\n=== H_C_IMAGE");
#endif
				H_C_Image();
#ifdef TEST_MODE_SEM
				printf("\n=== H_C_FOR_PROC");
#endif
				H_C_For_Proc();
			}
			if (Current_Variable->next == 0) break;
			Current_Variable = Current_Variable->next;
		} /* end of for */
	}
	return(!ZERO);
};

H_C_Image() {
	char string [BUFFER_LENGTH];
	INT16S i, j;
	i=0;
	Current_Part_Of_Var=Current_Variable->port;
	if ((Current_Part_Of_Var != (struct disc_port *)ZERO) &&
		(Current_Part_Of_Var != (struct disc_port *)1)) {
			if (Current_Variable->type == RW_LOG) {
				fputs("\n\tCоответствует биту ", fptr_SYM);
				sprintf(string, "%d порта %s",
					(Current_Part_Of_Var->start_bit-1),
					Current_Part_Of_Var->name);
				fputs(string,fptr_SYM);
			} else {
				fputs("\n--------------------------------------------",fptr_SYM);
				fputs("\n| N Бита       |    N Бита    |  Имя       |",fptr_SYM);
				fputs("\n| Переменной   |      Порта   |  Порта     |",fptr_SYM);
				fputs("\n--------------------------------------------",fptr_SYM);
				for (i=0; ; ) {
					for (j=((Current_Part_Of_Var->start_bit)-1);
						j < ((Current_Part_Of_Var->finish_bit)-1);
						j++, i++) {
							fputs("\n|    ", fptr_SYM);
							sprintf(string, "%d", i);
							fputs(string, fptr_SYM);
							fputs("   |    ", fptr_SYM);
							sprintf(string, "%d", j);
							fputs(string, fptr_SYM);
							fputs("   | ", fptr_SYM);
							fputs(Current_Part_Of_Var->name, fptr_SYM);
					};
					if (Current_Part_Of_Var->next == 0) {
						fputs("\n------------", fptr_SYM);
						break;
					}
					Current_Part_Of_Var = Current_Part_Of_Var->next;
				}
			}
	}
	if ((Current_Part_Of_Var == (struct disc_port *)ZERO)) {
		fputs("\n Нет Физического Образа.", fptr_SYM);
	}
	if ((Current_Part_Of_Var == (struct disc_port *)1)){
		fputs("\n ????? Is Equel ONE.", fptr_SYM);
	}
	return(!ZERO);
};

H_C_For_Proc() {
	Current_For_Proc = Current_Variable->forproc;
	if (Current_For_Proc == (struct disc_forproc *)RW_LOCAL) {
		fputs("\n Доступна только из процесса ", fptr_SYM);
		fputs(Current_Process->name, fptr_SYM);
	}
	if (Current_For_Proc == (struct disc_forproc *)RW_ALL) {
		fputs("\n Доступна из всех процессов.", fptr_SYM);
	}
	if ((Current_For_Proc != (struct disc_forproc *)ZERO)
		&& (Current_For_Proc != (struct disc_forproc *)RW_LOCAL)
		&& (Current_For_Proc != (struct disc_forproc *)RW_ALL)) {
			fputs("\n Доступна из следующих процессов:\n\t", fptr_SYM);
			fputs(Current_Process->name, fptr_SYM);
			fputs("(Процесс-Хозяин)\n\t", fptr_SYM);
			for (;;) {
				fputs(Current_For_Proc->name, fptr_SYM);
				fputs("\n\t", fptr_SYM);
				if (Current_For_Proc->next == 0) {break;}
				Current_For_Proc = Current_For_Proc->next;
			}
	}
	return(!ZERO);
};


/*sprintf(string,"\n extern INT16S INWORD(INT16S);");
/*fputs(string,fptr);
/*sprintf(string,"\n extern char  INBYTE(INT16S);");
/*fputs(string,fptr);
/*sprintf(string,"\n extern void OUTWORD(INT16S,INT16S);");
/* /*fputs(string,fptr);
/*sprintf(string,"\n extern void OUTBYTE(INT16S,INT16S);");
/*fputs(string,fptr);
/*sprintf(string,"\n extern INT16S IN_RAM_WORD(INT16S,INT16S,INT16S);");
/* /*fputs(string,fptr);
/*sprintf(string,"\n extern char  IN_RAM_BYTE(INT16S,INT16S,INT16S);");
/*fputs(string,fptr);
/*sprintf(string,"\n extern void OUT_RAM_WORD(INT16S,INT16S,INT16S,INT16S);");
/* /*fputs(string,fptr);
/*sprintf(string,"\n extern void OUT_RAM_BYTE(INT16S,INT16S,INT16S,INT16S);");
/*fputs(string,fptr);
/**/
/*return(!ZERO);
/*};
*/






/*fputs("\n extern INT16S INWORD(INT16S,INT32S);",fptrt_Prog);  /* адрес по СШ, адрес */
/*fputs("\n extern char  INBYTE(INT16S,INT32S);",fptrt_Prog);
/*fputs("\n extern void OUTWORD(INT16S,INT32S,INT16S);",fptrt_Prog); /* адрес по СШ, адрес, данные */
/*fputs("\n extern void OUTBYTE(INT16S,INT32S,char );",fptrt_Prog);
/*fputs("\n extern INT16S IN_RAM_WORD(INT16S,INT16S,INT16S);" ,fptrt_Prog);
/*fputs("\n extern char  IN_RAM_BYTE(INT16S,INT16S,INT16S);" ,fptrt_Prog);
/*fputs("\n extern void OUT_RAM_WORD(INT16S,INT16S,INT16S,INT16S);" ,fptrt_Prog);
/*fputs("\n extern void OUT_RAM_BYTE(INT16S,INT16S,INT16S,INT16S);" ,fptrt_Prog); */
/* fputs("\n\n /*========== Extern C-Routine =================*/
/* ",fptrt_Prog);
/*fputs("\n extern INT32S Get_DW(INT16S,INT32S);",fptrt_Prog);
/*fputs("\n extern INT16S  Get_W(INT16S,INT32S);",fptrt_Prog);
/*fputs("\n extern char  Get_B(INT16S,INT32S);",fptrt_Prog);
/*fputs("\n extern void Send_DW(INT16S,INT32S,INT32S);",fptrt_Prog);
/*fputs("\n extern void Send_W(INT16S,INT32S,INT16S);",fptrt_Prog);
/*fputs("\n extern void Send_B(INT16S,INT32S,char );",fptrt_Prog);
/*fputs("\n extern INT32S Get_MB_DW(INT16S,INT32S);",fptrt_Prog);
/*fputs("\n extern INT16S  Get_MB_W(INT16S,INT32S);",fptrt_Prog);
/*fputs("\n extern char  Get_MB_B(INT16S,INT32S);",fptrt_Prog);
/*fputs("\n extern void Send_MB_DW(INT16S,INT32S,INT32S);",fptrt_Prog);
/*fputs("\n extern void Send_MB_W(INT16S,INT32S,INT16S);",fptrt_Prog);
/*fputs("\n extern void Send_MB_B(INT16S,INT32S,char );",fptrt_Prog);
/*fputs("\n extern char  Set_MB(char );",fptrt_Prog);
/*fputs("\n extern void Restore_MB(char );",fptrt_Prog); */

