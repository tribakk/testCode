//◦
#include<memory>
#include<iostream>
#include "testWeak.h"

namespace smartPointerNS
{
    void Example01();
    void Example02();
    void Example03();
    void Example04();
}

void ExecuteSmartPointerCode()
{
	//smartPointerNS::Example01();
    //smartPointerNS::Example02();
    //smartPointerNS::Example03();
    smartPointerNS::Example04();
}

namespace smartPointerNS
{
    class testA
    {
    public:
        int a = 10;
        testA()
        {
            std::cout << "testA" << std::endl;
            //throw std::exception();
        }
        ~testA()
        {
            std::cout << "~testA" << std::endl;
        }
    };

    class testB
    {
    public:
        testA pA1;
        testB()
        {
            std::cout << "testB" << std::endl;
            throw std::exception();
            
        }
        ~testB()
        {
            std::cout << "~testB" << std::endl;
        }
    };

    void Example01()
    {
        std::unique_ptr<testB> pB1;
        try
        {
            pB1.reset(new testB());
        }
        catch (...)
        {

        }
        
        std::cout << 1 << std::endl;

        std::unique_ptr<testB> pB2;
        pB2.reset(new testB());

        std::cout << 2 << std::endl;
    }

    void Example02()
    {
        std::weak_ptr<testA> pWeak;
        {
            std::shared_ptr<testA> pSharedA = std::make_shared<testA>();
            pWeak = pSharedA;
            if (std::shared_ptr<testA> p1 = pWeak.lock())
            {
                std::cout << "lock" << std::endl;
            }
            else
            {
                std::cout << "not lock" << std::endl;
            }
        }

        if (std::shared_ptr<testA> p2 = pWeak.lock())
        {
            std::cout << "lock" << std::endl;
        }
        else
        {
            std::cout << "not lock" << std::endl;
        }
    }


    void Example03()
    {
        std::shared_ptr<testWeak1> pWeak1 = std::make_shared<testWeak1>();
        testWeak2 weak2(pWeak1);
        weak2.print();
        pWeak1.reset(/*new testWeak1()*/);
        weak2.print();
    }

    std::unique_ptr<testA> CreateA()
    {
        std::unique_ptr<testA> a(new testA());
        return a;
    }

    void Example04()
    {
        std::unique_ptr<testA> aa = CreateA();
        std::shared_ptr<testA> a = std::move(aa);


        std::unique_ptr<testA> a2;
        std::unique_ptr<testA> a3;
        a3 = std::move(a2);
    }
    
}