#include "1.h"
#include <stdlib.h> 


#define TEST_MODE_TRUE true

#ifdef  TEST_MODE_TRUE
#include <iostream>
#include <fstream>
std::ofstream logger;
#endif //  TEST



struct cool
{
	int g;
	int * h;
};

cool c = { 2, nullptr };
void sayToWholeWorld(char * speach);

int main()
{
//#ifdef TEST_MODE_TRUE
//
//	if (true == logger.is_open())
//	{
//		logger << "Initialisation\n" << std::endl;
//	}
//	logger.open("LOG.txt", std::ios::out | std::ios::app);
//	logger << "Initialisation!!!\n" << std::endl;
//	logger.close();
//
//	logger.open("LOG.txt", std::ios::out | std::ios::app);
//	logger << "Initialisation!!!\n" << std::endl;
//
//#endif // TEST_MODE_TRUE
//

	sayToWholeWorld("VB: set_states_array");
	load(8);
}

void sayToWholeWorld(char * speach)
{
	FILE * f;

	fopen_s(&f, "LOGGER_ERROR.txt", "w");
	fprintf(f, speach);
	fclose(f);
}


/* LabVIEW created typedefs - входныевыходные массивы*/
typedef struct Port
{
	int32_t dimSize;
	int8_t ports[1];
};
typedef Port **PortsHdl;

/* —ообщение типа:
*	- код сообщени€
*	- новое значение типа string
* - тип параметра */
typedef struct MessageCluster
{
	int16_t msg;// Msg 
	int32_t param; // Value
	int16_t type;
};

/*ћассив сообщений*/
typedef struct ArrayOfMessages
{
	int32_t dimSize;
	MessageCluster message[1];
};
typedef ArrayOfMessages **ArrayOfMessagesHdl;

typedef struct ProcessState
{
	uint16_t TimeInState;  /* врем€ нахождени€ в текущем состо€нии обнул€етс€ —тарт и Set_State*/
	int8_t cur_state;     /* текущее состо€ние */
};

typedef struct ArrayOfStates
{
	int32_t dimSize;
	ProcessState state[1];
} ArrayOfStates;

typedef ArrayOfStates ** ArrayOfStatesHdl;


typedef void(*MainCAFunction) (PortsHdl, //algInputPorts 
	PortsHdl, //algOutputPorts
	ArrayOfMessagesHdl, //scenarios2AlgOutputMsgs
	ArrayOfMessagesHdl, //algOutputMsgs
	ArrayOfStatesHdl);


__declspec(dllexport)int load(int num)
{
	HINSTANCE module = nullptr;

	if (nullptr == (module = ::LoadLibrary("SCM.dll")))
	{
		int g = GetLastError();
		return -1;
	}

	typedef void ( * CA) ();
	CA ca = nullptr;
	void * add;

	add = (CA)::GetProcAddress((HMODULE)module, "LLD");
	if (nullptr == add)
	{
		::FreeLibrary(module);
		int g = GetLastError();
		return -2;
	}
	// ca();

	::FreeLibrary(module); 

	return 0;
}