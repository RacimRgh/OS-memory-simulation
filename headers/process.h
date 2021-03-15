#ifndef PROCESS_HEADER
#define PROCESS_HEADER


//---------STRUCTURES DEFINITIONS---------//
//process structure
typedef struct process {
    int id;
    int time;
    int startTime;
    int size;
    int priority;
} process;

// Queue structure
typedef struct eltFile {
    process data;
    struct eltFile *next;
} eltFile;

typedef struct File {
    eltFile *h, *t;
} File;

// Stack structure
typedef struct eltPile {
    File f;
    struct eltPile *suiv;
} eltPile;
typedef eltPile *Pile;

//------------- PROTOTYPES ---------------//


#endif