/**
 * @file memory.c
 * @author Racim Righi et Lydia Trabelsi
 * @brief Fichier qui contient les implémentations des fonctions qui concernent la mémoire simulée
 * */
#include "../headers/memory.h"

/**
 * \fn int initMemory (int nBytes)
 * \brief Fonction d'initiation de la RAM avec une taille donnée
 * \param nBytes nombre d'octets à allouer
 * \return 0 en cas d'erreur, la taille allouée sinon
 * */
int initMemory(int nBytes, Memory *m)
{
    Memory l = NULL, p = NULL, q = NULL;
    Partition x;
    Process pr;
    int taille = nBytes;
    int address = 0;

    while (nBytes > 500)
    {
        if (!l)
        {
            /* Première partition */
            l = (Memory)calloc(1, sizeof(Partition));
            l->data.proc.id = 0;
            l->data.size = 500;
            l->data.start = address;
            l->data.state = 'F';
            p = l;
            q = l;
        }
        else
        {
            /* Liste des partitions*/
            q = (Memory)calloc(1, sizeof(Partition));
            q->data.proc.id = 0;
            q->data.size = 500;
            q->data.start = address;
            q->data.state = 'F';
            p->next = q;
            p = q;
        }
        address += 500;
        nBytes = nBytes - 500;
    }
    if (nBytes > 0)
    {
        /* Liste des partitions*/
        q = (Memory)calloc(1, sizeof(Partition));
        q->data.proc.id = 0;
        q->data.size = nBytes;
        q->data.state = 'F';
        q->data.start = address;
        p->next = q;
        p = q;
    }
    q->next = NULL;
    *m = l;
    return taille;
}

/**
 * \fn int initMemoryFile (int nBytes)
 * \brief Fonction d'initiation de la RAM à partir d'un fichier qui contient des partitions
 * \param nBytes nombre d'octets max à allouer
 * \return 0 en cas d'erreur, la taille allouée sinon
 * */
int initMemoryFile(int nBytes, Memory *m)
{
    Memory l = NULL, p = NULL, q = NULL;
    Partition x;
    Process pr;
    int taille = 0;
    FILE *f = NULL;
    f = fopen("./config_files/memory.txt", "r");

    if (f)
    {
        while (fscanf(f, "%d %d %c", &x.start, &x.size, &x.state) != EOF && taille < nBytes)
        {
            taille += x.size; //la taille de la ram
            if (!l)
            {
                /* Première partition */
                l = (Memory)calloc(1, sizeof(Partition));
                l->data = x;
                l->data.proc.id = 0;
                p = l;
                q = l;
            }
            else
            {
                /* Liste des partitions*/
                q = (Memory)calloc(1, sizeof(Partition));
                q->data = x;
                q->data.proc.id = 0;
                p->next = q;
                p = q;
            }
        }
        q->next = NULL;
        *m = l;
        fclose(f);
        return taille;
    }
    else
    {
        perror((const char *)f);
        return 0;
    }
}

/**
 * \fn void * myAlloc (int nBytes)
 * \brief Fonction d'allocation d'une partition dans la mémoire
 * \param nBytes nombre d'octets de la partition
 * \return -1 en cas d'erreur, la taille allouée sinon
 * */
void *myAlloc(int nBytes, Memory m, Memory (*fit_function_pointer)(Memory, int))
{
    Memory address = fit_function_pointer(m, nBytes);
    int diff;
    if (address)
    {
        if (address->data.state != 'F')
            puts("Erreur adresse renvoyée non libre");
        else
        {
            address->data.state = 'U';
            address->data.proc.id = 0;
            address->data.proc.startTime = time(NULL);
            diff = address->data.size - nBytes;
            address->data.size = nBytes;
            new_partition(diff, &m, address);
        }
    }
    return m;
}

/**
 * \fn void *new_partition(int nBytes, Memory m)
 * \brief Fonction qui crée une nouvelle partition. Elle sera utilisé après l'allocation d'un espace pour garder le résidu. 
 * */
void new_partition(int nBytes, Memory *m, Memory address)
{
    Memory p = *m, q;
    int start;
    if (nBytes > 0)
    {
        if (*m == address)
        {
            q = malloc(sizeof(Partition));
            q->next = (*m)->next;
            (*m)->next = q;
            q->data.size = nBytes;
            q->data.state = 'F';
            q->data.start = (*m)->data.size;
        }
        // initMemory(nBytes, &m);
        else
        {
            q = malloc(sizeof(Partition));
            q->data.size = nBytes;
            q->data.start = address->data.start + address->data.size;
            q->data.state = 'F';
            q->next = address->next;
            address->next = q;
        }
    }
}

/**
 * \fn int myFree(void * p)
 * \brief Fonction de récupération d'une partition de la mémoire
 * \param p pointeur sur la partition à récupérer  
 * \return -1 en cas d'erreur, la taille récupérée sinon
 * */
int myfree(void *m, Memory p)
{
    Memory l = (Memory)m;
    while(l->next!=p)
        l = l->next;
    
    l->next = p->next;
    free(p);
    return 0;
}

/**
 * \fn int freeMemory()
 * \brief Fonction de récupération de la mémoire alloué par initMemory ou initMemoryWpartition  
 * \return -1 en cas d'erreur, la taille récupérée sinon
 * */
int freeMemory(void *m)
{   
    free(m);
    return 0;
}

/**
 * \fn int freeMemory()
 * \brief Fonction de récupération de la mémoire alloué par initMemory ou initMemoryWpartition  
 * \return -1 en cas d'erreur, la taille récupérée sinon
 * */
int myRealloc(Memory *m)
{
    Memory l = *m, q, p;
    Memory r;
    // m = (Memory)m;
    p = *m;
    l = l->next;
    r = *m;
    int total_size = 0;
    while (l != NULL)
    {
        if (l->data.state == 'F')
        {
            total_size += l->data.size;
            if (p == *m)
            {
                message("here1", 10, 20);
                *m = (*m)->next;
                q = p;
                p = *m;
                l = p->next;
                free(q);
            }
            else
            {
                q = l;
                p->next = q->next;
                free(l);
                l = p->next;
                message("here2", 20, 20);
            }
        }
        else
        {
            message("here3", 25, 20);
            l = l->next;
            p = p->next;
        }
    }
    getch();
    l = *m;
    int address = 0;
    while (l->next)
    {
        l->data.start = address;
        address += l->data.size;
        l = l->next;
    }
    while (total_size > 1000)
    {
        total_size = total_size - 1000;
        new_partition(1000, &r, l);
    }
    if (total_size > 0)
        new_partition(total_size, &r, l);

    *m = r;
    return 0;
}

/**
 * \fn void show_memory(Memory m)
 * \brief Fonction qui affiche la mémoire sous forme de blocs rouge/vert en utilisant la librairie ncurses  
 * */
void show_memory(Memory m)
{
    WINDOW *win;
    Memory l = m;
    int i = 0;
    if (has_colors())
    {
        if (start_color() == OK)
        {
            init_pair(1, COLOR_GREEN, COLOR_GREEN);
            init_pair(2, COLOR_RED, COLOR_RED);
            while (l)
            {
                /* init_pair: numéro de la paire (avant-plan, arrière-plan)  */

                printw("\n@ %d", l->data.start);
                win = newwin(1, l->data.size / 10, 2 * i, 0);
                box(win, ACS_VLINE, ACS_HLINE);
                if (l->data.state == 'F')
                {
                    wbkgd(win, COLOR_PAIR(1));
                    mvprintw(i * 2, l->data.size / 10, "%d Ko", l->data.size);
                }
                else
                {
                    wbkgd(win, COLOR_PAIR(2));
                    mvprintw(i * 2, l->data.size / 10, "%d Ko <PROCESS %d RUNNING>", l->data.size, l->data.proc.id);
                }
                wrefresh(win);
                i++;
                l = l->next;
            }
        }
    }
    else
    {
        endwin();
        printf("Your terminal does not support color\n");
        exit(1);
    }
}

/**
 * \fn Memory first_fit(Memory m, int nBytes)
 * \brief La première partition libre et assez grande pour accueillir le processus/zone sera choisie.
 * */
Memory first_fit(Memory m, int nBytes)
{
    while (m && (m->data.state == 'U' || m->data.size < nBytes))
        m = m->next;
    return m;
}


/**
 * \fn Memory best_fit(Memory m, int nBytes)
 * \brief La partition choisie sera celle qui laissera le moins de résidu possible après l’allocation.
 * */
Memory best_fit(Memory m, int nBytes)
{
    Memory r = first_fit(m, nBytes);
    m = r;
    while (m)
    {
        if (m->data.state == 'F' && m->data.size >= nBytes && m->data.size < r->data.size)
            r = m;
        m = m->next;
    }
    return r;
}


/**
 * \fn Memory worst_fit(Memory m, int nBytes)
 * \brief La partition choisie sera celle qui laissera le plus de résidu après l’allocation, ce qui nous permettra d’y allouer d’autres processus/zones après.
 * */
Memory worst_fit(Memory m, int nBytes)
{
    Memory r = first_fit(m, nBytes);
    m = r;
    while (m)
    {
        if (m->data.state == 'F' && m->data.size >= nBytes && m->data.size > r->data.size)
            r = m;
        m = m->next;
    }
    return r;
}

// #endif