#pragma once

#include <vector>
#include "../classes/Astronauta.hpp"

using namespace std;

class Voo {
public:
    Voo(){
        codigoVoo = 9999999;
    };
    Voo(int codigoVoo1) {
        codigoVoo = codigoVoo1;
        finalizado = false;
        lancado = false;
        explodido = false;
    };

    int codigoVoo;
    vector<Astronauta> astronautas;
    bool lancado;
    bool explodido;
    bool finalizado;

    static string to_string(Voo voo) {
        int codigo = voo.codigoVoo;
        string codigoStr = std::to_string(codigo);

        string astronautas;

        if(!voo.astronautas.empty()) {
            astronautas += "\nAstronautas do voo:\n";
        }

        for(auto & astronauta : voo.astronautas) {
            astronautas += Astronauta::to_string(astronauta);
        }

        return ("Voo - " + codigoStr + astronautas + "\n");

    }
};