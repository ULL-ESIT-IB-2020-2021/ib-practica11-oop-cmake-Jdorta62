/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica
  *
  * @file complejos.cc
  * @author Jose Dorta Luis alu0101414676@ull.edu.es
  * @date 07 Jan 2021
  * @brief programa que inicializa dos objetos complejos e imprime en pantalla la suma y resta de estos
  * @bug No hay bugs conocidos
  * @see https://www.varsitytutors.com/hotmath/hotmath_help/spanish/topics/operations-with-complex-numbers
  * @see https://en.wikipedia.org/wiki/Complex_number
  */

#include <iostream>
#include "complejo.cc"

/** @brief Funcion main
 *  @param[in] argc numero de parametros en linea de comandos.
 *  @param[in] argv char* que almacena los paramatros.
 */

int main () {

  Complejo complejo1{4,5};
  Complejo complejo2{7,-8};

  Complejo result = Add(complejo1, complejo2);
  result.Print();

  result = Sub(complejo1, complejo2);
  result.Print();
  

  return 0;
}