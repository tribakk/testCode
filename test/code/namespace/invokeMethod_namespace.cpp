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
        f(s); //f ������� ������ ��� � ���������� ��� s
        //f1(10); // �� �������, �.�. ����� ���������� ��� ���������� �� ����������
        N::f1(10); //���� ����������� ���������
	}

	void Example02()
	{

	}
}
