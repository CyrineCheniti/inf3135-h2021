#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int nmb_elems;
    int capacite;
    int *elems;
} Set;

void set_ajouter(Set *set, int elm){
    if (set->capacite!=100){
        set->nmb_elems=0;
        set->capacite = 100;
        set->elems = malloc(sizeof(int) * set->capacite); 
        set->elems[set->nmb_elems++] =elm;
     } else {
        set->elems[set->nmb_elems++] =elm;
    }
}

void set_supprimer(Set *set, int elm){
     for (int i = 0; i < set->nmb_elems; ++i) {
        if (set->elems[i]==elm){
         
            for (int j=i; j < set->nmb_elems; ++j) {
               set->elems[j]=set->elems[j+1];    
            }
        }    
     }
     set->nmb_elems--;
}

void set_rechercher( Set *set, int elm){
   bool test=false;
    for (int i = 0; i < set->nmb_elems; ++i) {
        if (set->elems[i]==elm){
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
   set_ajouter(&set,2);
   set_ajouter(&set,3);
   printf("%d\n",set.nmb_elems);
   printf("%d\n",set.elems[0]);
   printf("%d\n",set.elems[1]);
   set_rechercher(&set,3);
   set_supprimer(&set,2);
   printf("%d\n",set.elems[0]);
   set_rechercher(&set,2);
   set_vider(&set);
   printf("%d\n",set.nmb_elems);
   return 0;
}
