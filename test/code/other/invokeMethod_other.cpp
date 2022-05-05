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
}

void ExecuteOtherTestCode()
{
	otherNS::Example01();

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


}