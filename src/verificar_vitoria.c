#include "verificar_vitoria.h"

int vitoria_linha(int i,char jogo[][3],char c) { // verifica vitoria em um linha, tem como parametro o numero da linha
    if (jogo[i][0] == c && jogo[i][1] == c && jogo[i][2] == c)
        return 1;
    else    
        return 0;
}

int vitoria_linhas(char jogo[][3],char c) { // verifica vitoria em todas as linhas
    int soma = 0;
    for (int i = 0;i < 3; i++) {
        soma += vitoria_linha(i,jogo, c); // passa o numero da linha para verificar se ocorreu vitoria
    }
    return soma;
}

int vitoria_coluna(int i,char jogo[][3],char c) { // verifica vitoria em uma coluna, tem como parametro o numero da coluna
    if (jogo[0][i] == c && jogo[1][i] == c && jogo[2][i] == c)
        return 1;
    else    
        return 0;
}

int vitoria_colunas(char jogo[][3],char c) { // verifica vitoria em todas as colunas
    int soma = 0;
    for(int i = 0;i < 3; i++){
        soma += vitoria_coluna(i,jogo, c); // passa o numero da coluna para verificar se ocorreu vitoria
    }
    return soma;
}

int vitoria_diagonalP(char jogo[][3],char c) { // verifica vitoria na diagonal principal
    if (jogo[0][0] == c && jogo[1][1] == c && jogo[2][2] == c)
        return 1;
    else
        return 0;
}

int vitoria_diagonalS(char jogo[][3],char c) { // verifica vitoria na diagonal secundaria
    if (jogo[0][2] == c && jogo[1][1] == c && jogo[2][0] == c)
        return 1;
    else
        return 0;
}

int vitoria_geral(char jogo[][3], char c) { // verifica se o jogador ganhou o jogo
    int vitoria = vitoria_colunas(jogo, c) + vitoria_linhas(jogo, c) + vitoria_diagonalP(jogo, c) + vitoria_diagonalS(jogo, c);
    return vitoria;
}