#ifndef FECHA_FUNCIONES_CC
#define FECHA_FUNCIONES_CC

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "fechafunciones.h"

const std::string kHelpText = "Este programa calcula las N siguientes fechas a la ingresa por el \
usuario y las almacena en un fichero de texto. Modo de uso: ./fechas dd/mm/aa N fichero_salida.txt";

void Usage(int argc, char *argv[]) {
  if (argc != 4 && argc != 2) {
    std::cout << argv[0] << ": Faltan parámetros o son incorrectos." << std::endl;
    std::cout << "Pruebe " << argv[0] << " --help para más información" << std::endl;
    exit(EXIT_SUCCESS);
  }
  std::string parameter{argv[1]};
  if (parameter == "--help") {
    std::cout << kHelpText << std::endl;
    exit(EXIT_SUCCESS);
  } 
  if (argc != 4) {
    std::cout << argv[0] << ": Faltan parámetros" << std::endl;
    std::cout << "Pruebe " << argv[0] << " --help para más información" << std::endl;
    exit(EXIT_SUCCESS);
  }
}

class Fecha {
 public:
  int day_{};
  int month_{};
  int year_{};

  bool IsLeapYear() {
    bool isleapyear{0};
    if (year_ % 4 == 0 && year_ % 100 != 0){
      isleapyear = 1;
    }
    if (year_ % 4 == 0 && year_ % 100 == 0 && year_ % 400 == 0) {
      isleapyear = 1;
    }
    return isleapyear;
  }
  
  int GetDay() {return day_;}
  int GetMonth() {return month_;}
  int GetYear() {return year_;}

  void Print() {
    std::cout << day_ << "/" << month_ << "/" << year_ << std::endl;
  }

  friend void DateGeneratorFunc(Fecha &today, const int &repetitions, std::string DatesData);
};

void Month31(int &day, int &month, int &year) {
  if (day < 31) {
    day += 1;
    return;
    }
  if (month == 12 && day == 31) {
    day = 1;
    month = 1;
    year += 1;
    return;
    }
  if (day == 31) {
    day = 1;
    month += 1;
    return;
    }    
}

void Month30(int &day, int &month) {
  if (day < 30) {
    day += 1;
    return;
  }
  if (day == 30) {
    day = 1;
    month += 1;
    return;
  } 
}

void FebruaryFunc(int &day, int &month, bool &esbisiesto) {
  int februarylimit = 28;
  if (esbisiesto == 1) {
      februarylimit = 29;
    }
  if (day > februarylimit) {
    std::cout << "Error: invalid data." << std::endl;
    exit(EXIT_SUCCESS);
  }
  if (day < februarylimit) {
    day += 1;
    return;
  }
  if (day == februarylimit) {
    day = 1;
    month += 1;
    return;
  } 
}

void DateGeneratorFunc(Fecha &today, const int &repetitions, std::string docname) {

  int day{today.day_};
  int month{today.month_};
  int &year{today.year_};
  std::ofstream DatesData (docname, std::ios::out);
  
  DatesData << day << "/" << month << "/" << year << "\n"; 

  for (int i{0}; i < repetitions; ++i) {
    bool esbisiesto{today.IsLeapYear()};

    switch (month) {
      case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        if (day > 31) {
          std::cout << "Error: invalid data." << std::endl;
          exit(EXIT_SUCCESS);
        }
        Month31(day, month, year);
        break;

      case 4: case 6: case 9: case 11:
        if (day > 30) {
          std::cout << "Error: invalid data." << std::endl;
          exit(EXIT_SUCCESS);
        }
        Month30 (day, month);
        break;

      case 2:
        FebruaryFunc (day, month, esbisiesto); 
        break;
        
      default:
        std::cout << "Error: invalid data" << std::endl;
        exit(EXIT_SUCCESS);
    }
    DatesData << day << "/" << month << "/" << year << "\n";
  }

}

std::string DayConverter(std::string fecha) {
  
  std::string day;
  int counter_slash{0};
  
  for (int i{0}; i < fecha.length(); ++i) {
    
    if (fecha[i] == '/') {
      counter_slash += 1;
    }
    if (fecha[i] != '/' && counter_slash == 0) {
      day += fecha[i];
    } 
  }
  return day;
}

std::string MonthConverter(std::string fecha) {

  std::string month;
  int counter_slash{0};
  
  for (int i{0}; i < fecha.length(); ++i) {
    
    if (fecha[i] == '/') {
      counter_slash += 1;
    }
    if (fecha[i] != '/' && counter_slash == 1) {
      month += fecha[i];
    }
  
  }
  return month;
}

std::string YearConverter(std::string fecha) {

  std::string year;
  int counter_slash{0};
  
  for (int i{0}; i < fecha.length(); ++i) {
    
    if (fecha[i] == '/') {
      counter_slash += 1;
    }
    if (fecha[i] != '/' && counter_slash == 2) {
      year += fecha[i];
    }
  }
  return year;
}

int IntegerConverter(std::string mystring) {
  int integer{stoi(mystring)};
  return integer;
}

#endif