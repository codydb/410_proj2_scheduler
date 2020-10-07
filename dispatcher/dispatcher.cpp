/*
 * Dispatcher.cpp
 *
 *  Created on: Oct 6, 2020
 *      Author: Cody Baker
 */
#include "../includes/dispatcher.h"

//pull current process (if any) off CPU and return it
//if nothing on CPU returns an uninitialized PCB
PCB Dispatcher:: get_from_CPU(){
	PCB get = cpu->get_process_off_core();
	return get;
}

//place the current process on the CPU for execution
void Dispatcher:: put_on_CPU(PCB &process){
	cpu->put_process_on_core(process);
}

//is CPU idle or working
//set or reset according to whether  there is a job on the CPU
bool Dispatcher:: isValidJobOnCPU(){
	PCB chk = cpu->get_COPY_of_Current_Process();
	return !chk.isEmpty();
}
