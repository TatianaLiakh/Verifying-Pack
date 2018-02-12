#include "const.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "typedef.h"
#include "prototyp.h"
#include "glob_ext.h"

char REWUNIT_Flag = ZERO;

/*----------------------------------------------------------------------------*/
void hello (INT16S argc, char **argv){
	INT32S  i;                       /* 32-� ���������! */
	char    *bstringptr;
	char    *bendptr;                /* byte pointers */

	/* void enfilname(), openfil(); */
	/* char * Strr_chr(char *,INT16S); */

	Flag_LIS = OFF;                  /* ���� �������� */
	Flag_MAP = OFF;                  /* ���� ����� �������� ������� */
	CFileMAXLen = 200000L;           /* ����������� �� ����� �-����� */
	strcpy(InputFileName, "");       /* �������� ��� �������� ����� */
	strcpy(BaseOutputFileName, "");  /* �������� ������ ���� �������� ������ */

	if (argc == 1) {    /* NO PARAMETERS */
		printf("      ==================================================================\n");
		printf("      =                                                                =\n");
		printf("      =    Reflex V1.0, IA&E, Novosibirsk, Russia. Copyleft (c) 2002   =\n");
		printf("      =    written by Vladimir E. Zyubin, mailto:zyubin@iae.nsk.su     =\n");
		printf("      =    Syntax is: reflex [option] filename                         =\n");
		printf("      =    Options:                                                    =\n");
		printf("      =        -Cl=xxx (C-file length in bytes), e.g. -Cl=10000        =\n");
		printf("      =        -L      (Create listing file)                           =\n");
		printf("      =        -M      (Create map file)                               =\n");
		printf("      =        -Oxxx   (Output, filename), e.g. -Oexam                 =\n");
// NEW 

		printf("      =        -P      (Create .cpp files)                             =\n");
		printf("      =        -G      (Create ports.h file)                          =\n");
		printf("      =        -T      (Test-mode generation)                          =\n");
		printf("      =        -N      (Create .cfg files)                          =\n");

//END NEW

		printf("      =        (-x- = turn switch x off)                               =\n");
		printf("      =    Default options: -Cl=200000 -L- -M-                         =\n");
		printf("      =                                                                =\n");
		printf("      ==================================================================\n");
		/*          printf("\n-@xxx   Command string file     -Cxxx 'C' limits\n");
		*          printf("\n-Cl=xxx C-file length           -Cxxx 'C' limits");
		*          printf("\n-gN     Stop after N warnings   -Ixxx Include files path");
		*          printf("\n-iN     Identifiers length      -jN   Stop after N errors");
		*          printf("\n-D      Syntax definition file  -L    Create a listing file");
		*          printf("\n-M      Create a map file       -Oxxx Output, filename");
		*          printf("\n-oxxx   Output, directory       -w    Turn on warnings");
		*/
		exit(ZERO);
	} else {                           /* ��������� ��������� ������ */
		for (i = 1; (i < (argc-1)) && (argv[i][0] == '-'); i++)
		{   /* ���������� ���� ����� ��������� ������ */
			switch (argv[i][1]) {    /* ��������� ����� */
			case 'C':           /* �������� ����������� �-����������� */
				switch (argv[i][2]) {    /* ������ ����� ����������� */
				case 'l':           /* ����� ��������� ����� */
					if (argv[i][3] == '=') {
						bstringptr = &argv[i][4]; /* ����� ������ ����� */
						CFileMAXLen = strtoul(bstringptr, &bendptr, 0);
#ifdef TEST_MODE
						printf("\n%%RCSL-64-MSG, ����������� �� ����� �-����� %ld ������", CFileMAXLen);
#endif
						if (CFileMAXLen <= 5000) {  /* ��������� ������ */
							printf("\n%%RCSL-64-FATERR, � ��������� ������ ��������� ����������� ���� \n ��� ����������� �� ����� ������ 5� - %s", argv[i]);
							exit(ZERO);
						}
					} else {       /* ��������� ������ */
						printf("\n%%RCSL-64-FATERR, � ��������� ������ ��������� ����������� ���� - %s", argv[i]);
						exit(ZERO);
					}
					break;
				default:
					printf("\n%%RCSL-64-FATERR, � ��������� ������ ��������� ����������� ���� - %s", argv[i]);
					exit(ZERO);
				}
				break;
			case 'L': /* ���������� ������� ������� */
				switch (argv[i][2]){
				case ZERO:
					Flag_LIS = ON;      /* ���� �������� ON */
#ifdef TEST_MODE
					printf("\n%%RCSL-64-MSG, ���� �������� �������");
#endif
					break;
				case '-':
					Flag_LIS = OFF;     /* ���� �������� OFF */
					break;
				default:
					printf("\n%%RCSL-64-FATERR, � ��������� ������ ��������� ����������� ���� - %s", argv[i]);
					exit(ZERO);
				}
				break;
			case 'M': /* ���������� ������� ���� �������� */
				switch (argv[i][2]){
				case ZERO:
					Flag_MAP = ON;      /* ���� ����� �������� ON */
#ifdef TEST_MODE
					printf("\n%%RCSL-64-MSG, ���� �����-�������� �������");
#endif
					break;
				case '-':
					Flag_MAP = OFF;     /* ���� ����� �������� OFF */
					break;
				default:
					printf("\n%%RCSL-64-FATERR, � ��������� ������ ��������� ����������� ���� - %s", argv[i]);
					exit(ZERO);
				}
				break;
			case 'O': /* �������� ���� ����� ������ ��� */
				bstringptr = &argv[i][2]; /* ����� ������ ����� */
				strcpy(BaseOutputFileName, bstringptr); /* copy filename */
				break;

			case 'T': /* ���������� ������� ���� ����� */
				switch (argv[i][2]){
				case ZERO:
					Flag_TEST = ON;      /* ���� ����� ON */
#ifdef TEST_MODE
					printf("\n%%RCSL-64-MSG, ���� ����� �������");
#endif
					break;
				case '-':
					Flag_TEST = OFF;     /* ���� ����� OFF */
					break;
				default:
					printf("\n%%RCSL-64-FATERR, � ��������� ������ ��������� ����������� ���� - %s", argv[i]);
					exit(ZERO);
				}
				break;
			case 'P': /* ���������� ������� ����� � ������� .cpp */
				switch (argv[i][2]){
				case ZERO:
					Flag_CPP = ON;      /* ���� ����� ON */
#ifdef TEST_MODE
					printf("\n%%RCSL-64-MSG, ���� ����� �������");
#endif
					break;
				case '-':
					Flag_CPP = OFF;     /* ���� ����� OFF */
					break;
				default:
					printf("\n%%RCSL-64-FATERR, � ��������� ������ ��������� ����������� ���� - %s", argv[i]);
					exit(ZERO);
				}
				break;
				
			case 'G': /* ���������� ������� ����� � ������� .cpp */
				switch (argv[i][2]){
				case ZERO:
					Flag_PROC_DESCR = ON;      /* ���� ����� ON */
#ifdef TEST_MODE
					printf("\n%%RCSL-64-MSG, ���� ��������� �������� ������ �������");
#endif
					break;
				case '-':
					Flag_PROC_DESCR = OFF;     /* ���� ����� OFF */
					break;
				default:
					printf("\n%%RCSL-64-FATERR, � ��������� ������ ��������� ����������� ���� - %s", argv[i]);
					exit(ZERO);
				}
				break;
			case 'N': /* ���������� ������� ���� .cfg */
				switch (argv[i][2]){
				case ZERO:
					Flag_CONFIG = ON;      /* ���� ����� ON */
#ifdef TEST_MODE
					printf("\n%%RCSL-64-MSG, ���� ��������� ����� .cnfg �������");
#endif
					break;
				case '-':
					Flag_CONFIG = OFF;     /* ���� ����� OFF */
					break;
				default:
					printf("\n%%RCSL-64-FATERR, � ��������� ������ ��������� ����������� ���� - %s", argv[i]);
					exit(ZERO);
				}
				break;
			default:
				printf("\n%%RCSL-64-FATERR, � ��������� ������ ��������� ����������� ���� - %s", argv[i]);
				exit(ZERO);
			} /* end of switch */
		} /* ����� for, ����� ��������� ������ */

		if (i != (argc-1) || !isalpha(argv[i][0])) { /* ��������� ��� ����� ��� ������ ����������� */
			printf("\n%%RCSL-64-FATERR, � ��������� ������ ���������� ������ - %s", argv[i]);
			exit(ZERO);
		}
		strcpy(InputFileName, argv[i]);
		if (strchr(InputFileName, '.') == ZERO) {  /* ���� �� ������� ���������� - ��������� */
			strcat(InputFileName, ".rcs");
		}
		if (!strcmp(BaseOutputFileName,"")) {   /* ���� �� ���� ������������������� */
			strcpy(BaseOutputFileName, InputFileName);
		}
		if (strchr(BaseOutputFileName, '.') != ZERO) {    /* "file.ext" -> "file" */
			i = ((INT32S)strchr(BaseOutputFileName, (INT16S)'.') - (INT32S)BaseOutputFileName);
			BaseOutputFileName[i] = ZERO;
		}
		if (strlen(BaseOutputFileName) > FLENGTH) {   /* ���� ����� ����� ������ FLENGTH-� */
			printf("\n%%RCSL-64-FATERR, ����� ����� ��������� ����� �� ������ ��������� 4 ������� - %s", BaseOutputFileName);
			exit(ZERO);
		}
	} /* ����� ��������� ��������� ������ */
#ifdef TEST_MODE
	printf("\n%%RCSL-64-TESTING, ������� ��� ��������� ����� - %s, �������� - %s", BaseOutputFileName,InputFileName);
#endif

};

/*----------------------------------------------------------------------------*/

void fskptr (FILE *fptr)
{
	if(fseek(fptr, (INT32S)0, 0) < 0)
	{
		perror("fseek");
		exit(ZERO );
	};
}

/*----------------------------------------------------------------------------*/


/*********************************************
* ��������� ������ �������
*
**********************************************/
int select_unit (void)
{
	int select_unit2(void);

#ifdef TEST_MODE_SELECT
	printf("= SU");
#endif


	strcpy(prev_unit, unit);      /* ������ ����� ������� ������� */
	strcpy(prev_spaces, spaces);  /* ������ ����� ����-����������� ������� ������� */

	if (REWUNIT_Flag)
		REWUNIT_Flag = ZERO;
	else
		spaces[0] = 0;                /* �������� spaces ��� ���������� ������ select_unit2*/

	Flag_Comment = ZERO;
	Flag_CString = ZERO;
	do {  /* ���� ����������� � �-������ */
		if(!select_unit2()) return(FALSE); /* ���������� �� */

		if ((Flag_PASS) && (Flag_CString)) {       /* ���� �-������ � ������������� */
			if (!Gen_Var(unit, DESTINATION)) {    /* ���� ��.���������� ��� ��������� */
				if (!Gen_Var(unit, SOURCE)) {    /* ���  �������� */
					if (!Gen_Port(unit)) {      /* ���� ���� */
						if(!isascii(unit[0]))  /* ���� ��-������ - ������ */
							error_msg(63, line_count, unit, NONE);
					}
				}
			}                        /* ���� ���-�� ������ (����, ����� � ��.) */
			if (Flag_CASE) {         /* ����������� � ���� ��������� ? */
				fputs(spaces, fptr_C); /* �������� ������� �������������� */
				fputs(unit, fptr_C);      /* � ���������� ������� */
			} else {                       /* �������������� - ����������� �������������� */
				if (!Flag_Comment)        /* ���� �� ������ ����������� */
					warning_msg(3, line_count, unit);
			}
		}
	} while (Flag_Comment || Flag_CString);   /* ���� ����������� � �-������ */

#ifdef TEST_MODE_SELECT
	printf("u = %s,",unit);
#endif

#ifdef TEST_MODE_SELECT
	if (strlen(buffer1) > BUFFER_LENGTH-3) printf("\n FATAL ERROR OF buffer1 - BL is %d, buffer is\n%s\n",strlen(buffer1),buffer1);
	if (strlen(unit) > BUFFER_LENGTH-3) printf("\n FATAL ERROR OF unit - UL is %d, unit is\n%s\n",strlen(unit), unit);
	if (strlen(spaces) > BUFFER_LENGTH-3) printf("\n FATAL ERROR OF spaces - BL is %d, buffer is\n%s\n",strlen(spaces),spaces);
#endif

	return(TRUE);
};

/************************************************
*          --- int Work_U_Spaces ---
* ��������� ������ ������������
* (����� ������������ �������� �-����),
* ���������� ��������� �� ������ �������
* ���� ����������� ������� ������� - ��������������
* ���� �������� ���� - ���������� 0
* ����� - ���������� !0
************************************************/

int Work_Up_Spaces (void) {
	int i, space_warning_flag, j, k;
	char local_spaces[BUFFER_LENGTH];
#ifdef TEST_MODE_SELECT
	printf("= (W_U_S)");
#endif

	space_warning_flag = ZERO;
	i = 0;
	for (;;) {
		for (;  isspace(buffer1[str_count]) && isascii(buffer1[str_count]); i++, str_count++) {
			local_spaces[i] = buffer1[str_count];
			if (i == (BUFFER_LENGTH - 2)) {   /* ������������ ������ ������������ ? */
				i--;                          /* ��������� ������������ */
				if (!space_warning_flag) {    /* ������ �������������� */
					space_warning_flag = !ZERO;
					warning_msg(2, line_count, "\0");
				}
			}

		}
		if (buffer1[str_count] == ZERO) {
			Flag_CString = ZERO;                    /* ������� ���� �-������ */
			if (!newstring()) return(FALSE);
		} else {
			local_spaces[i] = ZERO;              /* ����� ������, ���������� */
#ifdef TEST_MODE_SELECT
			printf(" %s", local_spaces);
#endif
			j = 0; k = 0;
			if (Flag_Comment || (local_spaces[0] == '\0')) return (TRUE);  /* ���������� ����� �� ������������ � ������ ������ */
			j = strlen(spaces); k = strlen(local_spaces);
			if (spaces[0] != '\0') {
				if ((spaces[j - 1] == '\n') && (local_spaces[k - 1] == '\n')) {
					/* printf("\nskip the LF in Local_spaces, strlen is %d", strlen(local_spaces)); */
					return(TRUE);
				}
			}

			if (j + k > BUFFER_LENGTH) return(TRUE); /* ����������, ���� ���.����� ������ ������ */
			strcat(spaces, local_spaces);
			return(TRUE);
		}
	}
};

/********************************************
* Select unit routine after test special sign // and */
/* work up buffer1 only and write unit */
int select_unit2 (void)
{
#ifdef TEST_MODE_SELECT
	printf(" (s_u2) ");
#endif

	if (!Work_Up_Spaces()) return(FALSE);

	if (isalpha(buffer1[str_count])  || /* ���� ����� (����|�����) ��� _ */
		!isascii(buffer1[str_count]) ||
		(buffer1[str_count] == '_')) {
			return (Get_Identifier());      /* ����� ������������� */
	} else {                                          /* ����� */
		if (isdigit(buffer1[str_count]) ||           /* ���� ����� */
			((buffer1[str_count] == '.') &&          /* ��� ������ ����.����� */
			isdigit(buffer1[str_count + 1]))) {
				return(Get_Number());      /* ����� ����� */
		} else {                                     /* ����� */
			if (buffer1[str_count] == '#') {        /* ������ ? */
				Get_Pragma();
				if(compare (unit, rezword[RW_CSTRING])) {
					Flag_CString = !ZERO;
					return(select_unit2());  /* � ��������� ��������� unit */
				}
				return(TRUE);
			} else {
				if ((buffer1[str_count] == '*') && /* �������� ����������� ? */
					(buffer1[str_count + 1] == '/')) {
						if (!Flag_Comment) /* ���� �� ����� ������������ � ����� ����������� �������� ������������ - ������ */
							error_msg(77, line_count, "\0", NONE);
						Flag_Comment = ZERO; str_count += 2;  /* �������� ������ */

						return(select_unit2());       /* � ��������� ��������� unit */
				} else {
					if ((buffer1[str_count] == '/') && /* �������� ����������� ? */
						(buffer1[str_count + 1] == '*')) {
							Flag_Comment = !ZERO; str_count+=2;  /* and skip them */
							return(select_unit2());       /* � ��������� ��������� unit */
					} else {
						return(Get_xFix());
					}
				}
			}
		}
	}
};

/**************************************
* ����� �-���� � unit
***************************************/
int Get_xFix (void)
{
	int i;
#ifdef TEST_MODE_SELECT
	printf("\n= Get_xFix");
#endif

	/* ===== ������� "������" - "<<=" � ">>=" */
	if (((buffer1[str_count]     == '>') &&
		(buffer1[str_count + 1] == '>') &&
		(buffer1[str_count + 2] == '=')) ||
		((buffer1[str_count]     == '<') &&
		(buffer1[str_count + 1] == '<') &&
		(buffer1[str_count + 2] == '='))) {
			for (i = 0; i < 3; i++, str_count++)
				unit[i] = buffer1[str_count];
			unit[i] = ZERO;
			return(TRUE);
	}

	/* ===== ������� "������" -  */
	if (((buffer1[str_count] == '<') && (buffer1[str_count+1]=='=')) || /* <= */
		((buffer1[str_count] == '>') && (buffer1[str_count+1]=='=')) || /* >= */
		((buffer1[str_count] == '=') && (buffer1[str_count+1]=='=')) || /* == */
		((buffer1[str_count] == '!') && (buffer1[str_count+1]=='=')) || /* != */
		((buffer1[str_count] == '&') && (buffer1[str_count+1]=='=')) || /* &= */
		((buffer1[str_count] == '^') && (buffer1[str_count+1]=='=')) || /* ^= */
		((buffer1[str_count] == '|') && (buffer1[str_count+1]=='=')) || /* |= */
		((buffer1[str_count] == '*') && (buffer1[str_count+1]=='=')) || /* *= */
		((buffer1[str_count] == '/') && (buffer1[str_count+1]=='=')) || /* /= */
		((buffer1[str_count] == '%') && (buffer1[str_count+1]=='=')) || /* %= */
		((buffer1[str_count] == '+') && (buffer1[str_count+1]=='=')) || /* += */
		((buffer1[str_count] == '-') && (buffer1[str_count+1]=='=')) || /* -= */
		((buffer1[str_count] == '&') && (buffer1[str_count+1]=='&')) || /* && */
		((buffer1[str_count] == '|') && (buffer1[str_count+1]=='|')) || /* || */
		((buffer1[str_count] == '<') && (buffer1[str_count+1]=='<')) || /* << */
		((buffer1[str_count] == '>') && (buffer1[str_count+1]=='>')) || /* >> */
		((buffer1[str_count] == '+') && (buffer1[str_count+1]=='+')) || /* ++ */
		((buffer1[str_count] == '-') && (buffer1[str_count+1]=='-'))) { /* -- */
			for (i = 0; i < 2; i++, str_count++)
				unit[i] = buffer1[str_count];
			unit[i] = ZERO;
			return(TRUE);
	}

	/* ===== ��������� "������" -  */
	unit[0] = buffer1[str_count];
	str_count++;
	unit[1] = ZERO;
	return(TRUE);
};

/**************************************
* ����� ������ � unit
***************************************/
int Get_Pragma (void)
{
	int i;
#ifdef TEST_MODE_SELECT
	printf("\n= Get_Pragma");
#endif

	unit[0] = buffer1[str_count]; str_count++;   /* ����� ���� ������ */
	for (i = 1; (buffer1[str_count] == '_') ||   /* ���� ��� ������� */
		isalnum(buffer1[str_count]) ||   /* ��� �����|����. ����� */
		!isascii(buffer1[str_count]);    /* ��� ������� ����� */
	i++, str_count++) {
		unit[i] = buffer1[str_count];           /* ��������� unit */
	}
	unit[i] = ZERO; /* ���������� */
	return(TRUE);   /* ������� */
}
/**************************************
* ����� ������������� � unit
***************************************/
int Get_Identifier (void)
{
	int i;

#ifdef TEST_MODE_SELECT
	printf("\n= Get_Identifier");
#endif
	for (i = 0; (buffer1[str_count] == '_') ||   /* ���� ������� */
		isalnum(buffer1[str_count]) ||   /* ��� �����|����. ����� */
		!isascii(buffer1[str_count]);    /* ��� ������� ����� */
	i++, str_count++) {
		unit[i] = buffer1[str_count];           /* ��������� unit */
	}
	unit[i] = ZERO; /* ���������� */
	return(TRUE);   /* ������� */
}

/**************************************
* ����� ����� � unit (���������, �����, �����������������)
* ���� - ���� �� ������ �����, ���� �� . � ����� (.0,.1 � �.�.)
***************************************/
int Get_Number (void)
{
	int i;
#ifdef TEST_MODE_SELECT
	printf("\n= Get_Number");
#endif

	i = 0;

	if (isdigit(buffer1[str_count])) { /* ����� */
		for (; isdigit(buffer1[str_count]); i++, str_count++) {
			unit[i] = buffer1[str_count];           /* ��������� unit */
		}                                            /* ����� ���� */
		switch (buffer1[str_count]) {                /* ��� ������ */
		case '.': /* ��������� ���������� */
			unit[i] = buffer1[str_count]; i++; str_count++;  /* ��������� unit */
			for (; isdigit(buffer1[str_count]); i++, str_count++) {
				unit[i] = buffer1[str_count];           /* ��������� unit */
			}
			if ((buffer1[str_count] != 'e') ||
				(buffer1[str_count] != 'E')) { /* ������� ? */
					unit[i] = ZERO; /* ���������� */
					return(TRUE);   /* ������� */
			} /* ���� ������� - ������������� ������ */
		case 'e': /* ������� */
		case 'E':
			unit[i] = buffer1[str_count]; i++; str_count++;  /* ��������� unit */
			if ((buffer1[str_count] == '+') || (buffer1[str_count] == '-')) {
				unit[i] = buffer1[str_count]; i++; str_count++;  /* ��������� unit */
			}
			for (; isdigit(buffer1[str_count]); i++, str_count++) {
				unit[i] = buffer1[str_count];           /* ��������� unit */
			}
			break;
		case 'x': /* ����������������� */
		case 'X':
			unit[i] = buffer1[str_count]; i++; str_count++;  /* ��������� unit */
			for (; isxdigit(buffer1[str_count]); i++, str_count++) {
				unit[i] = buffer1[str_count];           /* ��������� unit */
			}
			if ((buffer1[str_count] == 'l') || (buffer1[str_count] == 'L')) {
				unit[i] = buffer1[str_count]; i++; str_count++;  /* ��������� unit */
			}
			break;
		case 'l': /* ������� */
		case 'L':
			unit[i] = buffer1[str_count]; i++; str_count++;  /* ��������� unit */
			break;
		default: /* ����� ����� */
			break;
		}
	} else { /* ���������, ������� � ����� .� */
		unit[i] = buffer1[str_count]; i++; str_count++;  /* ��������� unit */
		for (; isdigit(buffer1[str_count]); i++, str_count++) {
			unit[i] = buffer1[str_count];           /* ��������� unit */
		}
		if ((buffer1[str_count] != 'e') ||
			(buffer1[str_count] != 'E')) {       /* ������� ? ��� - ����� */
				unit[i] = ZERO; return(TRUE);      /* ��� ����� ����� */
		}
		unit[i] = buffer1[str_count]; i++; str_count++;  /* ����� � (�������) */
		if ((buffer1[str_count] == '+') || (buffer1[str_count] == '-')) {
			unit[i] = buffer1[str_count]; i++; str_count++;  /* ����� ���� */
		}
		for (; isdigit(buffer1[str_count]); i++, str_count++) {
			unit[i] = buffer1[str_count];           /* ��������� �������� ������� */
		}
	}
	unit[i] = ZERO; /* ���������� */
	return(TRUE);   /* ������� */
}

/**************************************
* ������� unit (������� � ��������)
***************************************/
void cl_unit (void)
{
	unit[0]=ZERO;
};

/**************************************
* ������� spaces (������� � ����-������������ �������)
***************************************/
void cl_spaces (void)
{
	unit[0]=ZERO;
};

/*----------------------------------------------------------------------------*/
/* Read new string */
INT16S newstring (void) {
	/*printf("\nNEW string");*/
	str_count = 0;
	line_count++;
	if (fgets(buffer1, BUFFER_LENGTH, fptr_RCS) == ZERO) {
		if (Flag_Unexpect==TRUE) error_msg(13, line_count, "\0",NONE);
		return(FALSE);
	} else {
		if (Flag_LIS)
			fprintf(fptr_LIS, "%5d          %s", line_count, buffer1);
		return(TRUE);
	}
};

/*----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/* Return position on old unit */
INT16S rewunit (void)
{
	INT16S i;
	REWUNIT_Flag = !ZERO;

	i = strlen(unit);
	if (str_count >= i) {
		str_count = str_count - i;
		strcpy(unit, prev_unit);
	} else { /* ������ ���������, ����� ��� ���� �������� rewunit ������� */
		error_msg(29, line_count, "\0", NONE);
		printf("\nINTERNAL INFO: SN is %d.\nU is %s.\nPU is %s.\nB is %s.\nSC is %d.\nI is %d.", line_count, unit, prev_unit, buffer1, str_count, i);
		exit(ZERO);
	}
	return(!ZERO);
};


/************************************************
*
************************************************/

char * Strr_chr(char *str,INT16S ch){
	INT16S i;
	INT32S j;
	for (i=0; ((INT8U)str[i] != (INT8U)ch); i++) {
		if (str[i] == ZERO) return((char *)ZERO);
	}
	j = (INT32S)str + (INT32S)i;
	return((char *)j);
}
/************************************************
*            --- Open_File_W ---
*
************************************************/
INT16S Open_File_W(FILE **fptr, char *filname){
	fptr[0] = fopen(filname, "w+");
	if (fptr[0] == 0) {
		printf("\n%%RCSL-64-FATERW, �� ���� ������� ���� \"%s\" - ", filname);
		perror("fopen");
		exit(ZERO);
	};
	if (fseek(fptr[0], (INT32S)0, 0) < 0) {
		printf("\n%%RCSL-64-FATERW, �� ���� ������� ���� \"%s\" - ", filname);
		perror("fseek");
		exit(ZERO);
	};
	return(!ZERO);
}
/************************************************
*            --- Open_File_R ---
*
************************************************/
INT16S Open_File_R(FILE **fptr, char *filname){
	fptr[0] = fopen(filname, "r");
	if (fptr[0] == 0) {
		printf("\n%%RCSL-64-FATERR, �� ���� ������� ���� \"%s\" - ", filname);
		perror("fopen");
		exit(ZERO);
	};
	if (fseek(fptr[0], (INT32S)0, 0) < 0) {
		printf("\n%%RCSL-64-FATERR, �� ���� ������� ���� \"%s\" - ", filname);
		perror("fseek");
		exit(ZERO);
	};
	return(!ZERO);
}

#ifdef GEN_ID
/************************************************
* ��������� �������������� � �������� �� �������������� � ���������
*
************************************************/

void Cyr2Lat (char *id)
{
	char str[2*BUFFER_LENGTH];
	int i, j;

	for (i = 0, str[0] = ZERO; id[i] != ZERO; i++) {

		switch (id[i]) {
		case '�':
			strcat(str,"A"); break;
		case '�':
			strcat(str,"B"); break;
		case '�':
			strcat(str,"V"); break;
		case '�':
			strcat(str,"G"); break;
		case '�':
			strcat(str,"D"); break;
		case '�':
			strcat(str,"YE"); break;
		case '�':
			strcat(str,"YO"); break;
		case '�':
			strcat(str,"ZH"); break;
		case '�':
			strcat(str,"Z"); break;
		case '�':
			strcat(str,"I"); break;
		case '�':
			strcat(str,"J"); break;
		case '�':
			strcat(str,"K"); break;
		case '�':
			strcat(str,"L"); break;
		case '�':
			strcat(str,"M"); break;
		case '�':
			strcat(str,"N"); break;
		case '�':
			strcat(str,"O"); break;
		case '�':
			strcat(str,"P"); break;
		case '�':
			strcat(str,"R"); break;
		case '�':
			strcat(str,"S"); break;
		case '�':
			strcat(str,"T"); break;
		case '�':
			strcat(str,"U"); break;
		case '�':
			strcat(str,"F"); break;
		case '�':
			strcat(str,"KH"); break;
		case '�':
			strcat(str,"TS"); break;
		case '�':
			strcat(str,"CH"); break;
		case '�':
			strcat(str,"SH"); break;
		case '�':
			strcat(str,"SCH"); break;
		case '�':
			strcat(str,"_"); break;
		case '�':
			strcat(str,"Y"); break;
		case '�':
			strcat(str,"_"); break;
		case '�':
			strcat(str,"E"); break;
		case '�':
			strcat(str,"YU"); break;
		case '�':
			strcat(str,"YA"); break;
		case '�':
			strcat(str,"a"); break;
		case '�':
			strcat(str,"b"); break;
		case '�':
			strcat(str,"v"); break;
		case '�':
			strcat(str,"g"); break;
		case '�':
			strcat(str,"d"); break;
		case '�':
			strcat(str,"ye"); break;
		case '�':
			strcat(str,"yo"); break;
		case '�':
			strcat(str,"zh"); break;
		case '�':
			strcat(str,"z"); break;
		case '�':
			strcat(str,"i"); break;
		case '�':
			strcat(str,"j"); break;
		case '�':
			strcat(str,"k"); break;
		case '�':
			strcat(str,"l"); break;
		case '�':
			strcat(str,"m"); break;
		case '�':
			strcat(str,"n"); break;
		case '�':
			strcat(str,"o"); break;
		case '�':
			strcat(str,"p"); break;
		case '�':
			strcat(str,"r"); break;
		case '�':
			strcat(str,"s"); break;
		case '�':
			strcat(str,"t"); break;
		case '�':
			strcat(str,"u"); break;
		case '�':
			strcat(str,"f"); break;
		case '�':
			strcat(str,"kh"); break;
		case '�':
			strcat(str,"ts"); break;
		case '�':
			strcat(str,"ch"); break;
		case '�':
			strcat(str,"sh"); break;
		case '�':
			strcat(str,"sch"); break;
		case '�':
			strcat(str,"_"); break;
		case '�':
			strcat(str,"y"); break;
		case '�':
			strcat(str,"_"); break;
		case '�':
			strcat(str,"e"); break;
		case '�':
			strcat(str,"yu"); break;
		case '�':
			strcat(str,"ya"); break;
		default:
			j = strlen(str);
			str[j] = id[i]; str[j+1] = ZERO; break;

		}
	}
	/*    printf("\n id is %s, str is %s",id, str); */
	strncpy(id, str, BUFFER_LENGTH-1);
}
#endif
