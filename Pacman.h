#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/keyboard.h>
#include "Personagem.h"
#include <math.h>

#ifndef PACMAN_H
#define PACMAN_H


#define DESLOCAMENTO 5
#define PARADO 0
#define CIMA 1
#define DIREITA 2
#define BAIXO 3
#define ESQUERDA 4
#define ALTURA_TABULEIRO 722
#define LARGURA_TABULEIRO 722
#define MARGEM 38
#define ALTURA_PACMAN 38
#define LARGURA_PACMAN 38
#define SEM_INTENCAO 6
#define FATOR_PIXEL 5

class Pacman:public Personagem{
    public:
        int coleta_pilula(Labirinto  *lab);

};

#endif