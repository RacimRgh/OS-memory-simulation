/**
 * @file memory.c
 * @author Racim Righi et Lydia Trabelsi
 * @brief Fichier qui contient les implémentations des fonctions qui concernent la mémoire simulée
 * */
// #ifndef MEMORY_SRC
// #define MEMORY_SRC
#include "../headers/memory.h"

/**
 * \fn int initMemory (int nBytes)
 * \brief Fonction d'initiation de la RAM
 * \param nBytes nombre d'octets à allouer
 * \return 0 en cas d'erreur, la taille allouée sinon
 * */
int initMemory(int nBytes, Memory *m)
{
    Memory l = NULL;
    Partition x;
    l = (Memory)calloc(1, sizeof(Partition));
    if (l)
    {
        x.size = nBytes;
        x.start = 0;
        x.state = 'F';
        l->data = x;
        l->next = NULL;
        *m = l;
        return nBytes;
    }
    else
        return 0;
}
/**
 * \fn int initMemoryWpartitions (int nBytes)
 * \brief Fonction d'initiation de la RAM à partir d'un fichier qui contient des partitions
 * \param nBytes nombre d'octets max à allouer
 * \return 0 en cas d'erreur, la taille allouée sinon
 * */
int initMemoryWpartitions(int nBytes, Memory *m)
{
    Memory l = NULL, p = NULL, q = NULL;
    Partition x;
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
                p = l;
                q = l;
            }
            else
            {
                /* Liste des partitions*/
                q = (Memory)calloc(1, sizeof(Partition));
                q->data = x;
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
void *myAlloc(int nBytes, Memory m)
{
    
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
int myfree(void *p)
{
    return 0;
}

/**
 * \fn int freeMemory()
 * \brief Fonction de récupération de la mémoire alloué par initMemory ou initMemoryWpartition  
 * \return -1 en cas d'erreur, la taille récupérée sinon
 * */
int freeMemory()
{
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

// #endif