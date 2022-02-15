//
// Created by allan guigal on 15/02/2022.
//

#ifndef TPCOMPIL_AUTOMATE_H
#define TPCOMPIL_AUTOMATE_H

#include "Symbole.h"
#include "Etat.h"
#include "Lexer.h"
#include <deque>

using namespace std;

class Automate {

public:
    Automate(const string &expression);

    void decalage(Symbole *s, Etat *e);

    void reduction(int n, Symbole *s);

    Expr * popSymbol();

    void popAndDestroySymbol();

private:
    deque<Symbole *> symbolestack;
    deque<Etat *> statestack;
    Lexer *lexer;


};

#endif //TPCOMPIL_AUTOMATE_H