#include "lib.h"
#include "dll_interface.h"
#include "R_LIB.H"
#include "queue_const.h"
#include "r_main.h" 


PortsHdl algInputPorts = nullptr;
PortsHdl algOutputPorts = nullptr;


INT8S * aInput = nullptr;
INT8S * aOutput = nullptr;

ArrayOfMessagesHdl inputMsgArrayFromCA = nullptr;
ArrayOfMessagesHdl inputMsgArrayFromSC = nullptr;

ArrayOfMessagesHdl outputMsgArray = nullptr;
ArrayOfMessagesHdl outputMsgArray2SC = nullptr;

ArrayOfStatesHdl states = nullptr;




__declspec(dllexport) MgErr set_input_ports_array(PortsHdl new_handler)
{
	algInputPorts = new_handler;
	sayToWholeWorld("VB: set_input_ports_array"); 

	return checkPortsArrays();
}
__declspec(dllexport) MgErr set_output_ports_array(PortsHdl new_handler)
{
	algOutputPorts = new_handler;
	sayToWholeWorld("VB: set_output_ports_array");
	
	return checkPortsArrays();
}

__declspec(dllexport) MgErr set_input_msg_from_CA(ArrayOfMessagesHdl input_msgs)
{
	inputMsgArrayFromCA = input_msgs;

	sayToWholeWorld("VB: set_input_msg_from_CA");

	return _msg_array_resize(input_msgs);
}
__declspec(dllexport) MgErr set_input_msg_from_SC(ArrayOfMessagesHdl input_msgs)
{
	inputMsgArrayFromSC = input_msgs;

	sayToWholeWorld("VB: set_input_msg_from_SC");

	return _msg_array_resize(input_msgs);
}

__declspec(dllexport) MgErr set_output_msg(ArrayOfMessagesHdl output_msgs)
{
	outputMsgArray = output_msgs;

	sayToWholeWorld("VB: set_output_msg");

	return _msg_array_resize(output_msgs);
}
__declspec(dllexport) MgErr set_output_msg_to_SC(ArrayOfMessagesHdl output_msgs)
{
	outputMsgArray2SC = output_msgs;
	sayToWholeWorld("VB: set_output_msg_to_SC");
	//DSDisposeHandle(output_msgs); 
	//DSSetAlignedHSzClr();

	return _msg_array_resize(output_msgs);
}

__declspec(dllexport) MgErr set_states_array(ArrayOfStatesHdl states_hdl)
{
	states = states_hdl;
	MgErr error;
	if (mgNoErr == (error = DSSetHSzClr(states_hdl, Offset(ArrayOfStates, state) + sizeof(ProcessState) * (PROCESS_Nn + 1))))
	{
		for (size_t i = 0; i <= PROCESS_Nn; i++)
		{
			(*states_hdl)->state[i].cur_state = (int8)STATE_OF_STOP;
			(*states_hdl)->state[i].TimeInState = 0;
		}
		sayToWholeWorld("VB: set_states_array");

	}
	return error;
}


__declspec(dllexport)void LLD()
{
	static int32_t counter = 0;
	if (0 == counter)
	{
		Init_PSW((INT16U)(PROCESS_N1), (INT16U)PROCESS_Nn); // »нициализаци¤  PSW процессов
		counter = 1;
		ConstructMsgQueue(&MainGUIOutputQueue);
		ConstructMsgQueue(&SCMOutputQueue);
		ConstructMsgQueue(&CAInputQueue);
		ConstructMsgQueue(&SCMInputQueue);
	}

	parse_input_msg_array(inputMsgArrayFromCA, CAInputQueue);
	parse_input_msg_array(inputMsgArrayFromSC, SCMInputQueue);

	Control_Loop();

	parse_output_msg_array(MainGUIOutputQueue, outputMsgArray);
	parse_output_msg_array(SCMOutputQueue, outputMsgArray2SC);


	for (int k = 0; k < (*states)->dimSize && k <= PROCESS_Nn; k++)
	{
		(*states)->state[k].cur_state = Pr_States[k].cur_state;
		(*states)->state[k].TimeInState = Pr_States[k].TimeInState;
	}

}

void main(ArrayOfMessagesHdl * states_hdl)
{
	
//	(**states_hdl)->message[0].msg = 12;
//	_msg_array_resize(*states_hdl);

	int32_t new_size = ARRLENRSMSG;
	MgErr err;
	if (mgNoErr == (err = DSSetHSzClr(*states_hdl, Offset(ArrayOfMessages, message) + new_size * sizeof(MessageCluster))))
	{
		for (size_t i = 0; i < new_size; i++)
		{
			MessageCluster * msg = &(**states_hdl)->message[i];
			msg->msg = 10;
			msg->type = -9;
			msg->param = 100;
		}
		(**states_hdl)->dimSize = new_size;
	}
}


#include <cstdio>

void sayToWholeWorld(char * speach)
	{
		FILE * f;

		fopen_s(&f, "D:/LOGGER_ERROR.txt", "w");
		fprintf(f, speach);
		fclose(f);
	}




