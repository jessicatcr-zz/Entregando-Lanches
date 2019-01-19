/*******************************************************************************
 * fluxo.h                                                                     *
 * Propósito: Apenas uma interface para o método do cálculo de fluxo máximo    *
 * Declara:                                                                    *
 *     - fluxoMaximo: calcula o fluxo máximo em um grafo                       *
 *                                                                             *
 * @author Jéssica Taís C. Rodrigues                                           *
 * @version 1.0 19/05/2017                                                     *
 ******************************************************************************/
#ifndef _FLUXO_H_
#define _FLUXO_H_

/**
 * Calcula o fluxo máximo em um grafo.
 *
 * @param  Grafo* g    ponteiro para o grafo
 * @param  int    s    vertice inicial do fluxo
 * @param  int    t    vertice final do fluxo   
 * @return int         fluxo máximo no grafo de s para t 
 */
int fluxoMaximo(Grafo *g, int s, int t);

#endif