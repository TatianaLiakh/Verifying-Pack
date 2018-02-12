#include "msg_queue.h"


enum MsgCodes
{
	EMPTY_MSG,
	BYTE_TYPE,
    INT_TYPE,
    FLOAT_TYPE
};

MsgQueue MainInputQueue;
MsgQueue MainOutputQueue;

