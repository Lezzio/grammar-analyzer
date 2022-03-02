//
// Created by allan guigal on 15/02/2022.
//

#ifndef TPCOMPIL_AUTOMATE_H
#define TPCOMPIL_AUTOMATE_H

#include "symbole.h"
#include "Lexer.h"
#include <deque>

class Etat;

using namespace std;

/**
 * Automate (automaton) LR parser with shift-reduce methods
 * The automate is implemented using 2 stacks, one for the symbols and another for the states.
 * Finally, a lexer is used
 */
class Automate
{

public:
    /**
     * Construct an automate
     * @param expression, a reference to the expression represented by a string to treat
     * @param negatifs, whether or not the automate should support negative numbers or
     */
    explicit Automate(const string &expression, bool negatifs);

    ~Automate();

    /**
     * Enable the automate to run and listen to CLI inputs to evaluate and compute expressions
     */
    void run();

    /**
     * Shift method, push to the stack'symbole back the symbol and state provided (symbole, etat)
     * and move forward if the symbol is terminal
     * @param symbole
     * @param etat
     */
    void decalage(Symbole *symbole, Etat *etat);

    /**
     * Reduce method, apply a completed grammar rule
     * Remove a given amount of states and call the transition method upon the last state
     * @param n, the number of states to delete and pop (remove) from the stack
     * @param symbole, the symbole to provide to the transition
     */
    void reduction(int n, Symbole *symbole);

    /**
     * Pop a symbol from the stack
     */
    SymboleEvalue *popSymbol();

    /**
     * Push a symbol to the stack
     * @param symbole
     */
    void pushSymbol(Symbole *symbole);

    /**
     * Pop a symbol from the stack and destroy it (memory delete)
     */
    void popAndDestroySymbol();

private:
    deque<Symbole *> symbolestack;
    deque<Etat *> statestack;
    Lexer *lexer;
    bool negatifs;
};

#endif // TPCOMPIL_AUTOMATE_H