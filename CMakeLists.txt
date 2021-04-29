cmake_minimum_required(VERSION 3.17)
project(twt_spd)

set(CMAKE_CXX_STANDARD 17)

add_executable(twt_spd main.cpp Data.h RandomNumberGenerator.cpp RandomNumberGenerator.h Algorithms.cpp Algorithms.h)