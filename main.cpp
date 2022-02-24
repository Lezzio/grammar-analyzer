#include <iostream>
#include "Automate.h"


int main(int argc, char *argv[]) {
    string in;
    bool negatifs = false;
    if (argc >= 2) {
        cout << "Expression evaluee : " << argv[1] << endl;
        string expr = argv[1];

        if (argc == 3 && strcmp(argv[2],"[NEGATIVE=TRUE]") == 0){
            negatifs = true;
        }
        auto *a = new Automate(expr, negatifs);
        a->run();
        delete (a);
        return 0;
    }

    while (true) {
        cout << "Veuillez saisir l'expression a analyser svp ou '-quit' pour quitter le programme: " << endl;
        getline(cin, in);
        if (in == "-quit") {
            cout << "Fermeture de l'analyseur" << endl;
            break;
        }
        auto *a = new Automate(in, negatifs);
        a->run();
        delete (a);
    }

    return 0;
}