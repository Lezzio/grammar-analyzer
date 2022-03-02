//
// Created by allan guigal on 15/02/2022.
//
#include <iostream>
#include "Automate.h"
#include "etat.h"

Automate::Automate(const string &expr, bool negatifs)
{
    this->lexer = new Lexer(expr, negatifs);
    Automate::negatifs = negatifs;
    auto *etatInitial = new E0();
    statestack.push_back(etatInitial);
}

Automate::~Automate()
{
    delete (lexer);
    while (!statestack.empty())
    {
        delete (statestack.back());
        statestack.pop_back();
    }

    while (!symbolestack.empty())
    {
        delete (symbolestack.back());
        symbolestack.pop_back();
    }
}

void Automate::run()
{
    bool etatSuivant = true;
    while (etatSuivant)
    {
        Symbole *s = lexer->Consulter();
        lexer->Avancer();
        etatSuivant = statestack.back()->transition(*this, s);
    }
    if (*symbolestack.back() == ERREUR)
    {
        cout << "Mauvaise expression syntaxique." << endl;
        cout << "Veuillez réessayer avec une expression valide" << endl;
    }
    else
    {
        int result = ((Expr *)symbolestack.back())->getValeur();
        cout << "Le résultat de l'évaluation de l'expression est : " << result << endl;
    }
}

void Automate::decalage(Symbole *symbole, Etat *etat)
{
#ifdef MAP
    cout << "-----------" << endl;
    cout << "Decalage : " << endl;
    statestack.back()->print();
    cout << "Avec le symbole : ";
    symbole->Affiche();
    if (etat != nullptr)
    {
        cout << endl
             << " ==> ";
        etat->print();
    }
    cout << endl;
#endif
    symbolestack.push_back(symbole);
    statestack.push_back(etat);
    if (symbole->isTerminal())
    {
        lexer->Avancer();
    }
}

void Automate::reduction(int n, Symbole *symbole)
{
    for (int i = 0; i < n; i++)
    {
        delete (statestack.back());
        statestack.pop_back();
    }
    statestack.back()->transition(*this, symbole);
    // lexer->SetTampon(symbole);
}

SymboleEvalue *Automate::popSymbol()
{
    auto *eval = dynamic_cast<SymboleEvalue *>(symbolestack.back());
    symbolestack.pop_back();
    return eval;
}

void Automate::pushSymbol(Symbole *symbole)
{
    lexer->SetTampon(symbole);
}

void Automate::popAndDestroySymbol()
{
    delete (symbolestack.back());
    symbolestack.pop_back();
}