#include "../headers/menu.h"



//supprime tout ce qui se trouve a l'ecrans
void del_message() {
    for (size_t i = 0; i <= 250; i++) {
        mvprintw(i, 0, "                                                                                                                                             ");
    }
}

//affiche un carrée textuelle decrivant une alarme
void message(char *s, int x, int y) {
    WINDOW *win = newwin(3, 30, y, x);
    box(win, 0, 0);
    wattron(win, A_BOLD | A_ITALIC);
    mvwprintw(win, 1, 1, "%s", s);
    wattroff(win, A_BOLD | A_ITALIC);
    wrefresh(win);
}

//affiche un menu la selection en surlignée
void print_menu(WINDOW *win, int j, char *choices[], int size, char* title) 
{
    box(win, 0, 0);
    wattron(win, A_BOLD | A_ITALIC);
    mvwprintw(win, 1, 1, "%s", title);
    wattroff(win, A_BOLD | A_ITALIC);
    for (int i = 2; i <= size + 1; i++) {
        if (i == j) {
            wattron(win, A_REVERSE);
            mvwprintw(win, i, 1, "%s", choices[i - 2]);
            wattroff(win, A_REVERSE);
        } else mvwprintw(win, i, 1, "%s", choices[i - 2]);
    }
    wrefresh(win);
}

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
            //code pour la touche bas
            case 3 :
                if (highlight == 2)
                    highlight = size + 1;
                else --highlight;
                break;
            //code pour la touche bas
            case 2:
                if (highlight == size + 1)
                    highlight = 2;
                else ++highlight;
                break;
            //code pour la touche entrée
            case 10:
                choice = highlight;
                break;
            //code pour la touche retour
            case 127:
                    choice=1;
                    break;
            default :
                //mvprintw(10, 0, "Charcter pressed is = %3d Hopefully it can be printed as '%c'", c, c);
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