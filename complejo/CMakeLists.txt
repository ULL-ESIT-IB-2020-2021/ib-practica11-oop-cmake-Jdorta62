# Universidad de La Laguna
# Escuela Superior de Ingeniería y Tecnología
# Grado en Ingeniería Informática
# Informática Básica
#
# @author Jose Dorta
# @date 4 de enero del 2020
# @brief CMakeLists.txt para programa Complejo
# CMakeLists.txt defines the whole build
# CMake reads CMakeLists.txt sequentially
#
# Build process:
#   1. cd <project_folder>
#   2. mkdir build
#   3. cd build
#   4. cmake ..
#   5. make

cmake_minimum_required(VERSION 3.1)

project(complejo
    VERSION 1.0
    DESCRIPTION "Cmake for complejo program"
    LANGUAGES CXX)

add_executable(complejo
    src/complejo.cc
    src/complejo.h
    src/complejos.cc)

target_compile_features(complejo PRIVATE cxx_std_14)

target_compile_options(complejo PRIVATE -Wall -Wextra -Wpedantic)
