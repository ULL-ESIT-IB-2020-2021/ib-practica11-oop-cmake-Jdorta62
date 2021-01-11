/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica
  *
  * @file complejo.h
  * @author Jose Dorta Luis alu0101414676@ull.edu.es
  * @date 07 Jan 2021
  * @brief programa que inicializa dos objetos complejos e imprime en pantalla la suma y resta de estos
  * @bug No hay bugs conocidos
  * @see https://www.varsitytutors.com/hotmath/hotmath_help/spanish/topics/operations-with-complex-numbers
  * @see https://en.wikipedia.org/wiki/Complex_number
  */

#ifndef COMPLEJO_H
#define COMPLEJO_H

class Complejo {
 private:
    int real_part_{};
    int imaginary_part_{};

 public:
    
    Complejo(int, int);

    void Print();
    friend Complejo Add(Complejo &complex1, Complejo &complex2);
    friend Complejo Sub(Complejo &complex1, Complejo &complex2);
};

#endif