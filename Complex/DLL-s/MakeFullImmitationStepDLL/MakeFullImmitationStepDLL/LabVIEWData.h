#pragma once
#ifndef LAB_VIEW_DATA_TYPES_H
#define LAB_VIEW_DATA_TYPES_H
#include <cstdint> 

#include "windows.h"

#define TEST_MODE_TRUE true

/* LabView string handler*/
typedef struct LabViewString{
	int16_t	cnt;		/* number of bytes that follow */
	int8_t str[1];		/* cnt bytes */
} LStr, *LStrPtr, **LStrHandle;

/* LabVIEW created typedefs - ��������������� �������*/
typedef struct Port
{
	int32_t dimSize;
	int8_t ports[1];
};
typedef Port **PortsHdl;

/* ��������� ����:
*	- ��� ���������
*	- ����� �������� ���� string
* - ��� ��������� */
typedef struct MessageCluster 
{
	int16_t msg;// Msg 
	int32_t param; // Value
	int16_t type;
};

/*������ ���������*/
typedef struct ArrayOfMessages 
{
	int32_t dimSize;
	MessageCluster message[1];
};
typedef ArrayOfMessages **ArrayOfMessagesHdl;

typedef struct ProcessState
{
	uint16_t TimeInState;  /* ����� ���������� � ������� ��������� ���������� ����� � Set_State*/
	int8_t cur_state;     /* ������� ��������� */
};

typedef struct ArrayOfStates
{
	int32_t dimSize;
	ProcessState state[1];
} ArrayOfStates;

typedef ArrayOfStates ** ArrayOfStatesHdl;


#endif // !LAB_VIEW_DATA_TYPES_H

