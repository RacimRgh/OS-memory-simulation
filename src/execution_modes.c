#include "../headers/execution_modes.h"

char *allocation_method[] =
{
    "Gestion de processus.",
    "Allocation de mémoire.",
    "Pagination."
};

char *main_menu[] =
{
    "0- Initialiser la mémoire avec le fichier 'memory.txt'.",
    "1- Initialiser la mémoire manuellement.",
    "2- Afficher la mémoire.",
    "3- Initialiser la file de processus depuis le fichier 'proc_queue'.",
    "4- Afficher la pile de processus.",
    "5- Charger tout les processus.",
    "6- Charger les processus un par un.",
    "7- Allouer un espace.",
    "8- Quitter."
};

char *fit_menu[] = 
{
    "First fit",
    "Best fit",
    "Worst fit"
};


void interactive_menu()
{
    Proc_Queue pq ;
    Process p;
    Memory m = NULL, l;
    Memory (*fit_function_pointer)(Memory, Process) = NULL;
    char* proc = (char*)malloc(40 * sizeof(char));
    pq = init_queue(pq);
    initscr();
    noecho();
    cbreak();
    refresh();
    getch();
    int init = 0;
    int choice, fit_choice;
    // if(argc>1)
    // {
    //     FILE *f = NULL;
    //     f = fopen("./input_files/proc_queue.txt", "r");
    //     pq = create_queue(f);
    //     display_queue(pq, 0);
    //     p = get_proc(&pq);
    //     sprintf(proc, "id: %d - Taille: %d - Durée: %d - Début: %d", p.id, p.size, p.time, p.startTime);      
    //     // printf("%s", proc);
    //     message(proc, 10,10);
    //     exit(1);
    // }
    do
    {
        choice = menu(2, main_menu, SIZE_MAIN_MENU, "Menu principal");
        initscr();
        switch (choice)
        {
        case 0:
        {
            init = initMemoryWpartitions(10000, &m);
            message("Mémoire initialisé depuis le fichier memory.txt!", 10, 10);
            getch();
            break;
        }
        case 1:
        {
            init = initMemory(10000, &m);
            message("Mémoire initialisé!", 10, 10);
            getch();
            break;
        }
        case 2:
        {
            if (init)
            {
                show_memory(m);
            }
            else
                message("Initialisez d'abord la mémoire!", 10, 10);

            getch();
            break;
        }
        case 3:
        {
            FILE *f = NULL;
            f = fopen("./input_files/proc_queue.txt", "r");
            pq = create_queue(f);
            message("File initialisé!", 10, 10);
            getch();       
            break;
        }
        case 4:
        {
            if (pq.head != NULL)
                display_queue(pq, 1);
            else
                message("Initialisez d'abord la file de processus!", 10, 10);
            getch();
            break;
        }
        case 5:
        {
            break;
        }
        case 6:
        {
            if(!init && pq.head == NULL)
            {
                message("Initialisez d'abord la mémoire!", 10, 10);
                message("Initialisez d'abord la file de processus!", 20, 10);
                getch();
                break;
            }
            if(!init)
            {
                message("Initialisez d'abord la mémoire!", 10, 10);
                getch();
                break;
            }
            if(pq.head == NULL)
            {
                message("Initialisez d'abord la file de processus!", 10, 10);
                getch();
                break;
            }

            p = get_proc(&pq);
            sprintf(proc, "id: %d - Taille: %d - Duree: %d - Début: %d", p.id, p.size, p.time, p.startTime);   
            message(proc, 10,10);
            fit_choice = menu(2, fit_menu, SIZE_FIT_MENU, "Choix de la politique d'allocation");
            switch (fit_choice)
            {
            case 0:
                fit_function_pointer = &(first_fit);
                break;
            case 1:
                fit_function_pointer = &(best_fit);
                break;
            case 2:
                fit_function_pointer = &(worst_fit);
                break;
            default:
                break;
            }
            m = (Memory)myAllocProc(p.size, m, p, fit_function_pointer);
            // display_queue(pq, 1);
            show_memory(m);

            getch();
            break;
        }
        case 8:
        {
            choice = -1;
            message("Au revoir!", 10, 10);
            break;
        }

        default:
            break;
        }
        del_message();
        refresh();
    } while (choice != -1);

    getch();
    endwin();
}