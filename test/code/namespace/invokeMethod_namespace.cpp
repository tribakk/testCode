#include <iostream>

namespace namespaceNS
{
	void Example01();
	void Example02();
}

void ExecuteNameSpaceTestCode()
{
	namespaceNS::Example01();
	namespaceNS::Example02();
}

namespace namespaceNS
{
    namespace N
    {
        struct S
        {
        };
        void f(S)
        {
            std::cout << "f(S)" << std::endl;
        };
        void f1(int)
        {
            std::cout << "f1(int)" << std::endl;
        }
    }

	void Example01()
	{
        N::S s;
        f(s); //f нашлось потому что в неймспейсе для s
        //f1(10); // не нашлось, т.к. среди аргументов нет аргументов из неймспейса
        N::f1(10); //явно приходиться указывать
	}

	void Example02()
	{

	}
}
