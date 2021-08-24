/******************************************************************************
* jobPenalty.cpp - given an array of tasks(penalty, deadlines), minimize the
* total penalty while maximizing the tasks completed.
* Compile g++ jobPenalty.cpp -o JobPenalty -g -Wall -std=c++0x
*******************************************************************************/
#include<iostream>
using std::cout, std::endl;
#include<vector>

struct Job {
    int penalty;
    int deadline;
    // Constructor.
    Job(int penalty, int deadline) : penalty(penalty), deadline(deadline) {};
    // Default Constructor.
    Job() : penalty(0), deadline(0) {};
};

int earliest(bool* timeSlot, int onTime, int late) {
    // Search for an onTime slot.
    while (onTime >= 0) {
        if (timeSlot[onTime]) {
            return onTime;
        }
        onTime--;
    }
    // Find latest unused slot.
    while (late >= onTime) {
        if (timeSlot[late]) {
            return late;
        }
        late--;
    }
    return -1;
}

Job* schedule(Job* tasks, int n) {
    bool timeSlot[n];
    Job* schedule = new Job[n];
    int slot;

    // Sort the tasks list here if needed.

    // Set up our available timeslots
    for (int i = 0; i < n; i++) {
        timeSlot[i] = true;
    }

    // Iterate each job, assigning a timeSlot.
    for (int i = 0; i < n; i++) {
        slot = earliest(timeSlot, tasks[i].deadline - 1, n); // Find slot.
        timeSlot[slot] = false;                              // Update that the slot is used.
        schedule[slot] = tasks[i];                           // Add the task to the schedule slot.
    }
    return schedule;
}

int main() {
    // List sorted by penalty in order to avoid sort and 0 indexing.
    Job tasks[] = { Job(66, 3), Job(20, 2), Job(15,6), Job(14,1), Job(10,7), Job(9,0), Job(5,8), Job(4,4), Job(2,5) };
    Job* result = schedule(tasks, 9);
    for (int i = 0; i < 9; i++) {
        cout << i << "-" << i + 1 << ": " << result[i].deadline << ", " << result[i].penalty << endl;
    }

    delete[] result;
}
