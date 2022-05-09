//◦
#pragma once
#include "processInfo.h"
#include <iostream>
#include <string>

namespace utils
{
    class MemoryWriter
    {
        long m_CurrentSize;
    public:
        MemoryWriter()
        {
            start();
        }
        void WriteDeltaMemory(std::string text = "")
        {
            long tempSize = utils::GetCurrentSize();
            std::cout << tempSize - m_CurrentSize << " : "<< text << std::endl;
            m_CurrentSize = tempSize;
        }
        void start()
        {
            m_CurrentSize = utils::GetCurrentSize();
        }
    };
}