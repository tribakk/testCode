//◦
#include<memory>
#include<iostream>
#include <vector>
#include "testWeak.h"
#include "enableSharedFromThis.h"
#include "testDeleter.h"
#include "../../utils/memoryWriter.h"




namespace smartPointerNS
{
    void Example01();
    void Example02();
    void Example03();
    void Example04();
    void Example05();
    void Example06();
    void Example07();
    void Example08();
    void Example09();
}

void ExecuteSmartPointerCode()
{
	//smartPointerNS::Example01();
    //smartPointerNS::Example02();
    //smartPointerNS::Example03();
    //smartPointerNS::Example06();
    //smartPointerNS::Example07();
    //smartPointerNS::Example08();
    smartPointerNS::Example09();
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

    void Example05()
    {
        //testShared test;
        //testShared* test = new testShared();
        //auto test = testShared::create();
        std::shared_ptr<testShared> test(new testShared());
        std::shared_ptr<testShared> pTest1 = test->getP();
        //std::shared_ptr<testShared> pTest2 = test.getP();
        //std::shared_ptr<testShared> pTest3 = test.getP();
    }

    void Example06()
    {
        auto deletMy = [](testDel* test)
        {
            if (test == nullptr)
                return;
            std::cout << "custom Deleter: " << test->m_str << std::endl;
            delete test;
        };
        std::cout << "start 1" << std::endl;
        {
            /// 1 ///
            std::unique_ptr<testDel, decltype(deletMy)> mySmart(nullptr, deletMy);
            mySmart.reset(new testDel("123"));
            
        }
        std::cout << "end 1" << std::endl;
        std::cout << "start 2" << std::endl;
        {
            /// 2 ///
            auto delArray = [](testDel* test)
            {
                delete[] test;
            };
            std::unique_ptr<testDel, decltype(delArray)> unArray(nullptr, delArray);
            unArray.reset(new testDel[10]);
        }
        std::cout << "end 2" << std::endl;
        std::cout << "start 3" << std::endl;
        {
            /// 3 ///
            std::unique_ptr<testDel, decltype(deletMy)> mySmart(nullptr, deletMy);
            mySmart.reset(new testDel("123"));
            std::shared_ptr<testDel> sharedDel = std::move(mySmart);
        }
        std::cout << "end 3" << std::endl;
    }
    void Example07()
    {
        std::cout << "start 4" << std::endl;
        {
            /// 4 ///
            auto deletMy1 = [](testDel* test)
            {
                if (test == nullptr)
                    return;
                std::cout << "custom Deleter: " << test->m_str << std::endl;
                delete test;
            };
            std::shared_ptr<testDel> mySmart(nullptr, deletMy1);
            mySmart.reset(new testDel("123")); //не передали делетер, он и не вызовется
            mySmart.reset(new testDel("321"), deletMy1); //передали делетер, он вызовется
            
        }
        std::cout << "end 4" << std::endl;
        std::cout << "start 5" << std::endl;
        {
            /// 5 ///
            //коллекция и тип один, а делетеры разные
            std::vector<std::shared_ptr<testDel>> verShared;
            verShared.emplace_back(new testDel("1111"), [](testDel* pDel)
                {
                    std::cout << "1)" << std::endl;
                });

            verShared.emplace_back(new testDel("2222"), [](testDel* pDel)
                {
                    std::cout << "2)" << std::endl;
                });
        }
        std::cout << "end 5" << std::endl;
    }

    class VeryBigClass
    {
        int* bigMemory;
    public:
        VeryBigClass()
        {
            bigMemory = new int[1'000'000];
            std::cout << "veryBigClass" << std::endl;
        }
        ~VeryBigClass()
        {
            delete[] bigMemory;
            std::cout << "~veryBigClass" << std::endl;
        }
    };

    void Example08()
    {
        /*
        * эксперимент был расчитан, что в случае с make_shared
        * память почиститься только после освобождения последнего weak_ptr
        * так должно быть по Маерсу
        * однако чистить сразу после после освобождения последнего shared_ptr
        */
        utils::GetCurrentSize(); //прогрузим либы
        utils::MemoryWriter mem;
        std::cout << "1" << std::endl;
        {
            mem.start();
            std::shared_ptr<VeryBigClass> pShared(new VeryBigClass());
            mem.WriteDeltaMemory("after create by new");
            std::weak_ptr<VeryBigClass> pWeak = pShared;
            pShared.reset();
            mem.WriteDeltaMemory("after shared reset");
            pWeak.reset();
            mem.WriteDeltaMemory("after weak reset");

        }
        std::cout << "2" << std::endl;
        {
            mem.start();
            std::shared_ptr<VeryBigClass> pShared = std::make_shared<VeryBigClass>();
            mem.WriteDeltaMemory("after create by new");
            std::weak_ptr<VeryBigClass> pWeak = pShared;
            pShared.reset();
            mem.WriteDeltaMemory("after shared reset");
            pWeak.reset();
            mem.WriteDeltaMemory("after weak reset");
        }

    }

    class testAA
    {
        int a;
    public:
        testAA(int A, bool bExeption)
        {
            a = A;
            std::cout << "testAA " << a << std::endl;
            if (bExeption)
                throw std::exception();
        }
        ~testAA()
        {
            
            std::cout << "~testAA " << a << std::endl;
        }
    };

    class testBB
    {
        std::unique_ptr<testAA> uniq1;
        std::unique_ptr<testAA> uniq2;
    public:
        testBB(testAA* pA1, testAA* pA2)
        {
            uniq1.reset(pA1);
            uniq2.reset(pA2);
        }
    };

    void Example09()
    {
        try
        {
            testBB b(new testAA(10, false), new testAA(20, true));
        }
        catch (...)
        {

        }
    }
}