#include <iostream>
#include <fstream>
#include <string>
#include "racional.cc" 
#include "funciones_racional.h"


int main(int argc, char * argv[]) {

  Usage(argc, argv);
  
  std::string name_file_in = argv[1];
  std::string name_file_out = argv[2];

  std::ifstream textfile;

  PrinterOperationFunction(textfile, name_file_in, name_file_out);
  
}
