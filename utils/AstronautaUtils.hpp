#pragma once

#include <string>
#include <map>
#include <vector>

#include "../classes/Astronauta.hpp"

using namespace std;

class AstronautaUtils {
public:
    static void cadastrarAstronauta(map<string, Astronauta> &astronautas) {

        string cpf;
        cout << "Digite o cpf do astronauta: ";
        cin >> cpf;

        string nome;
        cout << "Digite o nome do astronauta: ";
        cin >> nome;

        int idade;
        cout << "Digite a idade do astronauta: ";
        cin >> idade;

        Astronauta astronauta = Astronauta(cpf, nome, idade, false, true);

        if (astronautas.find(cpf) == astronautas.end()) {
            astronautas[cpf] = astronauta;
            cout << "\nAstronauta " << nome << " cadastrado(a)" << endl << endl;
        }
        else {
            cout << "\nUm astronauta com este cpf já existe" << endl;
        }

    }

    static Astronauta findAstronauta(string cpf, map<string, Astronauta> &astronautas) {
        return astronautas[cpf];
    }

    static map<string, Astronauta> listAstronautasVivosDisponiveis(map<string, Astronauta> &astronautas, bool print) {
        map<string, Astronauta> astronautasVivosDisponiveis;

        for (map<string, Astronauta>::iterator it = astronautas.begin(); it != astronautas.end(); it++) {
            Astronauta astronautaAtual = it->second;

            if (astronautaAtual.vivo && !astronautaAtual.ocupado) {
                astronautasVivosDisponiveis[astronautaAtual.cpf] = astronautaAtual;
            }

            if (print) {
                cout << endl << Astronauta::to_string(it->second) << endl;
            }
        }

        return astronautasVivosDisponiveis;
    }
};