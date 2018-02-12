#include "stdafx.h"
#include "CppUnitTest.h"
#include "../VMTestCode/dll_interface.h"
//#include "extcode.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{		
	TEST_CLASS(LoggerTest)
	{
	public:
		
		TEST_METHOD(LogTestMethod)
		{
			sayToWholeWorld("LOL");
			// TODO: Разместите здесь код своего теста
		}

	};
}