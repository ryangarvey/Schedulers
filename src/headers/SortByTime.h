#include "Process.h"

bool sort(Process a, Process b) {
    return (b.arrival > a.arrival);
}