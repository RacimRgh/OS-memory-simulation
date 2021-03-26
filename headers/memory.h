/**
 * \file memory.h
 * \brief En-tête qui contient les descriptions des structures et fonctions de la mémoire
 * */

#ifndef MEMORY_HEADER
#define MEMORY_HEADER

#include "process.h"
#include <stdlib.h>
#include <stdio.h>
#include <curses.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

/**
* \struct Partition
* \brief Structure d'une partition dans la mémoire
* */
typedef struct Partition
{
    Process proc; /*!< Processus qui occupe la partition, NULL si aucun. */
    int start;    /*!< Adresse de début de la partition. */
    int size;     /*!< Taille de la partition en bytes. */
    char state;   /*!< Etat de la partition: F pour free=libre, U pour used=utilisée. */
} Partition;

/**
* \struct Memory
* \brief Structure de la mémoire qui contient l'ensemble des partitions sous forme de liste
* */
typedef struct elt
{
    Partition data;   /*<! Informations sur la partition. */
    struct elt *next; /*<! Pointeur sur la partition suivante. */
} elt;
typedef elt *Memory;

//------------- PROTOTYPES ---------------//
int initMemoryWpartitions(int nBytes, Memory *m);
int initMemory(int nBytes, Memory *m);
void *myAlloc(int nBytes, Memory m);
void *myAllocProc(int nBytes, Memory m, Process p, Memory (*fit_function_pointer)(Memory, Process));
void new_partition(int nBytes, Memory *m, Memory address);
int myfree(void *p);
int freeMemory();
void show_memory(Memory m);
Memory first_fit(Memory m, Process p);
Memory best_fit(Memory m, Process p);
Memory worst_fit(Memory m, Process p);

#endif