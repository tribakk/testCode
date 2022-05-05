//◦
#include "cast_class01.h"
#include <functional>
#include <iostream>

namespace castNS
{
	void Example01();
	void Example02();
}

void ExecuteCastTestCode()
{
	castNS::Example01();
	castNS::Example02();
}

namespace castNS
{
	void Example01()
	{
		cCast0* cast0 = new cCast0();

		//dynamic_cast не компилиться если в классах нет виртуальных функций
		//
		/*
			error C2683: 'dynamic_cast': 'castNS::cCast0' is not a polymorphic type
		*
		*/
		//if (dynamic_cast<cCast0_1*>(cast0))
		//{
		//	printf("dynamic_cast cCast0_1");
		//}

		/*
			error C2683: 'dynamic_cast': 'castNS::cCast0' is not a polymorphic type
		*
		*/
		//if (dynamic_cast<cCast0_2*>(cast0))
		//{
		//	printf("dynamic_cast cCast0_2");
		//}

		if (cCast0_1* cast01 = static_cast<cCast0_1*>(cast0))
		{
			//это по факту cCast0 поэтому будет мусор
			std::cout << cast01->a1 << std::endl;
			printf("static_cast cCast0_1\r\n");
		}

		if (cCast0_2* cast02 = static_cast<cCast0_2*>(cast0))
		{
			//это по факту cCast0 поэтому будет мусор
			std::cout << cast02->a2 << std::endl;
			printf("static_cast cCast1_2\r\n");
		}

		cCast0_1* cast01 = new cCast0_1();
		//cCast0_2* cast02 = static_cast<cCast0_2>(cast01);

		cCast1* cast1 = new cCast1_1();
		if (dynamic_cast<cCast1_1*>(cast1))
		{
			printf("dynamic_cast cCast1_1\r\n");
		}

		//каст не пройдет, не выведется
		if (dynamic_cast<cCast1_2*>(cast1))
		{
			printf("dynamic_cast cCast1_2\r\n");
		}

		if (static_cast<cCast1_1*>(cast1))
		{
			printf("static_cast cCast1_1\r\n");
		}

		if (static_cast<cCast1_2*>(cast1))
		{
			printf("static_cast cCast1_2\r\n");
		}
	}

	//void TestCast(cCast1_0& cast)

	void Example02()
	{
		cCast1_1 cast1_1;
		cCast1_1& cast1_11 = cast1_1;
		cast1_1.a1 = 1231231;
		cCast1& cast1 = cast1_1;
		cCast1_1 cast2 = dynamic_cast<cCast1_1&>(cast1_1);
		cast1_1.a1 = 10;

		//свалиться AV, тут пытается именно сконструироваться новый объект
		//cCast1_2 cast2_ = dynamic_cast<cCast1_2&>(cast1);
	}
}
