#include "stdlib.h"
using namespace std;

class CustomProcess {
public:
    int arrival;
    int burst;
    int priority;

    CustomProcess(int arr, int burr) : arrival(arr), burst(burr), priority(1) {};
    CustomProcess(int arr, int burr, int prior) : arrival(arr), burst(burr), priority(prior) {};
    
    // ~CustomProcess();
};