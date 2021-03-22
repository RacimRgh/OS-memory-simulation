#include "./headers/memory.h"
#include "./headers/process.h"
#include "./headers/menu.h"

void main()
{
    initscr();
    noecho();
    cbreak();
    refresh();
    getch();
    Memory m = NULL, l;
    int init = 0;
    int choice;
    char *choices[] = {
        "Initialiser la mémoire",
        "Afficher la mémoire",
        "Quitter"
    };
    do 
    {
        choice = menu(2, choices, SIZE_CHOICES, "Menu principal");
        initscr();
        switch (choice)
        {
        case 0:
        {

            init = initMemoryWpartitions(10000, &m);
            message("Mémoire initialisé!", 0, 10);
            getch();
            break;
        }
        case 1:
        {
            if (init)
            {
                show_memory(m);
            }
            else
                printf("Initialiser la mémoire d'abord");
            
            getch(); 
            break;
        }
        case 2:
        {
            choice = 0;
            break;
        }
        
        default:
            break;
        }
        del_message();
        refresh();
    }while(choice != -1);

    getch();
    endwin();
}