#pragma once

namespace templateNS
{
    class cTestCast0;

    


    class cTestCast
    {
        int _i;
        double _d;
    public:
        cTestCast(int i, double d)
        {
            _i = i;
            _d = d;
        }
        //operator int()
        //{
        //    return _i;
        //}

        operator double()
        {
            return _d;
        }

        //operator cTestCast0()
        //{
        //    cTestCast0 cast(_i);
        //    return cast;
        //}
    };

    class cTestCast0
    {
        int _a;
    public:
        cTestCast0(int a)
        {
            _a = a;
        }

        operator cTestCast()
        {
            cTestCast cast(_a, 999.999);
            return cast;
        }
    };
}

