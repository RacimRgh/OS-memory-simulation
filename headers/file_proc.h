#ifndef FILE_PROC
#define FILE_PROC
#include "process.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <curses.h>

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

Proc_Queue init_queue(Proc_Queue pq);
void add_proc(Proc_Queue *pq, Process p);
Process get_proc(Proc_Queue *q);
Proc_Queue create_queue(FILE *f);
void display_queue(Proc_Queue pq, int y, int x);

#endif