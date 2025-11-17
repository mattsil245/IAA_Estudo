#include <stdio.h>
#include <stdlib.h>

#include "../gerador_vetor.h"

void insertion_sort(int * A, int tam){
    int i,j;
    for(j=1; j<tam; j++){
        int chave = A[j];
        i = j-1;

        while(i>=0 && A[i]<chave){
            A[i+1] = A[i];
            i = i-1;
        }

        A[i+1] = chave;
    }
}

int main(){
    int n = 10000;
    int * v = (int*) malloc(n * sizeof(int));
    gerar_vetor(v, n);
/*      for(int i = 0; i<n; i++){
        scanf("%d", &v[i]);
    } */

    /* printf("Vetor não ordenado: ");
    for(int i = 0; i<n; i++){
        printf("%d ", v[i]);
    }

    printf("\n"); */
    insertion_sort(v, n); 

    /* printf("Vetor ordenado: ");
    for(int i = 0; i<n; i++){
        printf("%d ", v[i]);
    } */

    saida_vetor(v, n);

    return 0;
}