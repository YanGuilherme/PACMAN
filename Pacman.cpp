#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/keyboard.h>
#include "Pacman.h"
#include <stdio.h>
#include <iostream>

using namespace std;

int Pacman::colidiu_direita_tijolo(Labirinto lab){ 
   int indiceX, indiceY1, indiceY2;
   indiceX = ((pos_x + LARGURA_PACMAN)/LARGURA_PACMAN);
   indiceY1 = (pos_y/ALTURA_PACMAN);
   indiceY2 = ((pos_y + ALTURA_PACMAN - FATOR_PIXEL)/ALTURA_PACMAN);
   if(lab.matriz_colisao[indiceY1][indiceX] == TIJOLO || lab.matriz_colisao[indiceY2][indiceX] == TIJOLO){
      return PARADO;
   }
   return DIREITA;
}


int Pacman::colidiu_esquerda_tijolo(Labirinto lab){ 
   int indiceX, indiceY1, indiceY2;
   indiceX = (pos_x - FATOR_PIXEL)/(LARGURA_PACMAN);
   indiceY1 = (pos_y + ALTURA_PACMAN - FATOR_PIXEL)/ALTURA_PACMAN;
   indiceY2 = (pos_y)/ALTURA_PACMAN;
   
   if(lab.matriz_colisao[indiceY1][indiceX] == TIJOLO || lab.matriz_colisao[indiceY2][indiceX] == TIJOLO){
      return PARADO;
   }
   return ESQUERDA;
}


int Pacman::colidiu_baixo_tijolo(Labirinto lab){ 
   int indiceX1, indiceX2, indiceY;
   indiceX1 = ((pos_x)/LARGURA_PACMAN);
   indiceX2 = ((pos_x + LARGURA_PACMAN - FATOR_PIXEL)/LARGURA_PACMAN);
   indiceY = ((pos_y + ALTURA_PACMAN)/ALTURA_PACMAN);

   if(lab.matriz_colisao[indiceY][indiceX1] == TIJOLO || lab.matriz_colisao[indiceY][indiceX2] == TIJOLO  ){
      return PARADO;
   }
   return BAIXO;
}


int Pacman::colidiu_cima_tijolo(Labirinto lab){ 
   int indiceX1, indiceX2, indiceY;
   indiceX1 = ((pos_x)/LARGURA_PACMAN);
   indiceX2 = ((pos_x + LARGURA_PACMAN - FATOR_PIXEL)/LARGURA_PACMAN);
   indiceY = ((pos_y - FATOR_PIXEL)/ALTURA_PACMAN);

   if(lab.matriz_colisao[indiceY][indiceX1] == TIJOLO || lab.matriz_colisao[indiceY][indiceX2] == TIJOLO  ){
      return PARADO;
   }
   return CIMA;
}

void Pacman::exibe_pacman(){
    sprite_pacman = al_load_bitmap("./imagenstrab/sprites2.png");
    al_draw_bitmap_region(sprite_pacman, LARGURA_PACMAN*(int)frame, current_frame_y, LARGURA_PACMAN, ALTURA_PACMAN, pos_x ,pos_y,0);
    altera_frame();
}

void Pacman::move_jogador(Labirinto lab){

   if(intencao == SEM_INTENCAO && direcao == PARADO){ 
      return;
   }

   if(intencao == DIREITA && colidiu_direita_tijolo(lab)){
      direcao = intencao;
   }

   if(intencao == ESQUERDA && colidiu_esquerda_tijolo(lab)){
      direcao = intencao;
   }
   
   if(intencao == CIMA && colidiu_cima_tijolo(lab)){
      direcao = intencao;
   }

   if(intencao == BAIXO && colidiu_baixo_tijolo(lab)){
      direcao = intencao;
   }
   
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

int Pacman::coleta_pilula(Labirinto *lab){
   int indiceX = (pos_x+(LARGURA_PACMAN/2))/LARGURA_PACMAN;
   int indiceY = (pos_y+(ALTURA_PACMAN/2))/ALTURA_PACMAN;

   if(lab->matriz_colisao[indiceY][indiceX] == PILULA){
      lab->matriz_colisao[indiceY][indiceX] = CELULA_VAZIA;
      return 1;
   }

   return 0;
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

int Pacman::getIntencao(){
    return intencao;
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

void Pacman::setIntencao(int inten){
   intencao = inten;
}
