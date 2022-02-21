#include <iostream>
#include "Etat.h"

Etat::Etat(string name) : name(name) {}

Etat::~Etat() {}

void Etat::print() const
{
    cout << "Etat: " << name << endl;
}


E0::E0() : Etat("E0") {}
E0::~E0() {}

void E0::print() const
{
    Etat::print();
}

bool E0::transition(Automate &automate, Symbole *s)
{
    switch (*s)
    {
    case INT:
        automate.decalage(s, new E3);    
        break;
    case OPENPAR:
        automate.decalage(s, new E2);
        break;
    case EXPR:
        automate.decalage(s, new E1);
        break;
    default: 
        delete (s);
        automate.decalage(new Symbole(ERREUR), nullptr);
        return false;
    }
    return true;
}


E1::E1() : Etat("E1") {}
E1::~E1() {}

void E1::print() const
{
    Etat::print();
}

bool E1::transition(Automate &automate, Symbole *s)
{
    switch (*s)
    {
    case PLUS:
        automate.decalage(s, new E4);    
        break;
    case MULT:
        automate.decalage(s, new E5);
        break;
    case FIN:
        delete (s);
        return false;
    default: 
        delete (s);
        automate.decalage(new Symbole(ERREUR), nullptr);
        return false;
    }
    return true;
}


E2::E2() : Etat("E2") {}
E2::~E2() {}

void E2::print() const
{
    Etat::print();
}

bool E2::transition(Automate &automate, Symbole *s)
{
    switch (*s)
    {
    case INT:
        automate.decalage(s, new E3);    
        break;
    case OPENPAR:
        automate.decalage(s, new E2);
        break;
    case EXPR:
        automate.decalage(s, new E6);
        break;
    default: 
        delete (s);
        automate.decalage(new Symbole(ERREUR), nullptr);
        return false;
    }
    return true;
}


E3::E3() : Etat("E3") {}
E3::~E3() {}

void E3::print() const
{
    Etat::print();
}

bool E3::transition(Automate &automate, Symbole *s)
{
    switch (*s)
    {
    case PLUS:
    case MULT:
    case CLOSEPAR:
    case FIN:
        {
       // cout << "reduction E3 " << endl; // DEBUG
        Entier * valeur = (Entier *) automate.popSymbol();
        automate.reduction(1, new Expr(valeur->getValeur()));
        break;    
        }
    default: 
        delete (s);
        automate.decalage(new Symbole(ERREUR), nullptr);
        return false;
    }
    return true;
}


E4::E4() : Etat("E4") {}
E4::~E4() {}

void E4::print() const
{
    Etat::print();
}

bool E4::transition(Automate &automate, Symbole *s)
{
    switch (*s)
    {
    case INT:
        automate.decalage(s, new E3);    
        break;
    case OPENPAR:
        automate.decalage(s, new E2);
        break;
    case EXPR:
        automate.decalage(s, new E7);
        break;
    default: 
        delete (s);
        automate.decalage(new Symbole(ERREUR), nullptr);
        return false;
    }
    return true;
}


E5::E5() : Etat("E5") {}
E5::~E5() {}

void E5::print() const
{
    Etat::print();
}

bool E5::transition(Automate &automate, Symbole *s)
{
    switch (*s)
    {
    case INT:
        automate.decalage(s, new E3);    
        break;
    case OPENPAR:
        automate.decalage(s, new E2);
        break;
    case EXPR:
        automate.decalage(s, new E8);
        break;
    default: 
        delete (s);
        automate.decalage(new Symbole(ERREUR), nullptr);
        return false;
    }
    return true;
}


E6::E6() : Etat("E6") {}
E6::~E6() {}

void E6::print() const
{
    Etat::print();
}

bool E6::transition(Automate &automate, Symbole *s)
{
    switch (*s)
    {
    case PLUS:
        automate.decalage(s, new E4);    
        break;
    case MULT:
        automate.decalage(s, new E5);
        break;
    case CLOSEPAR:
        automate.decalage(s, new E9);
        break;
    default: 
        delete (s);
        automate.decalage(new Symbole(ERREUR), nullptr);
        return false;
    }
    return true;
}


E7::E7() : Etat("E7") {}
E7::~E7() {}

void E7::print() const
{
    Etat::print();
}

bool E7::transition(Automate &automate, Symbole *s)
{
    switch (*s)
    {
    case PLUS:
    case CLOSEPAR:
    case FIN:
        {
        Expr * s1 = (Expr *) automate.popSymbol();
        automate.popAndDestroySymbol();
        Expr * s2 = (Expr *) automate.popSymbol();
        automate.reduction(3, new ExprPlus(s2, s1));
        break; 
        } 
    case MULT:
        automate.decalage(s, new E5);    
        break;       
    default: 
        delete (s);
        automate.decalage(new Symbole(ERREUR), nullptr);
        return false;
    }
    return true;
}


E8::E8() : Etat("E8") {}
E8::~E8() {}

void E8::print() const
{
    Etat::print();
}

bool E8::transition(Automate &automate, Symbole *s)
{
    switch (*s)
    {
    case PLUS:
    case MULT:
    case CLOSEPAR:
    case FIN:
        {
        Expr * s1 = (Expr *) automate.popSymbol();
        automate.popAndDestroySymbol();
        Expr * s2 = (Expr *) automate.popSymbol();
        automate.reduction(3, new ExprMult(s2, s1));
        break;  
        }    
    default: 
        delete (s);
        automate.decalage(new Symbole(ERREUR), nullptr);
        return false;
    }
    return true;
}


E9::E9() : Etat("E9") {}
E9::~E9() {}

void E9::print() const
{
    Etat::print();
}

bool E9::transition(Automate &automate, Symbole *s)
{
    switch (*s)
    {
    case PLUS:
    case MULT:
    case CLOSEPAR:
    case FIN:
        automate.reduction(3, s);
        break;        
    default: 
        delete (s);
        automate.decalage(new Symbole(ERREUR), nullptr);
        return false;
    }
    return true;
}
