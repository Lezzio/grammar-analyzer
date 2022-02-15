//
// Created by allan guigal on 15/02/2022.
//

#include "Automate.h"

Automate::Automate(const string& expr, bool nombreNegatif) {

}

void Automate::decalage(Symbole *s, Etat *e) {
    symbolestack.push_back(s);
    statestack.push_back(e);

}

void Automate::reduction(int n, Symbole *s) {

}
