#include "process.hpp"
#include "ProcessManager.hpp"

Process::Process(int processID) 
{
    this->processID = processID;

    HandleWrapper processHandle(OpenProcess(PROCESS_ALL_ACCESS, FALSE, processID)); // uses the RAII wrapper to open and automatically destroy the handle
    CHAR processName[MAX_PATH];  // creates a buffer of 260 characters
    PROCESS_MEMORY_COUNTERS memCounter; // contains the memory statistics for a process.

    if (processHandle == NULL) { return; }
    if (!GetModuleBaseNameA(processHandle, NULL, processName, sizeof(processName))) { return; }
    if (!GetProcessMemoryInfo(processHandle, &memCounter, sizeof(memCounter))) { return; }

    this->processName = std::string(processName);
    std::cout << "Process ID: " << processID << " Name: " << processName << "\n";

    SIZE_T memUsageBytes = memCounter.WorkingSetSize;

    // dividing 2 integers in C++ results in a truncated integer result, so we cast one of the values to a double so the division happens as a float operation
    double memUsageMB = static_cast<double>(memUsageBytes) / (1024 * 1024);

    this->processMemUsage = memUsageMB;
}

void Process::display() { std::cout << processName + " | " << processID << " | " << processMemUsage << "\n"; }