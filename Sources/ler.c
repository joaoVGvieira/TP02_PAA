#define ANSI_COLOR_RED     "\x1b[31m"  //cores em ANSI utilizadas 
#define ANSI_COLOR_GRAY     "\e[0;37m"
#include "../Libs/ler.h"
mat *leitura( char* caminhoArquivo ){
    
    FILE *arq;
    mat *matriz;
    matriz = (mat*)malloc(sizeof(mat));

    arq = fopen( caminhoArquivo, "r" );
    if ( arq == NULL ) {
        printf("\nARQUIVO NAO ENCONTRADO\n");
        return NULL;
    }
    else {
        printf("\nLEITURA DE ARQUIVO FEITA COM SUCESSO!\n");
        fscanf( arq, "%d %d", &matriz->linhas,  &matriz->colunas ); // lendo linhas e colunas
        // no arquivo separado por espaço
        
        matriz->Matriz = ( int ** )malloc( sizeof( int ) * matriz->linhas * matriz->colunas );
        for ( int i = 0; i < matriz->linhas; i++ ){
            matriz->Matriz[i] = ( int * )malloc( sizeof( int ) * matriz->linhas * matriz->colunas );

            for ( int j = 0; j < matriz->colunas; j++ ) {
                int valor;
                
                if ( j < matriz->colunas - 1 ) { // Lendo os valores no arquivo
                    fscanf( arq, "%d ", &valor );
                }
                else { // Lendo o último valor no arquivo
                    fscanf( arq, "%d", &valor );
                }
                matriz->Matriz[i][j] = valor;
            }
        }

        matriz->matrizDistancias = ( celula ** )malloc( sizeof( celula ) * matriz->linhas );
        for ( int i = 0; i < matriz->linhas; i++ ){
            matriz->matrizDistancias[i] = ( celula * )malloc( sizeof( celula ) * matriz->colunas );
        }
       
    }

     for(int i = 0; i < matriz->linhas; i ++){
        for(int j = 0; j < matriz->colunas; j ++){
            matriz->matrizDistancias[i][j].distancia = -1;
        }
    }

    fclose( arq );
    return matriz;
}

void imprimir_matriz( mat *matriz ){
        printf("\n\t ------ MATRIZ ------ \t\n\n");
             for(int i=0;i<matriz->linhas;i++){
                for(int j=0;j<matriz->colunas;j++){
                    printf("%-3d ",matriz->Matriz[i][j]);
                } 
            printf("\n");   
        }
        printf("\n");
}


void printaMatrizColorida(mat* matriz){

    printf("\n \t--- CAMINHO COM CUSTO MININO ---\t\n\n");
    int linha = matriz->linhas-1, coluna = matriz->colunas-1;

    for(int k = 0; k < matriz->colunas + matriz->linhas -1 ; k ++){


        matriz->matrizDistancias[linha][coluna].anterior = 1;

        if(coluna == 0){
            linha -= 1;
            continue;
        } 
        if(linha == 0) {
            coluna -=1;
            continue;
        }

        if(matriz->matrizDistancias[linha-1][coluna].distancia < matriz->matrizDistancias[linha][coluna-1].distancia){
            linha = linha -1;
        }
        else coluna = coluna -1;
        
    }
    linha = 0;
    coluna = 0;
    printf("\nINICIO  ");

    for(int k = 0; k < matriz->colunas + matriz->linhas -1 ; k ++){
        if(k == matriz->colunas + matriz->linhas -2) printf("(%d,%d)\n", linha, coluna);
        else printf("(%d,%d) -> ", linha, coluna);

        if(linha == matriz->linhas-1){
            coluna ++;
            continue;
        }
        if(coluna == matriz->colunas-1){
            linha++;
            continue;
        }

        if(matriz->matrizDistancias[linha+1][coluna].anterior == 1){
            linha = linha +1;
        }
        else coluna = coluna +1;

    }
    printf("\n ----- MATRIZ ORIGINAL -----\n");
    for(int i = 0; i < matriz->linhas; i ++){
        for(int j = 0; j < matriz->colunas; j ++){
            if(matriz->matrizDistancias[i][j].anterior == 1){
                 printf( ANSI_COLOR_RED "%-4d " ANSI_COLOR_GRAY, matriz->Matriz[i][j]);
            }else printf("%-4d ",matriz->Matriz[i][j]);
        }

        printf("\n");
    }

    printf("\n ----- MATRIZ MEMOIZATION -----\n");

    for(int i = 0; i < matriz->linhas; i ++){
        for(int j = 0; j < matriz->colunas; j ++){
            if(matriz->matrizDistancias[i][j].anterior == 1){
                 printf( ANSI_COLOR_RED "%-4d " ANSI_COLOR_GRAY, matriz->matrizDistancias[i][j].distancia);
            }else printf("%-4d ",matriz->matrizDistancias[i][j].distancia);
        }

        printf("\n");
    }
    printf("\n");
}
