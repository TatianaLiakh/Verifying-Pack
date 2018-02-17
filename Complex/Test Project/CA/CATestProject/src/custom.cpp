#include "dll_interface.h"

#include "r_io.h"
#include "R_LIB.H"
#include "r_main.h" 

#include "msg_queue.h"
#include "queue_const.h"


// FOR CA

__declspec(dllexport)void LLD(PortsHdl algInputPorts, //algInputPorts 
	PortsHdl algOutputPorts, //algOutputPorts
	ArrayOfMessagesHdl scenarios2AlgOutputMsgs, //scenarios2AlgOutputMsgs
	ArrayOfMessagesHdl algOutputMsgs, //algOutputMsgs
	ArrayOfStatesHdl states_hdl)

{
	static int32_t counter = 0;
	if (0 == counter)
	{
		// Initialization  
		Init_PSW((INT16U)(PROCESS_N1), (INT16U)PROCESS_Nn); // »нициализаци¤  PSW процессов
		counter = 1;
		ConstructMsgQueue(&MainInputQueue);
		ConstructMsgQueue(&MainOutputQueue);

		set_input_ports_array(algInputPorts);
		set_output_ports_array(algOutputPorts);

	//	set_input_msg(scenarios2AlgOutputMsgs);
		set_output_msg(algOutputMsgs);

		set_states_array(states_hdl);
	}

	aInput = reinterpret_cast<INT8S*> ((*algInputPorts)->ports);
	aOutput = reinterpret_cast<INT8S*> ((*algOutputPorts)->ports);


	parse_input_msg_array(scenarios2AlgOutputMsgs);
	Control_Loop();
	parse_output_msg_array(algOutputMsgs);

	for (int k = 0; k < (*states_hdl)->dimSize && k <= PROCESS_Nn; k++)
	{
		(*states_hdl)->state[k].cur_state = Pr_States[k].cur_state;
		(*states_hdl)->state[k].TimeInState = Pr_States[k].TimeInState;
	}

}
