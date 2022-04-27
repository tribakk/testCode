//◦
#include "class01.h"
#include <utility>

namespace classNS
{
	void Example01();
}

void ExecuteClassTestCode()
{
	classNS::Example01();
}

namespace classNS
{
	void Example01()
	{
		TestClass t1(1);
		{
			TestClass t2(2);
			//t1 = std::move(t2);
			TestClass t3 = std::move(t2);
		}
		
		TestClass2 class2;

		int* a1 = new int();
		int* a2 = new int();
		a2 = std::move(a1);
	}
}
