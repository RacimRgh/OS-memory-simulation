// #ifndef PROCESS_SRC
// #define PROCESS_SRC

#include "../headers/process.h"

/**
 * \fn void * myAllocProc (int nBytes)
 * \brief Fonction d'allocation d'une partition dans la mémoire
 * \param nBytes nombre d'octets de la partition
 * \return -1 en cas d'erreur, la taille allouée sinon
 * */
void *myAllocProc(int nBytes, Memory m, Process p, Memory (*fit_function_pointer)(Memory, Process))
{
    Memory address = fit_function_pointer(m, p);
    int diff;
    if (address)
    {
        if (address->data.state != 'F')
            puts("Erreur adresse renvoyée non libre");
        else
        {
            address->data.state = 'U';
            address->data.proc = p;
            address->data.proc.startTime = time(NULL);
            diff = address->data.size - p.size;
            address->data.size = p.size;
            new_partition(diff, &m, address);
        }
    }
    return m;
}

Memory first_fit_proc(Memory m, Process p)
{
    while (m && (m->data.state == 'U' || m->data.size < p.size))
        m = m->next;
    return m;
}

Memory best_fit_proc(Memory m, Process p)
{
    Memory r = first_fit_proc(m, p);
    m = r;
    while (m)
    {
        if (m->data.state == 'F' && m->data.size >= p.size && m->data.size < r->data.size)
            r = m;
        m = m->next;
    }
    return r;
}

Memory worst_fit_proc(Memory m, Process p)
{
    Memory r = first_fit_proc(m, p);
    m = r;
    while (m)
    {
        if (m->data.state == 'F' && m->data.size >= p.size && m->data.size > r->data.size)
            r = m;
        m = m->next;
    }
    return r;
}

// #endif
