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
        main_exception()
        {
            int a = 10;
        }

        main_exception(const main_exception& e)
        {
            int a1 = 100;
        }

        main_exception(main_exception&& e) noexcept
        {
            int a2 = 1000;
        }
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

            //throw bomb_exception();
        }
    };
}
