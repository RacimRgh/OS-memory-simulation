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
    "1- Initialiser la mémoire en donnant une taille.",
    "2- Afficher la mémoire.",
    "3- Initialiser la file de processus depuis le fichier 'proc_queue'.",
    "4- Afficher la pile de processus.",
    "5- Charger les processus un par un.",
    "6- Allouer un espace.",
    "7- Quitter."
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
    start_color();
    refresh();
    getch();
    int init = 0;
    int choice, fit_choice;
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
            f = fopen("./config_files/proc_queue.txt", "r");
            pq = create_queue(f);
            message("File initialisé!", 10, 10);
            getch();       
            break;
        }
        case 4:
        {
            if (pq.head != NULL)
                display_queue(pq, 1, 1);
            else
                message("Initialisez d'abord la file de processus!", 10, 10);
            getch();
            break;
        }
        case 5:
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
        case 6:
        {
            break;
        }
        case 8:
        {
            choice = -1;
            message("Au revoir!", 10, 10);
            break;
        }
        default:
        {

            choice = -1;
            message("Au revoir!", 10, 10);
            break;
        }
        }
        del_message();
        refresh();
    } while (choice != -1);

    getch();
    endwin();
}

void config_file(char* file)
{
    FILE *f = NULL;
    Process pr;
    Partition x;
    Proc_Queue pq = {0};
    Memory (*fit_function_pointer)(Memory, Process) = NULL;
    Memory m = NULL, l = NULL, p = NULL, q = NULL;
    char* proc = (char*)malloc(40 * sizeof(char));
    pq = init_queue(pq);
    char* alloc_method = (char*)malloc(5 * sizeof(char));
    char line[256];
    int linenum = 0;
    char destination[] = "./config_files/";
    strcat(destination, file);
    f = fopen(destination, "r");
    fgets(line, 256, f);
    if(line[0] != '#')
    {
        puts("Fichier pas bien formatté, réessayez");
    }
    initscr();
    noecho();
    cbreak();
    refresh();
    getch();
    while(fgets(line, 256, f) != NULL)
    {   
        linenum++;
        if(line[0] == '#') break;
        if(sscanf(line, "%d %d %c", &x.start, &x.size, &x.state) != 3)
        {
            fprintf(stderr, "Syntax error, line %d\n", linenum);
            continue;
        }
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
    m = l;
    show_memory(m);
    getch();
    /* ----------------------------------- */
    while(fgets(line, 256, f) != NULL)
    {
        linenum++;
        if(line[0] == '#') break;
        if(sscanf(line, "%d %d %d %s", &pr.id, &pr.time, &pr.size, alloc_method) != 4)
        {
            fprintf(stderr, "Syntax error, line %d", linenum);
            continue;
        }
        pr.startTime = 0;
        pr.priority = 0;
        add_proc(&pq, pr);
        display_queue(pq, 15, 10);
        strcat(alloc_method, " fit.");
        message(alloc_method, 20, 10);
        pr = get_proc(&pq);
        getch();
        
        if(!strcmp("best fit.", alloc_method)) fit_function_pointer = &(best_fit);
        else if (!strcmp("worst fit.", alloc_method)) fit_function_pointer = &(worst_fit);
        else if (!strcmp("first fit.", alloc_method)) fit_function_pointer = &(first_fit);
        else continue;
        m = (Memory)myAllocProc(pr.size, m, pr, fit_function_pointer);
        show_memory(m);
        getch();
        refresh();
    }
    
    getch();
    endwin();
}