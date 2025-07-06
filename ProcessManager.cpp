#include "ProcessManager.hpp"

vector<Process> ProcessManager::getAll() 
{
    DWORD processIDs[1024]; // A DWORD is a 32-bit unsigned integer (range: 0 through 4294967295 decimal). Because a DWORD is unsigned, its first bit (Most Significant Bit (MSB)) is not reserved for signing.
    DWORD bytesReturned;
    HANDLE processHandle;               // a handle is basically a "key/ticket" that windows gives us to access a resource
    CHAR processName[MAX_PATH];         // creates a buffer of 260 characters
    PROCESS_MEMORY_COUNTERS memCounter; // Contains the memory statistics for a process.

    vector<Process> processes;

    if (EnumProcesses(processIDs, sizeof(processIDs), &bytesReturned)) // Retrieves the process id for each process object in the system
    {
        int numProcesses = bytesReturned / sizeof(DWORD);

        for (int i = 0; i < numProcesses; i++)
        {
            DWORD processID = processIDs[i];

            processHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processIDs[i]);

            if (processHandle != NULL)
            {
                cout << "Process ID: " << processID << " Name: " << processName << "\n";

                // tells the function what the buffer size of processName is (260!) and prevents a buffer overflow
                if (GetModuleBaseNameA(processHandle, NULL, processName, sizeof(processName)))
                {
                    if (GetProcessMemoryInfo(processHandle, &memCounter, sizeof(memCounter)))
                    {
                        //size_t can store the maximum size of a theoretically possible object of any type (including array) and is commonly used for array indexing and loop counting
                        SIZE_T memUsageBytes = memCounter.WorkingSetSize;

                        // dividing 2 integers in C++ results in a truncated integer result, so we cast one of the values to a double so the division happens as a float operation
                        double memUsageMB = static_cast<double>(memUsageBytes) / (1024 * 1024);

                        //emplace_back constructs the object directly in the vector's memory location, while push_back creates a temporary object first, then copies/moves it.
                        //so emplace_back is basically more effiecient and faster
                        processes.emplace_back(string(processName), processID, memUsageMB);
                    }
                }
                else
                {
                    cout << "Process ID: " << processID << " Name: <unknown>" << "\n";
                }
            }
            else
            {
                cout << "Process ID: " << processID << " Name: <access denied>" << "\n";
            }

            CloseHandle(processHandle);
        }
    }

    return processes;
}

// Process ProcessManager::findHighestMemory()
// {

// }