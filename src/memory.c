/**
 * @file memory.c
 * @author Racim Righi et Lydia Trabelsi
 * @brief Fichier qui contient les implémentations des fonctions qui concernent la mémoire simulée
 * */

#include "../headers/memory.h"

/**
 * \fn int initMemory (int nBytes)
 * \brief Fonction d'initiation de la RAM
 * \param nBytes nombre d'octets à allouer
 * \return 0 en cas d'erreur, la taille allouée sinon
 * */
int initMemory(int nBytes)
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
int initMemoryWpartitions(int nBytes)
{
    Memory l = NULL, p = NULL, q = NULL;
    Partition x;
    int taille = 0;
    FILE *f = NULL;
    f = fopen("../input_files/memory.txt", "r");

    if (f)
    {
        while (fscanf(f, "%d %d %c", &x.start, &x.size, &x.state) != EOF && taille < nBytes)
        {
            taille += x.size; //la taille de la ram

            if (!l)
            { //first partition
                l = (Memory)calloc(1, sizeof(Partition));
                l->data = x;
                p = l;
                q = l;
            }
            else
            {
                q = (Memory)calloc(1, sizeof(Partition));
                q->data = x;
                p->next = q;
                p = q;
            }
        }
        q->next = NULL;
        fclose(f);
    }
    else
    {
        puts("Impossible d'ouvrir le fichier MEMO.txt");
    }
}

/**
 * \fn void * myAlloc (int nBytes)
 * \brief Fonction d'allocation d'une partition dans la mémoire
 * \param nBytes nombre d'octets de la partition
 * \return -1 en cas d'erreur, la taille allouée sinon
 * */
void *myAlloc(int nBytes)
{
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