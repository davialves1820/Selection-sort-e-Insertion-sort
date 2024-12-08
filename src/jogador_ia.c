#include "jogador_ia.h"

void jogar_com_ia(char jogo[][3]) {

    // verifica se há alguma posição que a máquina possa vencer ou se o jogador pode vencer 
    // caso exista a máquina preenche esse espaço em branco
    for (int i = 0; i < 3; i ++) {
        for (int j = 0; j < 3; j++) {

            // ver se a posição ainda não foi preenchida
            if (jogo[i][j] == ' ') {

                // preenche a posição e em seguida verifica se causa um cenário de vitória
                jogo[i][j] = 'O';
                
                if (vitoria_geral(jogo, 'O') > 0) {
                    return;
                }

                // Caso não cause um cenário de vitória para máquina faz o mesmo teste para o outro jogador
                jogo[i][j] = 'X';
                
                if (vitoria_geral(jogo, 'X') > 0) {
                    jogo[i][j] = 'O';
                    return;
                }
                
                // Caso não haja casos de vitória de ambas as partes a posição volta a ficar vazia
                jogo[i][j] = ' ';
            }
        }
    }

    // verifica se a posição central não foi jogada
    if (jogo[1][1] == ' ') {
        jogo[1][1] = 'O';
        return;
    }

    // dar prioridade ao preenchimento dos cantos
    for (int i = 0; i < 3; i += 2) {
        for (int j = 0; j < 3; j += 2) {
            if (jogo[i][j] == ' ') {
                jogo[i][j] = 'O';
                return;
            }
        }
    }
    
    // preenche de forma aleatória
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (jogo[i][j] == ' ') {
                jogo[i][j] = 'O';
                return;
            }
        }
    }
}