/*******************************************************************************
 * fila.c                                                                      *
 * Propósito:                                                                  *
 *                                                                             *
 * @author Jéssica Taís C. Rodrigues                                           *
 * @version 1.0 19/05/2017                                                     *
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

Fila* criaFilaVazia(void) {
    Fila *f = malloc(sizeof(Fila));
    f->primeiro = NULL;
    f->ultimo = NULL;
    return f;
}

int filaVazia(Fila *f) {
    return (f->primeiro == NULL);
}

void enfileira(Fila *f, void *item) {
    Celula *novaCelula = malloc(sizeof(Celula));
    novaCelula->item = item;
    novaCelula->prox = NULL;

    if(filaVazia(f)){
        f->primeiro = novaCelula;
        f->ultimo = f->primeiro; 
    }else{
        f->ultimo->prox = novaCelula;
        f->ultimo = novaCelula;
    }
}

void* desenfileira(Fila *f) {
    void *item = NULL;
    Celula *aux;
    if(!filaVazia(f)){
        item = f->primeiro->item;
        aux = f->primeiro;
        f->primeiro = f->primeiro->prox;
        free(aux);
    }

    return item;
}

void liberaFila(Fila *f) {
    Celula *aux;
    while(!filaVazia(f)){
        aux = f->primeiro->prox;
        free(f->primeiro);
        f->primeiro = aux;
    }
    free(f);
}

