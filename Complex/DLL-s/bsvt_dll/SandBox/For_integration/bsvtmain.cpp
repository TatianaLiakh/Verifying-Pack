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
	P1();  /* Process ������������������������������������������� */
	P2();  /* Process ��������������������������������������������� */
	P3();  /* Process �������������������������������������� */
	P4();  /* Process �������������������������������������������������� */
	P5();  /* Process ����������������������������������������������� */
	P6();  /* Process ���������������������������������������������� */
	P7();  /* Process ������������������������������������������_�� */
	P8();  /* Process �������������������������������������� */
	P9();  /* Process �������������������������������������� */
	P10();  /* Process ������������������������������������ */
	P11();  /* Process ������������������������������������������������� */
	P12();  /* Process �������������������������������������������� */
	P13();  /* Process ������������������������������������������������ */
	P14();  /* Process ��������������������������������������������������� */
	P15();  /* Process ���������������������������������������������� */
	P16();  /* Process �������������������������������������� */
	P17();  /* Process ��������������������������������������� */
	P18();  /* Process �������������������������������������������������� */
	P19();  /* Process ������������������������������ */
	P20();  /* Process ����������������������������� */
	P21();  /* Process ����������������������� */
	P22();  /* Process ����������������������������������� */
	P23();  /* Process �������������������������������� */
	P24();  /* Process ������������������������������� */
	P25();  /* Process ��������������_����������������� */
	P26();  /* Process ��������������_���������������������� */
	P27();  /* Process ��������������_������������ */
	P28();  /* Process ��������������_���������������������������� */
	P29();  /* Process ��������������_����������������������������������� */
	P30();  /* Process ��������������_����������������������������������� */
	P31();  /* Process ��������������_���������������� */
	P32();  /* Process ��������������_��������������������� */
	P33();  /* Process ��������������_������������� */
	P34();  /* Process ���������_������� */
	P35();  /* Process ���������������������� */
	P36();  /* Process ��������������������������_��_��� */
	P37();  /* Process �������������������������_��_��� */
	P38();  /* Process �����������������_��_P_���������������� */
	P39();  /* Process �����������������_��_P_��������� */
	P40();  /* Process �����������������_��_T_�������� */
	P41();  /* Process �����������������_��_T_����� */
	P42();  /* Process �����������������_��_P_����������� */
	P43();  /* Process ����������������������������������������������� */
	P44();  /* Process �������������������������_�_���������_����� */
	P45();  /* Process �������������������������������� */
	P46();  /* Process ������������������������������������� */
	P47();  /* Process ������������������������������������ */
	P48();  /* Process �������������������������������� */
	P49();  /* Process ������������������������������������������ */
	P50();  /* Process ���������������������������������������������� */
	P51();  /* Process ������������������������������������������� */
	P52();  /* Process �����������������������������_�� */
	P53();  /* Process ����������������������������� */
	P54();  /* Process ���_���_���������� */
	P55();  /* Process ���_���_���������� */
	P56();  /* Process ����������������������������������� */
	P57();  /* Process ���������������������������������������� */
	P58();  /* Process ��������������������������������������� */
	P59();  /* Process ���������������������������������� */
	P60();  /* Process ����_������_��� */
	P61();  /* Process ����_������_��� */
	P62();  /* Process �������������������������������������������� */
	P63();  /* Process �������������������������������������������� */
	P64();  /* Process ����_����� */
	P65();  /* Process ����_����� */
	P66();  /* Process ������������������������������ */
	P67();  /* Process ��������������������������������� */
	P68();  /* Process ��������������������������������� */
	P69();  /* Process ���_���_���_���_������ */
	P70();  /* Process ���_���_���_���_������ */
	P71();  /* Process ������������������������������������ */
	P72();  /* Process ����������������������������������������� */
	P73();  /* Process ���������������������������������������� */
	P74();  /* Process ���_���_���_� */
	P75();  /* Process ���_���_���_� */
	P76();  /* Process ���������������������������_� */
	P77();  /* Process ��������������������������������_� */
	P78();  /* Process �������������������������������_� */
	P79();  /* Process ���_���_���_�� */
	P80();  /* Process ���_���_���_�� */
	P81();  /* Process ���������������������������_�� */
	P82();  /* Process ��������������������������������_�� */
	P83();  /* Process �������������������������������_�� */
	P84();  /* Process ���_���_���_��� */
	P85();  /* Process ���_���_���_��� */
	P86();  /* Process ���������������������������_��� */
	P87();  /* Process ��������������������������������������������� */
	P88();  /* Process �������������������������������������������� */
	P89();  /* Process ���_����_����_����� */
	P90();  /* Process ���_����_����_����� */
	P91();  /* Process ����������������������������_����� */
	P92();  /* Process ��������������������������������������� */
	P93();  /* Process �������������������������������������� */
	P94();  /* Process ���_��������������_����� */
	P95();  /* Process ���_��������������_����� */
	P96();  /* Process ���_���������_����� */
	P97();  /* Process ���_���������_����� */
	Output();
	Prepare_PSW((INT16S)(PROCESS_N1), (INT16S)PROCESS_Nn);
}