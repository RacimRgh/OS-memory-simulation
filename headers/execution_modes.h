#ifndef GUI_ALLOC_HEADER
#define GUI_ALLOC_HEADER
#include "menu.h"
#include "memory.h"
#include "process.h"
#include "file_proc.h"
#include <stdio.h>
#include <string.h>

#define SIZE_MAIN_MENU 9
#define SIZE_FIT_MENU 3
#define SIZE_METHOD_MENU 3

extern char *allocation_method[];

extern char *main_menu[];

extern char *fit_menu[];

void interactive_menu();
void config_file(char* file); 

#endif