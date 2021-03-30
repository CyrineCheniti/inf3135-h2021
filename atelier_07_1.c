#include <stdio.h>

#define COL 3
#define LIG 3

typedef int mat[COL][LIG];

void afficherMatrice(mat matrice){
    int col,lig;
    for(col=0;col<COL;col++){
        for(lig=0;lig<LIG;lig++){
             printf(" %d " ,matrice[col][lig]);
        }
        printf("\n");
    }
}

void additionnerMatrices(mat matrice1, mat matrice2, mat resultat){
    afficherMatrice(matrice1);
    printf("+\n");
    afficherMatrice(matrice2);
    printf("=\n");
    for (int i=0;i<COL;++i){
          for (int j=0;j<LIG;++j) {
              resultat[i][j] = matrice1[i][j] + matrice2[i][j];
          }
    }
    afficherMatrice(resultat);
}

int main() {
    mat matrice = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    mat matrice1 = { {1, 2, 3}, {3, 2, 1}, {1, 2, 3} };
    mat matrice2 = { {4, 3, 2}, {2, 3, 4}, {4, 3, 2} };
    mat resultat;
    afficherMatrice(matrice);
    printf("\n\n");
    additionnerMatrices(matrice1, matrice2, resultat);
    return 0;
}
