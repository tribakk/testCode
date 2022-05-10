//◦
#include <string>
#include <iostream>
#include <memory>

namespace RLValueNS
{
    void Example01();
    void Example02();
    //void Example03();
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
    RLValueNS::Example02();
}

namespace RLValueNS
{
    void printNewString()
    {
        std::cout << std::endl;
    }
    class testA
    {
    public:
        int a;
    public:
        testA(int A) noexcept
        {
            a = A;
            std::cout << "testAA " << a << std::endl;
        }
        ~testA() noexcept
        {

            std::cout << "~testAA " << a << std::endl;
        }
        testA(const testA& copyA) noexcept
        {
            a = copyA.a;
            std::cout << "simple copy testA" << a << std::endl;
        }
        testA& operator=(const testA copyA) noexcept
        {
            a = copyA.a;
            std::cout << "simple operator= testA" << a << std::endl;
            return *this;
        }
        testA(testA&& moveA) noexcept
        {
            a = moveA.a;
            moveA.a = 0;
            std::cout << "move Constructor testA" << a << std::endl;
        }
        testA& operator=(testA&& moveA) noexcept
        {
            a = moveA.a;
            std::cout << "move operator= testA" << a << std::endl;
            return *this;
        }
    };
    void testPrint(const testA& a)
    {

        std::cout << "const ref: " << a.a << std::endl;
    }

    void testPrint(testA&& a)
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
        testA a(10);
        testBeforePrint(a);
        printNewString();

        testBeforePrint(std::move(a));
        printNewString();
        testBeforePrint(testA(20));
        printNewString();

        //не может скомпилировать
        //testBeforePrint(std::make_unique<testA>(20));
        //std::unique_ptr<testA> uniqueA = std::make_unique<testA>(20);
        //testBeforePrint(uniqueA);

        testA b = std::move(a);
        testBeforePrint(b);
        testBeforePrint(std::move(b));

    }

    testA createA(int value)
    {
        return testA(value);
    }

    void testPrint2(testA&& a)
    {
        std::cout << "move: " << a.a << std::endl;
    }

    void Example02()
    {
        testA a(10);
        testPrint(a);
        printNewString();
        testPrint(std::move(a));
        printNewString();
        testPrint(std::forward<testA>(a)); //почему-то move
        printNewString();
        testPrint(testA(30));
        printNewString();

        testA&& b1 = createA(100);
        testPrint(std::forward<testA>(b1));
        testPrint(b1);
        std::cout << typeid(b1).name() << std::endl;
        printNewString();

        testA&& b2 = testA(200);
        testPrint(std::forward<testA>(b2));
        testPrint(b2);
        printNewString();

        testA&& b3(300);
        testPrint(std::forward<testA>(b3));
        testPrint(b3);
        printNewString();

        testA b4(400);
        testPrint(std::forward<testA>(b4));
        testPrint(b4);
        printNewString();
    }
}