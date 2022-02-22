#pragma once

#include <string>

#include "Automate.h"
#include "symbole.h"

using namespace std;

/**
 * @brief 
 * 
 */
class Etat {
public:
    /**
     * @brief Construct a new Etat object
     * 
     * @param name 
     */
    explicit Etat(string name);

    /**
     * @brief Destroy the Etat object
     * 
     */
    virtual ~Etat();

    virtual /**
     * @brief 
     * 
     */
    void print() const;

    /**
     * @brief 
     * 
     * @param automate 
     * @param s 
     * @return true 
     * @return false 
     */
    virtual bool transition(Automate &automate,
                            Symbole *s) = 0;

protected:
    string name;
};


class E0 : public Etat {
public :
    E0();

    ~E0() override;

    void print() const override;

    bool transition(Automate &automate,
                    Symbole *s) override;
};

class E1 : public Etat {
public :
    E1();

    ~E1() override;

    void print() const override;

    bool transition(Automate &automate,
                    Symbole *s) override;
};

class E2 : public Etat {
public :
    E2();

    ~E2() override;

    void print() const override;

    bool transition(Automate &automate,
                    Symbole *s) override;
};

class E3 : public Etat {
public :
    E3();

    ~E3() override;

    void print() const override;

    bool transition(Automate &automate,
                    Symbole *s) override;
};

class E4 : public Etat {
public :
    E4();

    ~E4() override;

    void print() const override;

    bool transition(Automate &automate,
                    Symbole *s) override;
};

class E5 : public Etat {
public :
    E5();

    ~E5() override;

    void print() const override;

    bool transition(Automate &automate,
                    Symbole *s) override;
};

class E6 : public Etat {
public :
    E6();

    ~E6() override;

    void print() const override;

    bool transition(Automate &automate,
                    Symbole *s) override;
};

class E7 : public Etat {
public :
    E7();

    ~E7() override;

    void print() const override;

    bool transition(Automate &automate,
                    Symbole *s) override;
};

class E8 : public Etat {
public :
    E8();

    ~E8() override;

    void print() const override;

    bool transition(Automate &automate,
                    Symbole *s) override;
};

class E9 : public Etat {
public :
    E9();

    ~E9() override;

    void print() const override;

    bool transition(Automate &automate,
                    Symbole *s) override;
};