#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/keyboard.h>
#include "Pacman.h"
#include <stdio.h>
#include <iostream>

using namespace std;


int Pacman::saiu_borda_direita(int x){ 
   return x > LARGURA_TABULEIRO- LARGURA_PACMAN - MARGEM ?  PARADO : DIREITA;
}

int Pacman::colidiu_direita(Labirinto lab,int x, int y){ 
   if(saiu_borda_direita(x) == PARADO){
      return PARADO;
   }

   if(colidiu_direita_tijolo(lab, x ,y) == PARADO ){
      return PARADO;
   }
   return DIREITA;
}

int Pacman::colidiu_direita_tijolo(Labirinto lab, int x, int y){ 
   int indiceX, indiceY;
   indiceX = (x/ALTURA_PACMAN)+1;
   indiceY = (y/ALTURA_PACMAN);
   if(lab.matriz_colisao[(int)indiceY][(int)indiceX] == PILULA ){
      return DIREITA;
   }
   return PARADO;
}






int Pacman::saiu_borda_esquerda(int x){
   return x <= MARGEM ? PARADO : ESQUERDA;
}

int Pacman::colidiu_esquerda(Labirinto lab,int x, int y){ 
   if(saiu_borda_esquerda(x) == PARADO){
      return PARADO;
   }

   if(colidiu_esquerda_tijolo(lab, x ,y) == PARADO ){
      return PARADO;
   }
   return ESQUERDA;
}

int Pacman::colidiu_esquerda_tijolo(Labirinto lab, int x, int y){ 
   int indiceX, indiceY;
   indiceX = (x/LARGURA_PACMAN);
   indiceY = (y/ALTURA_PACMAN);
   if(lab.matriz_colisao[(int)indiceY][(int)indiceX] == PILULA ){
      return ESQUERDA;
   }
   return PARADO;
}






int Pacman::saiu_borda_baixo(int y){
   return y > ALTURA_TABULEIRO - ALTURA_PACMAN - MARGEM ? PARADO : BAIXO;
}

int Pacman::colidiu_baixo(Labirinto lab,int x, int y){ 
   if(saiu_borda_baixo(x) == PARADO){
      return PARADO;
   }

   if(colidiu_baixo_tijolo(lab, x ,y) == PARADO ){
      return PARADO;
   }
   return BAIXO;
}

int Pacman::colidiu_baixo_tijolo(Labirinto lab, int x, int y){ 
   int indiceX, indiceY;
   indiceX = (x/ALTURA_PACMAN);
   indiceY= (y/ALTURA_PACMAN)+1;
   if(lab.matriz_colisao[(int)indiceY][(int)indiceX] == PILULA ){
      return BAIXO;
   }
   return PARADO;
}



int Pacman::saiu_borda_cima(int y){
   return y <= MARGEM ? PARADO : CIMA;
}
int Pacman::colidiu_cima(Labirinto lab,int x, int y){ 
   if(saiu_borda_cima(y) == PARADO){
      return PARADO;
   }

   if(colidiu_cima_tijolo(lab, x ,y) == PARADO ){
      return PARADO;
   }
   return CIMA;
}

int Pacman::colidiu_cima_tijolo(Labirinto lab, int x, int y){ 
   int indiceX, indiceY;
   indiceX = (x/ALTURA_PACMAN);
   indiceY = (y/ALTURA_PACMAN);
   if(lab.matriz_colisao[(int)indiceY][(int)indiceX] == PILULA ){
      return CIMA;
   }
   return PARADO;
}

void Pacman::exibe_pacman(){
    sprite_pacman = al_load_bitmap("./imagenstrab/sprites2.png");
    al_draw_bitmap_region(sprite_pacman, LARGURA_PACMAN*(int)frame, getCurrentFrame(), LARGURA_PACMAN, ALTURA_PACMAN, getPos_x() ,getPos_y(),0);
    altera_frame();
}

void Pacman::move_jogador(Labirinto lab){
   if(getDirecao() == PARADO){
      return;
   }
   if(getDirecao() ==  DIREITA){
         setDirecao(colidiu_direita(lab,getPos_x(),getPos_y())); 
            if(getDirecao()  != PARADO) setPos_x(pos_x+=DESLOCAMENTO);
   }else if(getDirecao() == ESQUERDA){
      setDirecao(colidiu_esquerda(lab,getPos_x(),getPos_y()));
      if(getDirecao() != PARADO) setPos_x(pos_x-= DESLOCAMENTO);
   }else if(getDirecao() == BAIXO){
      setDirecao(colidiu_baixo(lab,getPos_x(),getPos_y()));
      if(getDirecao() != PARADO) setPos_y(pos_y+=DESLOCAMENTO);
   }else if(getDirecao() == CIMA){
      setDirecao(colidiu_cima(lab,getPos_x(),getPos_y()));
      if(getDirecao() != PARADO) setPos_y(pos_y-= DESLOCAMENTO);
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

