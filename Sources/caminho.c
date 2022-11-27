#include "../Libs/caminho.h"

void ProcuraCaminho(mat* matriz, int linha, int coluna, int* contaCaminhosRepetidos, int *menorCaminho, int distancia){
    if (matriz->matrizDistancias[linha][coluna].distancia == -1 || matriz->matrizDistancias[linha][coluna].distancia >= distancia)
    {
        matriz->matrizDistancias[linha][coluna].distancia = distancia;
    } else return;

    if (linha == matriz->linhas - 1 && coluna == matriz->colunas - 1){ 
        if((distancia == *menorCaminho)){
            *contaCaminhosRepetidos = *contaCaminhosRepetidos + 1;
            return;
        }
        if(distancia < *menorCaminho || *menorCaminho == 0){
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


void ProcuraCaminhoComk(mat* matriz, int linha, int coluna, int* contaCaminhosRepetidos, int *menorCaminho, int distancia, int k){
    if (matriz->matrizDistancias[linha][coluna].distancia == 0 || matriz->matrizDistancias[linha][coluna].distancia >= distancia) 
    {
        matriz->matrizDistancias[linha][coluna].distancia = distancia;
    } 
    if (linha == matriz->linhas - 1 && coluna == matriz->colunas - 1){ 
        if((distancia == *menorCaminho)){
            if (distancia%k == 0)
            {
                 *contaCaminhosRepetidos = *contaCaminhosRepetidos + 1;
                 return;
            }
        }
        if((distancia < *menorCaminho || *menorCaminho == 0)){
            if (distancia%k == 0){
                *menorCaminho = distancia;
                *contaCaminhosRepetidos = 1;
                return;
            }
        }
    }
    
    if ( linha < matriz->linhas && coluna < matriz->colunas ){
        if(coluna < matriz->colunas-1){
            ProcuraCaminhoComk(matriz,linha,coluna+1, contaCaminhosRepetidos, menorCaminho, distancia + matriz->Matriz[linha][coluna+1], k);
        }
        if(linha < matriz->linhas-1){
            ProcuraCaminhoComk(matriz,linha+1,coluna, contaCaminhosRepetidos, menorCaminho, distancia + matriz->Matriz[linha+1][coluna], k);
        }
    }   
}


void memoizationIterativo(mat* matriz){
    
    int** temp = ( int ** )malloc( sizeof( int ) * matriz->linhas );
    for ( int i = 0; i < matriz->linhas; i++ ){
        temp[i] = ( int * )calloc( sizeof( int ) , matriz->colunas );
    }

    temp[matriz->linhas-1][matriz->colunas-1] = matriz->Matriz[matriz->linhas-1][matriz->colunas-1];
    
    for(int j = matriz->colunas-1; j >= 0 ; j --){
        
        for(int i = matriz->linhas-1; i >= 0; i --){

            if( i == matriz->linhas-1 && j == matriz->colunas-1) continue;
            
            if(j == matriz->colunas-1){ 
                temp[i][j] = temp[i+1][j] + matriz->Matriz[i][j];
                continue;
            }
            if(i == matriz->linhas-1){
                temp[i][j] = temp[i][j+1] + matriz->Matriz[i][j];
                continue;
            }

            if(temp[i+1][j] < temp[i][j+1]){
                temp[i][j] = temp[i+1][j] + matriz->Matriz[i][j];
            }else{
                 temp[i][j] = temp[i][j+1] + matriz->Matriz[i][j];
            }

        }
    }
    printf("\nDistancias minima de todas as posicoes ate o ponto de destino\n\n");
    for(int i = 0; i < matriz->linhas; i ++){
        for(int j = 0; j < matriz->colunas ; j ++){
            printf("%-4d ", temp[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}