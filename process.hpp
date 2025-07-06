#ifndef HEADERFILE_H
#define HEADERFILE_H

#include <iostream>

using std::cout;
using std::string;

class Process {       
  public:          
    string processName;   

    int processID;        
    double processMemUsage;  
    
    void display();

    Process(string processName, int processID, double processMemUsage);
};

#endif