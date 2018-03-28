#include "r_cnst.h"
#include "r_io.h"
#include "VMcnst.h"
#include "VMxvar.h"

void Input (void)
{
/*======= Input Ports Reading =============*/
	PI0 = INBYTE((INT16U)0, (INT16U)0); /* ������ ����� */
	PI1 = INBYTE((INT16U)0, (INT16U)1); /* ������ ����� */
	PI2 = INBYTE((INT16U)0, (INT16U)2); /* ������ ����� */
	PI3 = INBYTE((INT16U)0, (INT16U)3); /* ������ ����� */
	if (PI2 & MASK1_S8) P0V0 = 1;
	else P0V0 = 0;
	if (PI0 & MASK1_S8) P0V1 = 1;
	else P0V1 = 0;
}
