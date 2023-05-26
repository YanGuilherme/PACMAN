#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/keyboard.h>
#include "Personagem.h"
#include <math.h>

#ifndef PACMAN_H
#define PACMAN_H


class Pacman:public Personagem{
    public:
        Pacman();
        int coleta_pilula(Labirinto  *lab);
        void exibe_pacman();
        void altera_frame_pacman();
        void move_pacman(Labirinto lab);



};

#endif