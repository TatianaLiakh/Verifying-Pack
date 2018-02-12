/* MAIN FILE OF THE PROJECT */
#include "bsvtext.inc" /* Common files for all generated c-files */
#include "bsvtproc.h"  /* Process-functions desription */
#include "bsvtgvar.h"  /* Project variables images */
#include "bsvtio.h"    /* Scan-input/output functions */
void Control_Loop(void);  /* for r_main.h */
#include "r_main.h"  /* Codes of the main-function that calls Control_Loop */

void Control_Loop (void)    /* ����������� �������� */
{
	Input();
	P0();  /* Process ������������� */
	P1();  /* Process ��������������������_�_�������� */
	P2();  /* Process ���������������������� */
	P3();  /* Process �������������������������_��_��� */
	P4();  /* Process �����������������_��_P_���������������� */
	P5();  /* Process �����������������_��_P_��������� */
	P6();  /* Process �����������������_��_T_�������� */
	P7();  /* Process �����������������_��_T_����� */
	P8();  /* Process �����������������_��_P_����������� */
	P9();  /* Process ��������������������������������������� */
	P10();  /* Process �������������������������_�_���������_����� */
	P11();  /* Process �������������������������������� */
	P12();  /* Process ������������������������������������� */
	P13();  /* Process ������������������������������������ */
	P14();  /* Process �������������������������������� */
	P15();  /* Process ���_���_���������� */
	P16();  /* Process ���_���_���������� */
	P17();  /* Process ����_������_��� */
	P18();  /* Process ����_������_��� */
	P19();  /* Process ����_����� */
	P20();  /* Process ����_����� */
	P21();  /* Process ���_���_���_������ */
	P22();  /* Process ���_���_���_������ */
	P23();  /* Process ���_���_���_� */
	P24();  /* Process ���_���_���_� */
	P25();  /* Process ���_���_���_�� */
	P26();  /* Process ���_���_���_�� */
	P27();  /* Process ���_���_���_��� */
	P28();  /* Process ���_���_���_��� */
	P29();  /* Process ���_����_����_����� */
	P30();  /* Process ���_����_����_����� */
	P31();  /* Process ���_�����_��������� */
	P32();  /* Process ���_�����_��������� */
	P33();  /* Process ���_��������������_����� */
	P34();  /* Process ���_��������������_����� */
	Output();
	Prepare_PSW((INT16S)(PROCESS_N1), (INT16S)PROCESS_Nn);
}