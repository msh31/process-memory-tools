#ifndef HEADERFILE_H
#define HEADERFILE_H

#include <iostream>
#include <windows.h>
#include <psapi.h> // For process functions
#include <vector>

class Process {       
  public:          
    std::string processName;   

    int processID;        
    double processMemUsage;  
    
    void display();

    Process(int processID);
};

#endif