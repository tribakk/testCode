//◦
#include "bomb.h"

namespace exceptionNS
{
	void Example01();
	void Example02();
}

void ExecuteExceptionTestCode()
{
	//exceptionNS::Example01();
	exceptionNS::Example02();
}

namespace exceptionNS
{

	void Example01()
	{
        Bomb* bomb;
        try
        {
            bomb = new Bomb();
            //throw main_exception();
            throw main_exception();
        }
        catch (const bomb_exception&)
        {
            printf("3\r\n");
        }
        catch (main_exception& e)
        {
            printf("2\r\n");
        }
        catch (const std::exception&)
        {
            printf("1\r\n");
        }
	}

    main_exception CreateExeption()
    {
        auto exp = main_exception();
        return exp;
    }

	void Example02()
	{
        auto myExeption = main_exception();
        auto my2 = std::move(myExeption);

        auto exp = CreateExeption();
	}
}
