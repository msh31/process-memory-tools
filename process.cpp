#include "process.hpp"

Process::Process(string processName, int processID, double processMemUsage) {
        this->processName = processName;
        this->processID = processID;
        this->processMemUsage = processMemUsage;
}

void Process::display() {
    cout << processName + " | " << processID << " | " << processMemUsage << "\n";
}

