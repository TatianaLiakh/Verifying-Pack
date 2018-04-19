#include "LV_lib.h"

//
//ModuleDescriptor <MainCAFunction> ca_module = { nullptr , "D:/CA.dll", nullptr };
//ModuleDescriptor <MainVPFunction> vp_module = { nullptr , "D:/VP.dll" , nullptr };
//ModuleDescriptor <MainVBFunction> vb_module = { nullptr , "D:/VM.dll" , nullptr };
//ModuleDescriptor <MainSCFunction> sc_module = { nullptr , "D:/SCM.dll" , nullptr };


ModuleDescriptor <MainCAFunction> ca_module = { nullptr , nullptr , nullptr };
ModuleDescriptor <MainVPFunction> vp_module = { nullptr , nullptr , nullptr };
ModuleDescriptor <MainVBFunction> vm_module = { nullptr , nullptr , nullptr };
ModuleDescriptor <MainSCFunction> sc_module = { nullptr , nullptr , nullptr };

LPCSTR MainFunctionName = "LLD";

LPSTR newPathName(LStrHandle path, char * name)
{	
	FILE * file;

	fopen_s(&file, "D:/LOGTESTDLL.txt", "a");
	fprintf(file, "Start\n");
	fputs(name, file);
	fputs("\n", file);
	size_t len = (*path)->cnt;
	size_t new_size = len + strlen(name) + 1;

	char* newPath = new char[new_size];

	strncpy(newPath,(char*)(*path)->str, len);
	newPath[len] = '\0';
	fputs(newPath, file);

	for (int k = 0; k < strlen(name); ++k)
	{
		newPath[k + len] = name[k];
	}
	newPath[new_size - 1] = '\0';

	fputs(newPath, file);
	
	fputs("\n", file);
	fclose(file);


	return newPath; 
}
