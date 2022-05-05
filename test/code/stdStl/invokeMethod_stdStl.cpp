//◦
#include "unordered_map_example.h"
#include "vector_example.h"
#include <iostream>

namespace stdStlNS
{
    void Example01();
    void Example02();
    void Example03();
    void Example04();
    void Example05();
    void Example06();
}

void ExecuteStdStlCode()
{
    stdStlNS::Example05();
    stdStlNS::Example06();
}

namespace stdStlNS
{
    void Example01()
    {
        mainClass mClass;
        
        testStruct1 s1, s11, s12, s13;
        testStruct2 s2;
        
        mClass._map[s1] = s2;
        mClass._map[s11] = s2;
        mClass._map[s12] = s2;
        mClass._map[s13] = s2;
        //mClass._map2[s1] = s2;

        //mClass.Test();
    }

    void Example02()
    {
        char char1[] = "test";
        char char2[] = "test2";
        char char3[] = "test3";
        char* char4;
        {
            //char1 = char2;
            //static_cast<char*>(char1) = char2;
            //*char2 = char3;
            char4 = char3;
            char4 = char2;
            //char1 = 'e';
            *char1 = 'w';

        }

        {
            const char* char5 = char4;
            char5 = char2;
            //char5[2] = 'q';
        }

        {
            char* const char5 = char4;
            //char5 = char2;
            char5[2] = 'e';
        }
    }

    void Example03()
    {
        std::vector<testVector> arrayTest;
        arrayTest.emplace_back(testVector(1, 1));
        arrayTest.emplace_back(testVector(2, 2));
        arrayTest.emplace_back(testVector(3, 3));
        arrayTest.emplace_back(testVector(4, 4));
        arrayTest.emplace_back(testVector(5, 5));
        for (auto iter = arrayTest.begin(); iter != arrayTest.end(); iter++)
        {
            iter->testA = 2;
            iter->testB = 1;
        }
    }

    void Example04()
    {
        std::list<int> _list;
        _list.push_front(10);
        _list.push_front(11);
        auto iter = _list.begin();
        _list.push_front(12);
        _list.erase(iter);
    }

    void Example05()
    {
        std::vector<int> vec = {1,23,32,22,11,99,23};
        std::cout << typeid(std::begin(vec)).name() << std::endl;
        std::cout << typeid(vec.begin()).name() << std::endl;
        for (auto iter = std::begin(vec); iter != std::end(vec); iter++)
        {
            std::cout << *iter << " " ;
        }
        std::cout << std::endl;



        std::list<int> intList = {11,02,33,24,5'555};
        std::cout << typeid(std::begin(intList)).name() << std::endl;
        std::cout << typeid(intList.begin()).name() << std::endl;
        for (auto iter = std::begin(intList); iter != std::end(intList); iter++)
        {
            std::cout << *iter << " ";
        }
        std::cout << std::endl;

        std::unordered_map<int, int> intUnMap = {{3,15}, {10,37}, {1,92}, {2,10}, {2,17}};
        std::cout << typeid(std::begin(intUnMap)).name() << std::endl;
        std::cout << typeid(intUnMap.begin()).name() << std::endl;
        for (auto iter = std::begin(intUnMap); iter != std::end(intUnMap); iter++)
        {
            std::cout << iter->first << " " << iter->second << " | ";
        }
        std::cout << std::endl;
    }

    class testA
    {
        int a;
    public:
        testA(int a0)
        {
            a = a0;
            std::cout <<" testA : " << a << std::endl;
        }
        ~testA()
        {
            std::cout << "~testA : " << a << std::endl;
        }
        testA(const testA& tA)
        {
            a = tA.a;
            std::cout << "copy testA : " << a << std::endl;
        }

    };

    void Example06()
    {
        std::vector<testA> vec = {testA(1), testA(2), testA(10)};
        vec.~vector();
        std::unordered_map<int, testA> unMap{{1, testA(10)}, {2, testA(20)}, {3, testA(30)}, {3, testA(33)}};
    }
}