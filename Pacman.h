#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/keyboard.h>
#include "Labirinto.h"
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


class Pacman{
    public:
        void exibe_pacman();
    
        float frame;
        
        void move_jogador(Labirinto lab);

        void altera_frame();



        int getPos_x();
        int getPos_y();
        int getDirecao();
        int getCurrentFrame();

        int getIntencao();

        void setPos_x(int x);
        void setPos_y(int y);
        void setDirecao(int dir);
        void setCurrentFrame(int cf);

        void setIntencao(int inten);
        int coleta_pilula(Labirinto  *lab);



        ALLEGRO_BITMAP* sprite_pacman;


    private:

        int colidiu_direita_tijolo(Labirinto lab);

        int colidiu_esquerda_tijolo(Labirinto lab);


        int colidiu_baixo_tijolo(Labirinto lab);



        int colidiu_cima_tijolo(Labirinto lab);

        
        
   
        //variaveis para a movimentacao do pacman;
        int pos_x = (LARGURA_TABULEIRO/2-(LARGURA_PACMAN/2)), pos_y = ((ALTURA_TABULEIRO/2-(ALTURA_PACMAN/2))+ALTURA_PACMAN);
        int current_frame_y = 0;
        int direcao = PARADO;
        int intencao = SEM_INTENCAO;
};

#endif