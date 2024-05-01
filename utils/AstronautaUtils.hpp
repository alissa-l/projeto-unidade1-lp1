#pragma once

#include <map>
#include <string>
#include <vector>

#include "../classes/Astronauta.hpp"

using namespace std;

class AstronautaUtils {
  public:
    static Astronauta *selectAstronautaDisponivel(map<string, Astronauta> astronautas) {

        if (astronautas.empty()) {
            cout << "\nNão há nenhum astronauta cadastrado.\n";
            Astronauta *ptr = NULL;
            return ptr;
        }

        map<string, Astronauta> astronautasDisponiveis = listAstronautasVivosDisponiveis(astronautas);

        if(astronautasDisponiveis.empty()) {
            cout << "\nNão há astronautas disponiveis\n\n";
            return NULL;
        }

        cout << "\nAstronautas disponiveis:\n\n";

        for (auto ait : astronautasDisponiveis) {
            Astronauta::to_string(ait.second);
        }

        string cpf;
        while (true) {
            cout << "\nDigite o cpf do astronauta: ";
            cin >> cpf;

            if (astronautasDisponiveis.find(cpf) == astronautasDisponiveis.end()) {
                cout << "\nDigite um cpf válido!";
                break;
            }
        }
        Astronauta *astronautaPtr = &astronautasDisponiveis[cpf];
        return astronautaPtr;
    }

  private:
    static map<string, Astronauta> listAstronautasVivosDisponiveis(map<string, Astronauta> &astronautas) {
        map<string, Astronauta> astronautasVivosDisponiveis;

        for (map<string, Astronauta>::iterator it = astronautas.begin(); it != astronautas.end(); it++) {
            Astronauta astronautaAtual = it->second;

            if (astronautaAtual.vivo == true && astronautaAtual.ocupado == false) {
                astronautasVivosDisponiveis[astronautaAtual.cpf] = astronautaAtual;
            }
        }

        return astronautasVivosDisponiveis;
    }
};