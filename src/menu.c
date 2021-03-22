/**
 * @file menu.c
 * @brief Fichier qui contient les implémentations des fonctions des affichages et menus
 * 
*/

#include "../headers/menu.h"

/**
 * \fn void del_message()
 * \brief Fonction de suppression d'un message
 * \details Cette fonction supprime les carré qui affichage des messages de succès/erreur.
 * */
void del_message() {
    for (size_t i = 0; i <= 250; i++) {
        mvprintw(i, 0, "                                                                                                                                             ");
    }
}

/**
 * \fn void message(char *s, int y, int x)
 * \brief Fonction d'affichage d'un message
 * \param[in] s Message à afficher
 * \param[in] y Numéro de ligné où afficher
 * \param[in] x Numéro de colonne où afficher
 * */
void message(char *s, int y, int x) {
    WINDOW *win = newwin(3, 30, y, x);
    box(win, 0, 0);
    wattron(win, A_BOLD | A_ITALIC);
    mvwprintw(win, 1, 1, "%s", s);
    wattroff(win, A_BOLD | A_ITALIC);
    wrefresh(win);
}

/**
 * \fn void print_menu(WINDOW *win, int j, char *choices[], int size, char* title) 
 * \brief Fonction d'affichage d'un menu intéractif
 * \param[in] win Fenêtre où afficher
 * \param[in] j Element surligné
 * \param[in] choices Tableau qui contient les éléments du menu
 * \param[in] size Taille du menu (nombre d'éléments)
 * \param[in] title Titre du menu
 * */
void print_menu(WINDOW *win, int j, char *choices[], int size, char* title) 
{
    box(win, 0, 0);
    wattron(win, A_BOLD | A_ITALIC);
    mvwprintw(win, 1, 1, "%s", title);
    wattroff(win, A_BOLD | A_ITALIC);
    for (int i = 2; i <= size + 1; i++) 
    {
        if (i == j) 
        {
            wattron(win, A_REVERSE);
            mvwprintw(win, i, 1, "%s", choices[i - 2]);
            wattroff(win, A_REVERSE);
        } else mvwprintw(win, i, 1, "%s", choices[i - 2]);
    }
    wrefresh(win);
}

/**
 * \fn void delete_menu(WINDOW *win, int n)
 * \brief Fonction qui supprime les menus affichés
 * \param n Nombre d'éléments du menu
 * */
void delete_menu(WINDOW *win, int n)
{
    wborder(win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');

    for (size_t i = 0; i <= n; i++) 
    {
        mvwprintw(win, 1 + i, 1, "                                                                                           ");
    }
    wrefresh(win);
    delwin(win);
}

/**
 * \fn int menu(int a, char *choices[], int size, char* title)
 * \brief Fonction qui initialise un menu et son curseur, et surligne le choix de l'utilisateur
 * \param[in] a Choix de l'utilisateur
 * \param[in] choices Tableau qui contient les éléments du menu
 * \param[in] size Taille du menu (nombre d'éléments)
 * \param[in] title Titre du menu
 * \return Le choix de l'utilisateur
 * */
int menu(int a, char *choices[], int size, char* title)
{
    int choice = 0, highlight = a;
    char c;
    WINDOW *win = newwin(size + 3, 70, 0, 0);
    keypad(win, TRUE);

    print_menu(win, highlight, choices, size, title);

    while (1) {
        c = wgetch(win);
        switch (c) {
            /* Touche haut */
            case 3 :
                if (highlight == 2)
                    highlight = size + 1;
                else --highlight;
                break;

            /* Touche bas */
            case 2:
                if (highlight == size + 1)
                    highlight = 2;
                else ++highlight;
                break;

            /* Touche entrée */
            case 10:
                choice = highlight;
                break;

            /* Touche retour */
            case 127:
                    choice=1;
                    break;

            default :
                refresh();
                break;
        }

        print_menu(win, highlight, choices, size, title);
        if (choice != 0)
            break;
    }
    delete_menu(win, size + 1);
    return choice - 2;
}