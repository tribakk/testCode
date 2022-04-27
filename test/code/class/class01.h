//◦
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
		TestClass()
		{

		}

		TestClass(int value)
		{
			a = value;
		}
		TestClass(const TestClass&)
		{
			int a = 10;
		}
		TestClass(const TestClass&&)
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

	class TestClass2 : public TestClass
	{
	public:
		int test;
		TestClass2()
		{
			test = 10;
		}
	};
}
