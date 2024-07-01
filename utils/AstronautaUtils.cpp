#pragma once

#include <map>
#include <string>
#include <vector>

#include "../classes/Astronauta.hpp"

using namespace std;

class AstronautaUtils {
public:
    static Astronauta selectAstronauta(map<string, Astronauta> astronautas) {

        if (astronautas.empty()) {
            cout << "\nNão há nenhum astronauta cadastrado.\n";
            Astronauta *ptr = nullptr;
            return {};
        }

        map<string, Astronauta> astronautasDisponiveis = mapAstronautasVivosDisponiveis(astronautas);

        if (astronautasDisponiveis.empty()) {
            cout << "\nNão há astronautas disponiveis\n\n";
            return {};
        }

        cout << "\nAstronautas disponiveis:\n\n";
        for (auto ait: astronautasDisponiveis) {
            cout << Astronauta::to_string(ait.second) << "\n";
        }

        Astronauta astronauta = findAstronautaUser(astronautasDisponiveis);

        return astronauta;
    }

    static Astronauta selectAstronautaOcupado(vector<Astronauta> astronautas) {

        if (astronautas.empty()) {
            cout << "\nNão há nenhum astronauta cadastrado no voo.\n";
            return {};
        }

        map<string, Astronauta> astronautasVoo;

        for(auto ita : astronautas) {
            astronautasVoo[ita.cpf] = ita;
        }

        Astronauta astronauta = findAstronautaUser(astronautasVoo);

        return astronauta;

    }


private:
    static Astronauta findAstronautaUser(map<string, Astronauta> astronautas) {
        string cpf;
        while (true) {
            cout << "\nDigite o cpf do astronauta: ";
            cin >> cpf;

            if (astronautas.find(cpf) == astronautas.end()) {
                cout << "\nDigite um cpf válido!";
                continue;
            }
            break;
        }

        Astronauta astronauta = astronautas.find(cpf)->second;

        return astronauta;
    }

    static map<string, Astronauta> mapAstronautasVivosDisponiveis(map<string, Astronauta> &astronautas) {
        map<string, Astronauta> astronautasVivosDisponiveis;

        for (auto &ita: astronautas) {
            Astronauta astronautaAtual = ita.second;

            if (astronautaAtual.vivo && !astronautaAtual.ocupado) {
                astronautasVivosDisponiveis.insert({astronautaAtual.cpf, astronautaAtual});
            }
        }

        return astronautasVivosDisponiveis;
    }

    static map<string, Astronauta> mapAstronautasVivosDisponiveis(vector<Astronauta> &astronautas) {
        map<string, Astronauta> astronautasVivosDisponiveis;

        for (auto &ita: astronautas) {
            if(ita.vivo && !ita.ocupado) {}
            astronautasVivosDisponiveis[ita.cpf] = ita;
        }

        return astronautasVivosDisponiveis;
    }

    static map<string, Astronauta> mapAstronautasVivosOcupados(map<string, Astronauta> &astronautas) {

        map<string, Astronauta> astronautasVivosOcupados;

        for (auto &ita : astronautas) {
            Astronauta astronautaAtual = ita.second;

            if (astronautaAtual.vivo && astronautaAtual.ocupado) {
                astronautasVivosOcupados[astronautaAtual.cpf] = astronautaAtual;
            }
        }

    }

    static map<string, Astronauta> mapAstronautasVivosOcupados(vector<Astronauta> &astronautas) {
        map<string, Astronauta> astronautasVivosOcupados;

        for (auto &ita: astronautas) {
            if(ita.vivo && !ita.ocupado) {
                astronautasVivosOcupados[ita.cpf] = ita;
            }
        }

        return astronautasVivosOcupados;
    }

};