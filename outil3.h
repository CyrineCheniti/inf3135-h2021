#ifndef _OUTIL3_H_ 
#define _OUTIL3_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#endif
struct Reponse{
    char *indice;
    char *classement;
    char *classe_dividend;
    float prix_marche;
    float dividend;
    int aff;
};

struct stat{
   int c1;
   int c2;
   int c3;
   int c4;
   int d1;
   int d2;
   int d3;
   int cont;
   int contTotal;
};

/*
* Vérifier si le caractère est un numéro.
* @param c : le caractère.
* @return : 1 si le caractère est un numéro et 0 sinon.
*/

int estNum(char c);
/*
* Convertir une chaîne en float.
* @param c : la chaîne.
* @return : un float.
*/

float conv_float(const char *str);
struct Reponse recuperer_json(char indice[]);
void afficherRep(struct Reponse r);
void afficher(struct Reponse r, struct stat *s, char *rep[]);
int cmdline(int nbr, char *args[], char *rep[]);
void afficherStat(struct stat s, char *rep[]);


