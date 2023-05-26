#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/keyboard.h>
#include "Pacman.h"
#include <stdio.h>
#include <iostream>

using namespace std;

Pacman::Pacman(){
   pos_x = (LARGURA_TABULEIRO/2-(LARGURA_PACMAN/2));
   pos_y = ((ALTURA_TABULEIRO/2-(ALTURA_PACMAN/2))+ALTURA_PACMAN);

   direcao = PARADO;
   intencao = SEM_INTENCAO;
   nome_imagem = "./imagenstrab/sprites2.png";


}

int Pacman::coleta_pilula(Labirinto *lab)
{
    int indiceX = (pos_x + (LARGURA_PACMAN / 2)) / LARGURA_PACMAN;
    int indiceY = (pos_y + (ALTURA_PACMAN / 2)) / ALTURA_PACMAN;

    if (lab->matriz_colisao[indiceY][indiceX] == PILULA)
    {
        lab->matriz_colisao[indiceY][indiceX] = CELULA_VAZIA;
        return 1;
    }

    return 0;
}

void Pacman::exibe_pacman(){
    sprite_personagem = al_load_bitmap(nome_imagem);
    al_draw_bitmap_region(sprite_personagem, LARGURA_PACMAN*(int)frame, current_frame_y, LARGURA_PACMAN, ALTURA_PACMAN, pos_x ,pos_y,0);
    altera_frame_pacman();
}

void Pacman::move_pacman(Labirinto lab){

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

void Pacman::altera_frame_pacman(){
      frame += 0.2f;
      if(frame > 2){
         frame -= 2;
      }
}