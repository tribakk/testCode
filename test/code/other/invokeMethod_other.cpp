//◦
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <atomic>
#include <condition_variable>

namespace otherNS
{
	void Example01();
	void Example02();
}

void ExecuteOtherTestCode()
{
	//otherNS::Example01();
	otherNS::Example02();
}

namespace otherNS
{
	void test(int i)
	{
		//тест чтобы посмотреть расстояние между переменными
		//на дебаге по 32 байта между началами символов
		//на релизе по 4 байта
		int a = 10;
		int b = 20;
		int c = INT_MAX;
		int d = 40;
		std::cout << &a << ":" << &b << ":" << &c << ":" << &d << std::endl;
		i++;
		if (i < 20)
			test(i + 1);
		else
		{
			int aa = 30;
			std::cout << &aa << std::endl;
		}
	}

	void Example01()
	{
		test(0);
	}

	int counter = 0;
	class testA
	{
		int a;
	public:
		//static int counter;
		testA()
		{
			counter++;
			a = counter;
			std::cout << " testA : " << a << std::endl;
		}
		~testA()
		{
			std::cout << "~testA : " << a << std::endl;
		}
	};
	
	
	void Example02()
	{
		
		//testA::counter = 0;
		std::cout << " 1 " << std::endl;
		testA* pA_one = new testA();
		delete pA_one;
		std::cout << " 2 " << std::endl;
		
		//2 варианта
		// 1ый вариант, если убрать вывод значения переменной a, то будет бесконечно выводиться
		// 2ой вариант, уже с выводом переменной a, то при вызове диструктора свалиться
		// видимо удаляться будет какой-то случайный кусок памяти
		//в диструкторе this будет не равно значению pA_one
		//pA_one = new testA();
		//delete[] pA_one;
		
		std::cout << " 3 " << std::endl;
		const int size_collection = 20;
		testA* pA_many = new testA[size_collection];
		//delete pA_many; //удалить только 1ый элемент массива и отладчик сругается
		delete[] pA_many; //удаляет в обратной последовательности
	}

}