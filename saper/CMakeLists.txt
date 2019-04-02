cmake_minimum_required(VERSION 3.13)
project(saper)

set(CMAKE_CXX_STANDARD 11)

add_executable(saper main.cpp MinesweeperBoard.cpp MinesweeperBoard.h MSBoardTextView.cpp MSBoardTextView.h)

