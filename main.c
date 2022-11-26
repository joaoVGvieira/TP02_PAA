#include <stdio.h>
#include <stdlib.h>
#include "Libs/caminho.h"
int main(){
    mat *matriz = NULL;
    int opc;
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
          "| IMPRIMIR CAMINHO COLORIDO = 2                      |\n"
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
                printf("Soma Mínima: %d\n", menorCaminho);
                printf("Quantidade de Caminhos: %d\n", contaCaminhos);
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
        default:
            printf("\nOPCAO INVALIDA!!!!\n");
            break;
        }
    }while (opc!=0);    
}