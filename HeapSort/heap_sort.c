#include <stdio.h>
#include <stdlib.h>

#include "../gerador_vetor.h"

int esquerda(int i){
    return (2*i)+1;
}

int direita(int i){
    return (2*i)+2;
}

void refazHeapMax(int * A, int i, int compHeap){
    int esq, dir, maior, menor, temp;
    esq = esquerda(i);
    dir = direita(i);

    if(esq < compHeap && A[esq] > A[i]){
        maior = esq;
    }else{
        maior = i;
    }

    if(dir < compHeap && A[dir] > A[maior]){
        maior = dir;
    }

    if(maior != i){
        temp = A[i];
        A[i] = A[maior];
        A[maior] = temp;
        refazHeapMax(A, maior, compHeap);
    }
}

void constroiHeapMax(int * A, int n){
    int compHeap = n;
    for(int i = (n/2)-1; i>=0; i--){
        refazHeapMax(A, i, compHeap);
    }
}

void heapSort(int * A, int n){
    int i, compHeap, temp;

    compHeap = n;
    constroiHeapMax(A, compHeap);

    for(i = n-1; i>0; i--){
        temp = A[0];
        A[0] = A[i];
        A[i] = temp;

        compHeap--;
        refazHeapMax(A, 0, compHeap);
    }
}

int main(){
    int n = 1000000;
    int * v = (int*) malloc(n * sizeof(int));
    gerar_vetor(v, n);
    heapSort(v, n);
    saida_vetor(v, n);
    return 0;
}