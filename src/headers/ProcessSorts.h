
bool sortByArrival(Process a, Process b) {
    return (b.arrival > a.arrival);
}

bool sortByBurst(Process a, Process b) {
    return (b.burst > a.burst);
}

bool sortByPriority(Process a, Process b) {
    return (b.priority < a.priority);
}