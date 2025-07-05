#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(const string &str) //a vector is basically a resizeable array, it can shrink and grow dynamically if needed :D
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

class Process {       
  public:          
    string processName;   

    int processID;        
    double processMemUsage;  
    
    void display() {
        cout << processName + " | " << processID << " | " << processMemUsage << "\n";
    }

    Process(string processName, int processID, double processMemUsage) {
        this->processName = processName;
        this->processID = processID;
        this->processMemUsage = processMemUsage;
    }
};

int main()
{
    string line;
    ifstream fileToProcess("processes.txt");

    if (fileToProcess.is_open())
    {
        while (getline(fileToProcess, line))
        {
            auto words = split(line);

            Process currentProcess(words[0], stoi(words[1]), stod(words[2]));
            currentProcess.display();
        }
        fileToProcess.close();
    }
    else
    {
        cout << "Unable to open file";
    }

    return 0;
}