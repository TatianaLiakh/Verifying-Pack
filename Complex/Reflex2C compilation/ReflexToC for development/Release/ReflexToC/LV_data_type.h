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

/* LabVIEW created typedefs - ��������������� �������*/
typedef struct {
	long dimSize;
	char ports[1];
} Ports;
typedef Ports **PortsHdl;

/* ��������� ����:
*	- ��� ���������
*	- ����� �������� ���� string
* - ��� ��������� */
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

/* ���������� ����������: ����� � ���������*/

typedef struct 
{
    unsigned int  TimeInState;  /* ����� ���������� � ������� ��������� ���������� ����� � Set_State*/
    INT8U cur_state;     /* ������� ��������� */
} ProcStates;

typedef struct ArrayOfStates
{
	long dimSize;
	ProcStates state [1];
} ArrayOfStates;

typedef ArrayOfStates **ArrayOfStatesHdl;