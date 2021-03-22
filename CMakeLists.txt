cmake_minimum_required(VERSION 3.12)
project(Memoire)
set(CMAKE_C_STANDARD 99)
# Fichiers source
set(SRCS main.c src/menu.c src/memory.c src/process.c)
# Fichers en-tête
set(HEADERS headers/menu.h headers/memory.h headers/process.h)
# Librarie ncurses pour l'IHM graphique
find_package(Curses REQUIRED)
# Configuration de doxygen
# look for Doxygen package
find_package(Doxygen)

if(DOXYGEN_FOUND)
  # exclude sqlite code
  set(DOXYGEN_EXCLUDE_PATTERNS
        */sqlite3/*
  )

  # doxygen settings can be set here, prefixed with "DOXYGEN_"
  set(DOXYGEN_SOURCE_BROWSER YES)
  set(DOXYGEN_EXTRACT_PRIVATE YES)
  set(DOXYGEN_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/api-docs")

  # this target will only be built if specifically asked to.
  # run "make api-docs" to create the doxygen documentation
  doxygen_add_docs(
    api-docs
    ${PROJECT_SOURCE_DIR}
    COMMENT "Generate API-documents for NoteSearch."
  )
endif(DOXYGEN_FOUND)

include_directories(${CURSES_INCLUDE_DIR})
add_executable(Memoire ${SRCS} ${HEADERS})
target_link_libraries(Memoire ${CURSES_LIBRARIES})
