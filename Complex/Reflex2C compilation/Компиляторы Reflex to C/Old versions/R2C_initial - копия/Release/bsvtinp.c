#include "R_CNST.h"
#include "R_IO.h"
#include "bsvtcnst.h"
#include "bsvtxvar.h"

void Input (void)
{
/*======= Input Ports Reading =============*/
	PI0 = INBYTE((INT16U)0, (INT16U)0); /* чтение байта */
	PI1 = INBYTE((INT16U)0, (INT16U)1); /* чтение байта */
	PI2 = INBYTE((INT16U)0, (INT16U)2); /* чтение байта */
	PI3 = INBYTE((INT16U)0, (INT16U)3); /* чтение байта */
	PI4 = INBYTE((INT16U)0, (INT16U)4); /* чтение байта */
	PI5 = INBYTE((INT16U)0, (INT16U)5); /* чтение байта */
	PI6 = INBYTE((INT16U)0, (INT16U)6); /* чтение байта */
	PI7 = INBYTE((INT16U)0, (INT16U)7); /* чтение байта */
	PI8 = INBYTE((INT16U)0, (INT16U)8); /* чтение байта */
	PI9 = INBYTE((INT16U)0, (INT16U)9); /* чтение байта */
	PI10 = INBYTE((INT16U)0, (INT16U)10); /* чтение байта */
	FPO0 = OFF; PO0 = INBYTE((INT16U)1, (INT16U)0);
	if (PI0 & MASK1_S8) P0V0 = 1;
	else P0V0 = 0;
	if (PI0 & MASK2_S8) P0V1 = 1;
	else P0V1 = 0;
	if (PI1 & MASK1_S8) P0V2 = 1;
	else P0V2 = 0;
	if (PI1 & MASK2_S8) P0V3 = 1;
	else P0V3 = 0;
	if (PI2 & MASK1_S8) P0V4 = 1;
	else P0V4 = 0;
	if (PI2 & MASK2_S8) P0V5 = 1;
	else P0V5 = 0;
	if (PI3 & MASK1_S8) P0V6 = 1;
	else P0V6 = 0;
	if (PI3 & MASK2_S8) P0V7 = 1;
	else P0V7 = 0;
	if (PI4 & MASK1_S8) P0V8 = 1;
	else P0V8 = 0;
	if (PI4 & MASK2_S8) P0V9 = 1;
	else P0V9 = 0;
	if (PI5 & MASK1_S8) P0V10 = 1;
	else P0V10 = 0;
	if (PI5 & MASK2_S8) P0V11 = 1;
	else P0V11 = 0;
	if (PI6 & MASK1_S8) P0V12 = 1;
	else P0V12 = 0;
	if (PI6 & MASK2_S8) P0V13 = 1;
	else P0V13 = 0;
	if (PI7 & MASK1_S8) P0V14 = 1;
	else P0V14 = 0;
	if (PI7 & MASK2_S8) P0V15 = 1;
	else P0V15 = 0;
	if (PI8 & MASK1_S8) P0V16 = 1;
	else P0V16 = 0;
	if (PI8 & MASK2_S8) P0V17 = 1;
	else P0V17 = 0;
	if (PI9 & MASK1_S8) P0V18 = 1;
	else P0V18 = 0;
	if (PI9 & MASK2_S8) P0V19 = 1;
	else P0V19 = 0;
	if (PI10 & MASK1_S8) P0V20 = 1;
	else P0V20 = 0;
	if (PI10 & MASK2_S8) P0V21 = 1;
	else P0V21 = 0;
	if (PO0 & MASK1_S8) P0V22[0] = 1;
	else P0V22[0] = 0;
	P0V22[1] = P0V22[0];
	if (PO0 & MASK2_S8) P0V23[0] = 1;
	else P0V23[0] = 0;
	P0V23[1] = P0V23[0];
	if (PO0 & MASK3_S8) P0V24[0] = 1;
	else P0V24[0] = 0;
	P0V24[1] = P0V24[0];
	if (PO0 & MASK4_S8) P0V25[0] = 1;
	else P0V25[0] = 0;
	P0V25[1] = P0V25[0];
	if (PO0 & MASK5_S8) P0V26[0] = 1;
	else P0V26[0] = 0;
	P0V26[1] = P0V26[0];
	if (PO0 & MASK6_S8) P0V27[0] = 1;
	else P0V27[0] = 0;
	P0V27[1] = P0V27[0];
	if (PO0 & MASK7_S8) P0V28[0] = 1;
	else P0V28[0] = 0;
	P0V28[1] = P0V28[0];
	if (PO0 & MASK8_S8) P0V29[0] = 1;
	else P0V29[0] = 0;
	P0V29[1] = P0V29[0];
}
