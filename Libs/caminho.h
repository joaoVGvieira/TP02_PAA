#include "ler.h"

void ProcuraCaminho(mat* matriz, int linha, int coluna, int* contaCaminhosRepetidos, int *menorCaminho, int distancia);

void memoizationIterativo(mat* matriz);
void ProcuraCaminhoComk(mat* matriz, int linha, int coluna, int* contaCaminhosRepetidos, int *menorCaminho, int distancia, int k);