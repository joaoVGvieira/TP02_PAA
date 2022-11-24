#include <stdio.h>
#include <stdlib.h>

typedef struct mat{

    int linhas; 
    int colunas;
    int **Matriz; //matriz lida do arquivo, nao ira mudar
}mat;

mat *leitura( char* caminhoArquivo );

void imprimir_matriz( mat *matriz );