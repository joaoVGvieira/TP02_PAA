#include "../Libs/ler.h"

mat *leitura( char* caminhoArquivo ){
    
    FILE *arq;
    mat *matriz;
    matriz = (mat*)malloc(sizeof(mat));

    arq = fopen( caminhoArquivo, "r" );
    if ( arq == NULL ) {
        printf("\nARQUIVO NAO ENCONTRADO\n");
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
            matriz->matrizDistancias[i] = ( celula * )calloc( sizeof( celula ) , matriz->colunas );
        }
    }
    
    fclose( arq );
    return matriz;
}

void imprimir_matriz( mat *matriz ){
        printf("\n\t ------ MATRIZ ------ \t\n\n");
             for(int i=0;i<matriz->linhas;i++){
                for(int j=0;j<matriz->colunas;j++){
                    printf("%d ",matriz->Matriz[i][j]);
                } 
            printf("\n");   
        }
}