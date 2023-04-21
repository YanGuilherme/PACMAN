#include <stdio.h>
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/keyboard.h>

#include "Pacman.h"
#include "Labirinto.h"
#include "Pilula.h"

using namespace std;

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

int main(){

   Pacman pac;
   Labirinto lab;
    //Inicializacao dos serviços basicos
   al_init();
   al_init_image_addon();
   al_install_keyboard();


   ALLEGRO_DISPLAY *display = al_create_display(LARGURA_TABULEIRO,ALTURA_TABULEIRO); //Inicializacao do display
   al_set_window_title(display, "PACMAN");

   ALLEGRO_TIMER* timer = al_create_timer(1.0/20.0); // fps
   al_set_window_position(display,200,200); //seta onde abre a tela

   ALLEGRO_EVENT_QUEUE * event_queue = al_create_event_queue();
   al_register_event_source(event_queue, al_get_display_event_source(display));
   al_register_event_source(event_queue, al_get_timer_event_source(timer));
   al_register_event_source(event_queue, al_get_keyboard_event_source());

   al_start_timer(timer);

   pac.setDirecao(PARADO);


   lab.setNome_arquivo("./imagenstrab/coordenadas.txt");
   lab.carregarPosicaoDosTijolos();
   

   while(true){ //Loop principal
      ALLEGRO_EVENT event;
      al_wait_for_event(event_queue, &event); //esperar o evento

      if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE){ // fechar janela clicando no x
         break;
      }else if(event.keyboard.keycode == ALLEGRO_KEY_RIGHT){
         pac.setDirecao(DIREITA);
         pac.setCurrentFrame(0);

      }else if(event.keyboard.keycode == ALLEGRO_KEY_LEFT){

         pac.setDirecao(ESQUERDA);
         pac.setCurrentFrame(ALTURA_PACMAN);
      

      }else if(event.keyboard.keycode == ALLEGRO_KEY_DOWN){
         pac.setDirecao(BAIXO);
         pac.setCurrentFrame(ALTURA_PACMAN * 3);
         

      }else if(event.keyboard.keycode == ALLEGRO_KEY_UP){
         pac.setDirecao(CIMA);
         pac.setCurrentFrame(ALTURA_PACMAN * 2);

      }
      pac.move_jogador();
      //printf("x: %d\ny: %d", pac.getPos_x(), pac.getPos_y());
      lab.exibir_labirinto();
      pac.exibe_pacman();
      al_flip_display();
   }

   al_rest(0.1); //atrasar a movimentacao   
   al_destroy_display(display); //Destroi a tela
   al_destroy_event_queue(event_queue);//destroi fila de eventos
   al_destroy_bitmap(pac.sprite_pacman); //destoi imagem do pacman
   al_destroy_bitmap(lab.mapa_desenho); //destroi fundo
   al_uninstall_keyboard(); //desinstalar o teclado

   return 0;
}