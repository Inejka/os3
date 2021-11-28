cmake_minimum_required(VERSION 3.20)
project(os3 C)

set(CMAKE_C_STANDARD 99)

add_executable(os3 main.c page_manager.c page_manager.h segmentation_manager.c segmentation_manager.h virtual_address.h meme_manager.c meme_manager.h benchmark.c benchmark.h tester.c tester.h)
