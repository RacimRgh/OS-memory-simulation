#include "./headers/execution_modes.h"
#include <string.h>

void main(int argc, char* argv[])
{
    if(argc == 1)
        puts("Liste des options: ");
    else
    {
        if(!strcmp(argv[1], "-i"))
            interactive_menu();
    }
}