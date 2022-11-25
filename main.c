#include <stdio.h>
#include <stdlib.h>
#include "Libs/caminho.h"
int main(){
    mat *matriz;
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
            ProcuraCaminho(matriz,0,0,&contaCaminhos, &menorCaminho, matriz->Matriz[0][0]);
            imprimir_matriz(matriz);
            printf("Quantidade de caminhos: %d\n", contaCaminhos);
            printf("Menor caminho: %d", menorCaminho);
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