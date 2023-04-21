#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/keyboard.h>
#include "ListaCoordenadas.h"
#include "Coordenada.h"
#include <vector>

#define TAM_LADO 36
#define ORDEM 19 

#define CELULA_VAZIA 0
#define PACMAN 1
#define PILULA 2
#define TIJOLO 3

#ifndef LABIRINTO_H
#define LABIRINTO_H

class Labirinto{


    public:
        float frame_pilula;
        void carregarPosicaoDosTijolos();
        void carregarPosicaoDasPilulas();
        void exibir_labirinto();
        void exibir_pilulas();
        void altera_frame_pilula();
        ALLEGRO_BITMAP * mapa_desenho;
        ALLEGRO_BITMAP * pilula_desenho;
        void setNome_arquivo(const char * nome);
        int matriz_colisao[ORDEM][ORDEM];

        Labirinto();
    private:
        ListaCoordenadas coordenadas_pilulas;
        ListaCoordenadas coordenadas_tijolo;

        const char* nome_arquivo;

        void render();
};

#endif