//◦
#pragma once
#include <memory>
#include <iostream>
namespace smartPointerNS
{
	class testWeak1
	{
	public:
		testWeak1()
		{
			std::cout << "testWeak1" << std::endl;
		}
		~testWeak1()
		{
			std::cout << "~testWeak1" << std::endl;
		}
	
	};

	class testWeak2
	{
		std::weak_ptr<testWeak1> pWeak;
	public:
		testWeak2(std::shared_ptr<testWeak1> pTest)
		{
			pWeak = pTest;
		}

		void print()
		{
			if (pWeak.lock())
			{
				std::cout << "lock" << std::endl;
			}
			else
			{
				std::cout << "empty" << std::endl;
			}
		}

	};
}
