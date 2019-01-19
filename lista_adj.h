/*******************************************************************************
 * lista_adj.h                                                                 *
 * Propósito: Apenas uma interface para a estrutura de listas adjancentes e    *
 *            funções relacionadas                                             *
 * @author Jéssica Taís C. Rodrigues                                           *
 * @version 1.0 19/05/2017                                                     *
 ******************************************************************************/

#ifndef _LISTA_ADJ_H_
#define _LISTA_ADJ_H_

typedef struct aresta{
    int vOrigem;
    int vDestino;
    int capacidade;
    int fluxo;
    struct aresta *ant;    
    struct aresta *prox;    
} Aresta;

typedef struct lista{
    Aresta *primeiro;
    Aresta *ultimo;
} Lista;

Lista *criaListaVazia(void);
int listaVazia(Lista *l);
void insereArestaLista(Lista *l, int vOrigem, int vDestino, int capacidade, int fluxo);
Aresta *pegaArestaLista(Lista *l, int vertice);
void removeArestaLista(Lista *l, int vertice);
void alteraArestaLista(Lista *l, int vertice, int capacidade, int fluxo);
void liberaLista(Lista *l);

#endif