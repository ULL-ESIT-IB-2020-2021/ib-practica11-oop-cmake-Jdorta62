# Universidad de La Laguna
# Escuela Superior de Ingeniería y Tecnología
# Grado en Ingeniería Informática
# Informática Básica
#
# @author Jose Dorta
# @date 3 de enero del 2020
# @brief CMakeLists.txt para programa Fecha
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

project(fecha
    VERSION 1.0
    DESCRIPTION "Cmake for fecha program"
    LANGUAGES CXX)

add_executable(fecha
    src/fechafunciones.cc
    src/fechafunciones.h
    src/fechamain.cc)

target_compile_features(fecha PRIVATE cxx_std_14)

target_compile_options(fecha PRIVATE -Wall -Wextra -Wpedantic)