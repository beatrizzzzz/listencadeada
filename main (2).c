#include <stdio.h>
#include <stdlib.h>
#include "listaenc.h"

#define TRUE 1
#define FALSE 0

int main()
{
    tLista minhaLista;
    int i, dado;

    cria(&minhaLista);

    if (vazia(minhaLista) == FALSE){
        printf("Lista criada nao estava vazia!\n");
    }

    inserir(&minhaLista, 1, 1);
    inserir(&minhaLista, 2, 2);
    inserir(&minhaLista, 3, 3);
    inserir(&minhaLista, 4, 4);

    inserir(&minhaLista, 3, 25);
    inserir(&minhaLista, 5, 35);

    printf("Posição do elemento 1 = %d \n", posicao(minhaLista, 1));
    printf("Posição do elemento 3 = %d \n", posicao(minhaLista, 3));
    printf("Posição do elemento 4 = %d \n", posicao(minhaLista, 4));

    printf("\nLista antes da remocao \n");
    for (i = 0; i < tamanho(minhaLista); i++){
        obtervalor(minhaLista, i+1, &dado);
        printf("%dº elemento da lista = %d\n",
               i+1, dado);
    }

    remover(&minhaLista, 3, &dado);
    printf("\nDado removido = %d \n\n", dado);

    printf("Lista depois da remocao \n");
    for (i = 0; i < tamanho(minhaLista); i++){
        obtervalor(minhaLista, i+1, &dado);
        printf("%dº elemento da lista = %d\n",
               i+1, dado);
    }
    return 0;
}

