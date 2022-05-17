cmake_minimum_required(VERSION 3.22)
project(sys C)

set(CMAKE_C_STANDARD 99)

add_executable(sys main.c register_Head.h login_Head.h input_Head.h sort_Head.h output_Head.h find_Head.h revise_Head.h struct_Head.h menu_Head.h delete_Head.h adminGet_Head.h file_init_Head.h file_Head.h check_Head.h data_wr_Head.h)
