#include "../Libs/caminho.h"

void ProcuraCaminho(mat* matriz, int linha, int coluna){
    if (linha == matriz->linhas - 1 && coluna == matriz->colunas - 1)
    {
        return;
    }
    if (linha < matriz->linhas && coluna < matriz->colunas )
    {
        ProcuraCaminho(matriz,linha,coluna+1);
        ProcuraCaminho(matriz,linha+1,coluna);
    }
    
}

// pensei em  uma ideia que fazia varios percusos, e durante eles fosse somando os valores de cada posição e visse qual era menor percuso no caso (gostei mais dessa ideia)

