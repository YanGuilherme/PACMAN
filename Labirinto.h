#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/keyboard.h>
#include "CoordenadaTijolo.h"
#include <vector>

#define TAM_LADO 36




#ifndef LABIRINTO_H
#define LABIRINTO_H

class Labirinto{


    public:
        // Implementação da função begin()
        std::vector<CoordenadaTijolo>::iterator begin() {
            return coordenadas.begin();
        }

        // Implementação da função end()
        std::vector<CoordenadaTijolo>::iterator end() {
            return coordenadas.end();
        }   
        void carregarPosicaoDosTijolos();
        void exibir_labirinto();
        ALLEGRO_BITMAP * mapa_desenho;
        void setNome_arquivo(char * nome);
    private:
        std::vector<CoordenadaTijolo> coordenadas;
        char* nome_arquivo;

        void render();
};

#endif