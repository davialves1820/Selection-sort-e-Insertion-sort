#include "impressao.h"

void preencher_jogo(char jogo[][3]) { // inicializar cada posição da matriz com espaço em branco
    for (int i = 0;i < 3; i++) {
        for(int j = 0;j < 3; j++) {
            jogo[i][j] = ' ';
        }
    }
}

void imprimir_jogo(char jogo[][3]) { // exibe o jogo para o usuario
    
    printf("\ncolunas\t  0  1   2\tlinhas\n\n");

    for (int i = 0;i < 3; i++){

        printf("\t");

        for (int j = 0;j < 3; j++) {
            printf(" %c ",jogo[i][j]);
            if(j < 2)
                printf("|");
            if(j == 2)
                printf("\t%d",i);
        }
        if (i < 2)
            printf("\n\t------------\n");
        else
            printf("\n\n");
    }
}