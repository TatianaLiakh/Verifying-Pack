#include "r_cnst.h"
#include "r_io.h"
#include "bsvtcnst.h"
#include "bsvtxvar.h"

void Output (void)
{
	if (P0V34[0] != P0V34[1]) {
		FPO0 = ON;
		if (!(P0V34[1] == ZERO)) PO0 |= MASK1_S8;
		else PO0 &= ~MASK1_S8;
	}
	if (P0V35[0] != P0V35[1]) {
		FPO1 = ON;
		if (!(P0V35[1] == ZERO)) PO1 |= MASK1_S8;
		else PO1 &= ~MASK1_S8;
	}
	if (P0V36[0] != P0V36[1]) {
		FPO2 = ON;
		if (!(P0V36[1] == ZERO)) PO2 |= MASK1_S8;
		else PO2 &= ~MASK1_S8;
	}
	if (P0V37[0] != P0V37[1]) {
		FPO3 = ON;
		if (!(P0V37[1] == ZERO)) PO3 |= MASK1_S8;
		else PO3 &= ~MASK1_S8;
	}
	if (P0V38[0] != P0V38[1]) {
		FPO4 = ON;
		if (!(P0V38[1] == ZERO)) PO4 |= MASK1_S8;
		else PO4 &= ~MASK1_S8;
	}
	if (P0V39[0] != P0V39[1]) {
		FPO5 = ON;
		if (!(P0V39[1] == ZERO)) PO5 |= MASK1_S8;
		else PO5 &= ~MASK1_S8;
	}
	if (P0V40[0] != P0V40[1]) {
		FPO6 = ON;
		if (!(P0V40[1] == ZERO)) PO6 |= MASK1_S8;
		else PO6 &= ~MASK1_S8;
	}
	if (P0V41[0] != P0V41[1]) {
		FPO7 = ON;
		if (!(P0V41[1] == ZERO)) PO7 |= MASK1_S8;
		else PO7 &= ~MASK1_S8;
	}


/*======= Output Port =============*/
	if(FPO0 == ON) OUTBYTE((INT16U)1, (INT16U)0, (INT8U)~PO0);
	if(FPO1 == ON) OUTBYTE((INT16U)1, (INT16U)1, (INT8U)~PO1);
	if(FPO2 == ON) OUTBYTE((INT16U)1, (INT16U)2, (INT8U)~PO2);
	if(FPO3 == ON) OUTBYTE((INT16U)1, (INT16U)3, (INT8U)~PO3);
	if(FPO4 == ON) OUTBYTE((INT16U)1, (INT16U)4, (INT8U)~PO4);
	if(FPO5 == ON) OUTBYTE((INT16U)1, (INT16U)5, (INT8U)~PO5);
	if(FPO6 == ON) OUTBYTE((INT16U)1, (INT16U)6, (INT8U)~PO6);
	if(FPO7 == ON) OUTBYTE((INT16U)1, (INT16U)7, (INT8U)~PO7);
}
