#include <stdio.h>

enum Nombre_e {
  INT, FLOAT, DOUBLE
};

typedef struct {      // Un nombre
  enum Nombre_e type; // Le type de nombre
  union {
    int i;
    float f;
    double d;
  } valeur;       // La valeur
} Nombre_t;

Nombre_t max(Nombre_t a, Nombre_t b){
 switch (a.type){
 case 0 : switch(b.type){
      case 0: return (a.valeur.i<b.valeur.i)? b:a;
      case 1: return (a.valeur.i<b.valeur.f)? b:a;
      case 2: return (a.valeur.i<b.valeur.d)? b:a;
      }
 case 1 : switch(b.type){  
      case 0:return (a.valeur.f<b.valeur.i)? b:a;
      case 1:return (a.valeur.f<b.valeur.f)? b:a;
      case 2:return (a.valeur.f<b.valeur.d)? b:a;
      }
 case 2 : switch(b.type){ 
      case 0:return (a.valeur.d<b.valeur.i)? b:a;
      case 1:return (a.valeur.d<b.valeur.f)? b:a;
      case 2:return (a.valeur.d<b.valeur.d)? b:a;
      }
 }
}
int main (){
  Nombre_t a= {INT, 10};
  Nombre_t b= {INT, 80};
  Nombre_t c=max(a,b);
  printf("%d\n", c.valeur.i);   
  return 0; 
}





