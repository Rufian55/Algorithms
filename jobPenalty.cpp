#include<iostream>
#include<vector>

struct Job {
	int penalty;
	int deadline;
	Job(int penalty, int deadline) : penalty(penalty), deadline(deadline) {};
	Job() : penalty(0), deadline(0) {};
};

int earliest(bool* timeslot, int onTime, int late) {
	// look for an on time slot
	while (onTime >= 0) {
		if (timeslot[onTime]) {
			return onTime;
		}
		onTime--;
	}
	// find latest unused slot
	while (late >= onTime) {
		if (timeslot[late]) {
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

	// sort the tasks list if needed....

	// set up our available timeslots
	for (int i = 0; i < n; i++) {
		timeSlot[i] = true;
	}

	// iterate each job, assigning a timeSlot
	for (int i = 0; i < n; i++) {
		slot = earliest(timeSlot, tasks[i].deadline - 1, n);  // find slot
		timeSlot[slot] = false;         // update that the slot is used
		schedule[slot] = tasks[i];      // add the task to the schedule slot
	}
	return schedule;
}

int main() {
	// I'm creating the list sorted by penalty so we can skip the sort code, also 0 indexing it
	Job tasks[] = { Job(66, 3), Job(20, 2), Job(15,6), Job(14,1), Job(10,7), Job(9,0), Job(5,8), Job(4,4), Job(2,5) };
	Job* result = schedule(tasks, 9);
	for (int i = 0; i < 9; i++) {
		std::cout << i << "-" << i + 1 << ": " << result[i].deadline << ", " << result[i].penalty << std::endl;
	}
	//delete[] result;
}