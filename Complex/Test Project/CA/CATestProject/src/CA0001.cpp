/* FILE OF PROC-IMAGES OF THE PROJECT */
#include "CAext.h" /* Common files for all generated c-files */
#include "CAxvar.h"  /* Var-images */

void P0 (void) /* �������: ������������� */
{
	switch (Check_State(0)) {

		case 0:    /*  P0S0() - ���������: ������ */
  
	Set_Start(1);
	Set_State(0, 1);
			break;
		case 1:    /*  P0S1() - ���������: ������ */

   if (P0V1 == C_0  && P0V2 == C_1) 
   { 
     P0V3[1] = C_0;
     Set_State(0, 2);
	 }
	 else if (P0V1 == C_1  && P0V2 == C_1)
		P0V3[1] = C_1;
			break;
		case 2:    /*  P0S2() - ���������: ����� */
  
  if (P0V2 == C_1 && P0V1 == C_0) Set_State(0, 2);
  if (Timeout(0, 12))  Set_State(0, 1);
			break;
		default:
			break;
	}
}

void P1 (void) /* �������: ���������������������� */
{
	switch (Check_State(1)) {

		case 0:    /*  P1S0() - ���������: ������ */

    
    if (GetNextMsgGUI()) 
	{
		P1V2 = GetMsgGUICode();
		if (P1V2 == C_2)
		{
			P0V2 = C_0;
			SendMsgGUICode(C_6);
		}
		else	if (P1V2 == C_3)
		{
			P0V2 = C_0;
			SendMsgGUICode(C_7);
		}
		else if (P1V2 == C_4 && P0V2 == C_0)
		{
			P0V3[1] = C_0;
			SendMsgGUICode(C_9);
		}
		else if (P1V2 == C_5 && P0V2 == C_0)
		{
			P0V3[1] = C_1;
			SendMsgGUICode(C_8);			
		}
	}
	
			break;
		default:
			break;
	}
}
