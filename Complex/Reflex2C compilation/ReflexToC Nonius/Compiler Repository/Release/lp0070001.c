/* FILE OF PROC-IMAGES OF THE PROJECT */
#include "lp007ext.inc" /* Common files for all generated c-files */
#include "lp007xvar.h"  /* Var-images */

void P0 (void) /* ПРОЦЕСС: Инициализация */
{
	switch (Check_State(0)) {

		case 0:    /*  P0S0() - СОСТОЯНИЕ: Начало */
  
  if (P0V0 == C_0) { 
     P0V1[1] = C_0;
     Set_State(0, 1);
  } else P0V1[1] = C_1;
			break;
		case 1:    /*  P0S1() - СОСТОЯНИЕ: Сушка */
  
  if (P0V0 == C_0) Set_State(0, 1);
  if (Timeout(0, 12))  Set_State(0, 0);
			break;
		default:
			break;
	}
}
