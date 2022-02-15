#pragma once

#include <string>

#include "Automate.h"
#include "symbole.h"
using namespace std;

/**
 * @brief 
 * 
 */
class Etat
{
public:
    /**
     * @brief Construct a new Etat object
     * 
     * @param name 
     */
    Etat(string name);

    /**
     * @brief Destroy the Etat object
     * 
     */
    virtual ~Etat();

    /**
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
        virtual ~E0();
        void print() const;
        bool transition(Automate &automate,
                            Symbole *s) override;
};

class E1 : public Etat {
    public :
        E1();
        virtual ~E1();
        void print() const;
        bool transition(Automate &automate,
                            Symbole *s) override;
};

class E2 : public Etat {
    public :
        E2();
        virtual ~E2();
        void print() const;
        bool transition(Automate &automate,
                            Symbole *s) override;
};

class E3 : public Etat {
    public :
        E3();
        virtual ~E3();
        void print() const;
        bool transition(Automate &automate,
                            Symbole *s) override;
};

class E4 : public Etat {
    public :
        E4();
        virtual ~E4();
        void print() const;
        bool transition(Automate &automate,
                            Symbole *s) override;
};

class E5 : public Etat {
    public :
        E5();
        virtual ~E5();
        void print() const;
        bool transition(Automate &automate,
                            Symbole *s) override;
};

class E6 : public Etat {
    public :
        E6();
        virtual ~E6();
        void print() const;
        bool transition(Automate &automate,
                            Symbole *s) override;
};

class E7 : public Etat {
    public :
        E7();
        virtual ~E7();
        void print() const;
        bool transition(Automate &automate,
                            Symbole *s) override;
};

class E8 : public Etat {
    public :
        E8();
        virtual ~E8();
        void print() const;
        bool transition(Automate &automate,
                            Symbole *s) override;
};

class E9 : public Etat {
    public :
        E9();
        virtual ~E9();
        void print() const;
        bool transition(Automate &automate,
                            Symbole *s) override;
};