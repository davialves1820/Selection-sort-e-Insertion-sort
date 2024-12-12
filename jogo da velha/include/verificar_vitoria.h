#ifndef VERIFICAR_VITORIA
#define VERIFICAR_VITORIA

#include <stdio.h>

int vitoria_linha (int i,char jogo[][3],char c);

int vitoria_linhas (char jogo[][3],char c);

int vitoria_coluna (int i,char jogo[][3],char c);

int vitoria_colunas (char jogo[][3],char c);

int vitoria_diagonalP(char jogo[][3],char c);

int vitoria_diagonalS(char jogo[][3],char c);

int vitoria_geral(char jogo[][3], char c);

#endif