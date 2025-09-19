#ifndef FANTASMA_H
#define FANTASMA_H
#include <random>
#include "Personagem.h"
#include <iostream>

#define LADO_FANTASMA 38


class Fantasma: public Personagem{
    public:
        Fantasma(int);
        ~Fantasma();
        void exibe_fantasma();
        void altera_frame_fantasma();
        void move_fantasma_random(const Labirinto& lab);
        void direct_chase(const Labirinto& lab, const Pacman &pac);
        void vision_pursuit(const Labirinto& lab, const Pacman& pac);

        Fantasma(const Fantasma&) = delete;
        Fantasma& operator=(const Fantasma&) = delete;

    private:
        int num_possibilidades(const Labirinto& lab);

};





#endif