#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/keyboard.h>
#include "ListaCoordenadas.h"
#include "Labirinto.h"
#include "Coordenada.h"
#include <vector>

#ifndef PERSONAGEM_H
#define PERSONAGEM_H

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

class Pacman;
class Personagem{

    public:
        float frame;
        int getPos_x();
        int getPos_y();
        int getDirecao();
        int getIntencao();
        void altera_frame();
        void setPos_x(int x);
        void setPos_y(int y);
        int getCurrentFrame();
        void exibe_personagem();
        void setDirecao(int dir);
        void setIntencao(int inten);
        void setCurrentFrame(int cf);
        void move_personagem(Labirinto lab);
        ALLEGRO_BITMAP* sprite_personagem;

    private:

        int colidiu_cima_tijolo(Labirinto lab);
        int colidiu_baixo_tijolo(Labirinto lab);
        int colidiu_direita_tijolo(Labirinto lab);
        int colidiu_esquerda_tijolo(Labirinto lab);

        //variaveis para a movimentacao do pacman;
        int current_frame_y = 0;
        int direcao = PARADO;
        int intencao = SEM_INTENCAO;

    protected:
        //variaveis para a movimentacao do pacman;
        int pos_x = (LARGURA_TABULEIRO/2-(LARGURA_PACMAN/2));
        int pos_y = ((ALTURA_TABULEIRO/2-(ALTURA_PACMAN/2))+ALTURA_PACMAN);

};

#endif