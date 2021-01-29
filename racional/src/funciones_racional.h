/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica
  *
  * @file funciones_racionale.h
  * @author Jose Dorta Luis alu0101414676@ull.edu.es
  * @date 06 Jan 2021
  * @brief El programa recibe por linea de comando 2 nombres de 2 ficheros diferentes .txt. El primero ingresado será
  *        el fichero que contendrá parejas de numeros racionales en un formato específico (a/b c/d) y que el programa
  *        leerá para imprimir, en el 2do fichero ingresado, las operaciones básicas entre dichas parejas
  * @bug si no se deja un espacio después de introducir el 2do racional, el programa no funciona correctamente.
  * 
  */

#ifndef FUNCIONES_RACIONAL_H
#define FUNCIONES_RACIONAL_H

void Usage(int argc,char * argv[]);
void PrinterOperationFunction(std::ifstream &textfile, const std::string &name_file_in, const std::string &name_file_out);

#endif