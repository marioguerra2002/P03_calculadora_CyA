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
// Contiene la declaración de la clase Language
// Referencias:
// Enlaces de interés
#ifndef LANGUAGE_H_
#define LANGUAGE_H_
#include "chain.h"
#include <math.h>
const char kBraket{'}'};
const char kBraketOpen{'{'};
const char kComma{','};
const char kEpsilon_char{'&'};
class Language {
  public:
    Language () {};
    Language(std::string);
    Language(std::set<Chain>);
    friend std::ostream& operator<<(std::ostream& os, const Language& language);
    std::stringstream Salida (void);
    Language GetLanguage();
    Alphabet GetAlphabet();
    Language Concatenation(Language) const;
    Language Union(Language);
    Language Intersection(Language) const;
    Language Difference(Language) const;
    Language Inverse (void) const;
    Language Power (std::string) const;
    std::set <Chain> Concatenation(std::set <Chain>) const;
    std::stringstream SufixChain (void) const;
    // sobrecarga de funcion de concatenacion para poder usarla en la potencia
  private:
    std::set <Chain> language_;
    Alphabet alphabet_;
};
#endif // LANGUAGE_H_