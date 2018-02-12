/* MAIN FILE OF THE PROJECT */
#include <stdio.h>
#include <stdlib.h>  
#include <string.h>
#include "r_cnst.h" /* Internal constants */
#include "r_io.h"   /* IO-functions typedef */
#include "R_LIB.H"   /* IO-functions typedef */

#include "dll_interface.h" /* Internal constants */
#include "queue_const.h"
#include "LV_data_type.h"
#include "voc_id.h"
#include "bsvtusr1.h"

#pragma pack(1)

void fillInputQueue(ArrayOfMessagesHdl input_msg)
{
	int input_length = (*input_msg)->dimSize;
	int i = 0;
	unsigned char c;
	int par;
	float f;
	//FILE * file = fopen("input.txt", "a+" );
	MessageCluster * msg = (*input_msg)->message;

	for (i = 0; i < input_length; i++)
	{
		switch(msg[i].type)
		{
		case EMPTY_MSG:
			PutTailMsgQueue(& MainInputQueue,  msg[i].msg);
			break;
		case BYTE_TYPE:
			c = ((* msg[i].param)->str)[0];
			PutTailMsgQueueB(& MainInputQueue,  msg[i].msg , c);
			break;
		case INT_TYPE:
			par = atoi((* msg[i].param)->str);
			PutTailMsgQueueI( & MainInputQueue,  msg[i].msg, par);
			break;
		case FLOAT_TYPE:
			f = atof((* msg[i].param)->str);
			PutTailMsgQueueF( & MainInputQueue,  msg[i].msg, f);
			break;
		}
	}
	//fputs("\nHEAD : ", file);
	//fputc(MainInputQueue.head_item + '0', file);
	//fputs("\n  length : ", file);
	//fputc(MainInputQueue.length + '0', file);
	//fputs("\n  tail_item : ", file);
	//fputc(MainInputQueue.tail_item + '0', file);

	//fclose(file);
}

void getVOCMsg(ArrayOfMessagesHdl voc_msg)
{
	int input_length = (*voc_msg)->dimSize;
	int i = 0;
	unsigned char c;
	int par;
	FILE * file = fopen("FP_T_BAK.txt", "a+" );
	char buffer[100];
	float f, *f_ptr;
	int num;
	MessageCluster * msg = (*voc_msg)->message;

	fputc( input_length +'0' , file);
	fputs( " ^ \n" , file);	
	for (i = 0; i < input_length; i++)
	{
		switch(msg[i].msg)
		{
		case PK_TYEST_GUI_TYEMPYERATURA_VODY_V_BAKYE_IZMYENILAS_: /* ÏÊ_ÒÅÑÒ_ÃÓÈ_ÒÅÌÏÅÐÀÒÓÐÀ_ÂÎÄÛ_Â_ÁÀÊÅ_ÈÇÌÅÍÈËÀÑÜ */
			num = atoi((* msg[i].param)->str);
			f_ptr = (float*)&num;
			FP_T_BAK = *f_ptr;
			sprintf(buffer, " ÏÊ_ÒÅÑÒ_ÃÓÈ_ÒÅÌÏÅÐÀÒÓÐÀ_ÂÎÄÛ_Â_ÁÀÊÅ_ÈÇÌÅÍÈËÀÑÜ : %f", *f_ptr);
			fputs( buffer , file);
			fputs( " ^ \n" , file);				
			break;

		case PK_TYEST_GUI_DAVLYENIYE_V_BAKYE_KOMPRYESSORA_IZMYENILOS_: /* ÏÊ_ÒÅÑÒ_ÃÓÈ_ÄÀÂËÅÍÈÅ_Â_ÁÀÊÅ_ÊÎÌÏÐÅÑÑÎÐÀ_ÈÇÌÅÍÈËÎÑÜ */
			num = atoi((* msg[i].param)->str);
			f_ptr = (float*)&num;
			FP_P_BAK_COMPRESSOR = *f_ptr;

			sprintf(buffer, " ÏÊ_ÒÅÑÒ_ÃÓÈ_ÄÀÂËÅÍÈÅ_Â_ÁÀÊÅ_ÊÎÌÏÐÅÑÑÎÐÀ_ÈÇÌÅÍÈËÎÑÜ : %f", *f_ptr);
			fputs( buffer , file);
			fputs( " ^ \n" , file);		
			break;

		case PK_TYEST_GUI_DAVLYENIYE_V_PATRUBKYE_IZMYENILOS_: /* ÏÊ_ÒÅÑÒ_ÃÓÈ_ÄÀÂËÅÍÈÅ_Â_ÏÀÒÐÓÁÊÅ_ÈÇÌÅÍÈËÎÑÜ */
			num = atoi((* msg[i].param)->str);
			f_ptr = (float*)&num;
			FP_P_PATRUBKA = *f_ptr;

			sprintf(buffer, " ÏÊ_ÒÅÑÒ_ÃÓÈ_ÄÀÂËÅÍÈÅ_Â_ÏÀÒÐÓÁÊÅ_ÈÇÌÅÍÈËÎÑÜ : %f", *f_ptr);
			fputs( buffer , file);
			fputs( " ^ \n" , file);	
			break;

		case PK_TYEST_GUI_TYEMPYERATURA_VODY_V_RUBASHKYE_IZMYENILAS_: /* ÏÊ_ÒÅÑÒ_ÃÓÈ_ÒÅÌÏÅÐÀÒÓÐÀ_ÂÎÄÛ_Â_ÐÓÁÀØÊÅ_ÈÇÌÅÍÈËÀÑÜ */
			num = atoi((* msg[i].param)->str);
			f_ptr = (float*)&num;
			FP_T_RUBACHKA = *f_ptr;

			sprintf(buffer, " ÏÊ_ÒÅÑÒ_ÃÓÈ_ÒÅÌÏÅÐÀÒÓÐÀ_ÂÎÄÛ_Â_ÐÓÁÀØÊÅ_ÈÇÌÅÍÈËÀÑÜ : %f", *f_ptr);
			fputs( buffer , file);
			fputs( " ^ \n" , file);	
			break;

		case PK_TYEST_GUI_DAVLYENIYE_V_TRUBYE_SIDYEROSTATA_IZMYENILOS_: /* ÏÊ_ÒÅÑÒ_ÃÓÈ_ÄÀÂËÅÍÈÅ_Â_ÒÐÓÁÅ_ÑÈÄÅÐÎÑÒÀÒÀ_ÈÇÌÅÍÈËÎÑÜ */
			num = atoi((* msg[i].param)->str);
			f_ptr = (float*)&num;
			FP_P_TRUBA = *f_ptr;

			sprintf(buffer, " ÏÊ_ÒÅÑÒ_ÃÓÈ_ÄÀÂËÅÍÈÅ_Â_ÒÐÓÁÅ_ÑÈÄÅÐÎÑÒÀÒÀ_ÈÇÌÅÍÈËÎÑÜ : %f", *f_ptr);
			fputs( buffer , file);
			fputs( " ^ \n" , file);	
			break;
		}
	}

	fclose(file);
}

void fillOutputQueue(ArrayOfMessagesHdl output_msg)
{
	QueueMsg msg;
	LStrHandle * str;
	int i = 0;

	while (!isEmptyMsgQueue( & MainOutputQueue))
	{
		str = & ( (*output_msg)->message[i].param);

		GetHeadMsgQueue(& MainOutputQueue, & msg);
		(*output_msg)->message[i].msg = msg.code;

		sprintf((**str)->str, "%d", msg.param.pr_int[0]);
		(**str)->cnt = strlen((**str)->str);

		i++;
	}
}

__declspec(dllexport)void LLD (PortsHdl input, PortsHdl output, ArrayOfMessagesHdl input_msg, ArrayOfMessagesHdl output_msg, ArrayOfStatesHdl array_of_states, ArrayOfMessagesHdl voc_msg);


void LLD (PortsHdl input, PortsHdl output, ArrayOfMessagesHdl input_msg, ArrayOfMessagesHdl output_msg, ArrayOfStatesHdl array_of_states, ArrayOfMessagesHdl voc_msg)    /* Óïðàâëÿþùèé àëãîðèòì */
{
	FILE * file = fopen("list.txt", "a+" );
	int k = 0; 
	static int control = 0;
	MessageCluster * msg = (*input_msg)->message;
	char buffer[20];


	aInput = (*input)->ports;
	aOutput = (*output)->ports;
	input_counter = (*input)->dimSize;
	output_counter = (*output)->dimSize;	

	/*fputs("\nstart new \n", file);

	fputs("\ninit input values\n", file);

	for (  k = 0; k < input_counter ; k++)
	{
	char sym = aInput[k] + '0';
	fputc( sym , file);
	}

	fputs("\ninit output values\n", file);

	for (  k = 0; k < output_counter ; k++)
	{
	char sym = aOutput[k] + '0';
	fputc( sym , file);
	}

	*/
	if( 0 == control)
	{
		Init_PSW((INT16U)(PROCESS_N1), (INT16U)PROCESS_Nn); // Èíèöèàëèçàöèÿ  PSW ïðîöåññîâ
		control++;
		ConstructMsgQueue(&MainInputQueue);
		//fputs("\nMSG queue constructed\n", file);

	}

	//k = (*array_of_states)->dimSize;
	//fputs( "\n $ "  , file);

	//fputc( k + '0'  , file);
	//fputs( " $ "  , file);

	for (k = 0; k < (*array_of_states)->dimSize; k++)
	{
		//fputs( " ^ " , file);
		//fputs( itoa(Pr_States[k].cur_state, buffer, 10 )  , file);
		//fputs( " - " , file);
		//fputs( itoa((*array_of_states)->state[k].cur_state, buffer, 10 )  , file);

		(*array_of_states)->state[k].cur_state = Pr_States[k].cur_state;
		(*array_of_states)->state[k].TimeInState = Pr_States[k].TimeInState;

	}
	//	fclose(file);

	//for (k = 0; k <  (*input_msg)->dimSize; k++)
	//{
	//	fputc( msg[k].msg +'0', file); 
	//	fputs(" : ", file);
	//	fputs((* msg[k].param)->str, file);
	//	fputs(" : ", file);
	//	fputc( msg[k].type +'0', file); 
	//	fputs("\n", file);
	//}

	fillInputQueue(input_msg);
	getVOCMsg(voc_msg);
	//fputs("input msg taken\n", file);
	//fclose(file);

	Control_Loop();

	fillOutputQueue(output_msg);

	msg = (*output_msg)->message;

	//for (k = 0; k <  (*output_msg)->dimSize; k++)
	//{
	//	fputc( msg[k].msg +'0', file); 
	//	fputs(" : ", file);
	//	fputs((* msg[k].param)->str, file);
	//	fputs(" : ", file);
	//	fputc( msg[k].type +'0', file); 
	//	fputs("\n", file);
	//}
	//fclose(file);


	//for (  k = 0; k < 3 ; k++)
	//{
	//	char sym = aInput[k] + '0';
	//	fputc( sym , file);
	//}

	//fputs("\nresult output values\n", file);

	//for (  k = 0; k < (*output_msg)->dimSize ; k++)
	//{
	//	char sym = aOutput[k] + '0';
	//	fputc( sym , file);
	//	fputs( " ^ " , file);
	//	
	//}
	sprintf(buffer, "%f", FP_T_BAK);
	fputs( buffer , file);
	fputs( " ^ \n" , file);

	fclose(file);
}


//void main ()
//{
//	MessageCluster m_byte;
//	MessageCluster m_int;
//	MessageCluster m_float;
//	MessageCluster m[3];
//
//	ArrayOfMessages input_msg_c, * im;
//	ArrayOfMessages output_msg;
//
//	LStr *ll, l_i;
//	int i;
//
//	//i = sizeof(MainInputQueue.Arr[0].param); //8
//	//i = sizeof(MainInputQueue.Arr[0].param.pr_char); //4
//	//i = sizeof(MainInputQueue.Arr[0].param.pr_float);//4
//	//i = sizeof(MainInputQueue.Arr[0].param.pr_int);//8
//	//i = sizeof(MainInputQueue.Arr[0].param.pr_long);//4
//	//i = sizeof(MainInputQueue.Arr[0].param.pr_short);
//
//
//
//
//
//
//	//m_byte.msg = 0;
//	//m_byte.param =  & ll;
//	//m_byte.type = BYTE_TYPE;
//
//	l_i.cnt = 11;
//	sprintf(l_i.str, "315.4");
//	ll = & l_i;
//
//	m_float.msg = 1;
//	m_float.param =  & ll;
//	m_float.type = FLOAT_TYPE;/*
//
//	m_int.msg = 2;
//	m_int.param =  & ll;
//	m_int.type = INT_TYPE;*/
//
//	input_msg_c.dimSize = 1;
//	input_msg_c.message[0] = m_float;
//	im = &input_msg_c;
//
//	LLD(0,0,&im,0);
//
//
//}