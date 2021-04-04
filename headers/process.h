/**
 * \file Process.h
 * \brief En-tête contenant les déclarations et prototypes concernants les processus 
 * */

#ifndef PROCESS_HEADER
#define PROCESS_HEADER
#include "memory.h"

void *myAllocProc(int nBytes, Memory m, Process p, Memory (*fit_function_pointer)(Memory, Process));
Memory first_fit_proc(Memory m, Process p);
Memory best_fit_proc(Memory m, Process p);
Memory worst_fit_proc(Memory m, Process p);

#endif