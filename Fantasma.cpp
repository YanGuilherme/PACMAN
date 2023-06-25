#include "Fantasma.h"
#include "Pacman.h"

using namespace std;



Fantasma::Fantasma(){
}

Fantasma::Fantasma(int a){
   DESLOCAMENTO = 4;
   switch (a){
   case 1:
      pos_x = LADO_FANTASMA;
      pos_y = LADO_FANTASMA;
      direcao = PARADO;
      intencao = SEM_INTENCAO;
      nome_imagem = "./imagenstrab/fantasma_vermelho.png";
      break;
   case 2:
      pos_x = LADO_FANTASMA*17;
      pos_y = LADO_FANTASMA;
      direcao = PARADO;
      intencao = SEM_INTENCAO;
      nome_imagem =  "./imagenstrab/fantasma_rosa.png";

      break;
   case 3:
      pos_x = LADO_FANTASMA;
      pos_y = LADO_FANTASMA*17;
      direcao = PARADO;
      intencao = SEM_INTENCAO;
      nome_imagem =  "./imagenstrab/fantasma_azul.png";

      break;
   case 4:
      pos_x = LADO_FANTASMA*17;
      pos_y = LADO_FANTASMA*17;
      direcao = PARADO;
      intencao = SEM_INTENCAO;
      nome_imagem =  "./imagenstrab/fantasma_amarelo.png";

      break;
    
    default:
        break;
    }
}

void Fantasma::exibe_fantasma()
{
    sprite_personagem = al_load_bitmap(nome_imagem);
    al_draw_bitmap_region(sprite_personagem, LADO_FANTASMA*(int)frame, current_frame_y, LADO_FANTASMA, LADO_FANTASMA, pos_x ,pos_y,0);
    altera_frame_fantasma();
}

void Fantasma::altera_frame_fantasma(){
    frame += 0.2f;
    if(frame > 2){
        frame -= 2;
    }
}

int Fantasma::num_possibilidades(Labirinto lab){
    int cont = 0;
    if(colidiu_cima_tijolo(lab) != PARADO) cont++;
    if(colidiu_baixo_tijolo(lab) != PARADO) cont++;
    if(colidiu_direita_tijolo(lab) != PARADO) cont++;
    if(colidiu_esquerda_tijolo(lab) != PARADO) cont++;
    return cont;
}

void Fantasma::move_fantasma_random(Labirinto lab){
   std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, 4);

    int randomNumber = dis(gen);

    if(num_possibilidades(lab) > 2){
        if(
            (direcao == DIREITA && randomNumber != ESQUERDA )|| 
            (direcao == ESQUERDA && randomNumber != DIREITA) ||
            (direcao == CIMA && randomNumber != BAIXO) ||
            (direcao == BAIXO && randomNumber != CIMA)
            ){
        
        intencao = randomNumber;
        }        
    }

    
    if(direcao == PARADO){
        intencao = randomNumber;
    }

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
         current_frame_y = LADO_FANTASMA;
         pos_x-= DESLOCAMENTO;
      }


   }else if(direcao == BAIXO){
      direcao =colidiu_baixo_tijolo(lab);
      if(direcao != PARADO){
         current_frame_y = LADO_FANTASMA*3;
         pos_y+=DESLOCAMENTO;
      }


   }else if(direcao == CIMA){
      direcao = colidiu_cima_tijolo(lab);
      if(direcao != PARADO) {
         current_frame_y = LADO_FANTASMA*2;
         pos_y-= DESLOCAMENTO;
      }

   }
}


void Fantasma::direct_chase(Labirinto lab, Pacman pac){

   float diferenca_x = pac.getPos_x() - pos_x;
   float diferenca_y = pac.getPos_y() - pos_y;

   if (abs(diferenca_x) > abs(diferenca_y)) {
    if (diferenca_x > 0) {
        intencao = DIREITA;
    } else {
        intencao = ESQUERDA;
    }
   } else {
    if (diferenca_y > 0) {
        intencao = BAIXO;
    } else {
        intencao = CIMA;
    }
   }

        
    // if(direcao == PARADO){
    //     return;
    // }

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
         current_frame_y = LADO_FANTASMA;
         pos_x-= DESLOCAMENTO;
      }


   }else if(direcao == BAIXO){
      direcao =colidiu_baixo_tijolo(lab);
      if(direcao != PARADO){
         current_frame_y = LADO_FANTASMA*3;
         pos_y+=DESLOCAMENTO;
      }


   }else if(direcao == CIMA){
      direcao = colidiu_cima_tijolo(lab);
      if(direcao != PARADO) {
         current_frame_y = LADO_FANTASMA*2;
         pos_y-= DESLOCAMENTO;
      }

   }
}

   void Fantasma::vision_pursuit(Labirinto lab, Pacman pac){

   std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, 4);

    int randomNumber = dis(gen);

    if(num_possibilidades(lab) > 2){
        if(
            (direcao == DIREITA && randomNumber != ESQUERDA )|| 
            (direcao == ESQUERDA && randomNumber != DIREITA) ||
            (direcao == CIMA && randomNumber != BAIXO) ||
            (direcao == BAIXO && randomNumber != CIMA)
            ){
        
        intencao = randomNumber;
        }        
   }
   float diferenca_x = pac.getPos_x() - pos_x;
   float diferenca_y = pac.getPos_y() - pos_y;
   // cout << (int)(pac.getPos_x()/TAM_LADO) << (int)(pac.getPos_y()/TAM_LADO)  << endl  << pos_x/TAM_LADO << pos_y/TAM_LADO << endl; //visualizar indices
   if (((int)(pac.getPos_x()/TAM_LADO) == (int)(pos_x/TAM_LADO))&& direcao != PARADO){
    if (diferenca_y > 0) {
        intencao = BAIXO;
    } else {
        intencao = CIMA;
    }
   } else if(((int)(pac.getPos_y()/TAM_LADO) == (int)(pos_y/TAM_LADO))&& direcao != PARADO){
    if (diferenca_x > 0) {
        intencao = DIREITA;
    } else {
        intencao = ESQUERDA;
    }
   }else if(direcao == PARADO){
      intencao = randomNumber;
   }

        
    // if(direcao == PARADO){
    //     return;
    // }

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
         current_frame_y = LADO_FANTASMA;
         pos_x-= DESLOCAMENTO;
      }


   }else if(direcao == BAIXO){
      direcao =colidiu_baixo_tijolo(lab);
      if(direcao != PARADO){
         current_frame_y = LADO_FANTASMA*3;
         pos_y+=DESLOCAMENTO;
      }


   }else if(direcao == CIMA){
      direcao = colidiu_cima_tijolo(lab);
      if(direcao != PARADO) {
         current_frame_y = LADO_FANTASMA*2;
         pos_y-= DESLOCAMENTO;
      }
   }
}
