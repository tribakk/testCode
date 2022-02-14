#include "example01.h"

namespace templateNS
{
    void Example01();
}

void ExecuteTemplateTestCode()
{
    templateNS::Example01();
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
}