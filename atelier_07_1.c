#include <stdio.h>

void afficherMatrice(int matrice[3][3]){
    int col,lig;
    for(col=0;col<3;col++){
        for(lig=0;lig<3;lig++){
             printf(" %d " ,matrice[col][lig]);
        }
        printf("\n");
    }
}
void additionnerMatrices(int matrice1[3][3], int matrice2[3][3], int resultat[3][3]){
    afficherMatrice(matrice1);
    printf("+\n");
    afficherMatrice(matrice2);
    printf("=\n");
    for (int i = 0; i < 3; ++i){
          for (int j = 0; j < 3; ++j) {
              resultat[i][j] = matrice1[i][j] + matrice2[i][j];
          }
    }
    afficherMatrice(resultat);
}
int main() {
    int matrice[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    int matrice1[3][3] = { {1, 2, 3}, {3, 2, 1}, {1, 2, 3} };
    int matrice2[3][3] = { {4, 3, 2}, {2, 3, 4}, {4, 3, 2} };
    int resultat[3][3];
    afficherMatrice(matrice);
    printf("\n\n");
    additionnerMatrices(matrice1, matrice2, resultat);
    return 0;
}
