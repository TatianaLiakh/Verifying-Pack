#include "r_cnst.h"
#include "r_io.h"
#include "canoncnst.h"
#include "canonxvar.h"

void Output (void)
{
	if (P0V0[0] != P0V0[1]) {
		FPO0 = ON;
		if (!(P0V0[1] == ZERO)) PO0 |= MASK1_S8;
		else PO0 &= ~MASK1_S8;
	}
	if (P0V1[0] != P0V1[1]) {
		FPO0 = ON;
		if (!(P0V1[1] == ZERO)) PO0 |= MASK2_S8;
		else PO0 &= ~MASK2_S8;
	}
	if (P0V2[0] != P0V2[1]) {
		FPO0 = ON;
		if (!(P0V2[1] == ZERO)) PO0 |= MASK3_S8;
		else PO0 &= ~MASK3_S8;
	}
	if (P0V3[0] != P0V3[1]) {
		FPO0 = ON;
		if (!(P0V3[1] == ZERO)) PO0 |= MASK4_S8;
		else PO0 &= ~MASK4_S8;
	}
	if (P0V4[0] != P0V4[1]) {
		FPO0 = ON;
		if (!(P0V4[1] == ZERO)) PO0 |= MASK5_S8;
		else PO0 &= ~MASK5_S8;
	}
	if (P0V5[0] != P0V5[1]) {
		FPO0 = ON;
		if (!(P0V5[1] == ZERO)) PO0 |= MASK6_S8;
		else PO0 &= ~MASK6_S8;
	}
	if (P0V10[0] != P0V10[1]) {
		FPO1 = ON;
		if (!(P0V10[1] == ZERO)) PO1 |= MASK1_S8;
		else PO1 &= ~MASK1_S8;
	}
	if (P0V11[0] != P0V11[1]) {
		FPO1 = ON;
		if (!(P0V11[1] == ZERO)) PO1 |= MASK2_S8;
		else PO1 &= ~MASK2_S8;
	}
	if (P0V12[0] != P0V12[1]) {
		FPO1 = ON;
		if (!(P0V12[1] == ZERO)) PO1 |= MASK3_S8;
		else PO1 &= ~MASK3_S8;
	}
	if (P0V13[0] != P0V13[1]) {
		FPO1 = ON;
		if (!(P0V13[1] == ZERO)) PO1 |= MASK4_S8;
		else PO1 &= ~MASK4_S8;
	}
	if (P0V14[0] != P0V14[1]) {
		FPO1 = ON;
		if (!(P0V14[1] == ZERO)) PO1 |= MASK5_S8;
		else PO1 &= ~MASK5_S8;
	}


/*======= Output Port =============*/
	if(FPO0 == ON) OUTBYTE((INT16U)1, (INT16U)0, (INT8U)~PO0);
	if(FPO1 == ON) OUTBYTE((INT16U)1, (INT16U)1, (INT8U)~PO1);
}
