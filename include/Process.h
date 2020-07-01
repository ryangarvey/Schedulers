#include "stdlib.h"
#include <string>
using namespace std;

class Process {
public:
    string name;
    int arrival;
    int burst;
    int priority;

    Process(string nm, int arr, int burr) : name(nm), arrival(arr), burst(burr), priority(1) {};
    Process(string nm, int arr, int burr, int prior) : name(nm), arrival(arr), burst(burr), priority(prior) {};
};