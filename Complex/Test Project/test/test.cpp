

#pragma pack(1)	
#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)
#include <inttypes.h>
typedef int64_t __int64;	

 #if defined(_WIN32) &&  defined(__GNUC__)
     #pragma message("WIN 32")// Windows
	 #define _MSC_VER 1
	// #define _M_IX86 1
	 

// #elif defined(_WIN64)
    // #pragma message("WIN _WIN64") // Windows
// #elif defined(__CYGWIN__) && !defined(_WIN32) && defined(__GNUC__)
    // #pragma message "Windows (Cygwin POSIX under Microsoft Window)"
	// #define Compiler kGCC
	// #define OpSystem kMSWin32
	// #define WindowSystem kMSWin32WM
	// #define ProcessorType kX86
	// #define USE_C99_TYPES 1
 #endif	

#include "extcode.h"
//#define _WIN32 3
#include <stdio.h>

 __declspec(dllexport)void func()
 {}
 
 

int main()
{
//	NumericArrayResize(uB, 1, 0, 1);

	 printf ("I M ALIVE BRO!");
	// #ifdef Compiler
		// #pragma message "Compiler-> " STR(Compiler)
	// #endif
	
	// #ifdef OpSystem
		// #pragma message "OpSystem-> "  STR(OpSystem)
	// #endif
	
	 // #ifdef WindowSystem
		// #pragma message " WindowSystem-> "  STR(WindowSystem)
	 // #endif
	
	 // #ifdef ProcessorType
		// #pragma message "ProcessorType-> " STR(ProcessorType)
	 // #endif
	
	return 0 ;
}