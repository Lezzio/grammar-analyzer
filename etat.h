#pragma once

#include <string>

#include "Automate.h"
#include "symbole.h"

using namespace std;

/**
 * State of the automaton (Finite State Machine)
 */
class Etat {
public:
    /**
     * Construct a new Etat object, representing a state of the automaton
     * @param name of the state
     */
    explicit Etat(string name);

    /**
     * Destroy the Etat object
     */
    virtual ~Etat();

    /**
     * Print the state's attributes on the CLI
     */
    virtual void print() const;

    /**
     * Transition to another state inside the automaton based on the provided symbol
     * @param automate
     * @param symbole
     * @return whether the transition successful or not, false hence means an error occurred
     */
    virtual bool transition(Automate &automate, Symbole *symbole) = 0;

protected:
    string name;
};

class E0 : public Etat {
public:
    E0();

    ~E0() override;

    void print() const override;

    bool transition(Automate &automate, Symbole *s) override;
};

class E1 : public Etat {
public:
    E1();

    ~E1() override;

    void print() const override;

    bool transition(Automate &automate, Symbole *s) override;
};

class E2 : public Etat {
public:
    E2();

    ~E2() override;

    void print() const override;

    bool transition(Automate &automate, Symbole *s) override;
};

class E3 : public Etat {
public:
    E3();

    ~E3() override;

    void print() const override;

    bool transition(Automate &automate, Symbole *s) override;
};

class E4 : public Etat {
public:
    E4();

    ~E4() override;

    void print() const override;

    bool transition(Automate &automate, Symbole *s) override;
};

class E5 : public Etat {
public:
    E5();

    ~E5() override;

    void print() const override;

    bool transition(Automate &automate, Symbole *s) override;
};

class E6 : public Etat {
public:
    E6();

    ~E6() override;

    void print() const override;

    bool transition(Automate &automate, Symbole *s) override;
};

class E7 : public Etat {
public:
    E7();

    ~E7() override;

    void print() const override;

    bool transition(Automate &automate, Symbole *s) override;
};

class E8 : public Etat {
public:
    E8();

    ~E8() override;

    void print() const override;

    bool transition(Automate &automate, Symbole *s) override;
};

class E9 : public Etat {
public:
    E9();

    ~E9() override;

    void print() const override;

    bool transition(Automate &automate, Symbole *s) override;
};