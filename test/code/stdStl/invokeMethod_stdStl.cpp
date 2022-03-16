#include "unordered_map_example.h"
#include "vector_example.h"

namespace stdStlNS
{
    void Example01();
    void Example02();
}

void ExecuteStdStlCode()
{
    stdStlNS::Example02();
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
}