#ifndef JOGADOR_IA_H
#define JOGADOR_IA_H

#include "verificar_vitoria.h"
#include <stdlib.h>
#include <time.h>


int verificar_vitoria(char jogo[][3]);

int verificar_sequencia_de_duas(char jogo[][3]);

int verificar_centro(char jogo[][3]);

int verificar_marcacao_canto_oposto(char jogo[][3]);

int verificar_canto_vazio(char jogo[][3]);

void marcar_arbitrariamente(char jogo[][3]);

void jogar_com_ia(char jogo[][3]);

#endif