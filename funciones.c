#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int numrand(int min, int max){
    int num = min + ((float)rand() / (float)(RAND_MAX)) * (max - min);
    return num;
}

void imprimir_m(int **A, int r, int c){
    for(int i = 0; i < r; i++){
        printf("[ ");
        for(int j = 0; j < c; j++){
            char coma = ( j < c - 1) ? ',' : '\0'; 
            printf("%d%c ", A[i][j], coma);
        }
        printf("] \n");    
    }
}

int **genera_matriz(int r, int c) {
    int min = 0;
    int max = 100;
    int **M = (int**)calloc(r,sizeof(int*));
    
    for(int i = 0; i < r; i++){
        M[i] = (int*)calloc(c,sizeof(int));
        for(int j = 0; j < c; j++){
            M[i][j] = numrand(min, max); ;  
        }    
    }
    return M;
}

int ** calcula_matriz(int** A, int** B, int rA, int cA, int rB, int cB) {
    int rC = rA * rB;
    int cC = cA * cB;

    int contadorRenglonesA = 0;
    int contadorColumnasA = 0;
    int contadorRenglonesB = 0;
    int contadorColumnasB = 0;
    
    int **C = (int**)calloc(rA*rB,sizeof(int*));
    
     for(int i = 0; i < rC; i++){
        C[i] = (int*)calloc(cC,sizeof(int));
        for(int j = 0; j < cC; j++){
            C[i][j] =  A[contadorRenglonesA][contadorColumnasA] * B[contadorRenglonesB][contadorColumnasB];
            if ((j+1) >= cB*(contadorColumnasA + 1)) {
                contadorColumnasB = 0;
                contadorColumnasA++;
                if (contadorColumnasA >= cA) {
                    contadorColumnasA = 0;
                    contadorRenglonesB++;
                    if (contadorRenglonesB >= rB) {
                        contadorRenglonesB = 0;
                        contadorRenglonesA++;
                    }
                }
            }
            else {
                contadorColumnasB++;
            }
        }    
    }

    return C;

}

void limpiar(int **M,int r){
    for(int i = 0; i < r; i++){
        free(*(M + i));
    }
    free(M);
}