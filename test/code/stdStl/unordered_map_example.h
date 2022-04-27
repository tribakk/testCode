//◦
#pragma once
#include <unordered_map>

namespace stdStlNS
{
	struct testStruct1
	{
		//testStruct1(const testStruct1&) = delete;
		testStruct1()
		{
		};
		mutable bool testBool = false;
		int testA = 10;
		int testB = 20;

	};

	struct testStruct2
	{
		float testA = 5.5f;
		float testB = 7.2f;
	};
}

template <>
struct std::hash<stdStlNS::testStruct1>
{
	size_t operator()(const stdStlNS::testStruct1& k) const
	{
		size_t res = 0;

		return res;
	}
};

template <>
struct std::equal_to<stdStlNS::testStruct1>
{
	bool operator()(const stdStlNS::testStruct1& lhs, const stdStlNS::testStruct1& rhs) const;
};

namespace stdStlNS
{
	class mainClass
	{
	public:
		std::unordered_map<testStruct1, testStruct2> _map;
		//std::unordered_map<testStruct1, testStruct2, std::hash<stdStlNS::testStruct1>, std::equal_to<stdStlNS::testStruct1>> _map2;
		//void Test();
	};
}