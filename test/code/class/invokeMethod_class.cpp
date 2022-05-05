//◦
#include "class01.h"
#include "class_virtual.h"
#include <utility>

namespace classNS
{
	void Example01();
	void Example02();
}

void ExecuteClassTestCode()
{
	classNS::Example02();
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

	void Example02()
	{
		childA* cA = new childA();
		parrentA* pA = cA;
		pA->print();
		cA->print();
		cA->~childA();
	}
}
