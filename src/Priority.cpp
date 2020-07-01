#include "Scheduler.h"
#include "ProcessSorts.h"
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

void Priority(vector<Process>& procs) {
    Scheduler schedule;
    vector<Process> toExecute;

    sort(procs.begin(), procs.end(), sortByArrival);

    int currTime = procs[0].arrival + procs[0].burst;
    schedule.add(procs[0], procs[0].arrival);

    for (int i = 1; i < procs.size(); ++i) {
        sort(toExecute.begin(), toExecute.end(), sortByPriority);
        //if empty queue
        if (toExecute.size() == 0) {
            // push to queue
            if (currTime > procs[i].arrival) {
                toExecute.push_back(procs[i]);
            // execute straight away
            } else {
                schedule.add(procs[i], currTime);
                currTime += procs[i].burst;
            }
        // queue has elements
        } else {
            // push to queue
            if (currTime > procs[i].arrival) {
                toExecute.push_back(procs[i]);
            // execute front of element, push current element to queue
            } else {
                schedule.add(toExecute.front(), currTime);
                currTime += toExecute.front().burst;
                toExecute.erase(toExecute.begin());

                toExecute.push_back(procs[i]);
            }
        }
    }
    
    while(toExecute.size() > 0) {
        schedule.add(toExecute.front(), currTime);
        currTime += toExecute.front().burst;
        toExecute.erase(toExecute.begin());
    }

    schedule.printSchedule();
}

int main() {
    Process a("A", 0, 10, 10);
    Process b("B", 4, 6, 11);
    Process c("C", 7, 2, 12);  
    Process d("D", 9, 7, 7);  
    Process e("E", 12, 4, 6);  
    vector<Process> prc {a,b,c,d,e};

    Priority(prc);
}