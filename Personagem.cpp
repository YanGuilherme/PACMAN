#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/keyboard.h>
#include "Personagem.h"
#include <stdio.h>
#include <iostream>

using namespace std;

int Personagem::colidiu_direita_tijolo(Labirinto lab){ 
   int indiceX, indiceY1, indiceY2;
   indiceX = ((pos_x + LARGURA_PACMAN)/LARGURA_PACMAN);
   indiceY1 = (pos_y/ALTURA_PACMAN);
   indiceY2 = ((pos_y + ALTURA_PACMAN - FATOR_PIXEL)/ALTURA_PACMAN);
   if(lab.matriz_colisao[indiceY1][indiceX] == TIJOLO || lab.matriz_colisao[indiceY2][indiceX] == TIJOLO){
      return PARADO;
   }
   return DIREITA;
}


int Personagem::colidiu_esquerda_tijolo(Labirinto lab){ 
   int indiceX, indiceY1, indiceY2;
   indiceX = (pos_x - FATOR_PIXEL)/(LARGURA_PACMAN);
   indiceY1 = (pos_y + ALTURA_PACMAN - FATOR_PIXEL)/ALTURA_PACMAN;
   indiceY2 = (pos_y)/ALTURA_PACMAN;
   
   if(lab.matriz_colisao[indiceY1][indiceX] == TIJOLO || lab.matriz_colisao[indiceY2][indiceX] == TIJOLO){
      return PARADO;
   }
   return ESQUERDA;
}


int Personagem::colidiu_baixo_tijolo(Labirinto lab){ 
   int indiceX1, indiceX2, indiceY;
   indiceX1 = ((pos_x)/LARGURA_PACMAN);
   indiceX2 = ((pos_x + LARGURA_PACMAN - FATOR_PIXEL)/LARGURA_PACMAN);
   indiceY = ((pos_y + ALTURA_PACMAN)/ALTURA_PACMAN);

   if(lab.matriz_colisao[indiceY][indiceX1] == TIJOLO || lab.matriz_colisao[indiceY][indiceX2] == TIJOLO  ){
      return PARADO;
   }
   return BAIXO;
}


int Personagem::colidiu_cima_tijolo(Labirinto lab){ 
   int indiceX1, indiceX2, indiceY;
   indiceX1 = ((pos_x)/LARGURA_PACMAN);
   indiceX2 = ((pos_x + LARGURA_PACMAN - FATOR_PIXEL)/LARGURA_PACMAN);
   indiceY = ((pos_y - FATOR_PIXEL)/ALTURA_PACMAN);

   if(lab.matriz_colisao[indiceY][indiceX1] == TIJOLO || lab.matriz_colisao[indiceY][indiceX2] == TIJOLO  ){
      return PARADO;
   }
   return CIMA;
}



int Personagem::getPos_x(){
    return pos_x;
}
int Personagem::getPos_y(){
    return pos_y;
}
int Personagem::getDirecao(){
    return direcao;
}

int Personagem::getCurrentFrame(){
    return current_frame_y;
}

int Personagem::getIntencao(){
    return intencao;
}

void Personagem::setPos_x(int x){
    pos_x = x;
}
void Personagem::setPos_y(int y){
    pos_y = y;
}
void Personagem::setDirecao(int dir){
    direcao = dir;
}

void Personagem::setCurrentFrame(int cf){
    current_frame_y = cf;
}

void Personagem::setIntencao(int inten){
   intencao = inten;
}
