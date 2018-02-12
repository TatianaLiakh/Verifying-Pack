#pragma once
#ifndef LAB_VIEW_DATA_TYPES_H
#define LAB_VIEW_DATA_TYPES_H
//#ifdef __cplusplus
//extern "C" {
//#include "extcode.h"
//}
//#else
//#include "extcode.h"
//#endif
#include "extcode.h"
#pragma pack(1)

#define TEST_MODE_TRUE

/* LabVIEW created typedefs - входныевыходные массивы*/
typedef struct Port
{
	int32 dimSize;
	int8 ports[1];
};
typedef Port **PortsHdl;

/* —ообщение типа:
*	- код сообщени€
*	- новое значение типа string
* - тип параметра */
typedef struct MessageCluster 
{
	int16 msg;// Msg 
	int32 param; // Value
	int16 type;
};

/*ћассив сообщений*/
typedef struct ArrayOfMessages 
{
	int32 dimSize;
	MessageCluster message[1];
};
typedef ArrayOfMessages **ArrayOfMessagesHdl;

typedef struct ProcessState
{
	uInt16 TimeInState;  /* врем€ нахождени€ в текущем состо€нии обнул€етс€ —тарт и Set_State*/
	int8 cur_state;     /* текущее состо€ние */
};

typedef struct ArrayOfStates
{
	int32 dimSize;
	ProcessState state[1];
} ArrayOfStates;

typedef ArrayOfStates ** ArrayOfStatesHdl;


#endif // !LAB_VIEW_DATA_TYPES_H

