// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 3: Calculadora de lenguajes formales
// Autor: Mario Guerra Pérez
// Correo: alu0101395036@ull.es
// Fecha: 18/10/2022
// Archivo alphabet.h
// Contiene la declaración de la clase Calculator
// Referencias:
// Enlaces de interés
#include "language.h"
#include "chain.h"
#include <stack>
#include <map>
const std::string kConcatenation{'+'};
const std::string kUnion{'|'};
const std::string kIntersection{'^'};
const std::string kDifference{'-'};
const std::string kInverse{'!'};
const std::string kPower{'*'};
class Calculator {
  public:
    Calculator(std::map<std::string, Language>&, std::string);
    std::stack<std::string> GetStack();
    std::map<std::string, Language> GetMap();
    // friend std::ostream& operator<<(std::ostream& os, const Calculator& calculator);
  private:
    std::stack<std::string> stack_;  // Pila de operaciones
    std::map<std::string, Language> map_;  // donde se guardan los lenguajes
};
