#include "unordered_map_example.h"

namespace stdStlNS
{
    void Example01();
}

void ExecuteStdStlCode()
{
    stdStlNS::Example01();
}

namespace stdStlNS
{
    void Example01()
    {
        mainClass mClass;
        
        testStruct1 s1;
        testStruct2 s2;
        
        mClass._map[s1] = s2;
        //mClass._map2[s1] = s2;

        //mClass.Test();
    }
}