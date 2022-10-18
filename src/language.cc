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
// Contiene las declaraciones de los métodos de la clase Language
// Referencias:
// Enlaces de interés
#include "language.h"
const std::string kSpaceString{" "};
Language::Language(std::string input) {
  std::string auxiliar;
  std::set<Symbol> auxiliar_set;
  int counter{6};  // empieza en 5 para que no coja {
  if (input[5] == kBraketOpen) {  // me aseguro que no sean operaciones
    while (input[counter] != kBraket) {
      if (input[counter] != kSpace && input[counter] != kComma) {
        auxiliar += input[counter];
      } else {
        if (auxiliar == kEpsilon || auxiliar == kSpaceString) {
          auxiliar = "-"; // para que no me de error al meterlo en el alfabeto
          auxiliar_set.insert(Symbol(auxiliar));
          auxiliar = "";
        } else {  // si me encuentro con un espacio o una coma
          for (unsigned long int i = 0; i < auxiliar.size(); ++i) {
            std::string sub_auxiliar{auxiliar[i]};
            auxiliar_set.insert(Symbol(sub_auxiliar));  // inserto en el alfabeto cada símbolo por separado
          }
          auxiliar = "";
        }
      }
      counter++;
    }
    for (unsigned long int i = 0; i < auxiliar.size(); ++i) {
      std::string sub_auxiliar{auxiliar[i]};
      if (sub_auxiliar == kEpsilon || sub_auxiliar == kSpaceString) {
        sub_auxiliar = "-"; // para que no me de error al meterlo en el alfabeto
        auxiliar_set.insert(Symbol(sub_auxiliar));
        sub_auxiliar = "";
      } else {
        auxiliar_set.insert(Symbol(sub_auxiliar));  // inserto en el alfabeto cada símbolo por separado
      }
    }
    alphabet_.SetSet(auxiliar_set);
    // alfabeto creado
    counter = 6; // empieza en 5 para que no coja {
    auxiliar = "";
    while (input[counter] != kBraket) {
      if (input[counter] != kSpace) {
        if (input[counter] != kComma) {
          auxiliar += input[counter];
        }
      } else if (input[counter] == kEpsilon_char) {  // si es epsilon (lenguaje con cadena vacia)
        language_.insert(Chain(kEspsilonChar));
        auxiliar = "";
      } else if (auxiliar.empty() && input[counter + 1] == kBraket) {  // si no es cadena vacia
        language_.insert(Chain(kSpace));  // lenguaje vacío
        auxiliar = "";
      } else if (input[counter] == kSpace || input[counter + 1] == kBraket) {
        language_.insert(Chain(auxiliar, alphabet_));
        auxiliar = "";
      } 
      counter++;
    }
    language_.insert(Chain(auxiliar, alphabet_));
  }
}
Language::Language (std::set<Chain> language) {
  language_ = language;
}
Language Language::GetLanguage() {
  return *this;
}
//supongamos que esto funciona         
std::ostream& operator<<(std::ostream& out, const Language& language) {
  // out << "{";
  // out << language.alphabet_;
  // out << "}";
  // out << kSpace;
  out << "{";
  for (auto it = language.language_.begin(); it != language.language_.end(); ++it) {
    out << *it << kSpace;
  }
  out << "}";
  return out;      
}

Alphabet Language::GetAlphabet() {
  return alphabet_;
}
Language Language::Concatenation(Language language) const{
  std::set<Chain> auxiliar;
  Chain aux;
  for (auto& i : language.language_) {
    for (auto& j : language_) {
      if (i == Chain(kEspsilonChar)) {
        auxiliar.insert(Chain(kEspsilonChar));
        auxiliar.insert(j);
      } else if (j == Chain(kEspsilonChar)) {
        auxiliar.insert(Chain(kEspsilonChar));
        auxiliar.insert(i);
      } else if (i == Chain(kEspsilonChar) && j == Chain(kEspsilonChar)) {
        aux = Chain(kEspsilonChar);
        auxiliar.insert(aux);
      } else {
        aux = i + j;
        auxiliar.insert(aux);
      }
    }
  }

  return Language(auxiliar);
}
Language Language::Union(Language language) {
  for (auto& i : language.language_) {
    language_.insert(i);
  }
  return language_;
}
Language Language::Intersection(Language language) const {
  std::set<Chain> auxiliar;
  for (auto& i : language_) {
    for (auto& j : language.language_) {
      if (i == j) {
        auxiliar.insert(i);
      }
    }
  }
  return Language(auxiliar);
}
Language Language::Difference(Language language) const{
  std::set<Chain> auxiliar;
  bool flag{false};
  // metemos los elementosde a diferencia de b
  for (auto& i : language_) {
    for (auto& j : language.language_) {
      if (i == j) {
        flag = true;
      }
    }
    if (flag == false) {
      auxiliar.insert(i);
    } else {
      flag = false;
    }
  }
  return Language(auxiliar);
}
Language Language::Inverse (void) const {
  std::set<Chain> auxiliar;
  std::set<Chain> auxiliar2;
  Chain chain_aux;
  for (auto& i : language_) {
    auxiliar.insert(i);
  }
  auxiliar.erase(auxiliar.begin());
  for (auto& i : auxiliar) {
    chain_aux = i;
    auxiliar2.insert(chain_aux.Inverse());
  }
  return Language(auxiliar2);
}
//sobrecargo funciona concatenacion para implementar la potencia  
std::set<Chain> Language::Concatenation(std::set<Chain> language) const {
  std::set<Chain> auxiliar;
  Chain aux;
  for (auto& i : language) {
    for (auto& j : language_) {
      if (i == Chain(kEspsilonChar) || j == Chain(kEspsilonChar)) {
        auxiliar.insert(Chain(kEspsilonChar));
      } else {
        aux = i + j;
        auxiliar.insert(aux);

      }
    }
  }
  return auxiliar;
}

Language Language::Power(std::string power) const {
  long unsigned int elevation;
  elevation = std::stoi(power);
  std::set<Chain> auxiliar;
  std::set<Chain> empty_languaje;
  empty_languaje.insert(Chain(kEspsilonChar));
  for (auto& i : language_) {
    auxiliar.insert(i);
  }
  auxiliar.erase(auxiliar.begin());
  long unsigned int size_language{language_.size() - 1};
  if (elevation == 0) {
    auxiliar = empty_languaje;
    return Language(auxiliar);
  } else if (elevation == 1) {
    auxiliar = language_;
    return Language(auxiliar);
  } else {
    for (long unsigned int i = 1; i < elevation; i++) {
      auxiliar = Concatenation(auxiliar);
    }
    for (long unsigned int i{1}; i <= elevation - 1; i++) {
      size_language = pow(size_language, i);
    }
    long unsigned int iterator{0};
    while (iterator < size_language - 2) {
      auxiliar.erase(auxiliar.begin());
      iterator++;
    }
    for (auto& i : language_) {
      if (i == Chain(kEspsilonChar)) {
        auxiliar.insert(Chain(kEspsilonChar));
      }
    }
  }
  return Language(auxiliar);
}