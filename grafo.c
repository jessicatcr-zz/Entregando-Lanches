/*******************************************************************************
 * grafo.c                                                                     *
 * Propósito:                                                                  *
 *                                                                             *
 * @author Jéssica Taís C. Rodrigues                                           *
 * @version 1.0 19/05/2017                                                     *
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "lista_adj.h"
#include "grafo.h"

Grafo *criaGrafo(int nVertices){
    int i;
    Grafo *g = malloc(sizeof(Grafo));
    g->nVertices = nVertices;
    g->vertices = malloc(nVertices*sizeof(Lista*));
    for(i = 0; i < nVertices; i++){
        g->vertices[i] = criaListaVazia();
    }
    return g;
}

void insereAresta(Grafo *g, int u, int v, int capacidade, int fluxo){
    insereArestaLista(g->vertices[u], u, v, capacidade, fluxo);
}

Aresta *pegaAresta(Grafo *g, int u, int v){
    return pegaArestaLista(g->vertices[u], v);
}

void alteraAresta(Grafo *g, int u, int v, int capacidade, int fluxo){
    alteraArestaLista(g->vertices[u], v, capacidade, fluxo);
}

void removeAresta(Grafo *g, int u, int v){
    removeArestaLista(g->vertices[u], v);
}

void liberaGrafo(Grafo *g){
    int i;

    for(i = 0; i < g->nVertices; i++){
        liberaLista(g->vertices[i]);
    }
    free(g->vertices);
    free(g);
}
