/*******************************************************************************
 * main.c                                                                      *
 * Propósito: Calcular o número máximo de ciclistas que devem sair das         *
 *            franquias para o atendimento aos clientes na cidade.             *
 *                                                                             *
 * @author Jéssica Taís C. Rodrigues                                           *
 * @version 1.0 19/05/2017                                                     *
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "grafo.h"
#include "fluxo.h"

#define INF INT_MAX

int main(void){
    int V, A, F, C, i, u, v, m, fluxoMax;
    int s, t; //Vértices para algoritmo de fluxo
    Grafo *g;

    scanf("%d %d %d %d", &V, &A, &F, &C);

    s = V, t = V+1;
    g = criaGrafo(V+2);

    for(i = 0; i < A; i++){
        scanf("%d %d %d", &u, &v, &m);
        insereAresta(g, u, v, m, 0);
    }

    for(i = 0; i < F; i++){
        scanf("%d", &u);
        insereAresta(g, s, u, INF, 0);
   }

   for(i = 0; i < C; i++){
        scanf("%d", &v);
        insereAresta(g, v, t, INF, 0);
    }

    fluxoMax = fluxoMaximo(g, s, t);
    printf("%d\n", fluxoMax);

    liberaGrafo(g);

    return 0;
}