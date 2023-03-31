#ifndef LISTAENC_H_INCLUDED
#define LISTAENC_H_INCLUDED

typedef struct no{
    int dado;   
    struct no *prox; 
}tNo; 

typedef struct lista{
   struct no *cabeca;
   int tamanho;
}tLista;

void cria (tLista *lista);
int vazia (tLista lista);
int tamanho (tLista lista);
int obtervalor (tLista lista, int pos, int *dado );
int posicao (tLista lista, int dado);
int inserir (tLista *lista, int pos, int dado );
int remover (tLista *lista, int pos, int *dado );


#endif // LISTAENC_H_INCLUDED
