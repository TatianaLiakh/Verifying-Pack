#ifndef ADD_H
#define ADD_H

typedef struct Port
{
	int dimSize;
	char ports[1];
};
typedef Port **PortsHdl;

extern "C" __declspec(dllexport) int   add(int a, int b);
extern "C"  __declspec(dllexport) void __cdecl LLD( PortsHdl );
#endif  // ADD_H