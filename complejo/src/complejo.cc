/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica
  *
  * @file complejo.cc
  * @author Jose Dorta Luis alu0101414676@ull.edu.es
  * @date 07 Jan 2021
  * @brief programa que inicializa dos objetos complejos e imprime en pantalla la suma y resta de estos
  * @bug No hay bugs conocidos
  * @see https://www.varsitytutors.com/hotmath/hotmath_help/spanish/topics/operations-with-complex-numbers
  * @see https://en.wikipedia.org/wiki/Complex_number
  */

#include "complejo.h"
#include <iostream>


/**
 * @brief constructor de la clase complejo.
 * @param real_part objeto int referente a la parte real de un numero complejo.
 * @param imaginary_part objeto int referente a la parte real de un numero complejo.
*/

Complejo::Complejo(int real_part, int imaginary_part) {
  real_part_ = real_part;
  imaginary_part_ = imaginary_part;
}

/**
 * @brief imprime en pantalla objetos Complejo.
*/

void Complejo::Print() {

  std::cout << "(" << real_part_ << ") + (" << imaginary_part_ << ")i" << std::endl; 

}

/**
 * @brief realiza la suma de objetos complejos.
 * @param complex2 2do sumando.
*/

Complejo Add(Complejo &complex1, Complejo &complex2) {

  int realpart{complex1.real_part_ + complex2.real_part_};
  int imaginarypart{complex1.imaginary_part_ + complex2.imaginary_part_};
  Complejo result{realpart, imaginarypart};
  return result;

}

/**
 * @brief realiza la suma de objetos complejos.
 * @param complex2 sustrendo de la resta
*/

Complejo Sub(Complejo &complex1, Complejo &complex2) {

  int realpart{complex1.real_part_ - complex2.real_part_};
  int imaginarypart{complex1.imaginary_part_ - complex2.imaginary_part_};
  Complejo result{realpart, imaginarypart};
  return result;

}