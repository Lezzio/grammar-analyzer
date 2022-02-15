#pragma once

#include <string>
#include <map>
using namespace std;

enum Identificateurs { OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR, EXPR};

const string Etiquettes[] = { "OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "ERREUR"};

class Symbole {
   public:
      Symbole(int i) : ident(i){}
      virtual ~Symbole() { }
      void print();
      bool isTerminal() {return ident != EXPR;}
      operator int() const { return ident; }
      virtual void Affiche();

   protected:
      int ident;
};

class SymboleEvalue : public Symbole {
public:
    SymboleEvalue(int ident, int valeur) : Symbole(ident), valeur(valeur) {}
    virtual ~SymboleEvalue() {}
    int getValeur() const {return valeur;}
protected:
    int valeur;
};

class Expr : public SymboleEvalue {
public:
    Expr(int valeur): SymboleEvalue(EXPR, valeur){}
    virtual ~ Expr() {}
};

class Entier : public SymboleEvalue {
   public:
      Entier(int valeur) : SymboleEvalue(INT, valeur){}
      ~Entier() { }
      virtual void Affiche();
};


class MultiplicationExpr : public Expr {
public:
    static MultiplicationExpr *
    newMultiplication(SymboleEvalue *s1, SymboleEvalue *s2) {
        return new MultiplicationExpr(s1->getValeur() * s2->getValeur());
    }

private:
    explicit MultiplicationExpr(int valeur) : Expr(valeur) {}
};

class AdditionExpr : public Expr {
public:
    /**
     * @param s1 SymbolWithValue *
     * @param s2 SymbolWithValue *
     * @return AdditionExpr with an evaluated value of s1 + s2.
     */
    static AdditionExpr *
    newAddition(SymboleEvalue *s1, SymboleEvalue *s2) {
        return new AdditionExpr(s1->getValeur() + s2->getValeur());
    }

private:
    explicit AdditionExpr(int valeur) : Expr(valeur) {}
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
