//
// Created by allan guigal on 15/02/2022.
//

#ifndef TPCOMPIL_AUTOMATE_H
#define TPCOMPIL_AUTOMATE_H

#include "symbole.h"
#include "Lexer.h"
#include <deque>

class Etat;

using namespace std;

class Automate
{

public:
    explicit Automate(const string &expression, bool negatifs);

    ~Automate();

    void run();

    void decalage(Symbole *s, Etat *e);

    void reduction(int n, Symbole *s);

    SymboleEvalue *popSymbol();

    void pushSymbol(Symbole *s);

    void popAndDestroySymbol();

private:
    deque<Symbole *> symbolestack;
    deque<Etat *> statestack;
    Lexer *lexer;
    bool negatifs;
};

#endif // TPCOMPIL_AUTOMATE_H