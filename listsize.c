#include <stdio.h>
#include <stdint.h>

#include <cstdint>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

#include "bench_common.h"
#include "linux/exmap.h"

#include <atomic>
#include <iostream>
#include <thread>
#include <vector>

// sched affinity
#include <sched.h>
#include <pthread.h>

#define page_length 12
struct exmap_iov {
	union{
		uint64_t value;
		struct{
			uint64_t page	:64- page_length;
			uint64_t len	: page_length;
			};
		struct{
		int32_t res;
		int16_t pages;
		};
	};
};

int main(){
struct exmap_iov iov [512];
printf("%ld",sizeof(iov));
	// amount of CPUs
	int numCPU;
	//hardware_concurrency might not work and return 0 for amount of max concurrent threads
	if (!(numCPU = std::thread::hardware_concurrency())){
	numCPU = sysconf(_SC_NPROCESSORS_ONLN)
	}
	std::vector<std::thread> threads;
	//declare array of bitmasks 
	cpu_set_t *my_set= new cpu_set_t [numCPU];
	for (int i ; i<=numCPU;i++){
	//initialize with zero
	CPU_ZERO (&my_set[i]);
	//each set i, runs only on cpu i 
	CPU_SET(i,&myset[i]);
	
	if (pthread_setaffinity_np(threads[i].native_handle(),sizeof(cpu_set_t), &myset[i])){
	
	}
	std:cerr << "ERROR schedmask"<<"\n";
	}
	int thread_count = numCPU;
	for (int thread_id = 0; thread_id < thread_count; thread_id++) {
		threads.emplace_back([&, thread_id]() {
			std::cout <<" I am "<< thread_id << "running on cpu " << sched_getcpu() ;
			});
		
		sleep(1);
		for (auto& t : threads)
		t.join();
return 0;
}

