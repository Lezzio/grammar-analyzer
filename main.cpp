#include <iostream>
#include <cstring>
#include "Automate.h"

int main(int argc, char *argv[])
{
    string in, neg;
    bool negatifs = false;
    if (argc >= 2)
    {
        cout << "Expression évaluée : " << argv[1] << endl;
        string expr = argv[1];

        if (argc == 3 && strcmp(argv[2], "-neg") == 0)
        {
            negatifs = true;
        }
        auto *a = new Automate(expr, negatifs);
        a->run();
        delete (a);
        return 0;
    }

    cout << "Saisissez '-neg' pour que l'automate reconnaisse les entiers negatifs sinon Entree" << endl;
    getline(cin, neg);
    negatifs = (neg == "-neg");
    if (negatifs)
    {
        cout << "L'automate prend en charge les entiers negatifs" << endl;
    }
    else
    {
        cout << "L'automate ne prend pas en charge les entiers negatifs" << endl;
    }

    while (true)
    {
        cout << "Veuillez saisir l'expression a analyser svp ou '-quit' pour quitter le programme: " << endl;
        getline(cin, in);
        if (in == "-quit")
        {
            cout << "Fermeture de l'analyseur" << endl;
            break;
        }

        auto *a = new Automate(in, negatifs);
        a->run();
        delete (a);
    }

    return 0;
}