//◦
#pragma once
#include <iostream>
#include <string>
namespace utils
{
    class cRule5Str
    {
    public:
        std::string m_str;
    public:
        cRule5Str(std::string str) noexcept
        {
            m_str = str;
            std::cout << " cRule5 " << m_str << std::endl;
        }
        ~cRule5Str() noexcept
        {
            std::cout << "~rule5 " << m_str << std::endl;
        }
        cRule5Str(const cRule5Str& copy5) noexcept
        {
            m_str = copy5.m_str;
            std::cout << "simple copy rule5" << m_str << std::endl;
        }
        cRule5Str& operator=(const cRule5Str copy5) noexcept
        {
            m_str = copy5.m_str;
            std::cout << "simple operator= rule5" << m_str << std::endl;
            return *this;
        }
        cRule5Str(cRule5Str&& move5) noexcept
        {
            m_str = move5.m_str;
            move5.m_str.empty();
            std::cout << "move Constructor rule5" << m_str << std::endl;
        }
        cRule5Str& operator=(cRule5Str&& move5) noexcept
        {
            m_str = move5.m_str;

            std::cout << "move operator= rule5" << m_str << std::endl;
            return *this;
        }
    };

    
    class cRule5Int
    {
    public:
        int a;
    public:
        cRule5Int(int A) noexcept
        {
            a = A;
            std::cout << "cRule5Int " << a << std::endl;
        }
        ~cRule5Int() noexcept
        {
            std::cout << "~cRule5Int " << a << std::endl;
        }
        cRule5Int(const cRule5Int& copy5) noexcept
        {
            a = copy5.a;
            std::cout << "simple copy cRule5Int" << a << std::endl;
        }
        cRule5Int& operator=(const cRule5Int copy5) noexcept
        {
            a = copy5.a;
            std::cout << "simple operator= cRule5Int" << a << std::endl;
            return *this;
        }
        cRule5Int(cRule5Int&& move5) noexcept
        {
            a = move5.a;
            move5.a = 0;
            std::cout << "move Constructor cRule5Int" << a << std::endl;
        }
        cRule5Int& operator=(cRule5Int&& move5) noexcept
        {
            a = move5.a;
            std::cout << "move operator= cRule5Int" << a << std::endl;
            return *this;
        }
    };
}
