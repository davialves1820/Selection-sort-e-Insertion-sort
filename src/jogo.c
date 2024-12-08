#include "jogo.h"

void gameplay() { // função que executa o jogo
    int again;
    
    do{

    char jgX = 'X', jgO = 'O', jogo[3][3];
    int jogadas = 0, jogador = 0, vx = 0, vo = 0;
    preencher_jogo(jogo); // inicia o jogo

    do {
        imprimir_jogo(jogo);
        
        if (jogador == 0) { // verifica de quem é a vez de jogar, se jogador = 0 é o jogador X, caso contrario jogador O
            jogada(jogo, jgX);
            jogador++;
            vx = vitoria_geral(jogo, jgX);
        }
        else {
            jogar_com_ia(jogo);
            jogador--;
            vo = vitoria_geral(jogo, jgO);
        }
        jogadas++;

    } while (jogadas < 9 && vx == 0 && vo == 0); // enquanto não forem preenchidos todos os espaços da matriz ou quando um dos jogadores não tiver ganho
    
    imprimir_jogo(jogo); // exibe a situação do jogo após o fim
    
    if (vo != 0) // vitoria do O
        printf("PARABENS JOGADOR O :)");
    else if (vx != 0) { // vitoria do X
        printf("PARABENS JOGADOR X :)"); 
    }
    else { // caso de empate
        printf("JOGO TERMINOU EMPATADO");
    }
    
    do { // verificar se os jogadores querem jogar de novo
        printf("\n1- jogar novamente :)\n0- ir embora :(\n");
        scanf("%d",&again);
    } while (again > 1 || again < 0);

    } while (again == 1);
    printf("\n ;-_-;");
}