// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 3: Calculadora de lenguajes formales
// Autor: Mario Guerra Pérez
// Correo: alu0101395036@ull.es
// Fecha: 18/10/2022
// Archivo chain.cc
// Contiene las declaraciones de los métodos de la clase Calculator
// Referencias:
// Enlaces de interés
#include "calculator.h"
Calculator::Calculator(std::map<std::string, Language>& map, std::string operation) {
  map_ = map;
  std::string auxiliar;
  std::string names;
  std::string operator1;
  std::string operator2;
  Language result_of_operation;
  for (unsigned long int i = 0; i < operation.size(); ++i) {
    if (operation[i] != kSpace) {
      auxiliar += operation[i];
      if (auxiliar == kUnion || auxiliar == kIntersection || auxiliar == kDifference || 
          auxiliar == kInverse || auxiliar == kPower || auxiliar == kConcatenation) {
        operator1 = stack_.top();
        stack_.pop();
        operator2 = stack_.top();
        stack_.pop();
        switch (auxiliar[0]) {
          case '+':
            result_of_operation = map_[operator2].Concatenation(map_[operator1]);
            names = operator2 + kConcatenation + operator1;
            map_[names] = result_of_operation;
            if (names != " ") {
              stack_.push(names);
            }
            auxiliar.clear(); 
            break;
          case '|':
            result_of_operation = map_[operator2].Union(map_[operator1]);
            names = operator2 + kUnion + operator1;
            map_[names] = result_of_operation;
            stack_.push(names);
            auxiliar.clear();
            break;
          case '^':
            result_of_operation = map_[operator2].Intersection(map_[operator1]);
            names = operator2 + kIntersection + operator1;
            map_[names] = result_of_operation;
            if (names != " ") {
              stack_.push(names);
            }
            auxiliar.clear();
            names.clear();
            break;
          case '-':
            result_of_operation = map_[operator2].Difference(map_[operator1]);
            names = operator2 + kDifference + operator1;
            map_[names] = result_of_operation;
            if (names != " ") {
              stack_.push(names);
            }
            auxiliar.clear();
            break;
          case '!':  
            // a la hora de realizar la inversa, como hemos dicho que los símbolos 
            // del alfabeto de cada cadena del lenguaje es la propia cadena del lenguaje, 
            // a la hora de realizar la inversa, esta no varía ya que es el mismo símbolo.
            result_of_operation = map_[operator2].Inverse();
            names = kInverse + operator2;
            map_[names] = result_of_operation;
            if (names != " ") {
              stack_.push(names);
            }
            auxiliar.clear();
            break;
          case '*':
            result_of_operation = map_[operator2].Power(operator1);
            names = operator2 + kPower + operator1;
            map_[names] = result_of_operation;
            if (names != " ") {
              stack_.push(names);
            } 
            auxiliar.clear();
            break;
        }
      }
    } else {  // si hay un espacio y no es un operador
      if (auxiliar != "") {
        stack_.push(auxiliar);
        auxiliar.clear();
      }
    }
  }
  std::cout << "Lenguaje resultante de la operación " << stack_.top() << " = " 
  << map_[stack_.top()] << std::endl;  // funciona
}
std::map<std::string, Language> Calculator::GetMap() {
  return map_;
}
std::stack<std::string> Calculator::GetStack() {
  return stack_;
}