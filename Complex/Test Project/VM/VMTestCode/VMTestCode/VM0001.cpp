/* FILE OF PROC-IMAGES OF THE PROJECT */
#include "VMext.h" /* Common files for all generated c-files */
#include "VMxvar.h"  /* Var-images */

void P0 (void) /* ПРОЦЕСС: Инициализация */
{
	switch (Check_State(0)) {

		case 0:    /*  P0S0() - СОСТОЯНИЕ: Начало */
  
	P0V2 = C_1;
	P0V3 = C_1;
	P0V4 = C_1;
	
	Set_Start(1);
	Set_Start(3);
	Set_Stop(0);
			break;
		default:
			break;
	}
}

void P1 (void) /* ПРОЦЕСС: ЧтениеСообщенийОтБУС */
{
	switch (Check_State(1)) {

		case 0:    /*  P1S0() - СОСТОЯНИЕ: Начало */

    
    if (GetNextMsgFromSCM()) 
	{
		P1V2 = GetMsgCodeFromSCM();
		if (P1V2 == C_12)
		{
			
			Set_Stop(2);
			Set_Stop(3);
			Set_Start(4);
		}
		else if (P1V2 == C_13)
		{
			
			Set_Start(3);
			Set_Stop(4);
		}
		else if (P1V2 == C_14 ||
					P1V2 == C_15)
		{
		 
			P0V4 = C_0;
			Set_Start(2);
		}
	}
	
			break;
		default:
			break;
	}
}

void P2 (void) /* ПРОЦЕСС: КонтрольАвтоматическойРаботыСушилки */
{
	switch (Check_State(2)) {

		case 0:    /*  P2S0() - СОСТОЯНИЕ: Начало */

		if (P0V0 == C_0) Set_State(2, 1);
		else Set_State(2, 2);
			break;
		case 1:    /*  P2S1() - СОСТОЯНИЕ: ОжиданиеВключения */

		if (P0V1 == C_0)
		{
			Set_State(2, 3);
			SendMsgGUICode(C_21);
		}
			
		if (Timeout(2, C_2))  Set_State(2, 5);
			break;
		case 2:    /*  P2S2() - СОСТОЯНИЕ: ОжиданиеОтключения */

		if (P0V1 == C_1) 
		{
			Set_State(2, 7);
			SendMsgGUICode(C_22);
		}
		if (Timeout(2, C_2))  Set_State(2, 6);
			break;
		case 3:    /*  P2S3() - СОСТОЯНИЕ: СушилкаВключена */

		if (P0V1 == C_1  && P0V0 == C_0)
		{
			SendMsgGUICode(C_28);
			Set_Stop(2);
		}
		else if (P0V0 == C_1) Set_State(2, 4);
			break;
		case 4:    /*  P2S4() - СОСТОЯНИЕ: ОжиданиеПеремен */

		if (P0V0 == C_0) Set_State(2, 3);
		if (Timeout(2, C_3))  Set_State(2, 0);
			break;
		case 5:    /*  P2S5() - СОСТОЯНИЕ: ОшибкаВключения */

			SendMsgGUICode(C_24);
			Set_Stop(2);
			break;
		case 6:    /*  P2S6() - СОСТОЯНИЕ: ОшибкаВыключения */

		Set_Stop(2);
			break;
		case 7:    /*  P2S7() - СОСТОЯНИЕ: СушилкаВыключена */

		if (P0V1 == C_0  && P0V0 == C_1)
		{
			SendMsgGUICode(C_28);
			Set_Stop(2);
		}
		else if (P0V0 == C_1) Set_State(2, 0);
			break;
		default:
			break;
	}
}

void P3 (void) /* ПРОЦЕСС: КонтрольОтключенияРучногоУправления */
{
	switch (Check_State(3)) {

		case 0:    /*  P3S0() - СОСТОЯНИЕ: Старт */

		if (P0V3 == C_1)
		{
			SendMsgGUICode(C_20);
			Set_State(3, 2);
		}
		if (Timeout(3, C_2))  Set_State(3, 1);
			break;
		case 1:    /*  P3S1() - СОСТОЯНИЕ: Беда */

		SendMsgGUICode(C_25);
		Set_Stop(3);
			break;
		case 2:    /*  P3S2() - СОСТОЯНИЕ: Контроль */

		if (P0V3 != C_1)
		{
			SendMsgGUICode(C_27);
			Set_Stop(3);
		}
			break;
		default:
			break;
	}
}

void P4 (void) /* ПРОЦЕСС: КонтрольВключенияРучногоУправления */
{
	switch (Check_State(4)) {

		case 0:    /*  P4S0() - СОСТОЯНИЕ: Старт */

		if (P0V3 == C_0)
		{
			SendMsgGUICode(C_19);
			Set_State(4, 2);
		}
		if (Timeout(4, C_2))  Set_State(4, 1);
			break;
		case 1:    /*  P4S1() - СОСТОЯНИЕ: Беда */

		SendMsgGUICode(C_24);
		Set_Stop(4);
			break;
		case 2:    /*  P4S2() - СОСТОЯНИЕ: Контроль */

		if (P0V3 != C_0)
		{
			SendMsgGUICode(C_26);
			Set_Stop(4);
		}
			break;
		default:
			break;
	}
}
