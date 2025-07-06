#include "process.hpp"

Process::Process(std::string processName, int processID, double processMemUsage) {
        this->processName = processName;
        this->processID = processID;
        this->processMemUsage = processMemUsage;
}

void Process::display() {
    std::cout << processName + " | " << processID << " | " << processMemUsage << "\n";
}

