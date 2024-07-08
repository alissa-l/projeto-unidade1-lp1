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

        for(const auto& ita : astronautas) {
            astronautasVoo[ita.cpf] = ita;
        }

        Astronauta astronauta = findAstronautaUser(astronautasVoo);

        return astronauta;

    }

    static void listarAstronautasMortos(const map<string, Astronauta>& astronautas) {

        vector<Astronauta> astronautasMortos = findAstronautasMortos(astronautas);

        for(const auto& ait : astronautasMortos) {
            cout << Astronauta::to_string(ait);
            cout << "Participou dos voos: ";
            for (auto vit : ait.voos) {

                if(vit.second) {
                    cout << vit.first << " ";
                }
            }
            cout << "\n\n";
        }

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

            if (astronautaAtual.vivo && !astronautaAtual.ocupado && !astronautaAtual.cadastrado) {
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

        return astronautasVivosOcupados;

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

    static vector<Astronauta> findAstronautasMortos(const map<string, Astronauta>& astronautas) {

        vector<Astronauta> astronautasMortos;

        for(const auto& ait : astronautas) {
            if(!ait.second.vivo) {
                astronautasMortos.push_back(ait.second);
            }
        }

        return astronautasMortos;
    }

};