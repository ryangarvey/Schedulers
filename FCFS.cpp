#include "Process.h"
#include "SortByTime.h"

#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

void FirstComeFirstServed(vector<Process>& procs) {
    sort(procs.begin(), procs.end(), sort);
    int time = procs[0].arrival;
    
}