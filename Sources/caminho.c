#include "../Libs/caminho.h"

void ProcuraCaminho(mat* matriz, int linha, int coluna, int* cont, int *menorCaminho, int distancia){
    if (matriz->matrizDistancias[linha][coluna].distancia == 0 || matriz->matrizDistancias[linha][coluna].distancia > distancia)
    {
        
         matriz->matrizDistancias[linha][coluna].distancia = distancia;
         printf("%d\n", matriz->matrizDistancias[linha][coluna].distancia);
    }
    
    if (linha == matriz->linhas - 1 && coluna == matriz->colunas - 1){
        *cont = *cont + 1;
        if(distancia < *menorCaminho  || *menorCaminho == 0) *menorCaminho = distancia;
        return;
    }
    if ( linha < matriz->linhas && coluna < matriz->colunas ){
        if(coluna < matriz->colunas-1){
            ProcuraCaminho(matriz,linha,coluna+1, cont, menorCaminho, distancia + matriz->Matriz[linha][coluna+1]);
        }
        if(linha < matriz->linhas-1){
            ProcuraCaminho(matriz,linha+1,coluna, cont, menorCaminho, distancia + matriz->Matriz[linha+1][coluna]);
        }
    }   
}
    


// pensei em  uma ideia que fazia varios percusos, e durante eles fosse somando os valores de cada posição e visse qual era menor percuso no caso (gostei mais dessa ideia)
