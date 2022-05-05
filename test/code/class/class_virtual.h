//◦
#pragma once
#include <iostream>
class parrentA
{
	int a = 10;
public:
	virtual void print()
	{
		std::cout << "parrentA" << std::endl;
	}
};


class childA : public parrentA
{
	int b = 30;
public:
	virtual void print()
	{
		std::cout << "parrentB" << std::endl;
	}
	~childA()
	{
		std::cout << "~childA()" << std::endl;
	}
};