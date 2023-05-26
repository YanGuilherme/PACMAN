#include <stdio.h>
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/keyboard.h>
#include <allegro5/allegro_ttf.h>
#include "Pacman.h"
#include "Labirinto.h"
#include "Fantasma.h"

using namespace std;


bool colisao_com_fantasma(Pacman pac, Fantasma ghost1, Fantasma ghost2,Fantasma ghost3,Fantasma ghost4){
   int indiceX[5];
   int indiceY[5];
   indiceX[0] = (pac.getPos_x()+(TAM_LADO/2))/TAM_LADO;
   indiceY[0] = (pac.getPos_y()+(TAM_LADO/2))/TAM_LADO;

   indiceX[1] = (ghost1.getPos_x()+(TAM_LADO/2))/TAM_LADO;
   indiceY[1] = (ghost1.getPos_y()+(TAM_LADO/2))/TAM_LADO;
   indiceX[2] = (ghost2.getPos_x()+(TAM_LADO/2))/TAM_LADO;
   indiceY[2] = (ghost2.getPos_y()+(TAM_LADO/2))/TAM_LADO;
   indiceX[3] = (ghost3.getPos_x()+(TAM_LADO/2))/TAM_LADO;
   indiceY[3] = (ghost3.getPos_y()+(TAM_LADO/2))/TAM_LADO;
   indiceX[4] = (ghost4.getPos_x()+(TAM_LADO/2))/TAM_LADO;
   indiceY[4] = (ghost4.getPos_y()+(TAM_LADO/2))/TAM_LADO;

   for(int i = 1 ; i < 5 ; i++){
      for(int j = 1 ; j < 5 ; j++){
         if(indiceX[0] == indiceX[i] && indiceY[0] == indiceY[i]){
            return true;
         }
      }
   }
   return false;


   // cout << indiceX[0] << endl << indiceY[0] << endl;
}


void imprime_matriz_colisao(Labirinto lab){
   for(int i = 0 ; i<ORDEM ; i++){
      for(int j = 0 ; j <ORDEM; j++){
            printf("%d ", lab.matriz_colisao[i][j]);
      }
         printf("\n");
   }
   printf("\n");

}

int main(){

   ListaCoordenadas lc;
   Pacman pac;
   Labirinto lab = Labirinto();
   int placar = 0;
   int pilulas_totais = 0;
   Fantasma ghost1(1), ghost2(2), ghost3(3), ghost4(4);
   char texto[50];

    //Inicializacao dos serviços basicos
   al_init();
   al_init_image_addon();
   al_install_keyboard();


   ALLEGRO_DISPLAY *display;

    // Inicialize o addon Allegro para trabalhar com fontes TrueType (TTF)
    al_init_font_addon();
    al_init_ttf_addon();

   // Carregando fonte especifica
   ALLEGRO_FONT *font = al_load_font("./imagenstrab/fonte_jogo.ttf", 40, 0);


   // Defina a cor do texto
   ALLEGRO_COLOR textColor = al_map_rgb(85,255,249);

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

   pilulas_totais += lab.conta_pilulas();
   //printf("%d\n", pilulas_totais);
   while(true){ //Loop principal

      ALLEGRO_EVENT event;
      al_wait_for_event(event_queue, &event); //esperar o evento

      switch (event.type) {
      case ALLEGRO_EVENT_DISPLAY_CLOSE:
         // fechar janela clicando no x
         break;
      case ALLEGRO_EVENT_KEY_DOWN:
         switch (event.keyboard.keycode) {
            case ALLEGRO_KEY_RIGHT:
            pac.setIntencao(DIREITA);
            break;
            case ALLEGRO_KEY_LEFT:
            pac.setIntencao(ESQUERDA);
            break;
            case ALLEGRO_KEY_DOWN:
            pac.setIntencao(BAIXO);
            break;
            case ALLEGRO_KEY_UP:
            pac.setIntencao(CIMA);
            break;
         }
         break;
      }

      //int indiceX = (pac.getPos_x()/ALTURA_PACMAN);
      //int indiceY = (pac.getPos_y()/ALTURA_PACMAN);
      pac.move_pacman(lab);
      placar += pac.coleta_pilula(&lab);
      lab.exibir_pilulas();
      pac.exibe_pacman();
      sprintf(texto, "PLACAR %d", placar);
      ghost1.exibe_fantasma();
      ghost1.move_fantasma(lab);
      ghost2.exibe_fantasma();
      ghost2.move_fantasma(lab);
      ghost3.exibe_fantasma();
      ghost3.move_fantasma(lab);
      ghost4.exibe_fantasma();
      ghost4.move_fantasma(lab);





      // Desenhe o texto no display
      al_draw_text(font, textColor, 361, 0, ALLEGRO_ALIGN_CENTER, texto);
      //imprime_matriz_colisao(lab);
      al_flip_display();    
      lab.exibir_labirinto();
      if(placar == pilulas_totais){
         printf("PARABENS, VOCE VENCEU !!!!\n\n");
         break;
      }else if(colisao_com_fantasma(pac,ghost1,ghost2,ghost3,ghost4)){
         printf("VOCE PERDEU !!!!\n\n");
         break;
      }

   }

   al_rest(1.0); //atrasar a movimentacao   
   al_destroy_font(font);
   al_destroy_display(display); //Destroi a tela
   al_destroy_event_queue(event_queue);//destroi fila de eventos
   al_destroy_bitmap(pac.sprite_personagem); //destoi imagem do pacman
   al_destroy_bitmap(lab.mapa_desenho); //destroi fundo
   al_uninstall_keyboard(); //desinstalar o teclado

   return 0;
}