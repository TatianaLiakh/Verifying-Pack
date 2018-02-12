#include "queue_const.h"
#include "custom.h"

// FOR CA

void * get_output_msg()
{
	return static_cast <void *> (&MainInputQueue); 
}

void * get_input_msg()
{
	return static_cast <void *> (&MainOutputQueue);
}


