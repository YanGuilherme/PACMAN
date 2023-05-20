#include <vector>
#include "Coordenada.h"

#ifndef LISTA_COORDENADAS
#define LISTA_COORDENADAS

class ListaCoordenadas{
    public:

        std::vector<Coordenada> getCoordenadas(){
            return this->coordenadas;
        }

        void addCoordenada(Coordenada coordenada){
            this->coordenadas.push_back(coordenada);
        }


        // Implementação da função begin()
        std::vector<Coordenada>::iterator begin() {
            return coordenadas.begin();
        }

        // Implementação da função end()
        std::vector<Coordenada>::iterator end() {
            return coordenadas.end();
        }   

        
    private:
        std::vector<Coordenada> coordenadas;



};
#endif