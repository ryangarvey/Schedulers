#include "Process.h"

class Schedule {
    Process * proc;
    int startTime;
    int burstTime;

    Schedule(/* args */);
    
    ~Schedule() {
        delete proc;
    };
};
