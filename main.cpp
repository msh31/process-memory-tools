#include <iostream>
#include <string>
#include <vector> //a vector is basically a resizeable array, it can shrink and grow dynamically if needed :D
#include <sstream>

#include <windows.h>
#include <psapi.h>

#include "process.hpp"

using namespace std;

vector<string> split(const string &str) 
{
    vector<string> tokens;
    istringstream iss(str);
    string token;

    while (iss >> token)
    {
        tokens.push_back(token);
    }

    return tokens;
}

vector<Process> allProcesses;

int main()
{
    DWORD processIDs[1024]; //A DWORD is a 32-bit unsigned integer (range: 0 through 4294967295 decimal). Because a DWORD is unsigned, its first bit (Most Significant Bit (MSB)) is not reserved for signing.
    DWORD bytesReturned;
    HANDLE processHandle; // a handle is basically a "key/ticket" that windows gives us to access a resource
    CHAR processName[MAX_PATH]; //creates a buffer of 260 characters

    if (EnumProcesses(processIDs, sizeof(processIDs), &bytesReturned)) // Retrieves the process id for each process object in the system
    {
        int numProcesses = bytesReturned / sizeof(DWORD); 

        for (int i = 0; i < numProcesses; i++) 
        {
            DWORD processID = processIDs[i];

            processHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processIDs[i]);

            if (processHandle != NULL)
            {
                                                    //tells the function what the buffer size of processName is (260!) and prevents a buffer overflow
                if (GetModuleBaseNameA(processHandle, NULL, processName, sizeof(processName))) 
                {
                    cout << "Process ID: " << processID << " Name: " << processName << "\n";
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

    Process highestMemProcess = allProcesses[0];

    for (const auto& process : allProcesses) {
        if (process.processMemUsage > highestMemProcess.processMemUsage) {
            highestMemProcess = process;
        }
    }

    cout << "Process with highest memory usage:\n";
    highestMemProcess.display();

    return 0;
}