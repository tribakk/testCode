//◦
#pragma once
#include <windows.h>
#include <stdio.h>
#include "psapi.h"

namespace utils
{
    void PrintMemoryInfo(DWORD processID)
    {
        HANDLE hProcess;
        PROCESS_MEMORY_COUNTERS pmc;

        // Print the process identifier.

        printf("\nProcess ID: %u\n", processID);

        // Print information about the memory usage of the process.

        hProcess = OpenProcess(PROCESS_QUERY_INFORMATION |
            PROCESS_VM_READ,
            FALSE, processID);

        if (GetProcessMemoryInfo(hProcess, &pmc, sizeof(pmc)))
        {
            printf("\tPageFaultCount: 0x%08X\n", pmc.PageFaultCount);
            printf("\tPeakWorkingSetSize: 0x%08X\n",
                pmc.PeakWorkingSetSize);
            printf("\tWorkingSetSize: 0x%08X\n", pmc.WorkingSetSize);
            printf("\tQuotaPeakPagedPoolUsage: 0x%08X\n",
                pmc.QuotaPeakPagedPoolUsage);
            printf("\tQuotaPagedPoolUsage: 0x%08X\n",
                pmc.QuotaPagedPoolUsage);
            printf("\tQuotaPeakNonPagedPoolUsage: 0x%08X\n",
                pmc.QuotaPeakNonPagedPoolUsage);
            printf("\tQuotaNonPagedPoolUsage: 0x%08X\n",
                pmc.QuotaNonPagedPoolUsage);
            printf("\tPagefileUsage: 0x%08X\n", pmc.PagefileUsage);
            printf("\tPeakPagefileUsage: 0x%08X\n",
                pmc.PeakPagefileUsage);
        }

        CloseHandle(hProcess);
    }

    int GetCurrentSize()
    {
        HANDLE hProcess;
        PROCESS_MEMORY_COUNTERS pmc;
        DWORD currentPid = GetCurrentProcessId();
        hProcess = OpenProcess(PROCESS_QUERY_INFORMATION |
            PROCESS_VM_READ,
            FALSE, currentPid);
        GetProcessMemoryInfo(hProcess, &pmc, sizeof(pmc));
        CloseHandle(hProcess);
        return pmc.WorkingSetSize;
    }
}