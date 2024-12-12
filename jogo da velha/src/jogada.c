#include "jogada.h"

int jogada_valida(int linha,int coluna,char jogo[][3]) { // verifica se a jogada é valida

    // analisa se as coordenadas são validas e se o campo ja esta preenchido
    if (linha < 0 || linha > 2 || coluna < 0 || coluna > 2 || jogo[linha][coluna] != ' ') {
        return 1; // retorna 1 se invalida
    }
    else
        return 0; // retorna 0 se for valida
}

// função para realizar jogada
void jogada(char jogo[][3],char c) { 

    int i,j;

    printf("digite a linha e coluna que voce quer jogar(nessa ordem) jogador %c: ", c);
    scanf("%d %d",&i, &j);

    while (jogada_valida(i,j,jogo) == 1) { // looping so acaba quando a jogada for valida
        printf("COORDENADA INVALIDA! tente novamente ;-;\n");
        scanf("%d %d",&i, &j);
    }
    jogo[i][j] = c; // preenche o campo com a letra do jogador
}