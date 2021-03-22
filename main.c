#include "./headers/memory.h"
#include "./headers/process.h"
#include "./headers/menu.h"


#define SIZE_MAIN_MENU 4
char *main_menu[] = 
{
        "Initialiser la mémoire avec le fichier 'memory.txt'",
        "Initialiser la mémoire en une seule partition.",
        "Afficher la mémoire.",
        "Quitter."
};

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
                printf("Initialiser la mémoire d'abord");
            
            getch(); 
            break;
        }
        case 3:
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