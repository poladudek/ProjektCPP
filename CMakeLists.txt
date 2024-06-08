
cmake_minimum_required(VERSION 3.0)
project(SudokuSolver)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

set(SOURCE_FILES
    main.cpp
    SudokuGrid.cpp
    SudokuApp.cpp
    Buttons.cpp)

set(HEADER_FILES
    SudokuGrid.h
    SudokuApp.h
    Buttons.h)


add_executable(sudoku ${SOURCE_FILES} ${HEADER_FILES})
target_link_libraries(sudoku sfml-graphics sfml-window sfml-system)
