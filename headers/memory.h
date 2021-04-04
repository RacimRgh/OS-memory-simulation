/**
 * \file memory.h
 * \brief En-tête qui contient les descriptions des structures et fonctions de la mémoire
 * */

#ifndef MEMORY_HEADER
#define MEMORY_HEADER

// #include "process.h"
#include <stdlib.h>
#include <stdio.h>
#include <curses.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include "menu.h"

// typedef struct Process Process;

// typedef struct Process Process;

/**
* \struct Process
* \brief Structure d'un processus à insérer dans une partition
* */
typedef struct Process
{
    int id;        /*!< Id du processus, il est utilisé pour identifier la partition occupée*/
    int time;      /*!< Temps d'exécution du processus*/
    int startTime; /*!< Temps de démarrage de l'exécution du processus*/
    int size;      /*!< Taille en octets du processus*/
} Process;

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
int initMemoryFile(int nBytes, Memory *m);
int initMemory(int nBytes, Memory *m);
void *myAlloc(int nBytes, Memory m, Memory (*fit_function_pointer)(Memory, int));
void new_partition(int nBytes, Memory *m, Memory address);
int myfree(void *m, Memory p);
int freeMemory(void *m);
int myRealloc(Memory *m);
void show_memory(Memory m);
Memory first_fit(Memory m, int nBytes);
Memory best_fit(Memory m, int nBytes);
Memory worst_fit(Memory m, int nBytes);
#endif