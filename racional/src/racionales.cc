/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica
  *
  * @file racionales.cc
  * @author Jose Dorta Luis alu0101414676@ull.edu.es
  * @date 06 Jan 2021
  * @brief El programa recibe por linea de comando 2 nombres de 2 ficheros diferentes .txt. El primero ingresado será
  *        el fichero que contendrá parejas de numeros racionales en un formato específico (a/b c/d) y que el programa
  *        leerá para imprimir, en el 2do fichero ingresado, las operaciones básicas entre dichas parejas
  * @bug si no se deja un espacio después de introducir el 2do racional, el programa no funciona correctamente.
  * 
  */

#include <iostream>
#include <fstream>
#include <string>
#include "racional.h" 
#include "funciones_racional.h"

/** @brief Funcion main
 *  @param[in] argc numero de parametros en linea de comandos.
 *  @param[in] argv char* que almacena los paramatros.
 */

int main(int argc, char * argv[]) {

  Usage(argc, argv);
  
  std::string name_file_in = argv[1];
  std::string name_file_out = argv[2];

  std::ifstream textfile;

  PrinterOperationFunction(textfile, name_file_in, name_file_out);
  
}
