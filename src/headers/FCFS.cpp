#include "Scheduler.h"
#include "ProcessSorts.h"
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

void FirstComeFirstServed(vector<CustomProcess>& procs) {
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
    CustomProcess * a = new CustomProcess(1, 4);
    CustomProcess * b = new CustomProcess(4, 6);
    CustomProcess * c = new CustomProcess(7, 2);  
    vector<CustomProcess> prc {*a,*b,*c};

    FirstComeFirstServed(prc);
}