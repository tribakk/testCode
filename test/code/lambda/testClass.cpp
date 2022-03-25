#include "testClass.h"

namespace lambdaNS
{
	void testFunc::SetFunc(std::function<void()> F)
	{
		_func = F;
	}

	void testFunc::Execute()
	{
		_func();
	}

	void testFunc::ExecuteFunc(std::function<int(int a, int b)> F)
	{
		int res = F(10, 30);
	}
}
