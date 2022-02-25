#pragma once

#include <string>
#include <utility>
#include "Symbole.h"

using namespace std;

class Lexer
{

public:
    explicit Lexer(string s, bool negatifs) : flux(std::move(s)), tete(0), tampon(nullptr), negatifs(negatifs) {}

    ~Lexer() { delete (tampon); }

    Symbole *Consulter();

    void Avancer();

    void SetTampon(Symbole *s);

protected:
    string flux;
    int tete;
    Symbole *tampon;
    bool negatifs;
};
