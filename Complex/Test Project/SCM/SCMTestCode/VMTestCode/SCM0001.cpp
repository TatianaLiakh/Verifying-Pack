/* FILE OF PROC-IMAGES OF THE PROJECT */
#include "SCMext.h" /* Common files for all generated c-files */
#include "SCMxvar.h"  /* Var-images */

void P0 (void) /* ПРОЦЕСС: Инициализация */
{
	switch (Check_State(0)) {

		case 0:    /*  P0S0() - СОСТОЯНИЕ: Начало */
  
 	SendMsgToVirtualPlantCode(C_3);
	SendMsgToVerificationModuleCode(C_13);
	Set_State(0, 1);
			break;
		case 1:    /*  P0S1() - СОСТОЯНИЕ: Ожидание1 */

	if (Timeout(0, C_2))  Set_State(0, 2);
			break;
		case 2:    /*  P0S2() - СОСТОЯНИЕ: ПроверкаОтключения */

	SendMsgToVirtualPlantCode(C_4);

	SendMsgToVerificationModuleCode(C_14);
	Set_State(0, 3);
			break;
		case 3:    /*  P0S3() - СОСТОЯНИЕ: Ожидание2 */

	if (Timeout(0, C_2))  Set_State(0, 4);
			break;
		case 4:    /*  P0S4() - СОСТОЯНИЕ: ВРучнойРежим */

	SendMsgToControlAlgorythmCode(C_7);
	SendMsgToControlAlgorythmCode(C_9);
	SendMsgToVerificationModuleCode(C_11);
	Set_State(0, 5);
			break;
		case 5:    /*  P0S5() - СОСТОЯНИЕ: Ожидание3 */

	if (Timeout(0, C_2))  Set_State(0, 6);
			break;
		case 6:    /*  P0S6() - СОСТОЯНИЕ: ЛомаемСушилку */

	SendMsgToVirtualPlantCode(C_5);
	SendMsgToControlAlgorythmCode(C_10);
	SendMsgToVerificationModuleCode(C_17);
	Set_State(0, 7);
			break;
		case 7:    /*  P0S7() - СОСТОЯНИЕ: Ожидание4 */

	if (Timeout(0, C_2))  Set_Stop(0);
			break;
		default:
			break;
	}
}
