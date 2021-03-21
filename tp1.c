#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Reponse{
    char *indice;
    char *classement;
    char *classe_dividend;
    float prix_marche;
    float dividend;
};

/*
* Vérifier si le caractère est un numéro.
* @param c : le caractère.
* @return : 1 si le caractère est un numéro et 0 sinon.
*/

int estNum(char c){
    if(c<='9' && c>='0')
        return 1;
    else
        return 0;
}

/*
* Convertir une chaîne en float.
* @param c : la chaîne.
* @return : un float.
*/

float conv_float(const char *str)
{
    while (*str && !(estNum(*str) || ((*str == '-' || *str == '+') && estNum(*(str + 1)))))
        str++;

    return strtof(str, NULL);
}

struct Reponse recuperer_json(char indice[]){
   
 FILE    *infile;
 char name[100];

 strcpy(name,"data/");
 strcat(name,indice);
 strcat(name,".json");
 infile = fopen(name, "r");
 
 char **tab_rep;
 char str[1000];
 int i =0;
 int j = 0;
 char ch;
 tab_rep = (char**)malloc(500*(1000*sizeof(char)));

 while ((ch = fgetc(infile)) != EOF) {
    if(ch!=',') {
        str[i++]= ch;
    } else {
        tab_rep[j] =(char*) malloc(strlen(str)*sizeof(char));
        memcpy(tab_rep[j++],str,strlen(str));
        i = 0;
        memset(str,0,strlen(str));
    }
 }
 struct Reponse r;
 long int ftwl=0, ftwh=0;
 float rmp=0, tady=0;
 
 for(int i=0;i<j;i++) {
   if(strstr(tab_rep[i],"\"fiftyTwoWeekLow\":")!=0)
       { ftwl = (long int)(conv_float(tab_rep[i])*1000);          
   } else if(strstr(tab_rep[i],"\"fiftyTwoWeekHigh\":")!=0)
       { ftwh = (long int)(conv_float(tab_rep[i])*1000);
   } else if(strstr(tab_rep[i],"\"regularMarketPrice\":")!=0)
       { rmp = conv_float(tab_rep[i]); 
   } else if(strstr(tab_rep[i],"\"trailingAnnualDividendYield\":")!=0)
       { tady = conv_float(tab_rep[i]);
   }
 }
 r.indice =indice;
 float cx = 1- ((float)(ftwh-(long int)rmp*1000)/(float)(ftwh-ftwl)); 
 if (cx<0.25){
   r.classement="C-1";

 } else if (cx<0.5){
   r.classement="C-2";
 } else if( cx<0.75){
   r.classement="C-3";
 } else {
   r.classement="C-4";
 }
 
 if (tady<0.03){
   r.classe_dividend="DIV-1";
 } else if (tady<0.06){
   r.classe_dividend="DIV-2";
 } else {
   r.classe_dividend="DIV-3";
 }
 r.dividend=tady;
 r.prix_marche=rmp;
 
 return r;
}
 void afficher(struct Reponse r){
    printf ("%s\t",r.indice);
    printf ("%s\t",r.classement);
    printf ("%s\t",r.classe_dividend);
    printf ("%5.2f\t",r.prix_marche);
    printf ("%5.2f%%\n",r.dividend);

 }
 
int main(void) {
       
   char indice[200];
   char nom[100][200];
   int i=0;
   struct Reponse result;
   while(fgets(indice, sizeof(indice), stdin) != NULL) {  
         int l = strlen(indice);
         memcpy(nom[i],indice,l-1);
         i++;             
   } 
 
   for (int j = 0; j < i; j++) {    
        result = recuperer_json(nom[j]);
        afficher(result);
   }
   return 0;
}
