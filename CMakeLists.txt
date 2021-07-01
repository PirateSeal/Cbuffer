cmake_minimum_required(VERSION 3.19)
project(Cbuffer C)

set(CMAKE_C_STANDARD 99)

add_executable(Cbuffer main.c buffer.c utils.c lexer.c lexer.h parser.c parser.h ast.c ast.h symbols.c symbols.h projet.c)
