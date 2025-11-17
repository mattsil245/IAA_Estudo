#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "gerador_vetor.h"

#define MAIOR_NUMERO 6

void gerar_vetor(int *vetor, int n){
    srand(time(NULL));

    for(int i=0; i<n; i++){
        int num = rand() % MAIOR_NUMERO;
        vetor[i] = num;
    }
}

void saida_vetor(int * vetor, int tamanho){
    printf("Tentando criar arquivo...\n");

    FILE *pont_arq;
    int r;

    pont_arq = fopen("arquivo.txt", "w");
   
    if (pont_arq == NULL)
    {
    printf("Erro ao tentar abrir o arquivo!");
    exit(1);
    }
    printf("Tentando criar arquivo...\n");


    for(int i=0; i<tamanho; i++){
        if(i % 9 == 0 && i != 0){
            r = fprintf(pont_arq, "%d\n", vetor[i]);
        }else{
            r = fprintf(pont_arq, "%d ", vetor[i]);
        }

        if( r == EOF)
        {
            printf("Erro ao tentar gravar os dados! \n");
        }
        else
            {
                printf("Dados gravados com sucesso. \n");
            }
    }

    fclose(pont_arq);
}

