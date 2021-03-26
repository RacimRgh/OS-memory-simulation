/**
 * \file Process.h
 * \brief En-tête contenant les déclarations et prototypes concernants les processus 
 * */

#ifndef PROCESS_HEADER
#define PROCESS_HEADER
// #include "memory.h"

/**
* \struct Process
* \brief Structure d'un processus à insérer dans une partition
* */
typedef struct Process
{
    int id;
    int time;
    int startTime;
    int size;
    int priority;
} Process;

#endif