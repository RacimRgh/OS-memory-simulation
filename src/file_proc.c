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

    while (fscanf(f, "%d %d %d %d", &p.id, &p.size, &p.startTime, &p.time) != EOF)
    {
        // p.startTime = time(NULL);
        add_proc(&pq, p);
    }

    return pq;
}

void display_queue(Proc_Queue pq, int y, int x)
{
    eltQueue *p = pq.head;
    int i = y;
    wattron(stdscr, A_BOLD);
    mvprintw(y, x, "ID\t|Taille\t|Temps d'arrivee|Temps d'exe");
    wattroff(stdscr, A_BOLD);
    while (p)
    {
        mvprintw(1 + i, x, "%d \t%d \t%d \t%d", p->data.id, p->data.size, p->data.startTime, p->data.time);
        p = p->next;
        i = i + 1;
    }
    refresh();
}