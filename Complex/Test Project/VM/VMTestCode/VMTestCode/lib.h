#pragma once
#include "LabVIEWData.h"
#include "r_io.h"
#include "msg_queue.h"

MgErr checkPortsArrays();

MgErr _msg_array_resize(ArrayOfMessagesHdl _msgs);

void parse_input_msg_array(ArrayOfMessagesHdl input_LV_queue, MsgQueue & result_queue); 

void parse_output_msg_array(MsgQueue & output_queue, ArrayOfMessagesHdl output_LV_queue); 