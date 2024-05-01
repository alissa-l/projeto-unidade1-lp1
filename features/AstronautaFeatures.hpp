#pragma once

#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "../classes/Astronauta.hpp"

using namespace std;

class AstronautaFeatures {
  public:
    static void cadastrarAstronauta(map<string, Astronauta> &astronautas) {

        while (true) {
            string cpf;
            cout << "Digite o cpf do astronauta: ";
            cin >> cpf;

            if (astronautas.find(cpf) != astronautas.end()) {
                cout << "\n\nJá existe um astronauta com este cpf\n\n";
                continue;
            }

            string nome;
            cout << "Digite o nome do astronauta: ";
            cin >> nome;

            int idade;
            cout << "Digite a idade do astronauta: ";
            cin >> idade;

            Astronauta astronauta = Astronauta(cpf, nome, idade, false, true);

            if (astronautas.find(cpf) == astronautas.end()) {
                astronautas[cpf] = astronauta;
                cout << "\nAstronauta " << nome << " cadastrado(a)\n\n";
            } else {
                cout << "\nUm astronauta com este cpf já existe\n\n";
            }
            break;
        }
    }
};