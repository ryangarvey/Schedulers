#include "Process.h"
#include <vector>
#include <iostream>
using namespace std;

class Scheduler {
public:
    vector<Process> procs;
    vector<int> startTimes, burstTimes;

    Scheduler() {};
    
    // ~Scheduler() { for (auto proc : procs) delete proc; };

    void add(Process proc, int time) { 
        procs.push_back(proc);
        startTimes.push_back(time);
        burstTimes.push_back(proc.burst);
    }
    
    void add(Process proc, int time, int burst) { 
        procs.push_back(proc);
        startTimes.push_back(time);
        burstTimes.push_back(burst);
    }

    int calculateTotalTurnaround() {

    }

    int calculateTotalWait() {
        
    }

    double calculateAvgTurnaround() {

    }

    double calculateAvgWait() {
        
    }

    void printSchedule() {
        printf("\tProcesses\t");
        for (auto proc : procs) { cout << proc.name << "\t"; }
        printf("\n\tStart Time\t");
        for (int i = 0; i < procs.size(); ++i) { printf("%d\t", startTimes[i]); }
        printf("\n\tBurst Time\t");
        for (int i = 0; i < procs.size(); ++i) { printf("%d\t", burstTimes[i]); }
    }
};
