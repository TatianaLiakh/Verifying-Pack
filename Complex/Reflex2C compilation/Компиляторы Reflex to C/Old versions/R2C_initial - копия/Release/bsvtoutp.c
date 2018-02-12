#include "R_CNST.h"
#include "R_IO.h"
#include "bsvtcnst.h"
#include "bsvtxvar.h"

void Output (void)
{
	if (P0V22[0] != P0V22[1]) {
		FPO0 = ON;
		if (!(P0V22[1] == ZERO)) PO0 |= MASK1_S8;
		else PO0 &= ~MASK1_S8;
	}
	if (P0V23[0] != P0V23[1]) {
		FPO0 = ON;
		if (!(P0V23[1] == ZERO)) PO0 |= MASK2_S8;
		else PO0 &= ~MASK2_S8;
	}
	if (P0V24[0] != P0V24[1]) {
		FPO0 = ON;
		if (!(P0V24[1] == ZERO)) PO0 |= MASK3_S8;
		else PO0 &= ~MASK3_S8;
	}
	if (P0V25[0] != P0V25[1]) {
		FPO0 = ON;
		if (!(P0V25[1] == ZERO)) PO0 |= MASK4_S8;
		else PO0 &= ~MASK4_S8;
	}
	if (P0V26[0] != P0V26[1]) {
		FPO0 = ON;
		if (!(P0V26[1] == ZERO)) PO0 |= MASK5_S8;
		else PO0 &= ~MASK5_S8;
	}
	if (P0V27[0] != P0V27[1]) {
		FPO0 = ON;
		if (!(P0V27[1] == ZERO)) PO0 |= MASK6_S8;
		else PO0 &= ~MASK6_S8;
	}
	if (P0V28[0] != P0V28[1]) {
		FPO0 = ON;
		if (!(P0V28[1] == ZERO)) PO0 |= MASK7_S8;
		else PO0 &= ~MASK7_S8;
	}
	if (P0V29[0] != P0V29[1]) {
		FPO0 = ON;
		if (!(P0V29[1] == ZERO)) PO0 |= MASK8_S8;
		else PO0 &= ~MASK8_S8;
	}


/*======= Output Port =============*/
	if(FPO0 == ON) OUTBYTE((INT16U)1, (INT16U)0, (INT8U)~PO0);
}
