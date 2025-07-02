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

int main()
{
    string line;
    ifstream fileToProcess("processes.txt");

    string processName, processID, processMemUsage;

    if (fileToProcess.is_open())
    {
        while (getline(fileToProcess, line))
        {
            auto words = split(line);

            processName = words[0];
            processID = words[1];
            processMemUsage = words[2];

            cout << processName + " | " + processID + " | " + processMemUsage << "\n";
        }
        fileToProcess.close();
    }
    else
    {
        cout << "Unable to open file";
    }

    return 0;
}