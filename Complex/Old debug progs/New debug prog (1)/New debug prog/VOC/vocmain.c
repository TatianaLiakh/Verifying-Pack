/* MAIN FILE OF THE PROJECT */
#include "vocext.h" /* Common files for all generated c-files */
#include "vocproc.h"  /* Process-functions desription */
#include "vocgvar.h"  /* Project variables images */
#include "vocio.h"    /* Scan-input/output functions */
void Control_Loop(void);  /* for r_main.h */
#include "r_main.h"  /* Codes of the main-function that calls Control_Loop */

void Control_Loop (void)    /* ����������� �������� */
{
	Input();
	P0();  /* Process ������������� */
	P1();  /* Process ���������������������� */
	P2();  /* Process ��������_��������_����_������� */
	P3();  /* Process ���������������������������� */
	P4();  /* Process ���������_������_�������_��_����� */
	P5();  /* Process ����������_������_�������_��_����� */
	P6();  /* Process ������������������������������ */
	P7();  /* Process ���������_������_�������_��_������� */
	P8();  /* Process ����������_������_�������_��_������� */
	P9();  /* Process ������������������������������� */
	P10();  /* Process ���������_������_�������_��_�������� */
	P11();  /* Process ����������_������_�������_��_�������� */
	P12();  /* Process ������������������������ */
	P13();  /* Process ����������_����������� */
	P14();  /* Process ����������_������� */
	P15();  /* Process ������������������������ */
	P16();  /* Process ��������_�������_��������� */
	P17();  /* Process ��������_�������_��������� */
	P18();  /* Process ���������������������������� */
	P19();  /* Process ���������������������� */
	P20();  /* Process ��������_�������_������� */
	P21();  /* Process ��������_�������_������� */
	Output();
	Prepare_PSW((INT16S)(PROCESS_N1), (INT16S)PROCESS_Nn);
}