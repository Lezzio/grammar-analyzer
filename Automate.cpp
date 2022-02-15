//
// Created by allan guigal on 15/02/2022.
//

#include "Automate.h"

Automate::Automate(const string& expr, bool nombreNegatif) {
    this->lexer = new Lexer(expr);
    //statestack.push_back();
}

void Automate::decalage(Symbole *s, Etat *e) {
    symbolestack.push_back(s);
    statestack.push_back(e);
    if (s->isTerminal()) {
        lexer->Avancer();
    }
}

void Automate::reduction(int n, Symbole *s) {
    for (int i = 0; i < n; i++) {
        delete(statestack.back());
        statestack.pop_back();
    }
    statestack.back()->transition(*this, s);
}