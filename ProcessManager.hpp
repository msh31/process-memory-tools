#ifndef PROCESSMANAGER_H
#define PROCESSMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <psapi.h> // For process functions
#include "process.hpp"

using std::cout;
using std::vector;

class ProcessManager {       
  public:          
    static vector<Process> getAll();
    // static Process findHighestMemory();
};

#endif