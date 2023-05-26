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
class Fantasma;
class Personagem{

    public:
        float frame;
        int getPos_x();
        int getPos_y();
        int getDirecao();
        int getIntencao();
        void setPos_x(int x);
        void setPos_y(int y);
        int getCurrentFrame();
        void setDirecao(int dir);
        void setIntencao(int inten);
        void setCurrentFrame(int cf);

        ALLEGRO_BITMAP* sprite_personagem;

    private:




    protected:
        //variaveis para a movimentacao do pacman;
        int pos_x;
        int pos_y;

        int current_frame_y = 0;

        int direcao;
        int intencao;

        const char* nome_imagem;
        int colidiu_cima_tijolo(Labirinto lab);
        int colidiu_baixo_tijolo(Labirinto lab);
        int colidiu_direita_tijolo(Labirinto lab);
        int colidiu_esquerda_tijolo(Labirinto lab);

};

#endif