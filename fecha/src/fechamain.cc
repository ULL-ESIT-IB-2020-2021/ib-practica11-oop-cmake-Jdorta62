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

#include <iostream>
#include <string>
#include "fechafunciones.cc"

/** @brief Funcion main
 *  @param[in] argc numero de parametros en linea de comandos.
 *  @param[in] argv char* que almacena los paramatros.
 */

int main(int argc, char* argv[]) {
  
  Usage(argc, argv);
  std::string fecha{argv[1]};
  std::string daystring{DayConverter(fecha)}, monthstring{MonthConverter(fecha)}, yearstring{YearConverter(fecha)};
  
  int day{IntegerConverter(daystring)};
  int month{IntegerConverter(monthstring)};
  int year{IntegerConverter(yearstring)};

  std::string docname{argv[3]};
  
  std::string repetitions_string{argv[2]};
  int const krepetitions{IntegerConverter(repetitions_string)};

  Fecha firstdate{day, month, year};

  DateGeneratorFunc(firstdate, krepetitions, docname);

  return 0;
}