#include "example01.h"
#include "example02.h"
#include <iostream>

namespace templateNS
{
    void Example01();
    void Example02();
}

void ExecuteTemplateTestCode()
{
    //templateNS::Example01();
    templateNS::Example02();
}

namespace templateNS
{
    void Example01()
    {
        if (true)
        {
            C* c = new C();
            c->a = 15;
            c->b = 31;
            c->c = 47;
            c = c;
        }
    }

    template <class T>
    void print(T t)
    {
        std::cout << t << std::endl;
    }
    void Example02()
    {
        print("asdfs");
        print(5);

        cTestCast castTest(12, 123.456);
        int a = castTest;
        print(castTest);
        cTestCast0 cast0(30);
        print((cTestCast)cast0);
    }

}