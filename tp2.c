#include "outil3.c"
#include "outil3.h"

int main(int argc, char *argv[]) {
 char indice[200];
 char nom[100][200];
 int i=0;
 struct Reponse result;
 char *rep[4]={"C-5", "DIV-5", "N", "N"};
 struct stat s;  
 while(fgets(indice, sizeof(indice), stdin) != NULL) {
  int l = strlen(indice);
  memcpy(nom[i],indice,l-1);
  i++;
 }   
 int c=cmdline(argc,argv, rep);
  if (c==1){
   for (int j = 0; j < i; j++) {
    result = recuperer_json(nom[j]);
    afficher(result,&s,rep);
   }
     afficherStat(s, rep);
  }
   return 0;
}

