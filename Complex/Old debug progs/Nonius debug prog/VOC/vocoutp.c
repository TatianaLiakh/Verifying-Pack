#include "r_cnst.h"
#include "r_io.h"
#include "voccnst.h"
#include "vocxvar.h"

void Output (void)
{
	if (P0V6[0] != P0V6[1]) {
		FPO0 = ON;
		if (!(P0V6[1] == ZERO)) PO0 |= MASK1_S8;
		else PO0 &= ~MASK1_S8;
	}
	if (P0V7[0] != P0V7[1]) {
		FPO0 = ON;
		if (!(P0V7[1] == ZERO)) PO0 |= MASK2_S8;
		else PO0 &= ~MASK2_S8;
	}
	if (P0V8[0] != P0V8[1]) {
		FPO0 = ON;
		if (!(P0V8[1] == ZERO)) PO0 |= MASK3_S8;
		else PO0 &= ~MASK3_S8;
	}
	if (P0V9[0] != P0V9[1]) {
		FPO0 = ON;
		if (!(P0V9[1] == ZERO)) PO0 |= MASK4_S8;
		else PO0 &= ~MASK4_S8;
	}


/*======= Output Port =============*/
	if(FPO0 == ON) OUTBYTE((INT16U)1, (INT16U)0, (INT8U)~PO0);
	if(FPO1 == ON) OUTBYTE((INT16U)1, (INT16U)1, (INT8U)~PO1);
}
