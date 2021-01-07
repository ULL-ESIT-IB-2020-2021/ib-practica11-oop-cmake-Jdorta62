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