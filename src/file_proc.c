#include "../headers/file_proc.h"


Proc_Queue init_queue(Proc_Queue pq)
{
    pq.head = NULL;
    pq.rear = NULL;
    return pq;
}

void add_proc(Proc_Queue *pq, Process p)
{
    eltQueue *q;
    q = (eltQueue *)calloc(1, sizeof(eltQueue));
    q->data = p;
    q->next = NULL;
    if (pq->head == NULL)
    {
        pq->head = q;
        pq->rear = q;
    }
    else
    {
        (pq->rear)->next = q;
        pq->rear = q;
    }
}

Process get_proc(Proc_Queue *q)
{
    Process p = q->head->data;
    eltQueue *l;
    l = q->head;
    q->head = q->head->next;
    free(l);
    return p;
}

Proc_Queue create_queue(FILE *f)
{
    Process p;
    Proc_Queue pq = {0};

    while (fscanf(f, "%d %d %d %d", &p.id, &p.time, &p.startTime, &p.size) != EOF)
    {
        add_proc(&pq, p);
    }

    return pq;
}

void display_queue(Proc_Queue pq, int t)
{
    eltQueue *p = pq.head;
    int i = 0;
    wattron(stdscr, A_BOLD);
    mvprintw(0, t, "ID\t|SIZE\t|TIME\t|DELAY");
    wattroff(stdscr, A_BOLD);
    while (p)
    {
        mvprintw(1 + i * 2, t, "%d \t%d \t%d \t%d", i + 1, p->data.id, p->data.size, p->data.startTime, p->data.time);
        p = p->next;
        i = i + 1;
    }
    refresh();
}