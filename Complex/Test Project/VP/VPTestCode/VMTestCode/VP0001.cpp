/* FILE OF PROC-IMAGES OF THE PROJECT */
#include "VPext.h" /* Common files for all generated c-files */
#include "VPxvar.h"  /* Var-images */

void P0 (void) /* �������: ������������� */
{
	switch (Check_State(0)) {

		case 0:    /*  P0S0() - ���������: ������ */
  
	P0V2 = C_0;
	Set_Start(3);
	Set_State(0, 1);
			break;
		case 1:    /*  P0S1() - ���������: ������ */

		if (P0V2 == C_0)
		{
			Set_Stop(2);
			Set_Start(1);
		}
		else  
		{
			Set_Stop(1);
			Set_Start(2);
		}
		
			break;
		default:
			break;
	}
}

void P1 (void) /* �������: ��������������� */
{
	switch (Check_State(1)) {

		case 0:    /*  P1S0() - ���������: ������ */

		if (P0V1 == C_0) Set_State(1, 1);
		else Set_State(1, 2);
			break;
		case 1:    /*  P1S1() - ���������: ���������������� */

		if (Timeout(1, C_2))  Set_State(1, 3);
			break;
		case 2:    /*  P1S2() - ���������: ����������������� */

		if (Timeout(1, C_2))  Set_State(1, 4);
			break;
		case 3:    /*  P1S3() - ���������: ��������������� */

		if (P0V1 != C_0) Set_State(1, 0);
			break;
		case 4:    /*  P1S4() - ���������: ���������������� */

		if (P0V1 != C_1) Set_State(1, 0);
			break;
		default:
			break;
	}
}

void P2 (void) /* �������: ����������������� */
{
	switch (Check_State(2)) {

		case 0:    /*  P2S0() - ���������: ������ */

		if (P0V1 == C_1) Set_State(2, 1);
		else Set_State(2, 2);
			break;
		case 1:    /*  P2S1() - ���������: ���������������� */

		if (Timeout(2, C_2))  Set_State(2, 3);
			break;
		case 2:    /*  P2S2() - ���������: ����������������� */

		if (Timeout(2, C_2))  Set_State(2, 4);
			break;
		case 3:    /*  P2S3() - ���������: ��������������� */

		if (P0V1 != C_1) Set_State(2, 0);
			break;
		case 4:    /*  P2S4() - ���������: ���������������� */

		if (P0V1 != C_0) Set_State(2, 0);
			break;
		default:
			break;
	}
}

void P3 (void) /* �������: ��������������� */
{
	switch (Check_State(3)) {

		case 0:    /*  P3S0() - ���������: ������ */

		 if (GetMessageFromScenariousBlock()) 
		{
			P3V2 = GetMessageCodeFromScenariousBlock();
			if  ( P3V2 == C_4 ) Set_Start(4);
			else if ( P3V2 ==  C_5) 
			{
				Set_Stop(4);
				P0V0[1] = C_1;
			}
			else if ( P3V2 ==  C_6) P0V2 = C_1;
			else if ( P3V2 ==  C_7) P0V2 = C_0;
			
		}
			break;
		default:
			break;
	}
}

void P4 (void) /* �������: ���������� */
{
	switch (Check_State(4)) {

		case 0:    /*  P4S0() - ���������: ����� */

		P4V2 = Random();
		if (P4V2 >= 0.5)
			{
				Set_State(4, 1);
			}
		else Set_State(4, 2);
			break;
		case 1:    /*  P4S1() - ���������: ��������� */

		P0V0[1] = C_0; 
		if (Timeout(4, C_3))  Set_State(4, 0);
			break;
		case 2:    /*  P4S2() - ���������: ��������� */

		P0V0[1] = C_1;
		if (Timeout(4, C_3))  Set_State(4, 0);
			break;
		default:
			break;
	}
}
