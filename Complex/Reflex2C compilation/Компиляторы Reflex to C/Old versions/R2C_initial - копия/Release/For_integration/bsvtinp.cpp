#include "R_CNST.h"
#include "R_IO.h"
#include "bsvtcnst.h"
#include "bsvtxvar.h"

void Input (void)
{
/*======= Input Ports Reading =============*/
	PI0 = INBYTE((INT16U)0, (INT16U)0); /* чтение байта */
	PI1 = INBYTE((INT16U)0, (INT16U)1); /* чтение байта */
	PI2 = INBYTE((INT16U)0, (INT16U)1); /* чтение байта */
	FPO0 = OFF; PO0 = INBYTE((INT16U)1, (INT16U)2);
	FPO1 = OFF; PO1 = INBYTE((INT16U)1, (INT16U)3);
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
	if (PI0 & MASK7_S8) P0V6 = 1;
	else P0V6 = 0;
	if (PI0 & MASK8_S8) P0V7 = 1;
	else P0V7 = 0;
	if (PI1 & MASK1_S8) P0V8 = 1;
	else P0V8 = 0;
	if (PI1 & MASK2_S8) P0V9 = 1;
	else P0V9 = 0;
	if (PI1 & MASK3_S8) P0V10 = 1;
	else P0V10 = 0;
	if (PO0 & MASK1_S8) P0V11[0] = 1;
	else P0V11[0] = 0;
	P0V11[1] = P0V11[0];
	if (PO0 & MASK2_S8) P0V12[0] = 1;
	else P0V12[0] = 0;
	P0V12[1] = P0V12[0];
	if (PO0 & MASK3_S8) P0V13[0] = 1;
	else P0V13[0] = 0;
	P0V13[1] = P0V13[0];
	if (PO0 & MASK4_S8) P0V14[0] = 1;
	else P0V14[0] = 0;
	P0V14[1] = P0V14[0];
	if (PO0 & MASK5_S8) P0V15[0] = 1;
	else P0V15[0] = 0;
	P0V15[1] = P0V15[0];
	if (PO0 & MASK6_S8) P0V16[0] = 1;
	else P0V16[0] = 0;
	P0V16[1] = P0V16[0];
	if (PO0 & MASK7_S8) P0V17[0] = 1;
	else P0V17[0] = 0;
	P0V17[1] = P0V17[0];
	if (PO0 & MASK8_S8) P0V18[0] = 1;
	else P0V18[0] = 0;
	P0V18[1] = P0V18[0];
	if (PO1 & MASK1_S8) P0V19[0] = 1;
	else P0V19[0] = 0;
	P0V19[1] = P0V19[0];
	if (PO1 & MASK2_S8) P0V20[0] = 1;
	else P0V20[0] = 0;
	P0V20[1] = P0V20[0];
	if (PO1 & MASK3_S8) P0V21[0] = 1;
	else P0V21[0] = 0;
	P0V21[1] = P0V21[0];
	if (PO1 & MASK4_S8) P0V22[0] = 1;
	else P0V22[0] = 0;
	P0V22[1] = P0V22[0];
	if (PO1 & MASK5_S8) P0V23[0] = 1;
	else P0V23[0] = 0;
	P0V23[1] = P0V23[0];
	if (PO1 & MASK6_S8) P0V24[0] = 1;
	else P0V24[0] = 0;
	P0V24[1] = P0V24[0];
	if (PI2 & MASK1_S8) P0V25 = 1;
	else P0V25 = 0;
	if (PI2 & MASK2_S8) P0V26 = 1;
	else P0V26 = 0;
	if (PI2 & MASK3_S8) P0V27 = 1;
	else P0V27 = 0;
	if (PI2 & MASK4_S8) P0V28 = 1;
	else P0V28 = 0;
	if (PI2 & MASK5_S8) P0V29 = 1;
	else P0V29 = 0;
	if (PI2 & MASK6_S8) P0V30 = 1;
	else P0V30 = 0;
	if (PI2 & MASK7_S8) P0V31 = 1;
	else P0V31 = 0;
	if (PI2 & MASK8_S8) P0V32 = 1;
	else P0V32 = 0;
}
