/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica
  *
  * @file racional.cc
  * @author Jose Dorta Luis alu0101414676@ull.edu.es
  * @date 06 Jan 2021
  * @brief clase Racional que permite construir, operar y leer objetos del tipo Racional
  * @bug No hay bugs conocidos
  * 
  */

#include <iostream>
#include <fstream>
#include <string>
#include "racional.h"

/**
 * @brief constructor de la clase Racional
 * @param numerator objeto int necesario para inicializar objeto Racional
 * @param denominator objeto int que en caso de no indicarse, ya esta inicializado.
*/

Racional::Racional(int numerator, int denominator=1) {
  numerator_ = numerator;
  denominator_ = denominator;
}

/**
 * @brief método que permite imprimir en pantalla objetos Racionales.
*/

void Racional::Print() {
  std::cout << numerator_ << "/" << denominator_ << std::endl;
}

/**
 * @brief metodo que escribe en un fichero .txt de salida las operaciones básicas entre 2 objetos racionales.
 * @param filename nombre del fichero de salida.
 * @param racional2 racional con el que se va a operar.
*/

void Racional::WriteOperations(const std::string &filename,  const Racional &racional2) {
  
  std::ofstream file;
  file.open(filename, std::ios::out | std::ios::app);
  Racional racional1{numerator_ , denominator_};
  Racional result = racional1.Add(racional2);
  file << numerator_ << "/" << denominator_  << " + " << racional2.numerator_ << "/" << racional2.denominator_ << " = " << result.numerator_ << "/" << result.denominator_ << std::endl;
  
  result = racional1.Sub(racional2);
  file << numerator_ << "/" << denominator_  << " - " << racional2.numerator_ << "/" << racional2.denominator_ << " = " << result.numerator_ << "/" << result.denominator_ << std::endl;
  
  result = racional1.Multiplication(racional2);
  file << numerator_ << "/" << denominator_  << " * " << racional2.numerator_ << "/" << racional2.denominator_ << " = " << result.numerator_ << "/" << result.denominator_ << std::endl;

  result = racional1.Division(racional2);
  file << numerator_ << "/" << denominator_  << " / " << racional2.numerator_ << "/" << racional2.denominator_ << " = " << result.numerator_ << "/" << result.denominator_ << std::endl << std::endl;
  file.close();
}

/**
 * @brief realiza la suma de objetos racionales.
 * @param racional2 2do sumando.
*/

Racional Racional::Add(const Racional &racional2) {
  int denominator{denominator_ * racional2.denominator_};
  int numerator{(numerator_*(denominator/denominator_)) + (racional2.numerator_*(denominator/racional2.denominator_))};
  Racional result = Racional(numerator, denominator);
  return result;
}

/**
 * @brief realiza la resta de objetos racionales.
 * @param racional2 sustraendo de la operacion.
*/

Racional Racional::Sub(const Racional &racional2) {
  int denominator{denominator_ * racional2.denominator_};
  int numerator{(numerator_*(denominator/denominator_)) - (racional2.numerator_*(denominator/racional2.denominator_))};
  Racional result = Racional(numerator, denominator);
  return result;
}

/**
 * @brief realiza la multiplicación de objetos racionales.
 * @param racional2 2do factor de la operación
*/

Racional Racional::Multiplication(const Racional &racional2) {
  int numerator{numerator_ * racional2.numerator_};
  int denominator{denominator_ * racional2.denominator_};
  Racional result = Racional(numerator, denominator);
  return result;
}

/**
 * @brief realiza la división de objetos racionales
 * @param racional2 divisor de la división
*/

Racional Racional::Division(const Racional &racional2) {
  int numerator{numerator_ * racional2.denominator_};
  int denominator{denominator_ * racional2.numerator_};
  Racional result = Racional(numerator, denominator);
  return result;
}