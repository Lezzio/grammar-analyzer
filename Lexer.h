#pragma once

#include <string>
#include "Symbole.h"
using namespace std;

class Lexer {

   public:
      Lexer(string s) : flux(s), tete(0), tampon(nullptr) { }
      ~Lexer() { delete (tampon); }

      Symbole * Consulter();
      void Avancer();
      void SetTampon(Symbole *s);

   protected:
      string flux;
      int tete;
      Symbole * tampon;
};
