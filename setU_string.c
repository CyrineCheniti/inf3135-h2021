#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int nmb_elems;
    int capacite;
    char *elems;
} Set;

void set_ajouter(Set *set, char elm){
    if (set->capacite!=100){
        set->nmb_elems=0;
        set->capacite = 100;
        set->elems = malloc(sizeof(int) * set->capacite); 
        set->elems[set->nmb_elems++] =elm;
     } else {
         bool test=false;
         for (int i = 0; i < set->nmb_elems; ++i) {
             if (set->elems[i]==elm){
                test=true;
             }
         }
         if (test==false){
             set->elems[set->nmb_elems++] =elm;
         }
       
    }
}
/*
Set* set_union(Set *s1, Set *s2){
    Set *s3;
    s3->nmb_elems=s1->nmb_elems+s2->nmb_elems;;
    s3->capacite= 100;   
    s3->elems = malloc(sizeof(int) * s3->capacite);
    int i;
    for (i=0; i < s1->nmb_elems; ++i) {
         s3->elems[i] =s1->elems[i];
    }
    i++;
    for (int j = 0; j < s2->nmb_elems; ++j) {
         s3->elems[i] =s2->elems[j];
         i++; 
    }
    return *s3;
}
*/
void set_supprimer(Set *set, char *elm){
     for (int i = 0; i < set->nmb_elems; ++i) {
        if (strcmp(set->elems[i],elm)==0){
         
            for (int j=i; j < set->nmb_elems; ++j) {
               strcpy(set->elems[j],set->elems[j+1]);    
            }
        }    
     }
     set->nmb_elems--;
}

void set_rechercher( Set *set, char *elm){
   bool test=false;
    for (int i = 0; i < set->nmb_elems; ++i) {
        if (strcmp(set->elems[i],elm)==0){
            printf("L'élement est trouvé à la position %d.\n",i+1);
            test=true; 
        }
    }
    if (test==false)
       printf("L'élement n'est pas trouvé.\n");
    
}

void set_vider(Set *set){
 free(set->elems);
 set->nmb_elems=0;
}

int main(){
   Set set;
   set_ajouter(&set,"hello");
   printf("%d\n",set.nmb_elems);
   printf("%d\n",set.elems[0]);
   set_ajouter(&set,"world");
   printf("%d\n",set.elems[1]);
   set_supprimer(&set,"hello");
   printf("%d\n",set.elems[2]);
   set_rechercher(&set,"world");
   set_vider(&set);
   printf("%d\n",set.nmb_elems); 
}
