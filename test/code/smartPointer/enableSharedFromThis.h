//◦
#include <memory>
#include <iostream>
#pragma once
namespace smartPointerNS
{
	class testShared : public std::enable_shared_from_this<testShared>
	{
		int a = 10;
	public:
		static std::shared_ptr<testShared> create()
		{
			auto test = std::shared_ptr<testShared>(new testShared());
			test->a = 20;
			return test;
		}
		testShared()
		{
			int a = 10;
			std::cout << " testShared" << std::endl;
		}
		~testShared()
		{
			std::cout << "~testShared" << std::endl;
		}

		std::shared_ptr<testShared> getP()
		{
			return shared_from_this();
		}
	};
}
