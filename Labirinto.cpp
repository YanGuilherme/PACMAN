#include "Labirinto.h"
#include "CoordenadaTijolo.h"

#include <stdio.h>
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/keyboard.h>
#include <array> 

void Labirinto::setNome_arquivo(const char *nome){
    this->nome_arquivo = nome;
}


void Labirinto::exibir_labirinto(){
    al_clear_to_color(al_map_rgb(0,0,0)); //Cor de background da tela
   mapa_desenho = al_load_bitmap("./imagenstrab/bloco.png");
    for(CoordenadaTijolo& coordenada : coordenadas){
        al_draw_bitmap(mapa_desenho,TAM_LADO*coordenada.getX(),TAM_LADO*coordenada.getY(),0);
    }

    

}

void Labirinto::carregarPosicaoDosTijolos(){
    int x, y;
    FILE* arquivoDoLabirinto = fopen(this->nome_arquivo, "r");
    if(arquivoDoLabirinto == NULL){
        printf("Erro em abrir o arquivo de posição dos tijolos!");
        exit(1);
    }
    int i = 0;
    while (fscanf(arquivoDoLabirinto, "%d %d", &x, &y) == 2){
        coordenadas.push_back(CoordenadaTijolo(x,y));
        i++;
        
    }
    fclose(arquivoDoLabirinto);
}
void Labirinto::render(){
}


