#pragma once
#include <iostream>
namespace classNS
{
	class simpleClass
	{
		int a = 10;
	};
	class TestClass
	{

	public:
		simpleClass* p = new simpleClass();
		int a = 0;

		TestClass(int value)
		{
			a = value;
		}
		TestClass(const TestClass&)
		{
			int a = 10;
		}

		//TestClass& operator=(TestClass&)
		//{
		//	std::cout << "&" << std::endl;
		//	return *this;
		//}
		//TestClass& operator=(TestClass&&)
		//{
		//	std::cout << "&&" << std::endl;
		//	return *this;
		//}
		~TestClass()
		{
			delete p;
		}
	};
}
