/*
 * SchedulerSTRR.cpp
 *
 *  Created on: Oct 6, 2020
 *      Author: Cody Baker
 *
 *      implements round robin scheduling algorithm
 *      pre-emptive
 */

#include "../includes/scheduler_RR.h"

int jobTicks = 0;


//override base class behaviour if necessary, otherwise call it
bool Scheduler_RR:: time_to_switch_processes(int tick_count, PCB &p){

	if (jobTicks == (time_slice -1) || p.remaining_cpu_time <= 0){

		jobTicks = 0;

		return true;
	} else {

		jobTicks++;

		return false;
	}
}

//RR - preemptive - no sorting of ready_q needed.
void Scheduler_RR:: sort(){}


