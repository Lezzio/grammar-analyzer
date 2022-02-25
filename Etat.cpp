#include <iostream>
#include <utility>
#include "etat.h"

Etat::Etat(string name) : name(std::move(name)) {}

Etat::~Etat() = default;

void Etat::print() const
{
    cout << "Etat: " << name << endl;
}

E0::E0() : Etat("E0") {}

E0::~E0() = default;

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

E1::~E1() = default;

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
#ifdef MAP
        cout << "-----------" << endl;
        cout << "accepter " << endl;
        cout << endl;
#endif
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

E2::~E2() = default;

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

E3::~E3() = default;

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
#ifdef MAP
        cout << "-----------" << endl;
        cout << "reduction R5 " << endl; // DEBUG
        cout << endl;
#endif
        auto *valeur = (Entier *)automate.popSymbol();
        automate.reduction(1, new Expr(valeur->getValeur()));
        delete (valeur);
        automate.pushSymbol(s);
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

E4::~E4() = default;

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

E5::~E5() = default;

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

E6::~E6() = default;

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

E7::~E7() = default;

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
#ifdef MAP
        cout << "-----------" << endl;
        cout << "reduction R2 " << endl; // DEBUG
        cout << endl;
#endif
        Expr *s1 = (Expr *)automate.popSymbol();
        automate.popAndDestroySymbol();
        Expr *s2 = (Expr *)automate.popSymbol();
        automate.reduction(3, new ExprPlus(s2, s1));
        delete (s1);
        delete (s2);
        automate.pushSymbol(s);
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

E8::~E8() = default;

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
#ifdef MAP
        cout << "-----------" << endl;
        cout << "reduction R3 " << endl; // DEBUG
        cout << endl;
#endif
        Expr *s1 = (Expr *)automate.popSymbol();
        automate.popAndDestroySymbol();
        Expr *s2 = (Expr *)automate.popSymbol();
        automate.reduction(3, new ExprMult(s2, s1));
        delete (s1);
        delete (s2);
        automate.pushSymbol(s);
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

E9::~E9() = default;

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
    {
#ifdef MAP
        cout << "-----------" << endl;
        cout << "reduction R4 " << endl; // DEBUG
#endif
        automate.popAndDestroySymbol();
        auto *valeur = (Entier *)automate.popSymbol();
        automate.popAndDestroySymbol();
        automate.reduction(3, new Expr(valeur->getValeur()));
        delete (valeur);
        automate.pushSymbol(s);
        break;
    }
    default:
        delete (s);
        automate.decalage(new Symbole(ERREUR), nullptr);
        return false;
    }
    return true;
}
