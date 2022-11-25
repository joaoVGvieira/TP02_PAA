#include "../Libs/caminho.h"

void ProcuraCaminho(mat* matriz, int linha, int coluna, int* contaCaminhosRepetidos, int *menorCaminho, int distancia){
    if (matriz->matrizDistancias[linha][coluna].distancia == 0 || matriz->matrizDistancias[linha][coluna].distancia > distancia)
    {
        
         matriz->matrizDistancias[linha][coluna].distancia = distancia;
    } else return;

    if (linha == matriz->linhas - 1 && coluna == matriz->colunas - 1){ 
        if((distancia == *menorCaminho) || menorCaminho == 0){
            *contaCaminhosRepetidos = *contaCaminhosRepetidos + 1;
            return;
        }
        if(distancia < *menorCaminho){
            *menorCaminho = distancia;
            *contaCaminhosRepetidos = 1;
            return;
        }
    }
    
    if ( linha < matriz->linhas && coluna < matriz->colunas ){
        if(coluna < matriz->colunas-1){
            ProcuraCaminho(matriz,linha,coluna+1, contaCaminhosRepetidos, menorCaminho, distancia + matriz->Matriz[linha][coluna+1]);
        }
        if(linha < matriz->linhas-1){
            ProcuraCaminho(matriz,linha+1,coluna, contaCaminhosRepetidos, menorCaminho, distancia + matriz->Matriz[linha+1][coluna]);
        }
    }   
}
