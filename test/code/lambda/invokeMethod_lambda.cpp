#include "testClass.h"

namespace lambdaNS
{
	void Example01();
}

void ExecuteLamdaTestCode()
{
	lambdaNS::Example01();
}

namespace lambdaNS
{

	void Example01()
	{
		testFunc test;
		test._func = []()
		{
			printf("test._func\n\r");
		};

		test.Execute();


		test.SetFunc([]()
			{
				printf("test.SetFunc\n\r");
			});
		test.Execute();
	}
}
