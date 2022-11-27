#include <stdio.h>
#include <stdlib.h>
#include "Libs/caminho.h"
int main(){
    mat *matriz = NULL;
    int opc;
    int k;
    int contaCaminhos = 0;
    int menorCaminho = 0;
    char nome_arquivo[1000];
    do
    {
        printf("\n");
        printf(
          " _________________(MENU PRINCIPAL)___________________ \n"
          "|                                                    |\n"
          "| LER ARQUIVO = 1                                    |\n"
          "| VISUALIZAR CAMINHO COM CUSTO MINIMO = 2            |\n"
          "| DISTANCIA DE TODAS AS POSICOES = 3                 |\n"
          "| PROCURAR CAMINHO COM K = 4                         |\n"
          "| ENCERRAR OPERACOES = 0                             |\n"
          "|____________________________________________________|\n\n");
        printf("DIGITE A OPERACAO DESEJADA: ");
        scanf("%d",&opc);
        switch (opc)
        {
        case 1 :
            menorCaminho = 0;
            printf("\nDIGITE O NOME DO ARQUIVO DE ENTRADA: ");
            scanf(" %[^\n]s ",nome_arquivo);
            matriz = leitura(nome_arquivo);
            if (matriz!=NULL)
            {
                ProcuraCaminho(matriz,0,0,&contaCaminhos, &menorCaminho, matriz->Matriz[0][0]);
                imprimir_matriz(matriz);
                printf("Soma Minima: %d\n", menorCaminho);
                printf("Quantidade de Caminhos: %d\n", contaCaminhos);
                menorCaminho = 0;
                contaCaminhos= 0;
            }            
            break;
        case 2 :
            if (matriz!= NULL)
            {
                printaMatrizColorida(matriz);
            }
            break;
        case 0 :
            printf("\nPROGRAMA ENCERRADO!\n\n");
            break;
        case 3 :
            if (matriz!= NULL)
                {
                    memoizationIterativo(matriz);
                }
                break;
        case 4 :
            if (matriz!= NULL)
                {
                    printf("Digite K: ");
                    scanf("%d",&k);
                    ProcuraCaminhoComk(matriz,0,0,&contaCaminhos, &menorCaminho, matriz->Matriz[0][0],k);
                    imprimir_matriz(matriz);
                    printf("Soma Minima: %d\n", menorCaminho);
                    printf("Quantidade de Caminhos: %d\n", contaCaminhos);
                    menorCaminho = 0;
                    contaCaminhos= 0;
                }
        break;
        default:
            printf("\nOPCAO INVALIDA!!!!\n");
            break;
        }
    }while (opc!=0);    
}