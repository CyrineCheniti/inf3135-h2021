#include <stdio.h>

#define LIGNE 5 
#define CARACTERE 50

typedef char mat[LIGNE][CARACTERE];
typedef int matt[LIGNE][CARACTERE];


void afficherMatrice(matt matrice){
    int col,lig;
    for(col=0;col<LIGNE;col++){
        for(lig=0;lig<CARACTERE;lig++){
             if (matrice[col][lig]<32){
                matrice[col][lig]=32;
             }
             printf("%c:" ,matrice[col][lig]);
             printf("%d " ,matrice[col][lig]);
             fprintf(stderr,"%c " ,matrice[col][lig]);
        }
        printf("\n");
    }
}

void avg(mat mat1, mat mat2, matt matresultat){
   int col,lig;  
   for(col=0;col<LIGNE;col++){
        for(lig=0;lig<CARACTERE;lig++){
            matresultat[col][lig]=(mat1[col][lig]+mat2[col][lig])/2;              
        }
    }
    afficherMatrice(matresultat);
}

void add(mat mat1, mat mat2, matt matresultat){
   int col,lig;  
   for(col=0;col<LIGNE;col++){
        for(lig=0;lig<CARACTERE;lig++){
            matresultat[col][lig]=mat1[col][lig]+mat2[col][lig];            
        }
    }
    afficherMatrice(matresultat);
}

int main(){
 mat mat1={{"Les Canadiens sont une equipe de hockey"},{"Les Nordiques sont de Quebec"},{"Ils ne FONT pas de politique"},{"Super moi non plus"},{"Hourra!"}};
 mat mat2={{"Je dors ZZZ zzz"},{"Le cours de C est le meilleur"},{"J'aime apprendre"},{"Nous avons tous le temps pour un bon repas"},{"UQAM est mon univers"}};
 matt matresultat;
 avg(mat1,mat2,matresultat);
 printf("\n");
 add(mat1,mat2,matresultat);
 return 0;
}
