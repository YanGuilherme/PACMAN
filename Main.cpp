#include <stdio.h>
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/keyboard.h>

#include "Pacman.h"
#include "Labirinto.h"

using namespace std;



void imprime_matriz_colisao(Labirinto lab){
   for(int i = 0 ; i<ORDEM ; i++){
      for(int j = 0 ; j <ORDEM; j++){
            printf("%d", lab.matriz_colisao[i][j]);
      }
         printf("\n");
   }

}


void colisao(Pacman *pac,Labirinto lab,int indiceX, int indiceY){
   if(lab.matriz_colisao[indiceX][indiceY] == TIJOLO){
      cout << "Encostei em um tijolo." << endl;
   }   
}



int main(){

   ListaCoordenadas lc;
   Pacman pac;
   Labirinto lab = Labirinto();

    //Inicializacao dos serviços basicos
   al_init();
   al_init_image_addon();
   al_install_keyboard();


   ALLEGRO_DISPLAY *display;
   // carrega_display(display);
   display = al_create_display(LARGURA_TABULEIRO,ALTURA_TABULEIRO); //Inicializacao do display
   al_set_window_title(display, "PACMAN");
   al_set_window_position(display,200,200); //seta onde abre a tela
   ALLEGRO_TIMER* timer = al_create_timer(1.0/20.0); // fps

   ALLEGRO_EVENT_QUEUE * event_queue = al_create_event_queue();
   al_register_event_source(event_queue, al_get_display_event_source(display));
   al_register_event_source(event_queue, al_get_timer_event_source(timer));
   al_register_event_source(event_queue, al_get_keyboard_event_source());

   al_start_timer(timer);

   pac.setDirecao(PARADO);


   lab.setNome_arquivo("./imagenstrab/coordenadas.txt");
   lab.carregarPosicaoDosTijolos();
   lab.carregarPosicaoDasPilulas();


   while(true){ //Loop principal

      ALLEGRO_EVENT event;
      al_wait_for_event(event_queue, &event); //esperar o evento

      if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE){ // fechar janela clicando no x
         break;
      }else if(event.keyboard.keycode == ALLEGRO_KEY_RIGHT){
         pac.setIntencao(DIREITA);


      }else if(event.keyboard.keycode == ALLEGRO_KEY_LEFT){

         pac.setIntencao(ESQUERDA);

      

      }else if(event.keyboard.keycode == ALLEGRO_KEY_DOWN){
         pac.setIntencao(BAIXO);

         

      }else if(event.keyboard.keycode == ALLEGRO_KEY_UP){
         pac.setIntencao(CIMA);


      }
      //int indiceX = (pac.getPos_x()/ALTURA_PACMAN);
      //int indiceY = (pac.getPos_y()/ALTURA_PACMAN);

      pac.move_jogador(lab);
      pac.coleta_pilula(&lab);
      lab.exibir_pilulas();
      pac.exibe_pacman();

      imprime_matriz_colisao(lab);



      al_flip_display();    
      lab.exibir_labirinto();




   }

   al_rest(1.0); //atrasar a movimentacao   
   al_destroy_display(display); //Destroi a tela
   al_destroy_event_queue(event_queue);//destroi fila de eventos
   al_destroy_bitmap(pac.sprite_pacman); //destoi imagem do pacman
   al_destroy_bitmap(lab.mapa_desenho); //destroi fundo
   al_uninstall_keyboard(); //desinstalar o teclado

   return 0;
}