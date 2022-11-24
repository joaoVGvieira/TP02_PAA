#include <stdio.h>
#include <stdlib.h>
#include "Libs/caminho.h"
int main(){
    mat *matriz;
    int opc;
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
            printf("\nDIGITE O NOME DO ARQUIVO DE ENTRADA: ");
            scanf(" %[^\n]s ",nome_arquivo);
            matriz = leitura(nome_arquivo);
            imprimir_matriz(matriz);
            ProcuraCaminho(matriz,0,0);
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