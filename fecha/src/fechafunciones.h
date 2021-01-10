/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica
  *
  * @file fechamain.cc
  * @author Jose Dorta Luis alu0101414676@ull.edu.es
  * @date 06 Jan 2021
  * @brief El programa recibe por linea de comando: una fecha en el formato dd/mm/aa, un numero natural N, y el
  *        nombre de un fichero de texto. El programa almacenará en el fichero de texto las N sigueintes fechas
  *        a la ingresada. 
  * @bug No hay bugs conocidos
  * @see
  */

#ifndef FECHA_FUNCIONES_H
#define FECHA_FUNCIONES_H

#include "fechafunciones.cc"

class Fecha;

void Usage(int argc, char *argv[]);

void Month31(int &day, int &month, int &year);

void Month30(int &day, int &month);

void FebruaryFunc(int &day, int &month, bool &esbisiesto);

void DateGeneratorFunc(Fecha &today, const int &repetitions, std::string DatesData);

std::string DayConverter(std::string fecha);

std::string MonthConverter(std::string fecha);

std::string YearConverter(std::string fecha);

int IntegerConverter(std::string mystring);

#endif