cmake_minimum_required(VERSION 3.23)
project(LexicalAnalyzerGenerator)

set(CMAKE_CXX_STANDARD 14)

add_executable(LexicalAnalyzerGenerator main.cpp MinimizedDfa.cpp MinimizedDfa.h)
