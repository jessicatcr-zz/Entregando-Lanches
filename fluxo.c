/*******************************************************************************
 * fluxo.c                                                                     *
 * Propósito:                                                                  *
 *                                                                             *
 * @author Jéssica Taís C. Rodrigues                                           *
 * @version 1.0 19/05/2017                                                     *
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "grafo.h"
#include "fila.h"
#include "lista_adj.h"
#include "fluxo.h"

#define INF INT_MAX

int min(int a, int b){
    if(a < b)
        return a;
    else
        return b;
}

void bfs(Grafo *g, int inicial, Aresta **caminhoAumentado){
    int i, *atual;
    Fila *f;
    Aresta *a;

    for(i = 0; i < g->nVertices; i++) caminhoAumentado[i] = NULL;

    f = criaFilaVazia();
    enfileira(f, &inicial);
    while(!filaVazia(f)){
        atual = desenfileira(f);
        for(a = g->vertices[*atual]->primeiro; a != NULL; a = a->prox){
            if(caminhoAumentado[a->vDestino] == NULL &&
               a->vDestino != inicial && a->capacidade > a->fluxo){
                caminhoAumentado[a->vDestino] = a;
                enfileira(f, &(a->vDestino));
            }
        }
    }

    liberaFila(f);
}

int fluxoMaximo(Grafo *g, int inicial, int final){
    int fluxo = 0, menorfluxo, temCaminhoAumentado = 1;
    Aresta *a, *aRev, *caminhoAumentado[g->nVertices];

    while(temCaminhoAumentado){

        bfs(g, inicial, caminhoAumentado);

        if(caminhoAumentado[final] == NULL){
            temCaminhoAumentado = 0;
        }else{
            menorfluxo = INF;
            for(a = caminhoAumentado[final]; a != NULL; a = caminhoAumentado[a->vOrigem]){
                menorfluxo = min(menorfluxo, a->capacidade - a->fluxo);
            }

            for(a = caminhoAumentado[final]; a != NULL; a = caminhoAumentado[a->vOrigem]){
                a->fluxo += menorfluxo;
                aRev = pegaAresta(g, a->vDestino, a->vOrigem);
                if(aRev == NULL){
                    insereAresta(g, a->vDestino, a->vOrigem, 0, 0);
                    aRev = pegaAresta(g, a->vDestino, a->vOrigem);
                }
                aRev->fluxo -= menorfluxo;                
            }

            fluxo += menorfluxo;
        }
    }

    return fluxo;
}