#ifndef FILE_PROC
#define FILE_PROC
#include "process.h"

/**
* \struct Proc_Queue
* \brief Structure d'une Proc_Queue de processus
* */
typedef struct eltQueue
{
    Process data;
    struct eltQueue *next;
} eltQueue;

typedef struct Proc_Queue
{
    eltQueue *head, *rear;
} Proc_Queue;

void add_proc(Proc_Queue *q, Process p);
Process get_proc(Proc_Queue q);
Proc_Queue create_queue(FILE *f);

#endif