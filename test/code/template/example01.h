#pragma once

namespace templateNS
{
    template <typename T>
    class A
    {
    public:
        int a;
    };

    template <typename T>
    class B : public A<T>
    {
    public:
        int b;
    };

    class C : public B<C>
    {
    public:
        int c;
    };
}

