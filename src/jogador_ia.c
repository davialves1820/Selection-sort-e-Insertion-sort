#include "jogador_ia.h"

// Regra 1
int verificar_vitoria(char jogo[][3]) {

    // verifica se há alguma posição que a máquina possa vencer 
    // caso exista a máquina preenche esse espaço em branco
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {

            // ver se a posição ainda não foi preenchida
            if (jogo[i][j] == ' ') {

                // preenche a posição e em seguida verifica se causa um cenário de vitória
                jogo[i][j] = 'O';
                
                if (vitoria_geral(jogo, 'O') > 0) {
                    return 1;
                }
                
                // Caso não haja vitória a posição volta a ficar vazia
                jogo[i][j] = ' ';
            }
        }
    }

    // verifica se há alguma posição que o jogador possa vencer 
    // caso exista a máquina preenche esse espaço em branco
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (jogo[i][j] == ' ') {

                // preenche a posição e em seguida verifica se causa um cenário de vitória
                jogo[i][j] = 'X';
                
                if (vitoria_geral(jogo, 'X') > 0) {
                    jogo[i][j] = 'O';
                    return 1;
                }
                // Caso não haja vitória a posição volta a ficar vazia
                jogo[i][j] = ' ';
            }
            
        }
    }

    return 0;
}

// Regra 2
int verificar_sequencia_de_duas(char jogo[][3]) {

    //  Se houver uma jogada que crie duas sequências de duas marcações 
    int pontos = 0; // variável que vai guardar a quantidade de pontos da linha de acordo com o simbolo em cada espaço
    // o simbolo O vale 1 e X vale 3, espaço em branco não vale nada
    int linha = -1; // inicializa com -1 para impeder que preencha uma posição caso a condição de apenas ter 1 simbolo O na linha

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {

            if (jogo[i][j] == 'O') {
                pontos++;
            } else if (jogo[i][j] == 'X') {
                pontos += 3;
            }

        }
        // verifica se há condição de apenas um simbolo O na linha foi satisfeita
        if (pontos == 1) {
            linha = i; // guarda a linha que a condição foi satisfeita
        }
        pontos = 0; // reinicia os pontos para a chamada de uma nova linha
    }

    pontos = 0; // variável que vai guardar a quantidade de pontos da coluna de acordo com o simbolo em cada espaço
    int coluna = -1; // inicializa com -1 para impeder que preencha uma posição caso a condição de apenas ter 1 simbolo O na linha ou coluna

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {

            if (jogo[j][i] == 'O') {
                pontos++;
            } else if (jogo[j][i] == 'X') {
                pontos += 3;
            }

        }
        // verifica se há condição de apenas um simbolo O na coluna foi satisfeita
        if (pontos == 1) {
            coluna = i; // guarda a coluna que a condição foi satisfeita
        }
        pontos = 0; // reinicia os pontos para a chamada de uma nova coluna
    }

    // verifica se foram encontradas linha e coluna que satisfaçam a condição anterior, além de ver se a posição está vazia
    if (linha >= 0 && coluna >= 0 && jogo[linha][coluna] == ' ') { 
        jogo[linha][coluna] = 'O';
        return 1;
    }

    return 0;
}

// Regra 3
int verificar_centro(char jogo[][3]) {

    // verifica se a posição central não foi jogada
    if (jogo[1][1] == ' ') {
        jogo[1][1] = 'O';
        return 1;
    }

    return 0;
}

// Regra 4
int verificar_marcacao_canto_oposto(char jogo[][3]) {

    // caso o jogador marcar um canto, marca-se o oposto
    if (jogo[0][0] == 'X' && jogo[2][2] == ' ') {
        jogo[2][2] = 'O';
        return 1;
    }
    if (jogo[0][2] == 'X' && jogo[2][0] == ' ') {
        jogo[2][0] = 'O';
        return 1;
    }
    if (jogo[2][0] == 'X' && jogo[0][2] == ' ') {
        jogo[0][2] = 'O';
        return 1;
    }
    if (jogo[2][2] == 'X' && jogo[0][0] == ' ') {
        jogo[0][0] = 'O';
        return 1;
    }

    return 0;
}

// Regra 5
int verificar_canto_vazio(char jogo[][3]) {

    // dar prioridade ao preenchimento dos cantos
    for (int i = 0; i < 3; i += 2) {
        for (int j = 0; j < 3; j += 2) {
            if (jogo[i][j] == ' ') {
                jogo[i][j] = 'O';
                return 1;
            }
        }
    }

    return 0;
}

// Regra 6
void marcar_arbitrariamente(char jogo[][3]) {
    
    // preenche de forma aleatória
    int posicoes_livres[9][2];
    int numero_livres = 0;

    // identificar as posições livres
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (jogo[i][j] == ' ') {
                posicoes_livres[numero_livres][0] = i;
                posicoes_livres[numero_livres][1] = j;
                numero_livres++;
            }
        }
    }

    // escolher uma posição aleatória entre as livres
    if (numero_livres > 0) {
        srand(time(NULL));
        int indice = rand() % numero_livres;
        int l = posicoes_livres[indice][0];
        int c = posicoes_livres[indice][1];
        jogo[l][c] = 'O';
    }
}

void jogar_com_ia(char jogo[][3]) {

    // os ifs servem para verificar se a função chamada preencheu alguma posição no jogo
    // com isso evitasse que mais de uma posição seja preenchida em uma única jogada

    if (verificar_vitoria(jogo)) {
        return;
    }

    if (verificar_sequencia_de_duas(jogo)) {
        return;
    }

    if (verificar_centro(jogo)) {
        return;
    }

    if (verificar_marcacao_canto_oposto(jogo)) {
        return;
    }

    if (verificar_canto_vazio(jogo)) {
        return;
    }
    
    marcar_arbitrariamente(jogo);
}