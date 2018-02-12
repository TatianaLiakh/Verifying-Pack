#include "1.h"


#define TEST_MODE_TRUE true

#ifdef  TEST_MODE_TRUE
#include <iostream>
#include <fstream>
std::ofstream logger;
#endif //  TEST



struct cool
{
	int g;
	int * h;
};

cool c = { 2, nullptr };
void sayToWholeWorld(char * speach);

int main()
{
//#ifdef TEST_MODE_TRUE
//
//	if (true == logger.is_open())
//	{
//		logger << "Initialisation\n" << std::endl;
//	}
//	logger.open("LOG.txt", std::ios::out | std::ios::app);
//	logger << "Initialisation!!!\n" << std::endl;
//	logger.close();
//
//	logger.open("LOG.txt", std::ios::out | std::ios::app);
//	logger << "Initialisation!!!\n" << std::endl;
//
//#endif // TEST_MODE_TRUE
//

	sayToWholeWorld("VB: set_states_array");
	load(8);
}

void sayToWholeWorld(char * speach)
{
	FILE * f;

	fopen_s(&f, "LOGGER_ERROR.txt", "w");
	fprintf(f, speach);
	fclose(f);
}


__declspec(dllexport)int load(int num)
{
	HINSTANCE module = nullptr;

	if (nullptr == (module = ::LoadLibrary("VB.dll")))
		return -1;

	typedef void ( * CA) ();
	CA ca = nullptr;

	ca = (CA)::GetProcAddress((HMODULE)module, "LLD");
	if (nullptr == ca)
	{
		::FreeLibrary(module);
		int g = GetLastError();
		return -2;
	}
	// ca();

	::FreeLibrary(module); 

	return 0;
}