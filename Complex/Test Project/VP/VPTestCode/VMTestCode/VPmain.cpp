/* MAIN FILE OF THE PROJECT */
#include "VPext.h" /* Common files for all generated c-files */
#include "VPproc.h"  /* Process-functions desription */
#include "VPgvar.h"  /* Project variables images */
#include "VPio.h"    /* Scan-input/output functions */
void Control_Loop(void);  /* for r_main.h */
#include "r_main.h"  /* Codes of the main-function that calls Control_Loop */

void Control_Loop (void)    /* ����������� �������� */
{
	Input();
	P0();  /* Process ������������� */
	P1();  /* Process ��������������� */
	P2();  /* Process ����������������� */
	P3();  /* Process ��������������� */
	P4();  /* Process ���������� */
	Output();
	Prepare_PSW((INT16S)(PROCESS_N1), (INT16S)PROCESS_Nn);
}