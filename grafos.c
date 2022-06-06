#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "estruturas.h"
#include "geral.h"
#include "lista_adjacencia.h"
#include "matriz_adjacencia.h"
#include "matriz_incidencia.h"


//Teoria dos Grafos - Serie 3 - Algoritimos em grafos
//Problema: Grafo com lista de adjacências
//Alunos: PEDRO HENRIQUE BAKO DIOGO - 120.888 e Thiago Kishi da Rosa - 86961

int opcao_menu(TGrafo *Grafo, int qtde_grafo)
{
    int opcao=1;

    system("cls");
    lista_grafos(Grafo, qtde_grafo);
    printf("MENU DE OPCOES\n\n");
    printf("(%d) Criar novo grafo\n", opcao++);
    printf("(%d) Inserir vertice\n", opcao++);
    printf("(%d) Inserir vertices por arquivo\n", opcao++);
    printf("(%d) Inserir aresta\n", opcao++);
    printf("(%d) Inserir arestas por arquivo\n", opcao++);
    printf("(%d) Imprimir lista de adjacencias\n", opcao++);
    printf("(%d) Imprimir matriz de adjacencias\n", opcao++);
    printf("(%d) Imprimir matriz de incidencia\n", opcao++);
    printf("(%d) Imprimir dados dos grafos\n", opcao++);
    printf("(%d) Buscar vertice\n", opcao++);
    printf("(%d) Buscar aresta\n", opcao++);
    printf("(%d) Buscar caminho\n", opcao++);
    printf("(%d) Verificar subgrafo\n", opcao++);
    printf("(%d) Verificar isomorfismo\n", opcao++);
    printf("(%d) Verificar conectividade em vertices e arestas\n", opcao++);
    printf("(%d) Verificar conectividade do grafo\n", opcao++);
    printf("(%d) Apaga grafo\n", opcao++);
    printf("(%d) Sair\n", opcao++);
    printf("\nDigite uma opcao: ");
    scanf("%d", &opcao);

    return opcao;
}

int main()
{
    TGrafo *grafos = (TGrafo*) calloc(1, sizeof(TGrafo));
    TVertice *vertice = NULL;
    TAresta aresta; aresta.id=0; aresta.id_u=0; aresta.id_v=0; aresta.peso=0;
    TAdj *adjacencia = NULL;
    int seleciona_grafo=0, qtde_grafos=0, selecao=0, id=0, opcao=0, id_u=0, id_v=0;
    int *caminho=NULL;
    char nome[100];

    qtde_grafos++;
    grafos = (TGrafo*) realloc(grafos, (qtde_grafos+1) * sizeof(TGrafo));
    cria_grafo_completo(&grafos[qtde_grafos], qtde_grafos, "Artistas", "vertices_artistas.txt", "arestas_artistas.txt");

    opcao = opcao_menu(grafos, qtde_grafos);
    while (opcao != 18)
    {
        vertice = NULL; adjacencia = NULL; selecao = 0; id = 0;
        switch(opcao)
        {
        case 1://Criar novo grafo
            system("cls");
            lista_grafos(grafos, qtde_grafos);
            qtde_grafos++;
            grafos = (TGrafo*) realloc(grafos, (qtde_grafos+1) * sizeof(TGrafo));
            grafos[qtde_grafos] = cria_grafo(qtde_grafos);
            system("pause");
        break;
        case 2://Inserir vertice
            system("cls");
            lista_grafos(grafos, qtde_grafos);
            printf("Inserindo vertice\n\n");
            printf("Digite o ID do GRAFO para insercao do vertice: ");
            scanf("%d", &seleciona_grafo);
            vertice = recebe_vertice();
            printf("\n");
            insere_vertice(&grafos[seleciona_grafo], vertice);
            printf("\n");
            system("pause");
        break;
        case 3://Inserir vertices por arquivo
            system("cls");
            lista_grafos(grafos, qtde_grafos);
            printf("Inserindo vertices por arquivo...\n\n");
            printf("Digite o ID do GRAFO para inserir os vertices: ");
            scanf("%d", &seleciona_grafo);
            printf("Digite o nome do arquivo de vertices: ");
            scanf("%s", &nome);
            insere_vertices_por_arquivo(&grafos[seleciona_grafo], nome);
            printf("\n");
            system("pause");
        break;
        case 4://Inserir aresta
            system("cls");
            lista_grafos(grafos, qtde_grafos);
            printf("Inserindo aresta\n\n");
            printf("Digite o ID do GRAFO para insercao da aresta: ");
            scanf("%d", &seleciona_grafo);
            printf("\n");
            aresta.id++;
            aresta = recebe_aresta(aresta);
            printf("\n");
            insere_aresta(&grafos[seleciona_grafo], aresta);
            printf("\n");
            system("pause");
        break;
        case 5://Inserir arestas por arquivo
            system("cls");
            lista_grafos(grafos, qtde_grafos);
            printf("Inserindo arestas por arquivo...\n\n");
            printf("Digite o ID do GRAFO para inserir as arestas: ");
            scanf("%d", &seleciona_grafo);
            printf("Digite o nome do arquivo de arestas: ");
            scanf("%s", &nome);
            insere_arestas_por_arquivo(&grafos[seleciona_grafo], nome);
            printf("\n");
            system("pause");
        break;
        case 6:
            system("cls");
            lista_grafos(grafos, qtde_grafos);
            printf("Imprimindo lista de adjacencia...\n\n");
            printf("Digite o ID do GRAFO para imprimir sua matriz de adjacencia: ");
            scanf("%d", &seleciona_grafo);
            printf("\n");
            imprime_lista_adj(&grafos[seleciona_grafo]);
            printf("\n");
            system("pause");
        break;
        case 7://Imprime matriz de adjacencia
            system("cls");
            lista_grafos(grafos, qtde_grafos);
            printf("Imprimindo matriz de adjacencia...\n\n");
            printf("Digite o ID do GRAFO para imprimir sua matriz de adjacencia: ");
            scanf("%d", &seleciona_grafo);
            printf("\n");
            imprime_matriz_adj(grafos[seleciona_grafo].Matriz_adj, grafos[seleciona_grafo].qtde_vertices);
            printf("\n");
            system("pause");
        break;
        case 8:
            system("cls");
            lista_grafos(grafos, qtde_grafos);
            printf("Imprimindo matriz de incidencia...\n\n");
            printf("Digite o ID do GRAFO para imprimir sua matriz de incidencia: ");
            scanf("%d", &seleciona_grafo);
            printf("\n");
            imprime_matriz_inc(grafos[seleciona_grafo].Matriz_inc, grafos[seleciona_grafo].qtde_vertices, grafos[seleciona_grafo].qtde_arestas);
            printf("\n");
            system("pause");
        break;
        case 9:
            system("cls");
            printf("Imprimindo dados dos grafos...\n\n");
            printf("\n");
            imprime_dados_grafos(grafos, qtde_grafos);
            printf("\n");
            system("pause");
        break;
        case 10:
            system("cls");
            lista_grafos(grafos, qtde_grafos);
            printf("Buscando vertice...\n\n");
            printf("Digite o ID do GRAFO para buscar o vertice: ");
            scanf("%d", &seleciona_grafo);
            printf("\nDigite:\n(1) Para buscar vertice por ID\n(2) Para buscar vertice por NOME\nOpcao: ");
            scanf("%d", &selecao);
            if (selecao == 1)
            {
                printf("\nBuscando vertice por id.\n\nDigite o id do vertice a ser buscado: ");
                scanf("%d", &id);
                vertice = busca_vertice_por_id(&grafos[seleciona_grafo], id);
            }
            else if (selecao == 2)
            {
                printf("\nBuscando vertice por nome.\n\nDigite o nome do vertice a ser buscado: ");
                scanf("%*[^\n]"); scanf("%*c");//Esvaziando o buffer de leitura
                scanf("%[^\n]", nome);
                vertice = busca_vertice_por_nome(&grafos[seleciona_grafo], nome);
            }
            if (vertice != NULL)
            {
                printf("\nVertice localizado. Seguem os dados do vertice:\n");
                imprime_vertice(vertice);
                printf("\n");
            }
            else
            {
                if (selecao == 1)
                    printf("Vertice de id: %d nao localizado\n", id);
                else
                    printf("Vertice de nome: %s nao localizado\n", nome);
            }
            system("pause");
        break;
        case 11:
            system("cls");
            lista_grafos(grafos, qtde_grafos);
            printf("Buscando aresta...\n\n");
            printf("Digite o ID do GRAFO para buscar a aresta: ");
            scanf("%d", &seleciona_grafo);
            printf("\nDado que uma aresta e representada por um par (u, v).\n");
            printf("Digite o id do vertice u: ");
            scanf("%d", &aresta.id_u);
            printf("Digite o id do vertice v: ");
            scanf("%d", &aresta.id_v);
            aresta = busca_aresta(grafos[seleciona_grafo], aresta);
            if (aresta.peso > 0)
                printf("Existe aresta entre os vertices %d e %d.\nID da aresta: %d\nPeso da aresta: %d\n\n", aresta.id_u, aresta.id_v, aresta.id, aresta.peso);
            else
                printf("Nao existe aresta entre os vertices %d e %d.\n\n", aresta.id_u, aresta.id_v);
            system("pause");
        break;
        case 12:
            system("cls");
            lista_grafos(grafos, qtde_grafos);
            printf("Buscando caminho...\n\n");
            printf("Digite o ID do GRAFO para buscar o caminho: ");
            scanf("%d", &seleciona_grafo);
            printf("\nDigite o vertice de origem: ");
            scanf("%d", &id_u);
            printf("\nDigite o vertice de destino: ");
            scanf("%d", &id_v);
            caminho = busca_caminho_matriz_adj(grafos[seleciona_grafo].Matriz_adj, grafos[seleciona_grafo].qtde_vertices, id_u, id_v);
            if (caminho[0] > 0)
            {
                printf("\nCaminho entre os vertices %d e %d:\n", id_u, id_v);
                imprime_caminho(caminho);
                printf("\n");
            }
            else
                printf("Nao existe caminho entre os vertices %d e %d\n\n", id_u, id_v);
            system("pause");
        break;
        case 13:
            printf("Funcao nao definida.\n");
            system("pause");
        break;
        case 14:
            printf("Funcao nao definida.\n");
            system("pause");
        break;
        case 15:
            printf("Funcao nao definida.\n");
            system("pause");
        break;
        case 16:
            system("cls");
            lista_grafos(grafos, qtde_grafos);
            printf("Verificando conectividade do grafo...\n\n");
            printf("Digite o ID do GRAFO para vericacao: ");
            scanf("%d", &seleciona_grafo);
            if (verifica_grafo_conectado (&grafos[seleciona_grafo]) > 0)
                printf("\nO grafo %d - %s e conectado!\n\n", grafos[seleciona_grafo].id, grafos[seleciona_grafo].nome);
            else
                printf("\nO grafo %d - %s NAO e conectado!\n\n", grafos[seleciona_grafo].id, grafos[seleciona_grafo].nome);
            system("pause");
        break;
        case 17:
            printf("Funcao nao definida.\n");
            system("pause");
        break;
        case 18:
        break;

        default:
            printf("Opcao invalida\n\n");
            system("pause");
            break;
        }
        opcao=opcao_menu(grafos, qtde_grafos);
    }
    system("cls");
    return 0;
}
