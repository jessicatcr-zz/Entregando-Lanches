/*******************************************************************************
 * fila.h                                                                      *
 * Propósito: Apenas uma interface para a estrutura de fila                    *
 *                                                                             *
 * @author Jéssica Taís C. Rodrigues                                           *
 * @version 1.0 19/05/2017                                                     *
 ******************************************************************************/

#ifndef _FILA_H_
#define _FILA_H_

typedef struct celula{
    void *item;    
    struct celula *prox;    
} Celula;

typedef struct Fila{
    Celula *primeiro;
    Celula *ultimo;
} Fila;

Fila* criaFilaVazia(void);
int filaVazia(Fila *f);
void enfileira(Fila *f, void *item);
void* desenfileira(Fila *f);
void liberaFila(Fila *f);

#endif