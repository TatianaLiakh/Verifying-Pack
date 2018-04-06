/* MAIN FILE OF THE PROJECT */
#include "canonext.h" /* Common files for all generated c-files */
#include "canonproc.h"  /* Process-functions desription */
#include "canongvar.h"  /* Project variables images */
#include "canonio.h"    /* Scan-input/output functions */
void Control_Loop(void);  /* for r_main.h */
#include "r_main.h"  /* Codes of the main-function that calls Control_Loop */

void Control_Loop (void)    /* ����������� �������� */
{
	Input();
	P0();  /* Process ������������� */
	P1();  /* Process �����_������������� */
	P2();  /* Process ��������������� */
	P3();  /* Process �����_�� */
	P4();  /* Process �������������������� */
	P5();  /* Process ������������������������_��_R_������� */
	P6();  /* Process ������������������������_��_W_�����������_������� */
	P7();  /* Process �����������������_��_R_������� */
	P8();  /* Process �����������������_��_W_�����������_������� */
	P9();  /* Process ���_����_������� */
	P10();  /* Process ����������������������������������� */
	P11();  /* Process ���_����� */
	P12();  /* Process ������_���� */
	P13();  /* Process �������_���� */
	P14();  /* Process �������������_������ */
	P15();  /* Process ���_������ */
	P16();  /* Process ����_������ */
	P17();  /* Process ���������������������� */
	P18();  /* Process ���_���������_����� */
	P19();  /* Process ����_���������_����� */
	P20();  /* Process �������������_�������� */
	P21();  /* Process ���������������� */
	P22();  /* Process ���������������������� */
	P23();  /* Process ��������������� */
	P24();  /* Process ��������������������� */
	P25();  /* Process �������������_�����1212 */
	P26();  /* Process �������������_�����1214 */
	P27();  /* Process ����������������������1212 */
	P28();  /* Process ����������������������1214 */
	P29();  /* Process �������������_������_����������� */
	P30();  /* Process ����������_������_����������� */
	P31();  /* Process ������ */
	P32();  /* Process �����_������ */
	P33();  /* Process �������_�_�����_�������� */
	P34();  /* Process �������_�_��������_������ */
	P35();  /* Process ����_������� */
	P36();  /* Process �������_�_���������_���������_����� */
	P37();  /* Process ���_��������_����������������_��_�������� */
	P38();  /* Process ����_��������_����������������_��_�������� */
	P39();  /* Process ���_��������_����_�������_�_��_W */
	P40();  /* Process ����_��������_�����������_������� */
	Output();
	Prepare_PSW((INT16S)(PROCESS_N1), (INT16S)PROCESS_Nn);
}