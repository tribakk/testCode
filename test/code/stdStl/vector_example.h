#pragma once
#include <unordered_map>

namespace stdStlNS
{
	struct testVector
	{
		testVector(int a, int b)
			: testA(a)
			, testB(b)
		{
		};
		int testA;
		int testB;
	private:
		//testVector();
		//testVector(const testVector&);
		//testVector(const testVector&&);
		//void operator=(const testVector&);
		//void operator=(const testVector&&);
	};
}