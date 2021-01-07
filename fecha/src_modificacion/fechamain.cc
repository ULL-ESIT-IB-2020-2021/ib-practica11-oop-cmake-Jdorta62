#include <iostream>
#include <string>
#include "fechafunciones.h"

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