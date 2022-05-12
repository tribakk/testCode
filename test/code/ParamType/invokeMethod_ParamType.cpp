//◦
#include <string>
#include <iostream>
#include <vector>
#include "../../utils/class/class5.h"
#include "../../utils/type_name.h"

namespace ParamTypeNS
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

void ExecuteParamTypeNSCode()
{
    ParamTypeNS::Example01();
    //ParamTypeNS::Example02();
    //ParamTypeNS::Example03();
}

namespace ParamTypeNS
{
    void printNewString()
    {
        std::cout << std::endl;
    }

    template<class T>
    void f1(T value)
    {
        //std::cout << typeid(value).name() << std::endl << value.a << std::endl;
        std::cout << "void f1(T value)" << std::endl;
        std::cout << utils::type_name<T>() << std::endl;
        std::cout << utils::type_name<decltype(value)>() << std::endl;
    }

    template<class T>
    void f1_1(T& value)
    {
        std::cout << "void f1_1( T& value)" << std::endl;
        std::cout << utils::type_name<T>() << std::endl;
        std::cout << utils::type_name<decltype(value)>() << std::endl;
    }

    

    template<class T>
    void f1_2(const T& value)
    {
        //std::cout << typeid(value).name() << std::endl << value.a << std::endl;
        std::cout << "void f1_2(const T& value)" << std::endl;
        std::cout << utils::type_name<T>() << std::endl;
        std::cout << utils::type_name<decltype(value)>() << std::endl;
    }

    void Example01()
    {
        using namespace utils;
        
        cRule5Int rule5(10);
        f1(rule5); //T value
        /*
        * copy constructor
        * T     = utils::cRule5Int
        * value = utils::cRule5Int
        */
        printNewString();

        f1_1(rule5); //T& value
        /*
        *   NOT copy constructor
        *   T     = utils::cRule5Int
        *   value = utils::cRule5Int &
        */
        printNewString();

        f1_2(rule5); //const T& value
        /*
        * NOT copy constructor
        * T     = utils::cRule5Int
        * value = const utils::cRule5Int &
        */
        printNewString();


        const cRule5Int rule5_2(20);
        f1(rule5_2); //T value
        /*
        * copy constructor
        * T     = utils::cRule5Int
        * value = utils::cRule5Int
        */
        printNewString();

        f1_1(rule5_2); //T& value
        /*
        * NOT copy constructor
        * T     = const utils::cRule5Int
        * value = const utils::cRule5Int &
        */
        printNewString();

        f1_2(rule5_2); //const T& value
        /*
        * NOT copy constructor
        * T     = utils::cRule5Int
        * value = const utils::cRule5Int &
        */
        printNewString();
    }


    template<class T>
    void f2_1(T& value)
    {
        T newValue = value;
        std::cout << typeid(newValue).name() << std::endl << value.a << std::endl;
    }

    template<class T>
    void f2_2(T&& value)
    {
        T newValue = value;
        std::cout << typeid(newValue).name() << std::endl << value.a << std::endl;
    }

    void Example02()
    {
        using namespace utils;
        cRule5Int rule5(30);
        f2_1(rule5);
        f2_2(rule5);
    }

    void Example03()
    {
        auto x = {1,2,3};
        std::cout << typeid(x).name() << std::endl;

        std::vector<int> a = x;
        std::initializer_list<int> x1 = {1,3,4,5};
        std::vector<int> b = x;
        std::cout << utils::type_name<decltype(a)>();

    }
}