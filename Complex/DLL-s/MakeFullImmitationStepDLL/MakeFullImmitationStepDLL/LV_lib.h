#pragma once
#include "LabVIEWData.h"
#include "internal_errors.h"

#ifdef  TEST_MODE_TRUE
#include <iostream>
#include <fstream>
extern std::ofstream logger;
#endif //  TEST

typedef void( * MainFunction) ();

struct ModuleDescriptor
{
	HINSTANCE module;
	LPTSTR libName;
	MainFunction function;
};

extern ModuleDescriptor ca_module;
extern ModuleDescriptor vp_module;
extern ModuleDescriptor vb_module;
extern ModuleDescriptor sc_module;


#ifdef _WIN32
extern HINSTANCE hCAModule ;
extern HINSTANCE hVPModule;
extern HINSTANCE hVBModule;
extern HINSTANCE hSCModule;

extern LPTSTR ControlAlgorithmName ;
extern LPTSTR VirtualBlockName ;
extern LPTSTR VirtualPlantName ;
extern LPTSTR ScriptControlName ;
#endif


//typedef void(__stdcall * VP) ();
//typedef void(__stdcall * VB) ();
//typedef void(__stdcall * SC) ();

extern MainFunction ca ;
extern MainFunction vp ;
extern MainFunction vb ;
extern MainFunction sc ;
//extern LPTSTR MainFunctionName;

/*LV DATA STORE*/
extern PortsHdl algIP;
extern PortsHdl algOP;
/*MsgQueues*/
extern ArrayOfMessagesHdl sc2AlgOutMsgs ;
extern ArrayOfMessagesHdl sc2VpOutMsgs;
extern ArrayOfMessagesHdl sc2VerfOutMsgs ;
extern ArrayOfMessagesHdl ver2scOutMsgs ;

/*Msg2GUI*/
extern ArrayOfMessagesHdl algOutMsgs ;
extern ArrayOfMessagesHdl verf2GUIOutMsgs;
extern ArrayOfMessagesHdl vp2GUIOutMsgs ;
/*StatesArrays*/
extern ArrayOfStatesHdl aS ;
extern ArrayOfStatesHdl vpS ;
extern ArrayOfStatesHdl verS ;
extern ArrayOfStatesHdl scS ;
/**/

DllCallErroros setPortsArrays(HINSTANCE module, PortsHdl arrayInp, PortsHdl arrayOutp);
DllCallErroros setIOMsgsArrays(HINSTANCE module, ArrayOfMessagesHdl inputMsgs, ArrayOfMessagesHdl outputMsgs);
DllCallErroros setIOMsgsArrays(HINSTANCE module, ArrayOfMessagesHdl msgs, LPCSTR functionName);
DllCallErroros setStatesArray(HINSTANCE module, ArrayOfStatesHdl states);

DllCallErroros reloadCAModule();
DllCallErroros reloadVPModule();
DllCallErroros reloadVBModule();
DllCallErroros reloadSCModule();

