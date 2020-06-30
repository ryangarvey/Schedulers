#include "headers/Scheduler.h"
#include "headers/ProcessSorts.h"
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

/*
    Logic:
        independent timing
        start executing first proc
        if next proc begins before first proc ends - send it into queue
            queue is ordered by job
        when proc is done, if queue is empty, execute next one, otherwise execute first in queue

    Cases:
        if arrival after current execution
            
*/
void ShortestJobFirst(vector<Process>& procs) {
    Scheduler schedule;
    vector<Process> toExecute;

    sort(procs.begin(), procs.end(), sortByArrival);

    int currTime = procs[0].arrival + procs[0].burst;
    schedule.add(procs[0], procs[0].arrival);

    for (int i = 1; i < procs.size(); ++i) {
        sort(toExecute.begin(), toExecute.end(), sortByBurst);
        if (procs[i].arrival < currTime) toExecute.emplace(toExecute.begin(), procs[i]);
        else if (toExecute.size() < 1) {
            schedule.add(procs[i], currTime);
            currTime += procs[i].burst;
        } else {
            schedule.add(toExecute.back(), currTime);
            currTime += toExecute.back().burst;
            toExecute.pop_back();
        }
    }
    
    while(toExecute.size() > 0) {
        schedule.add(toExecute.back(), currTime);
        currTime += toExecute.back().burst;
        toExecute.pop_back();
    }

    schedule.printSchedule();
}

int main() {
    Process * a = new Process(1, 4);
    Process * b = new Process(4, 6);
    Process * c = new Process(7, 2);  
    vector<Process> prc {*a,*b,*c};

    ShortestJobFirst(prc);
}