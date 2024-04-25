#pragma once

#include <vector>

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
        int idade = voo.codigoVoo;
        string idadeStr = std::to_string(idade);
        return ("Voo - código: " + voo.codigoVoo + "\nCPF: " + astronauta.cpf + "\nIdade: " + idadeStr);
    }
};