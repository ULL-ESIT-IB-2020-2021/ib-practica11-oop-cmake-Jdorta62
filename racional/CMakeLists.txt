# Universidad de La Laguna
# Escuela Superior de Ingeniería y Tecnología
# Grado en Ingeniería Informática
# Informática Básica
#
# @author Jose Dorta
# @date 7 de enero del 2020
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

project(racionales
    VERSION 1.0
    DESCRIPTION "Cmake for complejo program"
    LANGUAGES CXX)

add_executable(racionales
    src/racional.cc
    src/racional.h
    src/funciones_racional.cc
    src/funciones_racional.h
    src/racionales.cc)

target_compile_features(racionales PRIVATE cxx_std_14)

#target_compile_options(racionales PRIVATE)