// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 3: Calculadora de lenguajes formales
// Autor: Mario Guerra Pérez
// Correo: alu0101395036@ull.es
// Fecha: 18/10/2022
// Archivo symbol.h
// Contiene la declaración de la clase Symbol
// Referencias:
// Enlaces de interés
#ifndef SYMBOL_H_
#define SYMBOL_H_
#include <iostream>
#include <string>
class Symbol {
  public:
    Symbol(std::string);
    std::string GetSymbol (void) const;  // getter de la clase
    const bool operator==(const Symbol&) const;
    const bool operator!=(const Symbol&) const;
    const bool operator<(const Symbol) const;  // operador de compación para setter
    const bool operator>(const Symbol) const;  // operador de compación para chain_
    friend std::ostream& operator<<(std::ostream& os, const Symbol& symbol);
  private:
    std::string recieved_;
};
#endif // SYMBOL_H_