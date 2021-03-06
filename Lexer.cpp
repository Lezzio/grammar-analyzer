#include "Lexer.h"
#include <iostream>

bool estUnChiffre(const char c)
{
   return c <= '9' && c >= '0';
}

int charToInt(const char c)
{
   return c - '0';
}

Symbole *Lexer::Consulter()
{
   if (!tampon)
   {

      if (tete == flux.length())
         tampon = new Symbole(FIN);
      else
      {

         switch (flux[tete])
         {
         case '(':
            tampon = new Symbole(OPENPAR);
            tete++;
            break;
         case ')':
            tampon = new Symbole(CLOSEPAR);
            tete++;
            break;
         case '*':
            tampon = new Symbole(MULT);
            tete++;
            break;
         case '+':
            tampon = new Symbole(PLUS);
            tete++;
            break;
         case ' ':
            tete++;
            tampon = this->Consulter();
            break;
         default:
            if (estUnChiffre(flux[tete]))
            {
               int resultat = charToInt(flux[tete]);
               while (estUnChiffre(flux[++tete]))
               {
                  resultat = resultat * 10 + charToInt(flux[tete]);
               }
               tampon = new Entier(resultat);
            }
            else if (negatifs && flux[tete++] == '-' && estUnChiffre(flux[tete]))
            {
               int resultat = charToInt(flux[tete]);
               while (estUnChiffre(flux[++tete]))
               {
                  resultat = resultat * 10 + charToInt(flux[tete]);
               }
               tampon = new Entier(-resultat);
            }
            else
            {
               tampon = new Symbole(ERREUR);
            }
         }
      }
   }
   return tampon;
}

void Lexer::Avancer()
{
   tampon = nullptr;
}

void Lexer::SetTampon(Symbole *s)
{
   tampon = s;
}