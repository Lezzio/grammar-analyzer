#include "symbole.h"
#include <iostream>

void Symbole::Affiche()
{
    cout << Etiquettes[ident];
}

void SymboleEvalue::Affiche()
{
    Symbole::Affiche();
    cout << "(" << valeur << ")";
}
