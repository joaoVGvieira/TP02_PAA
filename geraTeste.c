#include <stdio.h>
#include <stdlib.h>

int main(){

    int linhas = 10, colunas = 10;

    for(int i = 0; i < 10; i ++){
        for(int j = 0; j < 10; j ++){
            printf("%d ", rand() % 100);
        }
        printf("\n");
    }
}