#include <stdio.h>
#include <stdlib.h>
#include "../gerador_vetor.h"

int merge(int * A, int p, int q, int r){
    int i, j, k;
    int tam_seq1 = q - p+1;
    int tam_seq2 = r - q;
    int * seq1 = (int*) malloc(sizeof(int) * tam_seq1);
    int * seq2 = (int*) malloc(sizeof(int) * tam_seq2);

    //Copiando sequencia A[p...q]
    for(i=0; i<tam_seq1; i++){
        seq1[i] = A[i+p];
    }

    //Copiando sequencia A[q+1...r]
    for(j=0; j<tam_seq2; j++){
        seq2[j] = A[q+1+j];
    }

    k=p; i=j=0;

    while(i < tam_seq1 && j < tam_seq2){
        if(seq2[j] <= seq1[i]){
            A[k] = seq2[j];
            j++;
        }else{
            A[k] = seq1[i];
            i++;
        }
        k++;
    }

    while(i < tam_seq1){
        A[k] = seq1[i];
        i++;
        k++;
    }
    while(j<tam_seq2){
        A[k] = seq2[j];
        j++;
        k++;
    }

    free(seq1);
    free(seq2);
}

void merge_sort(int * numeros, int p, int r){
    //printf("p: %d r: %d\n", p, r);
    int q;

    if(p<r){
        q = (p+r)/2;
        merge_sort(numeros, p, q);
        merge_sort(numeros, q+1, r);
        merge(numeros, p, q ,r);
    }
}

int * fusao(int * A, int a_length, int * B, int b_length){
    int posa = 0, posb = 0, posc = 0;
    int c_length = a_length + b_length;
    int * c = (int*) malloc(c_length * sizeof(int));

    while(posa < a_length && posb < b_length){
        if(A[posa] < B[posb]){
            c[posc] = A[posa];
            posa++;
        }else{
            c[posc] = B[posb];
            posb++;
        }
        posc++;
    }

    while(posa<a_length){
        c[posc] = A[posa];
        posc++;
        posa++;
    }
    while(posb<b_length){
        c[posc] = B[posb];
        posc++;
        posb++;
    }

    return c;
}

int main(){
    /* int a_tam = 3;
    int b_tam = 2;
    int * a = (int*) malloc(a_tam * sizeof(int));
    int * b = (int*) malloc(b_tam * sizeof(int));

    for(int i=0; i<a_tam; i++){
        scanf("%d", &a[i]);
    }

    for(int i=0; i<b_tam; i++){
        scanf("%d", &b[i]);
    }

    printf("Vetor A: ");
    for(int i=0; i<a_tam; i++){
        printf("%d ", a[i]);
    }

    printf("\n");

    printf("Vetor B: ");
    for(int i=0; i<b_tam; i++){
        printf("%d ", b[i]);
    }

    printf("\n");

    int * c = fusao(a, a_tam, b, b_tam);

    printf("Fusao - Vetor C: ");
    for(int i=0; i<(a_tam+b_tam); i++){
        printf("%d ", c[i]);
    } */

    int n = 1000000;
    int * v = (int*) malloc(n * sizeof(int));
    gerar_vetor(v, n);
    merge_sort(v, 0, n-1);
    saida_vetor(v, n);
    /*printf("\n");
    printf("Merge Sort: ");
    for(int i=0; i<(a_tam+b_tam); i++){
         printf("%d ", c[i]);
    }

/*     free(a);
    free(b);
    free(c); */
    return 0;
}