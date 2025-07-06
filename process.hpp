#ifndef HEADERFILE_H
#define HEADERFILE_H

#include <iostream>

class Process {       
  public:          
    std::string processName;   

    int processID;        
    double processMemUsage;  
    
    void display();

    Process(std::string processName, int processID, double processMemUsage);
};

#endif