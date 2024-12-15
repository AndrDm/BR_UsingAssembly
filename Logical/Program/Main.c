//==============================================================================
//
// Title:		Using GNU Assembler in B&R PLC
// Purpose:		A short demo.
//
// Created on:	15.12.2024 at 07:56:31 by AD.
//
//==============================================================================
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

#include <unistd.h>

#include "asmfun.h"
#include "asmadd.h"
#include "asmadd_intel.h"

void _INIT ProgramInit(void)
{
	CounterU16 = 0; a = b = 0;
}

//==============================================================================
// Inline:
//
int add_integers_inline(int a, int b) {
	int result;
	__asm__ (
		"movl %1, %%eax\n\t"
		"addl %2, %%eax"
		: "=a" (result)
		: "r" (a), "r" (b)
	);
	return result;
}

//==============================================================================
// Read Real Time Time Stamp
//
uint64_t rdtsc() {
	uint32_t low, high;
	__asm__ __volatile__ (
		"rdtsc" 
		: "=a" (low), "=d" (high)
	);
	return ((uint64_t)high << 32) | low;
}

static uint64_t begin_time, begin_time_saved, end_time;

void _CYCLIC ProgramCyclic(void)
{
	begin_time = rdtsc(); // Time Stamp - begin
	cycle_time = (LREAL)(begin_time - begin_time_saved);
	begin_time_saved = begin_time;
	
	CounterU16 = asmfun(CounterU16); // original B&R Example
	res1 = add_integers(a++, b++);   // two params example
	res2 = add_integers_intel(a++, b++);
	res3 = add_integers_inline(a++, b++);
	
	__asm__ (
		"movl %1, %%eax\n\t"
		"addl %2, %%eax"
		: "=a" (res4)
		: "r" (a), "r" (b)
	);
		
	end_time = rdtsc(); // Time Stamp - end
	cpu_time = ((LREAL) (end_time - begin_time));
}


void _EXIT ProgramExit(void)
{

}
