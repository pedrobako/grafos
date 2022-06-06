#ifndef LISTA_ADJACENCIA_H_INCLUDED
#define LISTA_ADJACENCIA_H_INCLUDED
#include "estruturas.h"

TAdj* inicia_adjacente();

void insere_aresta_lista_adjacencia_interno(TVertice *vertice, int id);

void insere_aresta_lista_adjacencia(TVertice *vertices, TAresta aresta);

void imprime_lista_adj(TGrafo *grafo);

#endif // LISTA_ADJACENCIA_H_INCLUDED
