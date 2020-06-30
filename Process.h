#include "stdlib.h"
using namespace std;

class Process {
public:
    int arrival;
    int burst;
    int priority;

    Process(int arr, int burr) : arrival(arr), burst(burr), priority(1) {};
    Process(int arr, int burr, int prior) : arrival(arr), burst(burr), priority(prior) {};
    
    ~Process();
};