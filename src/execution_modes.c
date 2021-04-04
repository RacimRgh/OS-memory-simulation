#include "../headers/execution_modes.h"

char *allocation_method[] =
    {
        "Gestion de processus.",
        "Allocation de mémoire.",
        "Pagination."};

char *main_menu[] =
    {
        "0- Initialiser la mémoire avec le fichier 'memory.txt'.",
        "1- Initialiser la mémoire en donnant une taille.",
        "2- Afficher la mémoire.",
        "3- Initialiser la file de processus depuis le fichier 'proc_queue'.",
        "4- Afficher la pile de processus.",
        "5- Charger les processus un par un.",
        "6- Realloc.",
        "7- Free memory.",
        "8- Quitter."};

char *fit_menu[] =
    {
        "First fit",
        "Best fit",
        "Worst fit"};


/**
 * \fn void test()
 * \brief Fonction de test qui permet d'effectuer des allocations désallocations directement.
 * */
void test(){
    Proc_Queue pq;
    Process p;
    Memory l, m = NULL, mem;
    Memory (*fit_function_pointer)(Memory, int) = NULL;
    printf("Donnez la taille de la mémoire: ");
    int taille;
    scanf("%d", &taille);
    int init = initMemory(taille, &mem);
    initscr();
    cbreak();
    start_color();
    refresh();
    show_memory(mem);
    getch();
    endwin();
    int choix = 1;
    int part = 0;
    do
    {
        printf("\nDonnez la taille de l'allocation à faire (0 pour arrêter): ");
        scanf("%d", &part);
        printf("\nDonnez le mode d'allocation(first fit par défaut)");
        printf("\n1-First fit\n2-Worst fit\n3-Best fit\n");
        scanf("%d", &choix);
        switch (choix)
        {
        case 1:
            fit_function_pointer = &(first_fit);
            break;
        case 2:
            fit_function_pointer = &(best_fit);
            break;
        case 3:
            fit_function_pointer = &(worst_fit);
            break;
        default:
            fit_function_pointer = &(first_fit);
            break;
        }
        mem = (Memory)myAlloc(part, mem, fit_function_pointer);
        show_memory(mem);
        initscr();
        cbreak();
        start_color();
        refresh();
        show_memory(mem);
        getch();
        endwin();

    } while (part!=0);
    
}

/**
 * \fn void *myFreeProc(void *arg)
 * \brief Fonction qui vérifie les processus en cours d'exécution, et libère une partition si un des processus a terminé.
 * \param arg Pointeur générique qui va servir comme mémoire
 * */
void *myFreeProc(void *arg)
{
    time_t t;
    Memory m = (Memory)arg, l;
    while (1)
    {
        l = m;
        t = time(NULL);
        sleep(1);
        while (l)
        {
            if (l->data.state == 'U' && l->data.proc.id != 0 && t - l->data.proc.startTime >= l->data.proc.time)
            {

                l->data.state = 'F';
                l->data.proc.id = 0;
                show_memory(m);
                refresh();
            }
            l = l->next;
        }
    }
}



/**
 * \fn void interactive_menu()
 * \brief Mode d'exécution intéractif qui affiche un menu et attend le choix de l'utilisateur
 * */
void cmd(int argc, char* argv[])
{
    Memory (*fit_function_pointer)(Memory, int) = NULL;
    Memory mem;
    int init = initMemory(atoi(argv[2]), &mem);
    initscr();
    cbreak();
    start_color();
    refresh();
    show_memory(mem);
    getch();
    endwin();
    int i = 4;
    int taille;
    int choix;
    while(i<argc)
    {
        taille = atoi(argv[i]);
        choix = atoi(argv[i+1]);
        switch (choix)
        {
        case 1:
            fit_function_pointer = &(first_fit);
            break;
        case 2:
            fit_function_pointer = &(best_fit);
            break;
        case 3:
            fit_function_pointer = &(worst_fit);
            break;
        default:
            fit_function_pointer = &(first_fit);
            break;
        }
        mem = (Memory)myAlloc(taille, mem, fit_function_pointer);
        show_memory(mem);
        initscr();
        cbreak();
        start_color();
        refresh();
        show_memory(mem);
        getch();
        endwin();
        i += 2;
        myRealloc(&mem);
    }

}

/**
 * \fn void interactive_menu()
 * \brief Mode d'exécution intéractif qui affiche un menu et attend le choix de l'utilisateur
 * */
void interactive_menu()
{
    Proc_Queue pq;
    Process p;
    Memory l, m = NULL, mem;
    Memory (*fit_function_pointer)(Memory, Process) = NULL;
    char *proc = (char *)malloc(40 * sizeof(char));
    pq = init_queue(pq);
    initscr();
    // noecho();
    cbreak();
    start_color();
    refresh();
    getch();
    int init = 0;
    int choice, fit_choice;
    pid_t pid;
    pthread_t thread_id;
    do
    {
        choice = menu(2, main_menu, SIZE_MAIN_MENU, "Menu principal");
        initscr();
        switch (choice)
        {
        case 0:
        {
            init = initMemoryFile(10000, &m);
            mem = m;
            message("Mémoire initialisé depuis le fichier memory.txt!", 10, 10);
            // pid = fork();
            pthread_create(&thread_id, NULL, myFreeProc, mem);
            getch();
            break;
        }
        case 1:
        {
            // Input
            WINDOW *win = newwin(3, 80, 13, 40);
            char *input = (char *)malloc(5);
            message("Donnez une taille en octets: ", 10, 10);
            wgetnstr(win, input, sizeof(input));
            int nBytes = atoi(input);
            init = initMemory(nBytes, &mem);
            message("Mémoire initialisé!", 20, 10);
            getch();
            break;
        }
        case 2:
        {
            if (init)
            {
                show_memory(mem);
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
            if (!init && pq.head == NULL)
            {
                message("Initialisez d'abord la mémoire!", 10, 10);
                message("Initialisez d'abord la file de processus!", 20, 10);
                getch();
                break;
            }
            if (!init)
            {
                message("Initialisez d'abord la mémoire!", 10, 10);
                getch();
                break;
            }
            if (pq.head == NULL)
            {
                message("Initialisez d'abord la file de processus!", 10, 10);
                getch();
                break;
            }

            p = get_proc(&pq);
            sprintf(proc, "id: %d - Taille: %d - Duree: %d - Début: %d", p.id, p.size, p.time, p.startTime);
            message(proc, 10, 10);
            fit_choice = menu(2, fit_menu, SIZE_FIT_MENU, "Choix de la politique d'allocation");
            switch (fit_choice)
            {
            case 0:
                fit_function_pointer = &(first_fit_proc);
                break;
            case 1:
                fit_function_pointer = &(best_fit_proc);
                break;
            case 2:
                fit_function_pointer = &(worst_fit_proc);
                break;
            default:
                fit_function_pointer = &(first_fit_proc);
                break;
            }
            mem = (Memory)myAllocProc(p.size, mem, p, fit_function_pointer);
            // display_queue(pq, 1);
            show_memory(mem);

            getch();
            break;
        }
        case 6:
        {
            myRealloc(&mem);
            break;
        }
        case 7:
        {
            freeMemory(&mem);
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


/**
 * \fn void config_file(char *file)
 * \brief Mode d'exécution batch, qui lit un fichier de configuraiton dans le dossier config_files et commence l'exécution pas à pas
 * */
void config_file(char *file)
{
    FILE *f = NULL;
    Process pr;
    Partition x;
    Proc_Queue pq = {0};
    Memory (*fit_function_pointer)(Memory, Process) = NULL;
    Memory m = NULL, l = NULL, p = NULL, q = NULL;
    char *proc = (char *)malloc(40 * sizeof(char));
    pq = init_queue(pq);
    char *alloc_method = (char *)malloc(5 * sizeof(char));
    char line[256];
    int linenum = 0;
    char destination[] = "./config_files/";
    strcat(destination, file);
    f = fopen(destination, "r");
    fgets(line, 256, f);
    if (line[0] != '#')
    {
        puts("Fichier pas bien formatté, réessayez");
    }
    initscr();
    // noecho();
    cbreak();
    refresh();
    getch();
    while (fgets(line, 256, f) != NULL)
    {
        linenum++;
        if (line[0] == '#')
            break;
        if (sscanf(line, "%d %d %c", &x.start, &x.size, &x.state) != 3)
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
    while (fgets(line, 256, f) != NULL)
    {
        linenum++;
        if (line[0] == '#')
            break;
        if (sscanf(line, "%d %d %d %s", &pr.id, &pr.time, &pr.size, alloc_method) != 4)
        {
            fprintf(stderr, "Syntax error, line %d", linenum);
            continue;
        }
        pr.startTime = 0;
        add_proc(&pq, pr);
        display_queue(pq, 15, 10);
        strcat(alloc_method, " fit.");
        message(alloc_method, 20, 10);
        pr = get_proc(&pq);
        getch();

        if (!strcmp("best fit.", alloc_method))
            fit_function_pointer = &(best_fit_proc);
        else if (!strcmp("worst fit.", alloc_method))
            fit_function_pointer = &(worst_fit_proc);
        else if (!strcmp("first fit.", alloc_method))
            fit_function_pointer = &(first_fit_proc);
        else
            continue;
        m = (Memory)myAllocProc(pr.size, m, pr, fit_function_pointer);
        show_memory(m);
        getch();
        refresh();
    }

    getch();
    endwin();
}