#pragma once

#include <string>
#include <map>
using namespace std;

enum Identificateurs { OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR, EXPR};

const string Etiquettes[] = { "OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "ERREUR"};

class Symbole {
public:
    explicit Symbole(int i) : ident(i){}
    virtual ~Symbole() = default;
    bool isTerminal() const {return ident != EXPR;}
    explicit operator int() const { return ident; }
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
    static ExprMult *
    newMultiplication(SymboleEvalue *s1, SymboleEvalue *s2) {
        return new ExprMult(s1->getValeur() * s2->getValeur());
    }

private:
    explicit ExprMult(int valeur) : Expr(valeur) {}
};

class ExprPlus : public Expr {
public:
    static ExprPlus *
    newAddition(SymboleEvalue *s1, SymboleEvalue *s2) {
        return new ExprPlus(s1->getValeur() + s2->getValeur());
    }

private:
    explicit ExprPlus(int valeur) : Expr(valeur) {}
};

class OpenPar : public Symbole {
public:
    OpenPar() : Symbole(OPENPAR) {}
};

class ClosePar : public Symbole {
public:
    ClosePar() : Symbole(CLOSEPAR) {}
};

class Plus : public Symbole {
public:
    Plus() : Symbole(PLUS) {}
};

class Multiplication : public Symbole {
public:
    Multiplication() : Symbole(MULT) {}
};

class End : public Symbole {
public:
    End() : Symbole(FIN) {}
};

class Error : public Symbole {
public:
    Error() : Symbole(ERREUR) {}
};
