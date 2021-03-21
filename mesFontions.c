#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

void boucleAvant(int x){
   for (int i=0; i<x; ++i){
        printf("%d", i);
   }
}

void boucleApres(int x){
   for (int j=0; j<x; j++){
        printf("%d", j);
   }
}

int racineCarreEnitiere(int x){
    int i=0;
    int rc=0;
    do {
       rc=i*i;
       i+=1;
    } while (rc<x);
    if (rc==x){
     i=i-1;
    } else {
     i=i-2;
    }
    return i;
}

int somme (int len, int t[]){
    int total=0;
    for (long int i=0; i<len; ++i){
       total+=t[i];
    }
    return total;
}

bool estTrie(long int x, int t[]){
     for (int i = 0; i < x; ++i){
      if(t[x-1] < t[x-2])
         return false;
     }
     return true;
}

int elementPlusFrequent(int size, int t[]){
     int frequent;
     int test;
     int count=0;
     int maxcount=0;
     for (int i=0; i<size-1; ++i){
         test=t[i];
         count=1;
         for (int k=i+1;k<size; ++k){
            if (t[i]==t[k]) count +=1;
         }
         if (count > maxcount){
            maxcount = count;
            frequent = test;
         }
      }
      return frequent;
}	

int main (void) {
   int x=8;
   printf("%s\n", "Le boucle Avant :");
   boucleAvant(x);
   printf("\n");
   printf("%s\n", "Le boucle Apres :");
   boucleApres(x);
   printf("\n");
   int rc=racineCarreEnitiere(x);
   printf("%s\n", "La racine carre Entiere :");
   printf("%d\n", rc);
   int tab[] = {0,2,3,47,5,43,3,2,6,90,12,34,65,6,89,8};
   int size= 16;
   printf("%s\n", "La somme du tableau :");
   int ret=somme(16, tab);
   printf("%d\n", ret);
   bool trie=estTrie(16, tab);
   printf("%s\n", "Le tableau est trie ? :");
   printf("%d\n", trie);
   int epf=elementPlusFrequent(16, tab);
   printf("%s\n", "L'element le plus frequent dans le tableau :");
   printf("%d\n", epf); 
   return 0;
}
