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
// Contiene la declaración de la clase Alphabet
// Referencias:
// Enlaces de interés
#ifndef CHAIN_H_
#define CHAIN_H_
#include "symbol.h"
#include "alphabet.h"
#include <string>
#include <sstream>
#include <fstream>
const char kSpace{' '};
const std::string kEpsilon{'&'};
const char kEspsilonChar{'&'};
class Chain {
  public:
    Chain(std::string, Alphabet);
    Chain(std::string);
    Chain(char);  // constructor para cadena vacía y vacío
    Chain(std::vector<Symbol>);
    Chain() {};
    Chain GetChain();
    friend std::ostream& operator<<(std::ostream& os, const Chain& chain);
    friend std::ostream& operator<<(std::istream& os, const std::vector<Symbol>& vector);
    friend std::istream& operator>>(std::istream& is, Chain& chain);
    Chain operator+(const Chain& chain2) const;
    const bool operator==(const Chain& chain2) const;
    const bool operator!=(const Chain& chain2) const;
    std::stringstream Size();
    Chain Inverse();
    std::stringstream Prefixes();
    std::stringstream Sufixes();
    std::stringstream SubChain();
    std::stringstream CountSymbol();
    const bool operator<(const Chain& chain) const;
  private:
    std::vector<Symbol> chain_;
    Alphabet alphabet_;
};
#endif // CHAIN_H_