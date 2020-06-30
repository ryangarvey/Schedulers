#include "headers/Scheduler.h"
#include "headers/ProcessSorts.h"
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

void FirstComeFirstServed(vector<Process>& procs) {
    Scheduler schedule;
    sort(procs.begin(), procs.end(), sortByArrival);
    int currTime = procs[0].arrival;

    for (int i = 0; i < procs.size(); ++i) {
        if (currTime < procs[i].arrival) {
            schedule.add(procs[i], procs[i].arrival);
            currTime = procs[i].arrival;
        } else {
            schedule.add(procs[i], currTime);
            currTime += procs[i].burst;
        }
    }

    schedule.printSchedule();
}

int main() {
    Process * a = new Process(1, 4);
    Process * b = new Process(4, 6);
    Process * c = new Process(7, 2);  
    vector<Process> prc {*a,*b,*c};

    FirstComeFirstServed(prc);
}