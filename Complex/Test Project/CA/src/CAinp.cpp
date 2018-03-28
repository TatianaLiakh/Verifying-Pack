#include "r_cnst.h"
#include "r_io.h"
#include "CAcnst.h"
#include "CAxvar.h"

void Input (void)
{
/*======= Input Ports Reading =============*/
	PI0 = INBYTE((INT16U)0, (INT16U)0); /* чтение байта */
	PI1 = INBYTE((INT16U)0, (INT16U)1); /* чтение байта */
	FPO0 = OFF; PO0 = INBYTE((INT16U)1, (INT16U)0);
	FPO1 = OFF; PO1 = INBYTE((INT16U)1, (INT16U)1);
	P0V0 = 0;
	if (PI0 & MASK1_S8) P0V0 |= MASK1_S16;
	P0V0 = 0;
	if (PI0 & MASK2_S8) P0V0 |= MASK2_S16;
	P0V0 = 0;
	if (PI0 & MASK3_S8) P0V0 |= MASK3_S16;
	P0V0 = 0;
	if (PI0 & MASK4_S8) P0V0 |= MASK4_S16;
	P0V0 = 0;
	if (PI0 & MASK5_S8) P0V0 |= MASK5_S16;
	if (PI0 & MASK6_S8) P0V1 = 1;
	else P0V1 = 0;
	if (PO0 & MASK1_S8) P0V3[0] = 1;
	else P0V3[0] = 0;
	P0V3[1] = P0V3[0];
}
