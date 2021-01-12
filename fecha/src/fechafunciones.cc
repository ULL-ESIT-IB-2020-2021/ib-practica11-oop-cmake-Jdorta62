/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica
  *
  * @file fechafunciones.cc
  * @author Jose Dorta Luis alu0101414676@ull.edu.es
  * @date 06 Jan 2021
  * @brief El programa recibe por linea de comando: una fecha en el formato dd/mm/aa, un numero natural N, y el
  *        nombre de un fichero de texto. El programa almacenará en el fichero de texto las N sigueintes fechas
  *        a la ingresada. 
  * @bug No hay bugs conocidos
  * @see Metodo para saber si un año es bisiesto: https://docs.microsoft.com/es-es/office/troubleshoot/excel/determine-a-leap-year
  */

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "fechafunciones.h"

const std::string kHelpText = "Este programa calcula las N siguientes fechas a la ingresa por el \
usuario y las almacena en un fichero de texto. Modo de uso: ./fechas dd/mm/aa N fichero_salida.txt";
 
/**
 * @brief indica al usuario como usar el programa. Una vez mostrado mensaje por pantalla, finaliza ejecución.
 * @param argc numero de comandos pasados por linea de comando.
 * @param argv vector char* que contiene los parametros .
*/

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

/**
 * @brief Clase fecha que permite crear objetos fecha. Además puede saber si un año es bisiesto
 *        y puede generar N fechas posteriores
*/

Fecha::Fecha (int day, int month, int year) {
  day_ = day;
  month_ = month;
  year_ = year;
}

bool Fecha::IsLeapYear() {
  bool isleapyear{0};
  if (year_ % 4 == 0 && year_ % 100 != 0){
    isleapyear = 1;
  }
  if (year_ % 4 == 0 && year_ % 100 == 0 && year_ % 400 == 0) {
    isleapyear = 1;
  }
  return isleapyear;
}

int Fecha::GetDay() {return day_;}
int Fecha::GetMonth() {return month_;}
int Fecha::GetYear() {return year_;}

void Fecha::Print() {
  std::cout << day_ << "/" << month_ << "/" << year_ << std::endl;
}




/**
 * @brief soporta a la función DateGeratorFunc. Esta función entra en escena cuando el mes en el que se esta calculando
 *        los días próximos tiene 31 dias
 * @param day si day != 31, el programa sumará en una unidad a dicha variable. Si day == 31 && month != 12, la funcion
 *        reinicará la variable day (day = 1) y aumentará en una unidad el mes. Si day == 31 && month == 12, reiniciará
 *        la variable day y month a 1 y aumentará en una unidad el año
 * @param month
 * @param year 
*/

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

/**
 * @brief soporta a la función DateGeratorFunc. Esta función entra en escena cuando el mes en el que se esta calculando
 *        los días próximos tiene 30 dias
 * @param day si day != 30, el programa sumará en una unidad a dicha variable. Si day == 30, la funcion reinicará la 
 *        variable day (day = 1) y aumentará en una unidad el mes.
 * @param month
*/

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

/**
 * @brief soporta a la función DateGeratorFunc. Esta función entra en escena cuando el mes en el que se esta calculando
 *        los días próximos es febrero o el 
 * @param day si el año es bisiesto, febrero tendrá 29 días. En caso contrario tendrá 28 dias. Cuando day iguala al
 *        februarylimit, se reinicia los dias y se aumenta month en una unidad.
 * @param esbisiesto indicara si februarylimit será de 28 o 29 dias.
*/

void FebruaryFunc(int &day, int &month, bool &esbisiesto) {
  int februarylimit = 28;
  if (esbisiesto == 1) {
      februarylimit = 29;
    }
  if (day > februarylimit || day < 1) {
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

/**
 * @brief genera N fechas posteriores a la ingresada y lo guarda en un fichero .txt.
 * @param today objeto de la clase fecha del cual imprime en un documento txt las N fechas posteriores.
 * @param repetitions la cantidad de veces que se repetirá el bucle. Una iteracion del bucle es una fecha posterior.
 * @param docname nombre del fichero txt de salida
*/

void DateGeneratorFunc(Fecha &today, const int &repetitions, std::string docname) {

  int day{today.day_};
  int month{today.month_};
  int &year{today.year_};
  std::ofstream DatesData (docname, std::ios::out);
  
  DatesData << day << "/" << month << "/" << year << "\n"; 

  for (int i{0}; i < repetitions; ++i) {
    bool esbisiesto{today.IsLeapYear()};
    if (year < 1) {
      std::cout << "Error: invalid data." << std::endl;
      exit(EXIT_SUCCESS);
    }
    switch (month) {
      case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        if (day > 31 || day < 1) {
          std::cout << "Error: invalid data." << std::endl;
          exit(EXIT_SUCCESS);
        }
        Month31(day, month, year);
        break;

      case 4: case 6: case 9: case 11:
        if (day > 30 || day < 1) {
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

/**
 * @brief funcion que devuelve una string que contiene unicamente el dia del string fecha
 * @param fecha un objeto de la clase string que sigue el siguiente formato dd/mm/aa del cual se quiere obtener
 * el dia
*/

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

/**
 * @brief funcion que devuelve una string que contiene unicamente el mes del string fecha
 * @param fecha un objeto de la clase string que sigue el siguiente formato dd/mm/aa del cual se quiere obtener
 * únicamente el mes
*/

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

/**
 * @brief funcion que devuelve una string que contiene unicamente el año del string fecha
 * @param fecha un objeto de la clase string que sigue el siguiente formato dd/mm/aa del cual se quiere obtener
 * únicamente el año de la misma
*/

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

/**
 * @brief funcion que transforma un un objeto string en un objeto int
 * @param mystring cadena de caracteres numericos que se quiere transformar en un objeto int
*/

int IntegerConverter(std::string mystring) {
  int integer{stoi(mystring)};
  return integer;
}
