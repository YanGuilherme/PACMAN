#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/keyboard.h>
#include "Pacman.h"
#include <stdio.h>
#include <iostream>

using namespace std;

int Pacman::coleta_pilula(Labirinto *lab){
   int indiceX = (pos_x+(LARGURA_PACMAN/2))/LARGURA_PACMAN;
   int indiceY = (pos_y+(ALTURA_PACMAN/2))/ALTURA_PACMAN;

   if(lab->matriz_colisao[indiceY][indiceX] == PILULA){
      lab->matriz_colisao[indiceY][indiceX] = CELULA_VAZIA;
      return 1;
   }

   return 0;
}
