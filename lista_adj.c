/*******************************************************************************
 * lista_adj.c                                                                 *
 * Propósito:                                                                  *
 *                                                                             *
 * @author Jéssica Taís C. Rodrigues                                           *
 * @version 1.0 19/05/2017                                                     *
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "lista_adj.h"


Lista *criaListaVazia(void){
    Lista *l = malloc(sizeof(Lista));
    l->primeiro = NULL;
    l->ultimo = NULL;
    return l;
}

int listaVazia(Lista *l){
    return (l->primeiro == NULL);
}

void insereArestaLista(Lista *l, int vOrigem, int vDestino, int capacidade, int fluxo){
    Aresta *novaAresta = malloc(sizeof(Aresta));
    novaAresta->vOrigem = vOrigem;
    novaAresta->vDestino = vDestino;
    novaAresta->capacidade = capacidade;
    novaAresta->fluxo = fluxo;
    novaAresta->ant = NULL;
    novaAresta->prox = NULL;

    if(listaVazia(l)){
        l->primeiro = novaAresta;
        l->ultimo = l->primeiro; 
    }else{
        novaAresta->ant = l->ultimo;
        l->ultimo->prox = novaAresta;
        l->ultimo = novaAresta;
    }
}

Aresta *pegaArestaLista(Lista *l, int vertice){
    Aresta *aux = l->primeiro;
    while(aux != NULL && aux->vDestino != vertice){
        aux = aux->prox;
    }
    return aux; //NULL se não achar    
}


void removeArestaLista(Lista *l, int vertice){
    Aresta *aux = l->primeiro;
    while(aux != NULL && aux->vDestino != vertice){
        aux = aux->prox;
    }

    if(aux != NULL){
        if(aux->ant != NULL){
            aux->ant->prox = aux->prox;
        }else{
            l->primeiro = aux->prox;  
        } 
        if(aux->prox != NULL){
            aux->prox->ant = aux->ant;    
        }else{
            l->ultimo = aux->ant;
        }
        free(aux);
    }
}

void alteraArestaLista(Lista *l, int vertice, int capacidade, int fluxo){
    Aresta *aux = l->primeiro;
    while(aux != NULL && aux->vDestino != vertice){
        aux = aux->prox;
    }

    if(aux != NULL){
        aux->capacidade = capacidade;
        aux->fluxo = fluxo;
    }
}

void liberaLista(Lista *l){
    Aresta *aux;
    while(!listaVazia(l)){
        aux = l->primeiro->prox;
        free(l->primeiro);
        l->primeiro = aux;
    }
    free(l);
}
