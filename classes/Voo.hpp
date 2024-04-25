#pragma once

#include <vector>
#include "../classes/Astronauta.hpp"

using namespace std;

class Voo {
public:
    Voo(){};
    Voo(int codigoVoo1) {
        codigoVoo = codigoVoo1;
    };

    int codigoVoo;
    vector<Astronauta> astronautas;

    static string to_string(Voo voo) {
        int codigo = voo.codigoVoo;
        string codigoStr = std::to_string(codigo);

        string astronautas;

        for(vector<Astronauta>::iterator it = voo.astronautas.begin(); it != voo.astronautas.end(); it++) {
            astronautas = astronautas + Astronauta::to_string(*it);
        }

        return ("Voo - " + codigoStr + "\n" + astronautas);

    }
};