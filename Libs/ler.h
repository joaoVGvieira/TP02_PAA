#include <stdio.h>
#include <stdlib.h>
typedef struct{

    int distancia; // minima distancia de [0][0] até este ponto
    short int anterior; // 1 - cima    2 - esquerda   3 - pros dois

}celula;

typedef struct mat{

    int linhas; 
    int colunas;
    int **Matriz; //matriz lida do arquivo, nao ira mudar
    celula **matrizDistancias;
    
}mat;

mat *leitura( char* caminhoArquivo );

void imprimir_matriz( mat *matriz );

void printaMatrizColorida(mat* matriz);