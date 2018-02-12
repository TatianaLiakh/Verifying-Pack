/* MAIN FILE OF THE PROJECT */
#include <stdio.h>
#include <stdlib.h>  
#include <string.h>
#include "r_cnst.h" /* Internal constants */
#include "r_io.h"   /* IO-functions typedef */
#include "r_lib.H"

#include "dll_interface.h" /* Internal constants */
#include "msg_queue.h"
#include "LV_data_type.h"


#pragma pack(1)

void Control_Loop (); 

char * aInput;
char * aOutput;

int input_counter;
int output_counter;

MsgQueue MainInputQueue;
MsgQueue MainOutputQueue;

struct St_Word *Pr_States;                        
struct St_Word Original_Pr_States[PROCESS_Nn + 1];



void fillInputQueue(ArrayOfMessagesHdl input_msg)
{
	int input_length = (*input_msg)->dimSize;
	int i = 0;
	unsigned char c;
	int par;
	float f;
	MessageCluster * msg = (*input_msg)->message;
	if (input_length == 0)
		return;
	
	for (i = 0; i < input_length; i++)
	{
		if (msg[i].msg == -1) return;
		switch(msg[i].type)
		{
		case EMPTY_MSG:
			PutTailMsgQueue(& MainInputQueue,  msg[i].msg);
			break;
		case BYTE_TYPE:
			c =  msg[i].param;
			PutTailMsgQueueB(& MainInputQueue,  msg[i].msg , c);
			break;
		case INT_TYPE:
			par = msg[i].param;
			PutTailMsgQueueI( & MainInputQueue,  msg[i].msg, par);
			break;
		case FLOAT_TYPE:
			f = *(float *)(&(msg[i].param));
			PutTailMsgQueueF( & MainInputQueue,  msg[i].msg, f);
			break;
		}
	}
}

//FOR TESTING
void imitateOuputQueue(ArrayOfMessagesHdl input_msg)
{
	int input_length = (*input_msg)->dimSize;
	int i = 0;
	unsigned char c;
	int par;
	float f;
	FILE * file = fopen("input_log.txt", "a+" );
	char buffer[100];
	MessageCluster * msg = (*input_msg)->message;
	if (input_length == 0)
	{
		fputs("EMPTY\n ", file);
		return;
	}
	
	for (i = 0; i < input_length; i++)
	{
		sprintf(buffer, "\n Type: %d", msg[i].type);
		fputs( buffer , file);
		sprintf(buffer, "\n Code: %d", msg[i].msg);
		fputs( buffer , file);
		sprintf(buffer, "\n Paaram: %d", msg[i].param);
		fputs( buffer , file);
		switch(msg[i].type)
		{
		case EMPTY_MSG:
			PutTailMsgQueue(& MainOutputQueue,  msg[i].msg);
			fputs("EMPTY_MSG\n ", file);
			break;
		case BYTE_TYPE:
			c =  msg[i].param;
			PutTailMsgQueueB(& MainOutputQueue,  msg[i].msg , c);
			fputs("BYTE_TYPE\n ", file);
			break;
		case INT_TYPE:
			par = msg[i].param;
			PutTailMsgQueueI( & MainOutputQueue,  msg[i].msg, par);
			sprintf(buffer, "\nINT %d", par);			
			fputs(buffer, file);
			break;
		case FLOAT_TYPE:
			f = *(float *)(&(msg[i].param));
			sprintf(buffer, "\nFLOAT %f", f);
			fputs( buffer , file);

			PutTailMsgQueueF( & MainOutputQueue,  msg[i].msg, f);
			break;
		}
	}
	fclose(file);
}

void fillOutputQueue(ArrayOfMessagesHdl output_msg)
{
	QueueMsg msg;
	int param;
	int i = 0;
	FILE * file = fopen("output_log.txt", "a+" );
	char buffer[100];

	while (!isEmptyMsgQueue( & MainOutputQueue))
	{
		if ( (*output_msg)->dimSize <= i) 
			return;


		GetHeadMsgQueue(& MainOutputQueue, & msg);
		(*output_msg)->message[i].msg = msg.code;
		(*output_msg)->message[i].param = msg.param.pr_long;
		(*output_msg)->message[i].type = msg.type;

		sprintf(buffer, "\n Type: %d", (int)(msg.type));
		fputs( buffer , file); 
	
		i++;
	}
	fclose(file);
}

__declspec(dllexport)void LLD (PortsHdl input, PortsHdl output, ArrayOfMessagesHdl input_msg, ArrayOfMessagesHdl output_msg, ArrayOfStatesHdl array_of_states);


void LLD (PortsHdl input, PortsHdl output, ArrayOfMessagesHdl input_msg, ArrayOfMessagesHdl output_msg, ArrayOfStatesHdl array_of_states)    /* ”правл€ющий алгоритм */
{
	int k = 0; 
	static int control = 0;
	MessageCluster * msg = (*input_msg)->message;
	char buffer[20];


	aInput = (*input)->ports;
	aOutput = (*output)->ports;
	input_counter = (*input)->dimSize;
	output_counter = (*output)->dimSize;	

	
	if( 0 == control)
	{
		Init_PSW((INT16U)(PROCESS_N1), (INT16U)PROCESS_Nn); // »нициализаци€  PSW процессов
		control = 1;
		ConstructMsgQueue(&MainInputQueue);
	}


	fillInputQueue(input_msg);

	//imitateOuputQueue(input_msg);

	Control_Loop();

	fillOutputQueue(output_msg);

	for (k = 0; k < (*array_of_states)->dimSize && k <= PROCESS_Nn; k++)
	{
		(*array_of_states)->state[k].cur_state = Pr_States[k].cur_state;
		(*array_of_states)->state[k].TimeInState = Pr_States[k].TimeInState;

	}
}


