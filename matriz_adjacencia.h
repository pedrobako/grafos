#ifndef MATRIZ_ADJACENCIA_H_INCLUDED
#define MATRIZ_ADJACENCIA_H_INCLUDED
#include "estruturas.h"

int** insere_vertice_matriz_adj(int **matriz_adj, int qtde_vertices);

void insere_aresta_matriz_adjacencia(int **matriz_adj, TAresta aresta);

void imprime_matriz_adj(int **Matriz_adj, int Qtde_vertices);

int* busca_caminho_matriz_adj(int **Matriz_adj, int qtde_vertices, int id_u, int id_v);

void imprime_caminho(int *caminho);

#endif // MATRIZ_ADJACENCIA_H_INCLUDED
