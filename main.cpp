#include <iostream>
#include <string>
#include <vector> //a vector is basically a resizeable array, it can shrink and grow dynamically if needed :D
#include <sstream>

#include <windows.h>
#include <psapi.h>

#include "process.hpp"
#include "ProcessManager.hpp"

int main()
{
    std::vector<Process> allProcesses = ProcessManager::getAll();
    Process highestMemProcess = allProcesses[0];

    for (const auto& process : allProcesses) {
        if (process.processMemUsage > highestMemProcess.processMemUsage) {
            highestMemProcess = process;
        }
    }

    std::cout << "\nProcess with highest memory usage:\n\n";
    highestMemProcess.display();

    return 0;
}