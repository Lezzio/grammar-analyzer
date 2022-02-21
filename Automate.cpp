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

Automate::~Automate(){
    delete (lexer);
    while(!statestack.empty())
    {
        delete (statestack.back());
        statestack.pop_back();
    }

    while(!symbolestack.empty())
    {
        delete (symbolestack.back());
        symbolestack.pop_back();
    }
}

void Automate::run(){
    bool etatSuivant = true;
   // cout << "ici1" << endl;
    while (etatSuivant){
   //    cout << "ici boucle" << endl;
        Symbole * s = lexer->Consulter();
   //    s->Affiche();
   //    cout << endl;
        lexer->Avancer();
   //    statestack.back()->print();
        etatSuivant = statestack.back()->transition(*this,s);
   //     statestack.back()->print();
   //     cout << etatSuivant << endl;
   //     cout << "fin boucle" << endl;
    }
   // cout << "ici plus boucle" << endl;
    if(*symbolestack.back() == ERREUR){
        cout << "Mauvaise expression syntaxique." << endl;
        cout << "Veuillez réessayer avec une expression valide" << endl;
    } else {
        int result = ((Expr *) symbolestack.back())->getValeur();
        cout << "Le résult de l'évaluation de l'expression est : " << result << endl;
    }
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
        delete (statestack.back());
        statestack.pop_back();
    }
    statestack.back()->transition(*this, s);
    //lexer->SetTampon(s);
}

SymboleEvalue *Automate::popSymbol() {
    SymboleEvalue * eval=  dynamic_cast<SymboleEvalue *>(symbolestack.back());
    symbolestack.pop_back();
    return eval;
}

void Automate::pushSymbol(Symbole * s){
    lexer->SetTampon(s);
}

void Automate::popAndDestroySymbol() {
    delete (symbolestack.back());
    symbolestack.pop_back();
}