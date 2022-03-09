#include "cast_class01.h"
#include <functional>

namespace castNS
{
	void Example01();
}

void ExecuteCastTestCode()
{
	castNS::Example01();
}

namespace castNS
{
	void Example01()
	{
		cCast0* cast0 = new cCast0_1();

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

		if (static_cast<cCast0_1*>(cast0))
		{
			printf("static_cast cCast0_1\r\n");
		}

		if (static_cast<cCast0_2*>(cast0))
		{
			printf("static_cast cCast1_2\r\n");
		}

		cCast1* cast1 = new cCast1_1();
		if (dynamic_cast<cCast1_1*>(cast1))
		{
			printf("dynamic_cast cCast1_1\r\n");
		}

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
}
