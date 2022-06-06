#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estruturas.h"
#include "geral.h"
#include "lista_adjacencia.h"
#include "matriz_adjacencia.h"
#include "matriz_incidencia.h"

TGrafo cria_grafo(int qtde_grafos)
{
    TGrafo grafo;
    char nome[100];
    printf("Criando novo grafo com id %d.\n\n", qtde_grafos);
    grafo.id = qtde_grafos;
    printf("Digite o nome do novo grafo: ");
    scanf("%s", &nome);
    grafo.nome = (char*) calloc(strlen(nome)+1, sizeof(char));
    strcpy(grafo.nome, nome);
    grafo.qtde_vertices = 0;
    grafo.qtde_arestas = 0;
    grafo.Matriz_adj = NULL;
    grafo.Matriz_inc = NULL;
    grafo.vertices = NULL;
    printf("\nGrafo %d - %s criado com sucesso!\n\n", grafo.id, grafo.nome);

    return grafo;
}

void cria_grafo_completo(TGrafo *grafo, int qtde_grafos, char *nome, char *nome_arq_vertices, char *nome_arq_arestas)
{
    grafo->id = qtde_grafos;
    grafo->nome = nome;
    grafo->qtde_vertices = 0;
    grafo->qtde_arestas = 0;
    grafo->Matriz_adj = NULL;
    grafo->Matriz_inc = NULL;
    grafo->vertices = NULL;

    insere_vertices_por_arquivo(grafo, nome_arq_vertices);
    insere_arestas_por_arquivo(grafo, nome_arq_arestas);
}

void lista_grafos(TGrafo *Grafos, int qtde_grafos)
{
    int i=0;
    if (qtde_grafos > 0)
    {
        printf("Lista de grafos existentes\n");
        for (i=1; i<=qtde_grafos; i++)
            printf("Grafo %d - %s\n", Grafos[i].id, Grafos[i].nome);
        printf("\n");
    }
    else
        printf("Ainda nao existem grafos.\n\n");
}

void imprime_dados_grafos(TGrafo *grafos, int qtde_grafos)
{
    int i=0, j=0;

    for (i=1; i<=qtde_grafos; i++)
    {
        for (j=0; j<(strlen(grafos[i].nome)+20); j++)
            printf("*");
        printf("\n");
        printf("*  Grafo %d - %s\n*  Qtde vertices: %d\n*  Qtde arestas: %d\n", grafos[i].id, grafos[i].nome, grafos[i].qtde_vertices, grafos[i].qtde_arestas);
        for (j=0; j<(strlen(grafos[i].nome)+20); j++)
            printf("*");
        printf("\n\n");
    }
}

TVertice* inicia_vertice(int id, char *nome)
{
    TVertice *vertice = (TVertice*) calloc(1, sizeof(TVertice));
    vertice->nome = (char*) calloc(strlen(nome)+1, sizeof(char));
    vertice->id = id;
    strcpy(vertice->nome, nome);
    vertice->grau = 0;
    vertice->lista_adj = NULL;
    vertice->Prox = NULL;

    return vertice;
}

TVertice* recebe_vertice()
{
    char nome[100];
    int id=0;

    printf("Digite o identificador do vertice: ");
    scanf("%d", &id);
    printf("Digite o nome do vertice: ");
    scanf("%s", &nome);
    TVertice *vertice = inicia_vertice(id, nome);

    return vertice;
}

void insere_vertice(TGrafo *grafo, TVertice *vertice)
{
    TVertice *Aux = grafo->vertices;

    if (Aux == NULL)
        grafo->vertices = vertice;
    else
    {
        while (Aux->Prox != NULL)
            Aux = Aux->Prox;

        Aux->Prox = vertice;
    }
    printf("Vertice id = %d nome = %s inserido com sucesso!\n", vertice->id, vertice->nome);
    vertice = NULL;
    grafo->qtde_vertices++;
    grafo->Matriz_adj = insere_vertice_matriz_adj(grafo->Matriz_adj, grafo->qtde_vertices);
    grafo->Matriz_inc = insere_vertice_matriz_inc(grafo->Matriz_inc, grafo->qtde_vertices, grafo->qtde_arestas);
}

void insere_vertices_por_arquivo(TGrafo *grafo, char *nome_arq_vertices)
{
    char str[10], nome[100];
    int id=0;
    FILE *ptr_arq = NULL;
    TVertice *vertice = NULL;

    ptr_arq = fopen(nome_arq_vertices, "r");
    printf("\n");
    while (ptr_arq == NULL)
    {
        printf("Arquivo %s nao localizado. Digite corretamente o nome do arquivo: ", nome_arq_vertices);
        scanf("%s", &nome);
        ptr_arq = fopen(nome, "r");
    }

    while (fscanf(ptr_arq, "%d %[^\n]s", &id, &nome) != -1)
    {
        fscanf(ptr_arq, "%[\n]s", &str);
        vertice = inicia_vertice(id, nome);
        insere_vertice(grafo, vertice);
    }
    fclose(ptr_arq);
}

TVertice* busca_vertice_por_id(TGrafo *grafo, int id)
{
    TVertice *Aux = grafo->vertices;

    while ((Aux != NULL) && (Aux->id != id))
        Aux = Aux->Prox;

    return Aux;
}

TVertice* busca_vertice_por_nome(TGrafo *Grafo, char *nome)
{
    TVertice *Aux = Grafo->vertices;

    while ((Aux != NULL) && (strcmp(Aux->nome, nome) != 0))
    {
        printf("strcmp entre nome: %s e Aux->nome: %s igual a %d\n", nome, Aux->nome);
        Aux = Aux->Prox;
    }

    return Aux;
}

void imprime_vertice(TVertice *vertice)
{
    TAdj *adjacencia = vertice->lista_adj;

    printf("Id: %d\nNome: %s\nGrau: %d\n", vertice->id, vertice->nome, vertice->grau);
    while(adjacencia != NULL)
    {
        printf("%d ", adjacencia->id);
        adjacencia = adjacencia->Prox;
    }
}

void imprime_vertices(TVertice *vertice)
{
    TVertice *Aux = vertice;

    while(Aux != NULL)
    {
        imprime_vertice(Aux);
        Aux = Aux->Prox;
        printf("\n");
    }
}

TAresta recebe_aresta(TAresta aresta)
{
    char nome[100];

    printf("Digite o vertice de origem: ");
    scanf("%d", &aresta.id_u);
    printf("\nDigite o vertice de destino: ");
    scanf("%d", &aresta.id_v);
    printf("\nDigite o peso da aresta: ");
    scanf("%d", &aresta.peso);

    return aresta;
}

void insere_aresta(TGrafo *grafo, TAresta aresta)
{
    insere_aresta_lista_adjacencia(grafo->vertices, aresta);
    insere_aresta_matriz_adjacencia(grafo->Matriz_adj, aresta);
    grafo->Matriz_inc = insere_aresta_matriz_incidencia(grafo->Matriz_inc, grafo->qtde_vertices, grafo->qtde_arestas, aresta);

    grafo->qtde_arestas++;
}

void insere_arestas_por_arquivo(TGrafo *grafo, char *nome_arq_arestas)
{
    int id=0;
    char nome[100];
    FILE *ptr_arq = NULL;
    TAresta aresta;
    aresta.id = grafo->qtde_arestas+1;
    ptr_arq = fopen(nome_arq_arestas, "r");
    printf("\n");
    while (ptr_arq == NULL)
    {
        printf("Arquivo %s nao localizado. Digite corretamente o nome do arquivo: ", nome_arq_arestas);
        scanf("%s", &nome);
        ptr_arq = fopen(nome, "r");
    }

    while (fscanf(ptr_arq, "%d %d %d", &aresta.id_u, &aresta.id_v, &aresta.peso) != -1)
    {
        insere_aresta(grafo, aresta);
        (aresta.id)++;
    }

    fclose(ptr_arq);
}

int verifica_grafo_conectado (TGrafo *grafo)
{
    int i=0, check=1;//Assumo inicialmente que o grafo e conectado

    for (i=2; i<=grafo->qtde_vertices; i++)
    {
        check = busca_caminho_matriz_adj(grafo->Matriz_adj, grafo->qtde_vertices, 1, i)[0];

        //Se nao houver caminho entre dois vértices
        //Saio do for e deixo check = 0
        if (check == 0)
            i = 2*grafo->qtde_vertices;
    }
    return check;
}

