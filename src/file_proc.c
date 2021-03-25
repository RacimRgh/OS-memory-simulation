#include "../headers/file_proc.h"

void add_proc(Proc_Queue *q, Process p)
{
    eltQueue *p;
    p = (eltQueue *)calloc(1, sizeof(eltQueue));
    p->data = p;
    p->next = NULL;
    if (q->head == NULL)
    {
        q->head = p;
        q->rear = p;
    }
    else
    {
        (q->rear)->next = p;
        q->rear = p;
    }
}
Process get_proc(Proc_Queue *q)
{
    Process p = q.head->data;
    eltQueue *l;
    l = q.head;
    q->head = q->head->next;
    free(l);
    return p;
}

Proc_Queue create_queue(FILE *f)
{
    Process p;
    Proc_Queue f = {0};

    while (fscanf(f, "%d %d %d %d", &p.id, &p.time, &p.startTime, &p.size) != EOF)
    {
        add_proc(&f, x);
    }

    return f;
}