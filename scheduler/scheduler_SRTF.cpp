/*
 * SchedulerSRTF.cpp
 *
 *  Created on: Oct 6, 2020
 *      Author: Cody Baker
 *
 *      implements shortest remaining time first scheduling algorithm
 *     pre-emptive
 */
#include <algorithm>
#include "../includes/scheduler_SRTF.h"

//override base class behaviour if necessary, otherwise call it
bool Scheduler_SRTF:: time_to_switch_processes(int tick_count, PCB &p){
	sort();

	if (p.remaining_cpu_time <= 0){
		return true;
	} else if (ready_q-> size() == 0){
		return false;
	} else if (p.remaining_cpu_time > ready_q-> front().remaining_cpu_time){
		return true;
	} else {
		return false;
	}
}

//SRTF-preemptive - sort ready_q by remaining_cpu_time whenever add(PCB p) or time_to_switch_processes is called
void Scheduler_SRTF:: sort(){
	std::vector<PCB> vect;

	while (ready_q->size() != 0){
		vect.push_back(ready_q-> front());
		ready_q-> pop();
	}

	std::sort(vect.begin(), vect.end(), [](PCB a, PCB b) {
		return a.remaining_cpu_time < b.remaining_cpu_time;
	});

	for (std::vector<PCB>::iterator itr = vect.begin(); itr != vect.end(); itr++){
		ready_q-> push(*itr);
	}
	vect.clear();
}
