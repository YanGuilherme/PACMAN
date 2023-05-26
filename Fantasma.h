#ifndef FANTASMA_H
#define FANTASMA_H
#include <random>
#include "Personagem.h"

#define LADO_FANTASMA 38


class Fantasma: public Personagem{
    public:
        Fantasma();
        Fantasma(int);
        void exibe_fantasma();
        void altera_frame_fantasma();
        void move_fantasma(Labirinto lab);
        void move_fantasma_perseguicao(Labirinto lab, Pacman);
    private:
        int num_possibilidades(Labirinto lab);

        // bool matou_pacman();
        // float frame_fantasma;

};





#endif