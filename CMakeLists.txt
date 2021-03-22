cmake_minimum_required(VERSION 3.12)
project(Memoire)
set(CMAKE_C_STANDARD 99)
# Fichiers source
set(SRCS main.c src/menu.c src/memory.c src/process.c)
# Fichers en-tête
set(HEADERS headers/menu.h headers/memory.h headers/process.h)
# Librarie ncurses pour l'IHM graphique
#find_package("/usr/lib/libncurses.a")
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
add_executable(Memoire ${SRCS} ${HEADERS})
target_link_libraries(Memoire ${CURSES_LIBRARIES})
