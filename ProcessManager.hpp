#ifndef PROCESSMANAGER_H
#define PROCESSMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <psapi.h> // For process functions
#include "process.hpp"

class ProcessManager {       
  public:          
    static std::vector<Process> getAll();
    // static Process findHighestMemory();
};

#endif