#ifndef MENU
#define MENU
#include <curses.h>

#define SIZE_CHOICES 3

void message(char *s, int x, int y);
void print_menu(WINDOW *win, int j, char *choices[], int size, char* title);
void delete_menu(WINDOW *win, int n);
int menu(int a, char *choices[], int size, char* title);
void del_message();

#endif