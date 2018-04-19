#include "lib.h"
#include "dll_interface.h"
#include "R_LIB.H"
#include "VM_queue_const.h"
#include "r_main.h" 


PortsHdl algInputPorts = nullptr;
PortsHdl algOutputPorts = nullptr;


INT8S * aInput = nullptr;
INT8S * aOutput = nullptr;


MgErr set_input_msg_from_CA(ArrayOfMessagesHdl input_msgs)
{

	return _msg_array_resize(input_msgs);
}
MgErr set_input_msg_from_SC(ArrayOfMessagesHdl input_msgs)
{
	return _msg_array_resize(input_msgs);
}

 MgErr set_output_msg(ArrayOfMessagesHdl output_msgs)
{
	
	return _msg_array_resize(output_msgs);
}
MgErr set_output_msg_to_SC(ArrayOfMessagesHdl output_msgs)
{
	return _msg_array_resize(output_msgs);
}


/* TODO:
*/

extern "C" __declspec(dllexport)void LLD(PortsHdl algInputPorts, //algInputPorts 
	PortsHdl algOutputPorts, //algOutputPorts

/*INPUT MSGS*/
	ArrayOfMessagesHdl scenarios2VerifierOutputMsgs, //scenarios2VerifierOutputMsgs
	ArrayOfMessagesHdl algOutputMsgs, //algOutputMsgs

/*OUTPUT MSGS*/
	ArrayOfMessagesHdl verifier2GUIOutputMsgs, //verifier2GUIOutputMsgs
	ArrayOfMessagesHdl verifier2scenariousControlOutMsgs, //verifier2scenariousControlOutMsgs
	ArrayOfStatesHdl states)
{
	static int32_t counter = 0;
	if (0 == counter)
	{
		if ((*algInputPorts)->dimSize + (*algOutputPorts)->dimSize != INPUT_PORTS_COUNTER)
		{
			return;
		}
		Init_PSW((INT16U)(PROCESS_N1), (INT16U)PROCESS_Nn); // »нициализаци¤  PSW процессов
		counter = 1;
		ConstructMsgQueue(&MainGUIOutputQueue);
		ConstructMsgQueue(&SCMOutputQueue);
		ConstructMsgQueue(&CAInputQueue);
		ConstructMsgQueue(&SCMInputQueue);			

		aInput = new INT8S[INPUT_PORTS_COUNTER];

		set_output_msg(verifier2GUIOutputMsgs);
		set_output_msg_to_SC(verifier2scenariousControlOutMsgs);
		
		_states_array_resize(states);
	}


	size_t input_size = (*algInputPorts)->dimSize;

	for (size_t i = 0; i < input_size; i++)
	{
		aInput[i] = (INT8S)(*algInputPorts)->ports[i];
	}
	for (size_t i = 0; i < (*algOutputPorts)->dimSize; i++)
	{
		aInput[i + input_size] = (INT8S)(*algOutputPorts)->ports[i];
	}
	
	parse_input_msg_array(algOutputMsgs, CAInputQueue);
	parse_input_msg_array(scenarios2VerifierOutputMsgs, SCMInputQueue);


	Control_Loop();
	parse_output_msg_array(MainGUIOutputQueue, verifier2GUIOutputMsgs);
	parse_output_msg_array(SCMOutputQueue, verifier2scenariousControlOutMsgs);
	
	for (int k = 0; k < (*states)->dimSize && k <= PROCESS_Nn; k++)
	{
		(*states)->state[k].cur_state = Pr_States[k].cur_state;
		(*states)->state[k].TimeInState = Pr_States[k].TimeInState;
	}

}



