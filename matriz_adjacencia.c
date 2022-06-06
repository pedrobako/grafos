#include<stdio.h>
#include<stdlib.h>
#include"matriz_adjacencia.h"

int **insere_vertice_matriz_adj(int **matriz_adj, int qtde_vertices)
{
    int i=0;

    if (qtde_vertices == 1)
    {
        matriz_adj = (int**) calloc(2, sizeof(int*));
        matriz_adj[0] = (int*) calloc(2, sizeof(int));
        matriz_adj[1] = (int*) calloc(2, sizeof(int));
    }
    else
    {
        matriz_adj = (int**) realloc(matriz_adj, (qtde_vertices+1) * sizeof(int*));

        for (i=0; i<(qtde_vertices); i++)
        {
            matriz_adj[i] = (int*) realloc(matriz_adj[i], (qtde_vertices+1) * sizeof(int));

            matriz_adj[i][qtde_vertices]=0;
        }

        matriz_adj[qtde_vertices] = (int*) calloc(qtde_vertices+1, sizeof(int));
    }
    return matriz_adj;
}

void insere_aresta_matriz_adjacencia(int **matriz_adj, TAresta aresta)
{
    matriz_adj[aresta.id_u][aresta.id_v]=aresta.peso;
    matriz_adj[aresta.id_v][aresta.id_u]=aresta.peso;
}

void imprime_matriz_adj(int **Matriz_adj, int qtde_vertices)
{
    int i=0, j=0;

    printf("Matriz de adjacencias:\n\n");

    printf("| id  |");
    for (i=1; i<=qtde_vertices; i++)
    {
        if (i<10)
            printf("  %d  |", i);
        else if (i<100)
            printf("  %d |", i);
        else
            printf(" %d |", i);
    }
    printf("\n");

    for (i=1; i<=qtde_vertices; i++)
    {
        if (i<10)
            printf("| %d   |", i);
        else if (i<100)
            printf("| %d  |", i);
        else
            printf("| %d |", i);

        for (j=1; j<qtde_vertices+1; j++)
            printf("  %d  |", Matriz_adj[i][j]);

        printf("\n");
    }
}

int* busca_caminho_matriz_adj(int **Matriz_adj, int qtde_vertices, int id_u, int id_v)
{
    int *caminho = (int*) calloc(qtde_vertices+1, sizeof(int));
    int *descartados = (int*) calloc(qtde_vertices+1, sizeof(int));
    int atual = id_u, i=0, j=0, check=0, selecao=0;
    caminho[1] = atual;
    caminho[0] = 1;//Qtde de vértices existentes no caminho é grafado na 1ª posição

    while (caminho[0] != 0)
    {
        //Se houver uma aresta entre o vértice atual e o vertice de destino encerro a busca
        //E eu nao estiver voltando pelo mesmo caminho
        if ((Matriz_adj[atual][id_v] == 1) && ((id_v != caminho[caminho[0]-1]) || caminho[0] == 1))
        {
            caminho[caminho[0]+1] = id_v;
            caminho[0]++;
            break;
        }
        else
        {
            //Buscando o próximo vértice
            for (i=1; i<=qtde_vertices; i++)
            {
                check = 0;//check para verificar se o vertice passa nos testes condicionais para fazer parte do caminho
                selecao = 0;//check de pre-selecao de um vertice

                //Se houver aresta entre o vertice atual e o vertice i
                if(Matriz_adj[atual][i]==1)
                    selecao = 1;//pre-seleciono o vertice i para fazer parte do caminho

                //Se tem um possível vérice pres-selecionado como saída do vértice atual
                //Passo a avaliá-lo
                if(selecao==1)
                {
                    //Verifico se o vértice pré selecionado já não faz parte do caminho
                    for (j=0; j<=caminho[0]; j++)
                        if (caminho[j] == i)
                            check = 1;//Se já está no caminho descarto

                    //Verifico se o vértice pré selecionado não é um vértice descartado
                    for (j=0; j<=descartados[0]; j++)
                        if (descartados[j] == i)
                            check = 1;//Se for, descarto

                    //Se o vértice passar nos dois crivos anteriores
                    //Coloco ele no caminho
                    if (check != 1)
                    {
                        atual = i;
                        caminho[caminho[0]+1] = atual;
                        caminho[0]++;
                        i = qtde_vertices+1;//Para sair do for atual e reiniciar a verificação do primeiro vértice
                    }
                }

                //Se o vertice atual chegou no ultimo vertice e nao achou saida
                //Tiro o vertice atual do caminho e coloco na lista de descartados
                if ((i == qtde_vertices) && ((check == 1) || (selecao == 0)))
                {
                    descartados[descartados[0]+1]=atual;
                    descartados[0]++;
                    caminho[caminho[0]]=0;//Descarto o vértice atual
                    caminho[0]--;
                    atual = caminho[caminho[0]];//Atual recebe o último da lista
                    i = qtde_vertices+1;//Para sair do for atual e reiniciar a verificação do primeiro vértice
                }
            }
        }
    }

    return caminho;
}

void imprime_caminho(int *caminho)
{
    int i=0;

    if (caminho[0] > 0)
    {
        printf("{");
        for (i=1; i<=caminho[0]; i++)
            printf("%d, ", caminho[i]);

        printf("\b\b}\n");
    }
}
