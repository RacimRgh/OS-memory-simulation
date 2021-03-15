#ifndef MEMORY_HEADER
#define MEMORY_HEADER
#include "process.h"


//---------STRUCTURES DEFINITIONS---------//

// Memory partition structure
typedef struct partition {
    process proc;
    int start;
    int size;
    char state; // F pour libre "Free" ET U pour utilisé "Used"
} partition;

// List of partitions
typedef struct elt
{
    partition data;
    struct elt *next;
} elt;
typedef elt *Memo;

//------------- PROTOTYPES ---------------//
int initMemory(int nBytes);
void* myAlloc(int nBytes);
int myfree(void* p);
int freeLemory();


#endif