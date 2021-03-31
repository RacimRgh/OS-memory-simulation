cmake_minimum_required(VERSION 3.13)
project(Memoire)
set(CMAKE_C_STANDARD 99)

# Fichiers source
set(SRCS main.c src/menu.c src/memory.c src/process.c src/file_proc.c src/execution_modes.c)
# Fichers en-tête
set(HEADERS headers/menu.h headers/memory.h headers/process.h headers/file_proc.h headers/execution_modes.h)
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
  set(DOXYGEN_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/docs")
  # this target will only be built if specifically asked to.
  # run "make api-docs" to create the doxygen documentation
  doxygen_add_docs(
    docs
    ${PROJECT_SOURCE_DIR}
    COMMENT "Generate API-documents for NoteSearch."
  )
endif(DOXYGEN_FOUND)

# pthreads
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

#Put the executable in the same folder as the file (not in build/)
set(EXECUTABLE_OUTPUT_PATH ../)
include_directories(${CURSES_INCLUDE_DIR})
add_executable(Memoire ${SRCS} ${HEADERS})
target_link_libraries(Memoire PRIVATE Threads::Threads ${CURSES_LIBRARIES})