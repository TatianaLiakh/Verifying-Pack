#include "lib.h"
#include "dll_interface.h"
#include "R_LIB.H"
#include "SCM_queue_const.h"
#include "r_main.h" 

 INT8S * aInput = nullptr;
 INT8S * aOutput = nullptr;


MgErr set_input_msg_from_VM(ArrayOfMessagesHdl input_msgs)
{
	return _msg_array_resize(input_msgs);
}

 MgErr set_output_msg_to_Alg(ArrayOfMessagesHdl output_msgs)
{
	return _msg_array_resize(output_msgs);
}
MgErr set_output_msg_to_VP(ArrayOfMessagesHdl output_msgs)
{
	return _msg_array_resize(output_msgs);
}

MgErr set_output_msg_to_VM(ArrayOfMessagesHdl output_msgs)
{
	return _msg_array_resize(output_msgs);
}


/* TODO:
*/

extern "C" __declspec(dllexport)void LLD(	ArrayOfMessagesHdl verifier2scenariousControlOutMsgs, //verifier2scenariousControlOutMsgs  
								ArrayOfMessagesHdl scenarios2AlgOutputMsgs, //scenarios2AlgOutputMsgs
								ArrayOfMessagesHdl scenarios2VirtPlantOutputMsgs, //scenarios2VirtPlantOutputMsgs
								ArrayOfMessagesHdl scenarios2VerifierOutputMsgs, //scenarios2VerifierOutputMsgs
								ArrayOfStatesHdl states)
{
	static int32_t counter = 0;
	if (0 == counter)
	{
		Init_PSW((INT16U)(PROCESS_N1), (INT16U)PROCESS_Nn); // ������������  PSW ���������
		counter = 1;

		ConstructMsgQueue(&InputQueueFromVM);

		ConstructMsgQueue(&SCM2CA_OutputQueue);
		ConstructMsgQueue(&SCM2VP_OutputQueue);
		ConstructMsgQueue(&SCM2VM_OutputQueue);


		//set_input_msg_from_VM(verifier2scenariousControlOutMsgs);

		set_output_msg_to_Alg(scenarios2AlgOutputMsgs);
		set_output_msg_to_VP(scenarios2VirtPlantOutputMsgs);
		set_output_msg_to_VM(scenarios2VerifierOutputMsgs);

		_states_array_resize(states);
	}

	parse_input_msg_array(verifier2scenariousControlOutMsgs, InputQueueFromVM);

	Control_Loop();

	parse_output_msg_array(SCM2CA_OutputQueue, scenarios2AlgOutputMsgs);
	parse_output_msg_array(SCM2VP_OutputQueue, scenarios2VirtPlantOutputMsgs);
	parse_output_msg_array(SCM2VM_OutputQueue, scenarios2VerifierOutputMsgs);

	for (int k = 0; k < (*states)->dimSize && k <= PROCESS_Nn; k++)
	{
		(*states)->state[k].cur_state = Pr_States[k].cur_state;
		(*states)->state[k].TimeInState = Pr_States[k].TimeInState;
	}

}




