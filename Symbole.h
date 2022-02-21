#pragma once

#include <string>
#include <map>
using namespace std;

enum Identificateurs { OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR, EXPR};

const string Etiquettes[] = { "OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "ERREUR", "EXPR"};

class Symbole {
public:
    Symbole(int i) : ident(i){}
    virtual ~Symbole() = default;
    bool isTerminal() const {return ident != EXPR;}
    operator int() const { return ident; }
    virtual void Affiche();

protected:
    int ident;
};

class SymboleEvalue : public Symbole {
public:
    SymboleEvalue(int ident, int valeur) : Symbole(ident), valeur(valeur) {}
    ~SymboleEvalue() override = default;
    int getValeur() const {return valeur;}
    void Affiche() override;
protected:
    int valeur;
};

class Expr : public SymboleEvalue {
public:
    explicit Expr(int valeur): SymboleEvalue(EXPR, valeur){}
    ~ Expr() override = default;
};

class Entier : public SymboleEvalue {
public:
    explicit Entier(int valeur) : SymboleEvalue(INT, valeur){}
    ~Entier() override = default;
};


class ExprMult : public Expr {
public:
    ExprMult(SymboleEvalue *s1, SymboleEvalue *s2) : Expr(s1->getValeur() * s2->getValeur()) 
    {}
};

class ExprPlus : public Expr {
public:
    ExprPlus(SymboleEvalue *s1, SymboleEvalue *s2) : Expr(s1->getValeur() + s2->getValeur()) 
    {}
};
