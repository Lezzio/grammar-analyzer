#pragma once

#include <string>
#include <map>
using namespace std;

enum Identificateurs { OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR, EXPR};

const string Etiquettes[] = { "OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "ERREUR", "EXPR" };

class Symbole {
   public:
      Symbole(int i, bool t) : ident(i), terminal(t) {}
      virtual ~Symbole() { }
      void print();
      bool isTerminal() {return terminal;}
      operator int() const { return ident; }
      virtual void Affiche();

   protected:
      int ident;
      bool terminal;
};


class Expr : public Symbole {
public:
    Expr(): Symbole(EXPR, false){};
    virtual ~ Expr() {};
};

class Entier : public Symbole {
   public:
      Entier(int valeur, bool t) : Symbole(INT,t), valeur(valeur) { }
      ~Entier() { }
      virtual void Affiche();
      int getValeur() const {return valeur;}
   protected:
      int valeur;
};


class MultiplicationExpr : public Expr {
public:
    /**
     * @param s1 SymbolWithValue *
     * @param s2 SymbolWithValue *
     * @return MultiplicationExpr with an evaluated value of s1 * s2.
     */
    static MultiplicationExpr *
    newMultiplication(Entier *s1, Entier *s2) {
        return new MultiplicationExpr(s1->getValeur() * s2->getValeur());
    }

private:
    //explicit MultiplicationExpr(int valeur) : Entier(valeur) {}
};

