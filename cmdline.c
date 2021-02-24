#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int cmdline(char input){
   int codeRetour=0;
   switch(input){
    case 'd': 
    codeRetour =3;
    break;
    case 'c':
    codeRetour=1;
    break;
    case 'v':
    codeRetour =2;
    break;
    default:
    break;
   }
   return codeRetour;
}

bool numeric(char *str){
  while (*str) {
        if (isdigit(*str++) == 0) return true;
  }
   return false;
}

int main(int argc, char *argv[]){
     int reslt=0;
     bool check=false;
     for (int i=1; i<argc; i++){
        if (strcmp(argv[i],"-c")==0){
              check=true; 
             if (strlen(argv[i+1])!=12){
                    reslt=cmdline('c');  
              }
        } else if (strcmp(argv[i],"-d")==0){
              if (strcmp(argv[i+1],"INC")!=0 &&  strcmp(argv[i+1],"DEC")!=0){
                    reslt=cmdline('d');
              }
        } else if (strcmp(argv[i],"-v")==0){
             if(numeric(argv[i+1])){
                   reslt=cmdline('v');
             } 
        } else if (i==argc-1 && check==false){
                   reslt=cmdline('c');                   
        }
        
     }
     printf("\n%d\n",reslt);
     return reslt;
       
}

