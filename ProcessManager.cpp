#include "ProcessManager.hpp"

std::vector<Process> ProcessManager::getAll() {
    DWORD processIDs[1024]; // A DWORD is a 32-bit unsigned integer (range: 0 through 4294967295 decimal). Because a DWORD is unsigned, its first bit (Most Significant Bit (MSB)) is not reserved for signing.
    DWORD bytesReturned;
    std::vector<Process> processes;
    
    if (!EnumProcesses(processIDs, sizeof(processIDs), &bytesReturned)) { return {}; }
    
    int numProcesses = bytesReturned / sizeof(DWORD);

    for (int i = 0; i < numProcesses; i++) { processes.emplace_back(processIDs[i]); }

    return processes;
}

// Process ProcessManager::findHighestMemory()
// {

// }