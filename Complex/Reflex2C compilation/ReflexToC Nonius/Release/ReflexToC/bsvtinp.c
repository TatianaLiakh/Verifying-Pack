#include "r_cnst.h"
#include "r_io.h"
#include "bsvtcnst.h"
#include "bsvtxvar.h"

void Input (void)
{
/*======= Input Ports Reading =============*/
	PI0 = INBYTE((INT16U)0, (INT16U)0); /* ������ ����� */
	PI1 = INBYTE((INT16U)0, (INT16U)1); /* ������ ����� */
	PI2 = INBYTE((INT16U)0, (INT16U)2); /* ������ ����� */
	PI3 = INBYTE((INT16U)0, (INT16U)3); /* ������ ����� */
	PI4 = INBYTE((INT16U)0, (INT16U)4); /* ������ ����� */
	PI5 = INBYTE((INT16U)0, (INT16U)5); /* ������ ����� */
	PI6 = INBYTE((INT16U)0, (INT16U)6); /* ������ ����� */
	PI7 = INBYTE((INT16U)0, (INT16U)7); /* ������ ����� */
	PI8 = INBYTE((INT16U)0, (INT16U)8); /* ������ ����� */
	PI9 = INBYTE((INT16U)0, (INT16U)9); /* ������ ����� */
	PI10 = INBYTE((INT16U)0, (INT16U)10); /* ������ ����� */
	PI11 = INBYTE((INT16U)0, (INT16U)11); /* ������ ����� */
	PI12 = INBYTE((INT16U)0, (INT16U)12); /* ������ ����� */
	PI13 = INBYTE((INT16U)0, (INT16U)13); /* ������ ����� */
	PI14 = INBYTE((INT16U)0, (INT16U)14); /* ������ ����� */
	PI15 = INBYTE((INT16U)0, (INT16U)15); /* ������ ����� */
	PI16 = INBYTE((INT16U)0, (INT16U)16); /* ������ ����� */
	FPO0 = OFF; PO0 = INBYTE((INT16U)1, (INT16U)0);
	FPO1 = OFF; PO1 = INBYTE((INT16U)1, (INT16U)1);
	FPO2 = OFF; PO2 = INBYTE((INT16U)1, (INT16U)2);
	FPO3 = OFF; PO3 = INBYTE((INT16U)1, (INT16U)3);
	FPO4 = OFF; PO4 = INBYTE((INT16U)1, (INT16U)4);
	FPO5 = OFF; PO5 = INBYTE((INT16U)1, (INT16U)5);
	FPO6 = OFF; PO6 = INBYTE((INT16U)1, (INT16U)6);
	FPO7 = OFF; PO7 = INBYTE((INT16U)1, (INT16U)7);
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
	if (PI11 & MASK1_S8) P0V22 = 1;
	else P0V22 = 0;
	if (PI11 & MASK2_S8) P0V23 = 1;
	else P0V23 = 0;
	if (PI12 & MASK1_S8) P0V24 = 1;
	else P0V24 = 0;
	if (PI12 & MASK2_S8) P0V25 = 1;
	else P0V25 = 0;
	if (PI13 & MASK1_S8) P0V26 = 1;
	else P0V26 = 0;
	if (PI13 & MASK2_S8) P0V27 = 1;
	else P0V27 = 0;
	if (PI14 & MASK1_S8) P0V28 = 1;
	else P0V28 = 0;
	if (PI14 & MASK2_S8) P0V29 = 1;
	else P0V29 = 0;
	if (PI15 & MASK1_S8) P0V30 = 1;
	else P0V30 = 0;
	if (PI15 & MASK2_S8) P0V31 = 1;
	else P0V31 = 0;
	if (PI16 & MASK1_S8) P0V32 = 1;
	else P0V32 = 0;
	if (PI16 & MASK2_S8) P0V33 = 1;
	else P0V33 = 0;
	if (PO0 & MASK1_S8) P0V34[0] = 1;
	else P0V34[0] = 0;
	P0V34[1] = P0V34[0];
	if (PO1 & MASK1_S8) P0V35[0] = 1;
	else P0V35[0] = 0;
	P0V35[1] = P0V35[0];
	if (PO2 & MASK1_S8) P0V36[0] = 1;
	else P0V36[0] = 0;
	P0V36[1] = P0V36[0];
	if (PO3 & MASK1_S8) P0V37[0] = 1;
	else P0V37[0] = 0;
	P0V37[1] = P0V37[0];
	if (PO4 & MASK1_S8) P0V38[0] = 1;
	else P0V38[0] = 0;
	P0V38[1] = P0V38[0];
	if (PO5 & MASK1_S8) P0V39[0] = 1;
	else P0V39[0] = 0;
	P0V39[1] = P0V39[0];
	if (PO6 & MASK1_S8) P0V40[0] = 1;
	else P0V40[0] = 0;
	P0V40[1] = P0V40[0];
	if (PO7 & MASK1_S8) P0V41[0] = 1;
	else P0V41[0] = 0;
	P0V41[1] = P0V41[0];
}
