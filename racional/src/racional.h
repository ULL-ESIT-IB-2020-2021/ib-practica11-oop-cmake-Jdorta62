/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica
  *
  * @file racional.h
  * @author Jose Dorta Luis alu0101414676@ull.edu.es
  * @date 06 Jan 2021
  * @brief clase Racional que permite construir, operar y leer objetos del tipo Racional
  * @bug No hay bugs conocidos
  * 
  */

#ifndef RACIONAL_H
#define RACIONAL_H

class Racional {
 private:
  int numerator_;
  int denominator_;

 public:
  Racional(int numerator, int denominator);

  void Print();
  void WriteOperations(const std::string &filename, const Racional &racional2);
  Racional Add(const Racional &racional2);
  Racional Sub(const Racional &racional2);
  Racional Multiplication(const Racional &racional2);
  Racional Division(const Racional &racional2);
};

#endif