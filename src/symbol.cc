// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 3: Calculadora de lenguajes formales
// Autor: Mario Guerra Pérez
// Correo: alu0101395036@ull.es
// Fecha: 18/10/2022
// Archivo symbol.cc
// Contiene las declaraciones de los métodos de la clase Symbol
// Referencias:
// Enlaces de interés
#include "symbol.h"
Symbol::Symbol(std::string recieved) {
  recieved_ = recieved;
}
std::string Symbol::GetSymbol() const {
  return recieved_;
}
const bool Symbol::operator==(const Symbol& symbol2) const {
  return recieved_ == symbol2.recieved_;
}
const bool Symbol::operator!=(const Symbol& symbol2) const {
  return recieved_ != symbol2.recieved_;
}
const bool Symbol::operator<(const Symbol symbol_2) const { return recieved_ < symbol_2.recieved_; }
const bool Symbol::operator>(const Symbol symbol_2) const { return recieved_ > symbol_2.recieved_; }
std::ostream& operator<<(std::ostream& os, const Symbol& symbol) {
  os << symbol.recieved_;
  return os;
}