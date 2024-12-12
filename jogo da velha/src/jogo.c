#include "jogo.h"

// função que executa o jogo
void gameplay() { 

    int again;
    
    do { // looping de execução do jogo

        char jgX = 'X', jgO = 'O', jogo[3][3];
        int jogadas = 0, jogador = 0, vx = 0, vo = 0;
        preencher_jogo(jogo); // inicia o jogo

        // looping de uma partida
        do { 
            imprimir_jogo(jogo);
            
            // verifica de quem é a vez de jogar, se jogador = 0 é o jogador O, caso contrario jogador X
            if (jogador == 0) { 
                jogar_com_ia(jogo);
                jogador++;
                vo = vitoria_geral(jogo, jgO);
            }
            else {
                jogada(jogo, jgX);
                jogador--;
                vx = vitoria_geral(jogo, jgX);
            }
            jogadas++;

        } while (jogadas < 9 && vx == 0 && vo == 0); // enquanto não forem preenchidos todos os espaços da matriz ou quando um dos jogadores não tiver ganho
        
        imprimir_jogo(jogo); // exibe a situação do jogo após o fim
        
        if (vo != 0) { // vitoria do O
            printf("PARABENS JOGADOR O");
        } else if (vx != 0) { // vitoria do X
            printf("PARABENS JOGADOR X"); 
        } else { // caso de empate
            printf("JOGO TERMINOU EMPATADO");
        }
        
        // verificar se os jogadores querem jogar de novo
        do { 
            printf("\n1- jogar novamente \n0- sair\n");
            scanf("%d",&again);
        } while (again > 1 || again < 0);

    } while (again == 1);
}