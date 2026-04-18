cmake_minimum_required(VERSION 4.2)
project(power_analyser C)

set(CMAKE_C_STANDARD 99)

add_executable(power_analyser main.c
        io.c
        io.h
        waveform.c
        waveform.h)
