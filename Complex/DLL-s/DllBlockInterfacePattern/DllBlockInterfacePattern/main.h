#pragma once
#include <stdint.h>
#include "extcode.h"

typedef struct Port
{
	int32_t dimSize;
	int8_t ports[1];
};
typedef Port **PortsHdl;

MgErr integerArrayResize(PortsHdl array, size_t new_size)
{
	MgErr error = NumericArrayResize(uB, 1, (UHandle*)(&array), new_size);
	(*array)->dimSize = new_size;
	(*array)->ports[9] = 255;
	return error;

}

void set_input_ports_array(PortsHdl input)
{
	

	if (nullptr != input)
	{
		integerArrayResize(input, 10); 
	}

}
void set_output_ports_array(int16_t * oputput);
void set_states_array();


void loop();
