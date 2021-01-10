#include <iostream>
#include <string>

void Usage(int argc,char * argv[]) {

  if (argc == 1) {
    std::cout << "./racionales -- Números Racionales \n" << "Modo de uso: ./racionales \
    fichero_entrada fichero_salida \n" << "Pruebe ./racionales --help para más información" << std::endl;
    exit(EXIT_SUCCESS);
  }
  
  std::string parameter{argv[1]};
  if (parameter == "--help") {
    std::cout << "/racionales -- Números Racionales" << std::endl;
    std::cout << "Modo de uso: ./racionales fichero_entrada fichero_salida" << std::endl;
    std::cout << "fichero_entrada: Fichero de texto conteniendo líneas con un par de números racionales: `a/b c/d ` con un espacio después de ingresar cada racional" << std::endl;
    std::cout << "fichero_salida:  Fichero de texto que contendrá líneas con las operaciones realizadas: `a/b + c/d = n/m`" << std::endl;
    exit(EXIT_SUCCESS);
  }

}

void PrinterOperationFunction(std::ifstream &textfile, const std::string &name_file_in, const std::string &name_file_out) {
textfile.open(name_file_in, std::ios::in);

  while(!textfile.eof()) {

    std::string file_reader;
    std::getline(textfile, file_reader);
    int slash_counter{0};
    int blank_space{0};
    int numerator;
    int denominator{1};
    int insurance{0};
    int string_size =  file_reader.length();
    std::string temporal_variable;
    Racional racional1{0,0};
    

    for (int i{0};  string_size >= i; ++i) {

      if (file_reader[i] == '/' || file_reader[i] == ' ') {

        if (file_reader[i] == '/' || (file_reader[i] == ' ' && slash_counter == 0)) {
          numerator = stoi(temporal_variable);
          if (file_reader[i] == '/') {
              slash_counter = 1;
          }
          temporal_variable = "";
          
          if (file_reader[i] == ' ') {
            blank_space += 1;
          } 
        }
        if ((file_reader[i] == ' ' && slash_counter == 1)) {
          denominator = stoi(temporal_variable);
          temporal_variable = "";
          if (file_reader [i] == ' ') {
            blank_space += 1;
          }
        }
      } else {

        temporal_variable += file_reader[i];
    
      }
      if (blank_space != 0 && insurance == 0) {
        if (denominator == 0) {
            std::cerr << "Error: denominator not valid" << std::endl;
            exit(EXIT_SUCCESS);
        }
        racional1 = Racional(numerator, denominator);
        blank_space = 0;
        insurance = 1;
      }
    }

    if (denominator == 0) {
      std::cerr << "Error: denominator not valid" << std::endl;
      exit(EXIT_SUCCESS);
    }

    Racional racional2 = Racional(numerator,denominator);
    racional1.WriteOperations(name_file_out, racional2);

  } 
  textfile.close();
}