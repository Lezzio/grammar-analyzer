#include <iostream>
#include "Automate.h"


int main(int argc, char *argv[]) {
   string in;

   if(argc == 2){
      cout << "Expression évaluée : " << argv[1] << endl;
      string expr = argv[1];
      Automate *a = new Automate(expr);
      a->run();
      delete (a);
      return 0;
   }
   
   while(true){
      cout << "Veuillez saisir l'expression à analyser svp ou '-quit' pour quitter le programme: "<< endl;
      getline(cin, in);
      if(in == "-quit"){
         cout << "Fermeture de l'analyseur" << endl;
         break;
      }
      Automate *a = new Automate(in);
      a->run();
      delete (a);
   }
   
   return 0;
}