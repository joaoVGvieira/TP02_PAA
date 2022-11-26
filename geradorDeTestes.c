#include <stdio.h>
#include <stdlib.h>
#include <time.h>

criar_arquivo(char* nome){
    FILE *arq;
    int linhas ,colunas;
    srand(time(NULL));
    linhas = rand() % (100 + 1 - 2) + 2;
    colunas = rand() % (100 + 1 - 2) + 2;
    int matriz[linhas][colunas];
    for(int i = 0; i < linhas; i ++){
            for(int j = 0; j < colunas ; j ++){
                matriz[i][j] = rand() % 101;
            }
    }
    arq = fopen( nome, "w" );
    if ( arq == NULL ) {
        printf("\nNAO HA ESPACO PARA CRIACAO DO ARQUIVO\n");
        exit;
    }
    else {
        printf("\nARQUIVO CRIADO COM SUCESSO!\n");
        fprintf (arq, "%d %d\n", linhas,colunas);
        for(int i = 0; i < linhas; i ++){
            for(int j = 0; j < colunas ; j ++){
                fprintf(arq,"%-2d ", matriz[i][j]);
            }
            fprintf(arq,"\n");
        }
    }
    fclose(arq);    
}

int main(){
    char nome[1000];
    int opc;
    do
    {
        printf(
          " \n_________________(MENU PRINCIPAL)___________________ \n"
          "|                                                    |\n"
          "| CRIAR ARQUIVO = 1                                  |\n"
          "| ENCERRAR OPERACOES = 0                             |\n"
          "|____________________________________________________|\n\n");
        printf("DIGITE A OPERACAO DESEJADA: ");
        scanf("%d",&opc);
        switch (opc)
        {
            case 1:
                printf("Digite o nome do arquivo pra ser gerado (com txt):");
                scanf(" %[^\n]s ",nome);
                criar_arquivo(nome);
                break;
            case 0:
                printf("PROGRAMA ENCERRADO!!!\n");
                break;
            default:
                printf("OPCAO INVALIDA!!!\n");
                break;
        }
    } while (opc!=0);
}  