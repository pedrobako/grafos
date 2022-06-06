#ifndef GERAL_H_INCLUDED
#define GERAL_H_INCLUDED
#include "estruturas.h"

//extern struct TAdj;

TVertice* inicia_vertice();

TVertice* recebe_vertice();

void insere_vertice(TGrafo *Grafo, TVertice *vertice);

void insere_vertices_por_arquivo(TGrafo *grafo, char *nome_arq_vertices);

TVertice* busca_vertice_por_id(TGrafo *Grafo, int id);

TVertice* busca_vertice_por_nome(TGrafo *Grafo, char *nome);

void imprime_vertice(TVertice *vertice);

void imprime_vertices(TVertice *vertice);

TAresta recebe_aresta();

void insere_aresta(TGrafo *grafo, TAresta aresta);

void insere_arestas_por_arquivo(TGrafo *grafo, char *nome_arq_arestas);

void lista_grafos(TGrafo *Grafos, int qtde_grafos);

TGrafo cria_grafo();

void cria_grafo_completo(TGrafo *grafo, int qtde_grafos, char *nome, char *nome_arq_vertices, char *nome_arq_arestas);

void imprime_dados_grafos(TGrafo *grafos, int qtde_grafos);

int verifica_grafo_conectado (TGrafo *grafo);

#endif // GERAL_H_INCLUDED
