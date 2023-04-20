#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/keyboard.h>

#ifndef PACMAN_H
#define PACMAN_H


#define DESLOCAMENTO 5
#define PARADO 0
#define CIMA 1
#define DIREITA 2
#define BAIXO 3
#define ESQUERDA 4
#define ALTURA_TABULEIRO 684
#define LARGURA_TABULEIRO 684
#define MARGEM 36
#define ALTURA_PACMAN 36
#define LARGURA_PACMAN 36


class Pacman{
    public:
        void exibe_pacman();
    
        float frame;
        
        void move_jogador();

        void altera_frame();

        int getPos_x();
        int getPos_y();
        int getDirecao();
        int getCurrentFrame();

        void setPos_x(int x);
        void setPos_y(int y);
        void setDirecao(int dir);
        void setCurrentFrame(int cf);

        ALLEGRO_BITMAP* sprite_pacman;


    private:
        int saiu_direita(int x);
        int saiu_esquerda(int x);
        int saiu_baixo(int y);
        int saiu_cima(int y);
        
   
        //variaveis para a movimentacao do pacman;
        int pos_x = (LARGURA_TABULEIRO/2-(LARGURA_PACMAN/2)), pos_y = ((ALTURA_TABULEIRO/2-(ALTURA_PACMAN/2))+43);
        int current_frame_y = 0;
        int direcao = PARADO;
};

#endif