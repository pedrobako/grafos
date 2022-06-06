#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "lista_adjacencia.h"

TAdj* inicia_adjacente(int id)
{
    TAdj *adjacente = (TAdj*) calloc(1,sizeof(TAdj));
    adjacente->id = id;
    adjacente->Prox = NULL;
    return adjacente;
}

void insere_aresta_lista_adjacencia_interno(TVertice *vertice, int id)
{
    TAdj *Novo = inicia_adjacente(id);

    TAdj *Aux = vertice->lista_adj;

    if (Aux == NULL)
        vertice->lista_adj = Novo;
    else
    {
        while (Aux->Prox != NULL)
            Aux = Aux->Prox;

        Aux->Prox = Novo;
    }

    vertice->grau++;

    Aux = NULL;
    Novo = NULL;
}

void insere_aresta_lista_adjacencia(TVertice *vertices, TAresta aresta)
{
    int cont=0;
    TVertice *Aux_vert = vertices;

    while (Aux_vert != NULL)
    {
        if (Aux_vert->id == aresta.id_u)
        {
            cont++;
            insere_aresta_lista_adjacencia_interno(Aux_vert, aresta.id_v);

            if (cont == 2)
                Aux_vert = NULL;
        }
        else if (Aux_vert->id == aresta.id_v)
        {
            cont++;
            insere_aresta_lista_adjacencia_interno(Aux_vert, aresta.id_u);

            if (cont == 2)
                Aux_vert = NULL;
        }

        if (cont != 2)
            Aux_vert = Aux_vert->Prox;
    }
}

void imprime_lista_adj(TGrafo *grafo)
{
    TVertice *Aux_vert = grafo->vertices;
    TAdj *Aux_adj = NULL;

    printf("  Id Vertice\t|  Grau |  Lista de adjacentes\n");

    while (Aux_vert != NULL)
    {
        printf("     %d\t\t|   %d   |  ", Aux_vert->id, Aux_vert->grau);

        Aux_adj = Aux_vert->lista_adj;

        while (Aux_adj != NULL)
        {
            printf("-> %d ", Aux_adj->id);
            Aux_adj = Aux_adj->Prox;
        }

        printf("\n");
        Aux_vert = Aux_vert->Prox;
    }
    printf("\nQuantidade de vertices: %d\n", grafo->qtde_vertices);
    printf("\nQuantidade de arestas: %d\n", grafo->qtde_arestas);
}
