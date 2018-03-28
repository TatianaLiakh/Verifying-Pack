

#pragma pack(1)	
#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)

#if defined(_WIN32)
    #pragma message("WIN 32")// Windows
#elif defined(_WIN64)
    #pragma message("WIN _WIN64") // Windows
#elif defined(__CYGWIN__) && !defined(_WIN32) && defined(__GNUC__)
    #pragma message "Windows (Cygwin POSIX under Microsoft Window)"
	#define Compiler kGCC
	#define OpSystem kMSWin32
	#define WindowSystem kMSWin32WM
	#define ProcessorType kX86
	#define USE_C99_TYPES 1
#endif	


//#define _WIN32 3
#include "extcode.h"	

int main()
{
//	NumericArrayResize(uB, 1, 0, 1);

	
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