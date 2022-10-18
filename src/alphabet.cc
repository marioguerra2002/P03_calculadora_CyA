// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 3: Calculadora de lenguajes formales
// Autor: Mario Guerra Pérez
// Correo: alu0101395036@ull.es
// Fecha: 18/10/2022
// Archivo alphabet.cc
// Contiene las declaraciones de los métodos de la clase Alphabet
// Referencias:
// Enlaces de interés
#include "alphabet.h"
Alphabet::Alphabet (std::vector<std::string> input) {
  for (unsigned int i{0}; i < input.size() - 1; ++i) {  // -1 porque el símbolo final es chain
    alphabet_.insert(Symbol(input[i]));
  }
}
std::set<Symbol> Alphabet::GetSet(void) {
  return alphabet_;
}
void Alphabet::SetSet(std::set<Symbol> set) {
  alphabet_ = set;
}
std::ostream& operator<<(std::ostream& os, const Alphabet& alphabet) {
  for (auto i : alphabet.alphabet_) {
    os << i << " ";
  }
  return os;
}