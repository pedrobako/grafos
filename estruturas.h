#ifndef ESTRUTURAS_H_INCLUDED
#define ESTRUTURAS_H_INCLUDED

#include "stdlib.h"

typedef struct
{
    int id;
    int id_u;
    int id_v;
    int peso;
} TAresta;

typedef struct SAdj
{
    int id;
    struct SAdj *Prox;
} TAdj;

typedef struct SVertice
{
    int id;
    char *nome;
    int grau;
    TAdj *lista_adj;
    struct SVertice *Prox;
} TVertice;

typedef struct
{
    TVertice *Vertices;
    int Qtde_vertices;
    int Qtde_arestas;
} TLista_adj;

typedef struct
{
    int id;
    char *nome;
    int qtde_vertices;
    int qtde_arestas;
    TVertice *vertices;
    int **Matriz_adj;
    int **Matriz_inc;
} TGrafo;


#endif // ESTRUTURAS_H_INCLUDE
