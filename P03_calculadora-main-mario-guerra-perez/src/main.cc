// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 3: Calculadora de lenguajes formales
// Autor: Mario Guerra Pérez
// Correo: alu0101395036@ull.es
// Fecha: 18/10/2022
// Archivo ClienteChain.cc
// Contiene la función main del programa, la cual se encarga de leer el archivo de entrada 
// y de llamar a las funciones de la clase Calculator
// Referencias:
// Enlaces de interés
#include "symbol.h"
#include "alphabet.h"
#include "chain.h"
#include "language.h"
#include "calculator.h"
#include <sstream>
const char kEqual{'='};
int main(int argc, char* argv[]) {
  std::ifstream inputfile(argv[1]);
  std::vector<std::string> operations;
  std::map<std::string, Language> languages_map;
  std::string aux;
  Language aux_language;
  if (inputfile.is_open()) {
    std::string language_name;
    while (getline(inputfile, aux)) {
      std::string input;
      for (unsigned int i{0}; i < aux.size(); ++i) {
        input += aux[i];  // meto en input cada cadena de aux
      }
      bool flag{false};
      for (unsigned int i{0}; i < input.size(); ++i) {
        if (input[i] == kEqual) {  // compruebo si es una operacion o un lenguaje
          flag = true;
        }
      }
      if (flag == true) { // si es una operacion
        aux_language = Language(input);
      } else {
        operations.push_back(input);
      }
      language_name += input[0];
      language_name += input[1]; // nombre del lenguaje
      languages_map.insert(std::pair<std::string, Language>(language_name, aux_language));
      language_name = "";
    }
  }
  inputfile.close();
  for (unsigned int i{0}; i < operations.size(); ++i) {
    Calculator calculator(languages_map, operations[i]);
  }
  return 0;
}
