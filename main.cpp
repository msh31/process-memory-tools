#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

#include "process.hpp"

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

vector<Process> allProcesses;

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
            // currentProcess.display();
            allProcesses.push_back(currentProcess);
        }
        fileToProcess.close();
    }
    else
    {
        cout << "Unable to open file";
    }

    Process highestMemProcess = allProcesses[0];

    for (const auto& process : allProcesses) {
        if (process.processMemUsage > highestMemProcess.processMemUsage) {
            highestMemProcess = process;
        }
    }

    cout << "Process with highest memory usage:\n";
    highestMemProcess.display();

    return 0;
}