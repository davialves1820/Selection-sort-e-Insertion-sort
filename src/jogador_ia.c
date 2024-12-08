#include "jogador_ia.h"

void jogar_com_ia(char jogo[][3]) {

    for (int i = 0; i < 3; i ++) {
        for (int j = 0; j < 3; j++) {
            
            if (jogo[i][j] == ' ') {
                jogo[i][j] = 'O';
                
                if (vitoria_geral(jogo, 'O') > 0) {
                    return;
                }
                jogo[i][j] = 'X';
                
                if (vitoria_geral(jogo, 'X') > 0) {
                    jogo[i][j] = 'O';
                    return;
                }
                jogo[i][j] = ' ';
            }
        }
    }

    if (jogo[1][1] == ' ') {
        jogo[1][1] = 'O';
        return;
    }


    for (int i = 0; i < 3; i += 2) {
        for (int j = 0; j < 3; j += 2) {
            if (jogo[i][j] == ' ') {
                jogo[i][j] = 'O';
                return;
            }
        }
    }
    

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (jogo[i][j] == ' ') {
                jogo[i][j] = 'O';
                return;
            }
        }
    }
}