#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/keyboard.h>
#include "Pacman.h"
#include <stdio.h>
#include <iostream>

using namespace std;




int Pacman::colidiu_direita_tijolo(Labirinto lab){ 
   int indiceX, indiceY;
   indiceX = (pos_x/ALTURA_PACMAN)+1;
   indiceY = (pos_y/ALTURA_PACMAN);
   if(lab.matriz_colisao[(int)indiceY][(int)indiceX] == PILULA ){
      return DIREITA;
   }
   return PARADO;
}








int Pacman::colidiu_esquerda_tijolo(Labirinto lab){ 
   int indiceX, indiceY;
   indiceX = (pos_x-5)/LARGURA_PACMAN;
   indiceY = (pos_y)/ALTURA_PACMAN;
   

   if(lab.matriz_colisao[(int)indiceY][(int)indiceX] != TIJOLO ){
      return ESQUERDA;
   }
   return PARADO;
}








int Pacman::colidiu_baixo_tijolo(Labirinto lab){ 
   int indiceX, indiceY;
   indiceX = (pos_x/ALTURA_PACMAN);
   indiceY= (pos_y/ALTURA_PACMAN)+1;
   if(lab.matriz_colisao[(int)indiceY][(int)indiceX] == PILULA ){
      return BAIXO;
   }
   return PARADO;
}





int Pacman::colidiu_cima_tijolo(Labirinto lab){ 
   int indiceX, indiceY;
   indiceX = ((pos_x)/ALTURA_PACMAN);
   indiceY= ((pos_y-5)/ALTURA_PACMAN);

   if(lab.matriz_colisao[(int)indiceY][(int)indiceX] == PILULA ){
      return CIMA;
   }
   return PARADO;
}

void Pacman::exibe_pacman(){
    sprite_pacman = al_load_bitmap("./imagenstrab/sprites2.png");
    al_draw_bitmap_region(sprite_pacman, LARGURA_PACMAN*(int)frame, current_frame_y, LARGURA_PACMAN, ALTURA_PACMAN, pos_x ,pos_y,0);
    altera_frame();
}

void Pacman::move_jogador(Labirinto lab){
   if(direcao == DIREITA){
         direcao = colidiu_direita_tijolo(lab); 
            if(direcao  != PARADO){
               current_frame_y = 0;
               pos_x+=DESLOCAMENTO;
            }


   }else if(direcao == ESQUERDA){
      direcao =colidiu_esquerda_tijolo(lab);
      if(direcao != PARADO){
         current_frame_y = ALTURA_PACMAN;
         pos_x-= DESLOCAMENTO;
      }


   }else if(direcao == BAIXO){
      direcao =colidiu_baixo_tijolo(lab);
      if(direcao != PARADO){
         current_frame_y = ALTURA_PACMAN*3;
         pos_y+=DESLOCAMENTO;
      }


   }else if(direcao == CIMA){
      direcao = colidiu_cima_tijolo(lab);
      if(direcao != PARADO) {
         current_frame_y = ALTURA_PACMAN*2;
         pos_y-= DESLOCAMENTO;
      }

   }
}

void Pacman::altera_frame(){
      frame += 0.2f;
      if(frame > 2){
         frame -= 2;
      }
}

int Pacman::getPos_x(){
    return pos_x;
}
int Pacman::getPos_y(){
    return pos_y;
}
int Pacman::getDirecao(){
    return direcao;
}

int Pacman::getCurrentFrame(){
    return current_frame_y;
}

void Pacman::setPos_x(int x){
    pos_x = x;
}
void Pacman::setPos_y(int y){
    pos_y = y;
}
void Pacman::setDirecao(int dir){
    direcao = dir;
}

void Pacman::setCurrentFrame(int cf){
    current_frame_y = cf;
}

