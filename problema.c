#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funciones.h"

int main(void){ 
    int rA, cA;
    int rB, cB;
    int rC, cC;
    srand(time(0));
    
    printf("Dime la cantidad de renglones de la matriz A: ");
    scanf("%d", &rA);
    printf("Dime la cantidad de columnas de la matriz A: ");
    scanf("%d", &cA);
    
    int **A = genera_matriz(rA, cA);
    printf("\n A:\n");
    imprimir_m(A, rA, cA);
    
    printf("Dime la cantidad de renglones de la matriz B: ");
    scanf("%d", &rB);
    printf("Dime la cantidad de columnas de la matriz B: ");
    scanf("%d", &cB);
    
    int **B = genera_matriz(rB, cB);

    printf("\n B:\n");
    imprimir_m(B, rB, cB);

    int **C = calcula_matriz(A, B, rA, cA, rB, cB);
    
    rC = rA * rB;
    cC = cA * cB;
    
    printf("\n C:\n");
    imprimir_m(C, rC, cC);

    return 0;
}