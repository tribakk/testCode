﻿//◦
#include "testClass.h"
#include <iostream>

namespace lambdaNS
{
	void Example01();
	void Example02();
	void Example03();
}

void ExecuteLamdaTestCode()
{
	//lambdaNS::Example01();
	//lambdaNS::Example02();
	lambdaNS::Example03();
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


	void Example02()
	{
		testFunc test;
		test.ExecuteFunc([](int a1, int a2)
			{
				return a1 + a2;
				//return "asdf";
			});

		test.ExecuteFunc([](int a1, int a2)->bool
			{
				return a1 + a2;
				//return "asdf";
			});
	}


	void print3(std::function <void()> f)
	{
		f();
	}

	void Example03()
	{
		auto func = []()
		{
			std::cout << "03"<< std::endl;
		};

		print3(func);
	}
}
