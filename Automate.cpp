//
// Created by allan guigal on 15/02/2022.
//
#include <iostream>
#include "Automate.h"
#include "Etat.h"

Automate::Automate(const string &expr) {
    this->lexer = new Lexer(expr);
    auto *etatInitial = new E0();
    statestack.push_back(etatInitial);
}

Automate::~Automate() {
    delete (lexer);
    while (!statestack.empty()) {
        delete (statestack.back());
        statestack.pop_back();
    }

    while (!symbolestack.empty()) {
        delete (symbolestack.back());
        symbolestack.pop_back();
    }
}

void Automate::run() {
    bool etatSuivant = true;
    while (etatSuivant) {
        Symbole *s = lexer->Consulter();
        lexer->Avancer();
        etatSuivant = statestack.back()->transition(*this, s);
    }
    if (*symbolestack.back() == ERREUR) {
        cout << "Mauvaise expression syntaxique." << endl;
        cout << "Veuillez réessayer avec une expression valide" << endl;
    } else {
        int result = ((Expr *) symbolestack.back())->getValeur();
        cout << "Le résult de l'évaluation de l'expression est : " << result << endl;
    }
}

void Automate::decalage(Symbole *s, Etat *e) {
#ifdef MAP
    cout << "-----------" << endl;
    cout << "Decalage : " << endl;
    statestack.back()->print();
    cout << "Avec le symbole : ";
    s->Affiche();
    if(e != nullptr){
        cout << endl << " ==> ";
        e->print();
    }
    cout << endl;
#endif

    symbolestack.push_back(s);
    statestack.push_back(e);
    if (s->isTerminal()) {
        lexer->Avancer();
    }
}

void Automate::reduction(int n, Symbole *s) {
    for (int i = 0; i < n; i++) {
        delete (statestack.back());
        statestack.pop_back();
    }
    statestack.back()->transition(*this, s);
    //lexer->SetTampon(s);
}

SymboleEvalue *Automate::popSymbol() {
    auto *eval = dynamic_cast<SymboleEvalue *>(symbolestack.back());
    symbolestack.pop_back();
    return eval;
}

void Automate::pushSymbol(Symbole *s) {
    lexer->SetTampon(s);
}

void Automate::popAndDestroySymbol() {
    delete (symbolestack.back());
    symbolestack.pop_back();
}