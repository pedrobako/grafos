#include<stdio.h>
#include<stdlib.h>
#include "matriz_incidencia.h"

int** insere_vertice_matriz_inc(int **matriz_inc, int qtde_vertices, int qtde_arestas)
{
    int i=0;

    if (qtde_vertices == 1)
        matriz_inc = (int**) calloc(2, sizeof(int*));
    else
    {
        matriz_inc = (int**) realloc(matriz_inc, (qtde_vertices+1) * sizeof(int*));

        for (i=0; i<=(qtde_arestas); i++)
        {
            matriz_inc[i] = (int*) realloc(matriz_inc[i], (qtde_vertices+1) * sizeof(int));

            matriz_inc[i][qtde_vertices]=0;
        }
    }
    return matriz_inc;
}

int** insere_aresta_matriz_incidencia(int **matriz_inc, int qtde_vertices, int qtde_arestas, TAresta aresta)
{
    //QTDE_ARESTA NÃO CONTABILIZA A ARESTA QUE ESTÁ SENDO INSERIDA
    int i=0;

    if (qtde_arestas == 0)
    {
        for (i=0; i<=qtde_vertices; i++)
            matriz_inc[i] = (int*) calloc(2, sizeof(int));
    }
    else
    {
        for (i=0; i<=qtde_vertices; i++)
        {
            matriz_inc[i] = (int*) realloc(matriz_inc[i], (qtde_arestas+2) * sizeof(int));
            matriz_inc[i][qtde_arestas+1] = 0;
        }
    }
    matriz_inc[aresta.id_u][aresta.id]=aresta.peso;
    matriz_inc[aresta.id_v][aresta.id]=aresta.peso;

    return matriz_inc;
}

void imprime_matriz_inc(int **matriz_inc, int qtde_vertices, int qtde_arestas)
{
    int i=0, j=0;

    printf("Matriz de incidencias:%d\n\n", qtde_arestas);

    printf("|  arestas->  |");
    for (i=1; i<=qtde_arestas; i++)
    {
        if (i<10)
            printf("  %d  |", i);
        else if (i<100)
            printf("  %d |", i);
        else
            printf(" %d |", i);
    }
    printf("\n|  vertices   |");
    for (i=1; i<=qtde_arestas; i++)
        printf("_____|");
    printf("\n");

    for (i=1; i<=qtde_vertices; i++)
    {
        if (i<10)
            printf("|      %d      |", i);
        else if (i<100)
            printf("|      %d     |", i);
        else
            printf("|      %d    |", i);

        for (j=1; j<=qtde_arestas; j++)
        {
           // printf(" %d \n", j);
            if (matriz_inc[i][j] < 10)
                printf("  %d  |", matriz_inc[i][j]);
            else if (matriz_inc[i][j] < 100)
                printf("  %d |", matriz_inc[i][j]);
            else if (matriz_inc[i][j] < 1000)
                printf("  %d|", matriz_inc[i][j]);
        }
        printf("\n");
    }
}

TAresta busca_aresta(TGrafo grafo, TAresta aresta)
{
    int i=0;
    aresta.peso = -1;//Significa que a aresta nao existe

    for (i=0; i<=grafo.qtde_arestas; i++)
    {
        if ((grafo.Matriz_inc[aresta.id_u][i] > 0) && (grafo.Matriz_inc[aresta.id_v][i] > 0))
        {
            aresta.id = i;
            aresta.peso = grafo.Matriz_inc[aresta.id_u][i];
            printf("Aresta peso: %d\n", aresta.peso);
            i = 2*grafo.qtde_arestas;
        }
    }
    return aresta;
}
