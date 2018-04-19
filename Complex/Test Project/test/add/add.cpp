#include "add.h"
extern "C" __declspec(dllexport) int  add(int a, int b) {
    return a + b;
}
extern "C"  __declspec(dllexport) void  __cdecl LLD( PortsHdl )
{}