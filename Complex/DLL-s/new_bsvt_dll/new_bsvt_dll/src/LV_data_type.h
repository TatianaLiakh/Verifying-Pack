#include "R_LIB.H"

#pragma pack(1)

extern struct St_Word cat;

void Init_PSW(INT16U, INT16U);
void Control_Loop (); 


/* LabView string handler*/ 
typedef struct { 
	int	cnt;		/* number of bytes that follow */
	char str[1];		/* cnt bytes */
} LStr, *LStrPtr, **LStrHandle;

/* LabVIEW created typedefs - входныевыходные массивы*/
typedef struct {
	long dimSize;
	char ports[1];
} Ports;
typedef Ports **PortsHdl;

/* —ообщение типа:
*	- код сообщени€
*	- новое значение типа string
* - тип параметра */
typedef struct {
	int msg;// Msg 
	LStrHandle param; // Value
	int type;
} MessageCluster;

typedef struct {
	long dimSize;
	MessageCluster message[1];
} ArrayOfMessages;
typedef ArrayOfMessages **ArrayOfMessagesHdl;

/* ќтладочна€ информаци€: врем€ и состо€ни€*/

typedef struct 
{
    unsigned int  TimeInState;  /* врем€ нахождени€ в текущем состо€нии обнул€етс€ —тарт и Set_State*/
    INT8U cur_state;     /* текущее состо€ние */
} ProcStates;

typedef struct ArrayOfStates
{
	long dimSize;
	ProcStates state [1];
} ArrayOfStates;

typedef ArrayOfStates **ArrayOfStatesHdl;