cmake_minimum_required(VERSION 3.10)
project(IDI C)

set(CMAKE_C_STANDARD 99)

add_executable(UI UI.c classificationStatistics.c classificationStatistics.h interfacelib.c interfacelib.h dao.c dao.h)
