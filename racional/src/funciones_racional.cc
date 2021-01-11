/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica
  *
  * @file funciones_racionale.cc
  * @author Jose Dorta Luis alu0101414676@ull.edu.es
  * @date 06 Jan 2021
  * @brief El programa recibe por linea de comando 2 nombres de 2 ficheros diferentes .txt. El primero ingresado será
  *        el fichero que contendrá parejas de numeros racionales en un formato específico (a/b c/d ) y que el programa
  *        leerá para imprimir, en el 2do fichero ingresado, las operaciones básicas entre dichas parejas
  * @bug si no se deja un espacio después de introducir el 2do racional, el programa no funciona correctamente.
  * 
  */

#include <iostream>
#include <string>


/**
 * @brief indica al usuario como usar el programa. Una vez mostrado mensaje por pantalla, finaliza ejecución.
 * @param argc numero de comandos pasados por linea de comando.
 * @param argv vector char* que contiene los parametros .
*/

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


/**
 * @brief Es una función void que lo que hace es leer el fichero de entrada, una linea por cada iteración del bucle while.
 *        Al principio de cada iteracion se crea un objeto string (std::string file_reader;) que almacena los caracteres de dicha línea. Tambien se 
 *        crea otra string (std::string temporal_variable;) en la cual se irán alojando los caracteres importantes (numerador y denominador), que
 *        están dentro de la string "file_reader", para despues transformarlo en un bojeto entero. Una vez obtenido los 2 racionales y creados
 *        ambos objetos racionales, se procede a imprimir las operaciones y el resultado en el fichero de salida. 
 * @param textfile objeto ifstream 
 * @param name_file_in string con el nombre del fichero de entrada.
 * @param name_file_out string con el nombre del fichero de salida.
 */

void PrinterOperationFunction(std::ifstream &textfile, const std::string &name_file_in, const std::string &name_file_out) {
textfile.open(name_file_in, std::ios::in);

  while(!textfile.eof()) {

    std::string file_reader;
    std::getline(textfile, file_reader);
    int slash_counter{0};
    int blank_space{0};                       ///cuenta los espacios en blancos. Si se lee un espacio indica la finalización de un racional
    int numerator;                            ///almacenará temporalmente el valor del numerador leido en el fichero. Permite construir los objetos de la clase Racional.
    int denominator{1};                       ///almacenará temporalmente el valor del denomindor leido en el fichero. Permite construir los objetos de la clase Racional. Esta inicializado en 1 en caso de que se lea un numero entero
    int insurance{0};                         /// es una variable para evitar que se entre más de una vez en el condicional en el que se construye el racional1 (linea 102)
    int string_size =  file_reader.length();  /// sirve para indicar cuantas veces se repetirá el bucle for de la linea 75
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

/**
 * @brief El programa esta preparado para leer fichero y obtener racionales siempre y cuando se cumpla el formato
 * preestablecido (a/b c/d ). Por lo tanto solo existen 3 caracteres diferentes: el slash "/", el espacio " ", y
 * numeros enteros. Cuando el string[n] contiene alguno de estos caracteres implica un comportamiento. El 
 * comportamiento es el siguiente:
 *     
 *      - Si string[n] no es ni un slash ni un espacio en blanco, entoneces es un numero natural. Añadelo a la
 *        variable "temporal_variable".
 * 
 *      - Si el string[n] es un slash, implica que los caracteres/numeros añadidos en "temporal_variable" es el
 *        numerador, convierte la string en entero e inicializa "numerator". A su vez implica que los siguientes
 *        caracteres corresponden al denominador del racional, inicializa "slash_counter" = 1 para se cumpla una
 *        de las condiciones del if de la linea 90. 
 * 
 *      - Si el string[n] es un espacio, implica el final del racional y a su vez puede implicar 2 cosas: 1. Que
 *        los caracteres/numeros añadidos en "temporal_variable" pertencen al denominador; 2. Que el denominador
 *        del racional sea 1 (por lo que no se escribió en el documento), y los caracteres/numeros añadidos en 
 *        "temporal_variable" correspondan al numerador. Para diferenciar un caso del otro se usa la variable
 *        "slash_counter"; si "slash_counter" == 1 se trata de un denominador, si "slash_counter" == 0, se trata
 *        de un numerador. En cualquier caso, indica el final del racional (ya hay valores para el numerador y el
 *        denominador) por lo que se puede inicializar el objeto Racional. Ahora entra en juego la variable 
 *        "insurance"; si "insurance" == 1, se inicializa "racional2"; si "insurance" == 0; se inicializa
 *        "racional 1".  
 */