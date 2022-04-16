#pragma once
#include <iostream>
namespace exceptionNS
{
    struct bomb_exception : public std::exception
    {
        int a = 10;
    };

    struct main_exception : public std::exception
    {

    };

    struct testClass
    {
        testClass()
        {
            printf("testClass\r\n");
        }
        ~testClass()
        {
            printf("~testClass\r\n");
        }
    };

    struct Bomb
    {
        testClass test;
        Bomb()
        {

            throw bomb_exception();
        }
    };
}
