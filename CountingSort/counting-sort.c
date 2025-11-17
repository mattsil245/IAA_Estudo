#include <stdio.h>
#include <stdlib.h>

#include "../gerador_vetor.h"

void countingSort(int *v, int *b, int n, int k){
    int *c = calloc(k+1, sizeof(int));

    for(int j=0; j<n; j++){
        c[v[j]]++;
    }

    for(int i=1; i<=k; i++){
        c[i] += c[i-1];
    }

    for(int j=n-1; j>=0; j--){
        b[c[v[j]] - 1] = v[j];
        c[v[j]]--;
    }

    free(c);
}

int main(){
    int n = 100000;
    int *a = (int*) calloc(n, sizeof(int));
    int *b = (int*) calloc(n, sizeof(int));

    gerar_vetor(a, n);
    countingSort(a, b, n, 6);
    saida_vetor(b, n);
    free(a);
    free(b);
}