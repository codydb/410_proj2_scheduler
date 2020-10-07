/*
 * Stats.cpp
 *
 *   Created on: Oct 6, 2020
 *      Author: Cody Baker
 */

#include "../includes/stats.h"

//Constructor
Stats:: Stats(std::vector<PCB> &finished_vector){
	vec = &finished_vector;

	calcStats();
}

//loops thru vec, prints 1 line for each process using the following format
//Process 1 Required CPU time:2  arrived:0 started:0 finished:2
//if there are 10 processes in vector, should print 10 lines
void Stats:: showAllProcessInfo(){
	int cnt = 1;

	for (std::vector<PCB>::iterator itr = vec-> begin(); itr < vec-> end(); itr++){
		printf("Process %d Required CPU time: %d arrived:%d started:%d finished:%d\n",
				 cnt, itr-> required_cpu_time, itr-> arrival_time, itr-> start_time, itr-> finish_time);

		cnt++;
	}
}

//after a process is placed in the ready_q, how long does
//it take before its placed on the processor?
//response_time per process = start_time - arrival_time
//this funtion returns the average over all processes
float Stats:: get_av_response_time(){
	float ret = 0.0;
	int cnt = 0;

	for (std::vector<PCB>::iterator itr = vec-> begin(); itr < vec-> end(); itr++){
		ret += (itr-> start_time - itr-> arrival_time);
		cnt++;
	}

	ret = ret/cnt;

	return ret;
}

//after a process is placed in the ready_q, how long does
//it take to complete?
//turnaround time per process = finish_time - arrival_time
//this funtion returns the average over all processes
float Stats:: get_av_turnaround_time(){
	float ret = 0.0;
	int cnt = 0;

	for (std::vector<PCB>::iterator itr = vec-> begin(); itr < vec-> end(); itr++){
		ret += (itr-> finish_time - itr-> arrival_time);
		cnt++;
	}

	ret = ret/cnt;

	return ret;
}

//after a process is placed in the ready_q, how much time does it
//spend waiting for processor time?
//wait time per process = finish_time - arrival_time-required_CPU_time
//this funtion returns the average over all processes
float Stats:: get_av_wait_time(){
	float ret = 0.0;
	int cnt = 0;

	for (std::vector<PCB>::iterator itr = vec-> begin(); itr < vec-> end(); itr++){
		ret += (itr-> finish_time - itr-> arrival_time - itr-> required_cpu_time);
		cnt++;
	}

	ret = ret/cnt;

	return ret;
}


//does the work (only needs to run once)
void Stats:: calcStats(){
	av_wait_time = get_av_wait_time();
	av_turnaround_time = get_av_turnaround_time();
	av_response_time = get_av_response_time();
}

