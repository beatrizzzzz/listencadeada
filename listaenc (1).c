#include <stdio.h>
#include <stdlib.h>
#include "listaenc.h"

//1. Cria uma Lista//

void cria (tLista *lista) {
    lista->cabeca = NULL;
    lista->tamanho = 0;
}

//2. Verificar se está vazia//
int vazia (tLista lista) {
    if (lista.tamanho == 0)
        return 1;
    else
        return 0;
}

//3. Retorna o tamanho//
int tamanho (tLista lista) {
    return lista.tamanho;
}

//4. Retorna o elemento de determinada posição//
int obtervalor (tLista lista, int pos, int *dado ) {
    tNo *p;
    int n = 1;

    if (lista.cabeca == NULL) {
            return 0;
    }

    p = lista.cabeca;
    while ((p != NULL) && (n < pos)){
        
        p = p-> prox;
        n++;
    }

	 if (p == NULL) {
            return 0;
     }

    *dado = p->dado;
    return 1;
}

//Retorna a posicao de um elemento pesquisado.
  
int posicao (tLista lista, int dado) {
    int n = 1;
    tNo *p;

    if ( lista.cabeca == NULL) {
            return 0;
    }

    p = lista.cabeca;
	while (p != NULL) {
        if (p->dado == dado){
            return n;
        }
        p = p->prox;
        n++;
    }

    return 0;
}

int insereInicioLista(tLista *lista, int valor) {
    tNo *novoNo;

    /* Aloca memoria para novo no */
    novoNo = malloc(sizeof(tNo));
    if (novoNo == NULL) { /* mem. insuf. */
		 return 0;
    }

    /* Insere novo elemento na cabeca da lista */
    novoNo->dado = valor;
    novoNo->prox = NULL;
    lista->cabeca = novoNo;
    lista->tamanho++;
    return 1;
}

int insereMeioLista(tLista *lista, int pos, int dado){
    tNo *p, *novoNo;

    int n = 1;
    p = lista->cabeca;
    while ((n < pos-1) && (p != NULL)){
          p = p->prox;
          n++;
    }

    if (p == NULL) { 
            return 0;
    }

    novoNo = malloc(sizeof(tNo));
    if (novoNo == NULL) { 
		 return 0;
    }

    /* Insere novo elemento apos p */
    novoNo->dado = dado;
    novoNo->prox = p->prox;
    p->prox = novoNo;
    lista->tamanho++;

    return 1;
}

int insereFimLista(tLista *lista, int dado){
    tNo *novoNo;

    /* Aloca memoria para novo no */
    novoNo = malloc(sizeof(tNo));
    if (novoNo == NULL) { /* mem. insuf. */
		 return 0;
    }

    novoNo->dado = dado;

    /* Procura o final da lista */
    tNo *ult = lista->cabeca;
    while(ult->prox != NULL){
        ult = ult->prox;
    }

    ult->prox = novoNo;
    novoNo->prox = NULL;
    lista->tamanho++;

    return 1;
}

//5. Insere o elemento de determinada posição//
int inserir(tLista *lista, int pos, int dado ) {
    tNo *p, *novoNo;
    int  ret, tamanho = lista->tamanho;

    if ((vazia(*lista)) || (pos == 1)){
        ret = insereInicioLista(lista, dado);
        return ret;
    }
    else if (pos == tamanho+1){
        ret = insereFimLista(lista, dado);
        return ret;
   }
   else{
        ret = insereMeioLista(lista, pos, dado);
        return ret;
   }
}

int removeInicioLista(tLista *lista, int *dado){
    tNo *p = lista->cabeca;

    /* dado recebe o dado removido*/
    *dado = p->dado;

    /* retira o 1o elemento da lista (p)*/
    lista->cabeca = p->prox;
    lista->tamanho--;

    /* libera a memoria da regiao apontada por p*/
    free(p);

    return 1;
}

int removeNaLista(tLista *lista, int pos, int *dado){
     tNo *aux, *p;
     int n = 1;

     /* Localiza o n� que ser� removido*/
     p = lista->cabeca;
     while((n < pos) && (p != NULL)){
           aux = p;
           p = p->prox;
           n++;
     }

     if (p == NULL) { /* pos. inv�lida */
        return (0);
     }

    /* retira o elemento da lista */
    *dado = p->dado;
     aux->prox = p->prox;
     lista->tamanho--;

     free(p);
     return 1;
}

//6. Remove o elemento de determinada posição//
int remover (tLista *lista, int pos, int *dado ) {
    int  ret;

    /* Lista vazia */
    if (vazia(*lista)) {
            return 0;
    }

    /*remo�o do elemento da cabe�a da lista */
    if (pos == 1){
        ret = removeInicioLista(lista, dado);
        return ret;
    }
    /* remo�o em outro lugar da lista*/
    else{
        ret = removeNaLista(lista, pos, dado);
        return ret;
    }
}