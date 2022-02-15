//
// Created by allan guigal on 15/02/2022.
//

#ifndef TPCOMPIL_AUTOMATE_H
#define TPCOMPIL_AUTOMATE_H

#include "symbole.h"
#include "Etat.h"
#include <deque>

using namespace std;

class Automate {

public:
    Automate(const string& expression, bool nombreNegatif);
    deque<Symbole*> symbolestack;
    deque<Etat*> statestack;

public:
    void decalage(Symbole * s, Etat * e);
    void reduction(int n, Symbole * s);

};

#endif //TPCOMPIL_AUTOMATE_H