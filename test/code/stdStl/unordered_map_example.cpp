//◦
#include "unordered_map_example.h"

bool std::equal_to<stdStlNS::testStruct1>::operator()(const stdStlNS::testStruct1& lhs, const stdStlNS::testStruct1& rhs) const
{
    return lhs.testA == rhs.testA && lhs.testB == rhs.testB;
}

namespace stdStlNS
{
    //void mainClass::Test()
    //{
    //    testStruct1 s1;
    //    testStruct2 s2;

    //    //_map[s1] = s2;
    //    //_map2[s1] = s2;
    //}

}
