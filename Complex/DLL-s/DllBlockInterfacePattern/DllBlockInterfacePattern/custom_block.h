#pragma once
#include "extcode.h"


/*FOR CA*/
void set_output_msg();
void set_input_msg();

/*FOR VP*/

typedef struct {
	int32_t dimSize;
	uInt16 Item[1];
} DataArray;
typedef DataArray ** DataArrayPtr;



void set_input_msg(DataArrayPtr array)
{
	MgErr error = NumericArrayResize(uB, 1, (UHandle*)(&array), 10);
	(*array)->dimSize = 10;
	(*array)->Item[9] = 255;
	return error;

}

/*FOR SC*/

void set_output_msg_queue_for_CA();
void set_output_msg_queue_for_VP();
void set_output_msg_queue_for_VB();

/*FOR VB*/

void set_output_msg();
void set_input_msg_from_CA();
void set_input_msg_from_SC();

