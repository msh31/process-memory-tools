#ifndef PROCESSMANAGER_H
#define PROCESSMANAGER_H

#include <iostream>
#include <windows.h>

#include "process.hpp"

class ProcessManager {       
  public:          
    static std::vector<Process> getAll();
    // static Process findHighestMemory();
};

//RAII wrapper, ensures the handle automtically gets destroyed
class HandleWrapper {
private:
    HANDLE handle; // a handle is basically a "key/ticket" that windows gives us to access a resource
    
public:
    HandleWrapper(HANDLE h) : handle(h) {} //store the handle in the constructor
    
    ~HandleWrapper() {  //destructor
      if (handle != NULL && handle != INVALID_HANDLE_VALUE) {
          CloseHandle(handle);
      }
    }
    
    // conversion operator, let it be used like a normal HANDLE!
    operator HANDLE() const { 
        return handle; 
    }
    
    // disable copying (prevent accidental double-cleanup)
    HandleWrapper(const HandleWrapper&) = delete;
    HandleWrapper& operator=(const HandleWrapper&) = delete;
};

#endif