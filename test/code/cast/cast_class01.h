//◦
#pragma once
namespace castNS
{
	class cCast0
	{
	public:
		int a = 10;
	};

	class cCast0_1 : public cCast0
	{
	public:
		double a1 = 123.456;
	};

	class cCast0_2 : public cCast0
	{
	public:
		bool a2 = true;
	};


	class cCast1
	{
	public:
		int a = 20;
		virtual void test()
		{

		}
	};

	class cCast1_1 : public cCast1
	{
	public:
		double a1 = 321.654;
		virtual void test()
		{

		}
	};

	class cCast1_2 : public cCast1
	{
	public:
		bool a2 = true;
		virtual void test()
		{

		}
	};
}
