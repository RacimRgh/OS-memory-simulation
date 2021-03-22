/**
 * \file memory.h
 * \brief En-tête qui contient les descriptions des structures et fonctions de la mémoire
 * */

#ifndef MEMORY_HEADER
#define MEMORY_HEADER
#include "process.h"
#include <stdlib.h>
#include <stdio.h>

/**
* \struct Partition
* \brief Structure d'une partition dans la mémoire
* */
typedef struct Partition
{
    process proc; /*!< Processus qui occupe la partition, NULL si aucun. */
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
int initMemoryWpartitions(int nBytes);
int initMemory(int nBytes);
void *myAlloc(int nBytes);
int myfree(void *p);
int freeMemory();

#endif