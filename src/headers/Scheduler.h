#include "CustomProcess.h"
#include <vector>
#include <cstdio>
using namespace std;

class Scheduler {
public:
    vector<CustomProcess*> procs;
    vector<int> startTimes, burstTimes;

    Scheduler() {};
    
    ~Scheduler() { for (auto proc : procs) delete proc; };

    void add(CustomProcess & proc, int time) { 
        procs.push_back(&proc);
        startTimes.push_back(time);
        burstTimes.push_back(proc.burst);
    }
    
    void add(CustomProcess & proc, int time, int burst) { 
        procs.push_back(&proc);
        startTimes.push_back(time);
        burstTimes.push_back(burst);
    }

    void printSchedule() {
        printf("\tProcesses\t");
        for (int i = 0; i < procs.size(); ++i) { printf("P%d\t", i); }
        printf("\n\tArrival Time\t");
        for (int i = 0; i < procs.size(); ++i) { printf("%d\t", startTimes[i]); }
        printf("\n\tBurst Time\t");
        for (int i = 0; i < procs.size(); ++i) { printf("%d\t", burstTimes[i]); }
    }
};
