#include "r_cnst.h"
#include "r_io.h"
#include "voccnst.h"
#include "vocxvar.h"

void Input (void)
{
/*======= Input Ports Reading =============*/
	PI0 = INBYTE((INT16U)0, (INT16U)0); /* чтение байта */
	PI1 = INBYTE((INT16U)0, (INT16U)1); /* чтение байта */
	FPO0 = OFF; PO0 = INBYTE((INT16U)1, (INT16U)0);
	FPO1 = OFF; PO1 = INBYTE((INT16U)1, (INT16U)1);
	if (PI0 & MASK1_S8) P0V0 = 1;
	else P0V0 = 0;
	if (PI0 & MASK2_S8) P0V1 = 1;
	else P0V1 = 0;
	if (PI0 & MASK3_S8) P0V2 = 1;
	else P0V2 = 0;
	if (PI0 & MASK4_S8) P0V3 = 1;
	else P0V3 = 0;
	if (PI0 & MASK5_S8) P0V4 = 1;
	else P0V4 = 0;
	if (PI0 & MASK6_S8) P0V5 = 1;
	else P0V5 = 0;
	if (PO0 & MASK1_S8) P0V6[0] = 1;
	else P0V6[0] = 0;
	P0V6[1] = P0V6[0];
	if (PO0 & MASK2_S8) P0V7[0] = 1;
	else P0V7[0] = 0;
	P0V7[1] = P0V7[0];
	if (PO0 & MASK3_S8) P0V8[0] = 1;
	else P0V8[0] = 0;
	P0V8[1] = P0V8[0];
	if (PO0 & MASK4_S8) P0V9[0] = 1;
	else P0V9[0] = 0;
	P0V9[1] = P0V9[0];
	if (PI1 & MASK1_S8) P0V10 = 1;
	else P0V10 = 0;
	if (PI1 & MASK2_S8) P0V11 = 1;
	else P0V11 = 0;
	if (PI1 & MASK3_S8) P0V12 = 1;
	else P0V12 = 0;
	if (PI1 & MASK4_S8) P0V13 = 1;
	else P0V13 = 0;
	if (PI1 & MASK5_S8) P0V14 = 1;
	else P0V14 = 0;
	if (PI1 & MASK6_S8) P0V15 = 1;
	else P0V15 = 0;
	if (PI1 & MASK7_S8) P0V16 = 1;
	else P0V16 = 0;
}
