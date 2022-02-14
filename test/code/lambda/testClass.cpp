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
}
