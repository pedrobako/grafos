#ifndef MATRIZ_INCIDENCIA_H_INCLUDED
#define MATRIZ_INCIDENCIA_H_INCLUDED
#include "estruturas.h"

int** insere_vertice_matriz_inc(int **matriz_inc, int qtde_vertices, int qtde_arestas);

int** insere_aresta_matriz_incidencia(int **matriz_inc, int qtde_vertices, int qtde_arestas, TAresta aresta);

void imprime_matriz_inc(int **matriz_inc, int qtde_vertices, int qtde_arestas);

TAresta busca_aresta(TGrafo grafo, TAresta aresta);

#endif // MATRIZ_INCIDENCIA_H_INCLUDED

