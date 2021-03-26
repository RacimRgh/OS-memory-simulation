#include "./headers/memory.h"
#include "./headers/process.h"
#include "./headers/menu.h"
#include "./headers/file_proc.h"




void main()
{
    FILE *f = NULL;
    f = fopen("./input_files/proc_queue.txt", "r");
    Proc_Queue pq = create_queue(f);
    // eltQueue *pq = create_queue(f);
    eltQueue *q = pq.head;
    char *msg;
    while(q != NULL)
    {
        // printf("id: %d - Taille: %d - Debut: %ds - Temps: %ds\n", pq->head->data.id, pq.head->data.size, pq.head->data.startTime, pq.head->data.time);
        sprintf(msg, "%d - %d", q->data.id, q->data.size);
        message(msg, 10, 10);
        // printf("%d", q->data.id);
        q = q->next;
    }

}