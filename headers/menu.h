/**
 * @file menu.h
 * @brief Fichier en tête qui décrit les fonctions d'affichage de menu
 * 
 * Ce fichier contient les prototypes qui affichent les menus grâce à la librairie curses.h
 * Il contient aussi l'ensemble des messages d'affichage de ces menus + les messages d'erreurs et de succès.
*/

#ifndef MENU
#define MENU
#include <curses.h>

void message(char *s, int y, int x);
void print_menu(WINDOW *win, int j, char *choices[], int size, char* title);
void delete_menu(WINDOW *win, int n);
int menu(int a, char *choices[], int size, char* title);
void del_message();

#endif