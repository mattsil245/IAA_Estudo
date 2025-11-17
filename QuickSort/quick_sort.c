#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../gerador_vetor.h"

int particao(int *A, int p, int r){
    int x, i, j, temp;
    x = A[r];
    i = p-1;
    j = p;

    while(j <= r-1){
        if(A[j] <= x){
            i++;
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
        j++;
    }

    temp = A[i+1];
    A[i+1] = A[r];
    A[r] = temp;
    return (i+1);
}

int particaoAleatoria(int *A, int p, int r){
    int i, temp;
    double f;
    time_t t;

    srand((unsigned) time(&t));

    f = (rand() % 100)/100.0;
    i = (int) (p + (r-p) * f);

    temp = A[r];
    A[r] = A[i];
    A[i] = temp;
    return particao(A, p, r);
}

void quickSort(int *A, int p, int r){
    int q;
    if(p<r){
        q = particaoAleatoria(A, p, r);
        quickSort(A, p, q-1);
        quickSort(A, q+1, r);
    }
}

int main(){
    int n = 1000000;
    int * v = (int*) malloc(n * sizeof(int));
    gerar_vetor(v, n);
    quickSort(v, 0, n-1);
    saida_vetor(v, n);
}