//◦
#include <string>
#include <iostream>
#include <memory>
#include "../../utils/class/class5.h"

using namespace utils;

namespace RLValueNS
{
    void Example01();
    void Example02();
    void Example03();
    //void Example04();
    //void Example05();
    //void Example06();
    //void Example07();
    //void Example08();
    //void Example09();
}

void ExecuteRLValueNSCode()
{
    //RLValueNS::Example01();
    //RLValueNS::Example02();
    RLValueNS::Example03();
}

namespace RLValueNS
{
    void printNewString()
    {
        std::cout << std::endl;
    }
    
    void testPrint(const cRule5Int& a)
    {
        std::cout << "const ref: " << a.a << std::endl;
    }

    void testPrint(cRule5Int&& a)
    {
        std::cout << "move: " << a.a << std::endl;
    }

    template <class T>
    void testBeforePrint(T&& value)
    {
        testPrint(std::forward<T>(value));
        T temp = value;
        testPrint(std::forward<T>(temp));
        T temp2 = temp;
        testPrint(std::forward<T>(temp2));
        //testPrint(temp);
        //testPrint(value);
        //testPrint(std::move(value));
    }

    template <class T>
    void testBeforePrint2(T&& value)
    {
        T temp = value;
        testPrint(std::forward<T>(temp));
    }

    void Example01()
    {
        cRule5Int a(10);
        testBeforePrint(a);
        testPrint(a);
        printNewString();

        testBeforePrint(std::move(a));
        testPrint(std::move(a));
        printNewString();

        testBeforePrint(cRule5Int(20));
        testPrint(cRule5Int(20));
        printNewString();

        //не может скомпилировать
        //testBeforePrint(std::make_unique<testA>(20));
        //std::unique_ptr<testA> uniqueA = std::make_unique<testA>(20);
        //testBeforePrint(uniqueA);

        cRule5Int b = std::move(a);
        testBeforePrint(b);
        testBeforePrint(std::move(b));

    }

    cRule5Int createA(int value)
    {
        return cRule5Int(value);
    }

    void testPrint2(cRule5Int&& a)
    {
        std::cout << "move: " << a.a << std::endl;
    }

    void Example02()
    {
        cRule5Int a(10);
        testPrint(a);
        printNewString();
        testPrint(std::move(a));
        printNewString();
        testPrint(std::forward<cRule5Int>(a)); //почему-то move
        printNewString();
        testPrint(cRule5Int(30));
        printNewString();

        cRule5Int&& b1 = createA(100);
        testPrint(std::forward<cRule5Int>(b1));
        testPrint(b1);
        std::cout << typeid(b1).name() << std::endl;
        printNewString();

        cRule5Int&& b2 = cRule5Int(200);
        testPrint(std::forward<cRule5Int>(b2));
        testPrint(b2);
        printNewString();

        cRule5Int&& b3(300);
        cRule5Int&& b33(300);
        //testPrint(std::forward<testA>(b3));
        //testPrint(b3);
        printNewString();

        cRule5Int b4(400);
        testPrint(std::forward<cRule5Int>(b4));
        testPrint(b4);
        printNewString();
    }

    void logStrings(const cRule5Str& str5)
    {
        std::cout << "const ref: " << str5.m_str << std::endl;
    }

    void logStrings(cRule5Str&& str5)
    {
        std::cout << "move: " << str5.m_str << std::endl;
    }

    void Example03()
    {
        cRule5Str str5_1("test1");
        logStrings(str5_1);
        printNewString();

        logStrings(std::string("test2"));
        printNewString();
        logStrings(cRule5Str("test3"));
        printNewString();

        logStrings(std::move(str5_1));
        printNewString();

        cRule5Str&& str5_2(std::string("test2"));
        logStrings(str5_2);
        printNewString();

        logStrings(std::move(str5_2));
        printNewString();
    }
}