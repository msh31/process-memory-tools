#include <iostream>

using namespace std;

class Process {       
  public:          
    string processName;   
    int processID;        
    double processMemUsage;  
    void display();
};

int main() {
  Process processInfo;  

  processInfo.processID = 15; 
  processInfo.processName = "Some text";

  cout << processInfo.processID << "\n";
  cout << processInfo.processName;
  return 0;
}