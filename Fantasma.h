#ifndef FANTASMA_H
#define FANTASMA_H
#include <random>
#include "Personagem.h"
#include <iostream>

#define LADO_FANTASMA 38


class Fantasma: public Personagem{
    public:
        Fantasma();
        Fantasma(int);
        void exibe_fantasma();
        void altera_frame_fantasma();
        void move_fantasma_random(Labirinto lab);
        void direct_chase(Labirinto lab, Pacman);
        void vision_pursuit(Labirinto lab, Pacman);

    private:
        int num_possibilidades(Labirinto lab);

};





#endif