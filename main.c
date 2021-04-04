#include "./headers/execution_modes.h"
#include <string.h>

void main(int argc, char* argv[])
{
    if(argc == 1)
    {
        puts("Liste des options: ");
        puts("Mode test: $ ./Mémoire -t");
        puts("Mode interactif : $ ./Mémoire -i");
        puts("Mode ligne de commande : $ ./Mémoire -m <taille_memoire> -p <partition_1> … <partition_n> ");
        puts("Mode fbatch:  $ ./Mémoire -f <nom_du_fichier_conf>");
    }
    else
    {
        if(!strcmp(argv[1], "-h"))
        {
            puts("Liste des options: ");
            puts("Mode test: $ ./Mémoire -t");
            puts("Mode interactif : $ ./Mémoire -i");
            puts("Mode ligne de commande : $ ./Mémoire -m <taille_memoire> -p <partition_1> … <partition_n> ");
            puts("Mode fbatch:  $ ./Mémoire -f <nom_du_fichier_conf>");   
        }
        if(!strcmp(argv[1], "-t"))
            test();
        if(!strcmp(argv[1], "-i"))
            interactive_menu();
        
        if(!strcmp(argv[1], "-f"))
        {
            if(argc < 3)
                puts("Donnez le fichier de configuration.");
            else
            {
                config_file(argv[2]);
            }
        }
        if(!strcmp(argv[1], "-m"))
        {
            if(argc < 6)
                puts("Nombre d'arguments insuffisant");
            else
            {
                if(!strcmp(argv[2], "-p"))
                    puts("Mauvaise syntaxe");
                else
                    cmd(argc, argv);
            }
        }
    }
}