#pragma once

#include <map>
#include <string>
#include <vector>

#include "../classes/Astronauta.hpp"

using namespace std;

class AstronautaUtils {
  public:
    static Astronauta selectAstronautaDisponivel(map<string, Astronauta> astronautas) {

        if (astronautas.empty()) {
            cout << "\nNão há nenhum astronauta cadastrado.\n";
            Astronauta *ptr = nullptr;
            return {};
        }

        map<string, Astronauta> astronautasDisponiveis = listAstronautasVivosDisponiveis(astronautas);

        if (astronautasDisponiveis.empty()) {
            cout << "\nNão há astronautas disponiveis\n\n";
            return {};
        }

        cout << "\nAstronautas disponiveis:\n\n";
        for (auto ait : astronautasDisponiveis) {
            cout << Astronauta::to_string(ait.second) << "\n";
        }

        Astronauta astronauta = findAstronautaUser(astronautasDisponiveis);

        return astronauta;
    }

    static Astronauta removeAstronauta(vector<Astronauta> astronautas) {

        if (astronautas.empty()) {
            cout << "\nNão há nenhum astronauta cadastrado no voo.\n";
            Astronauta *ptr = nullptr;
            return {};
        }


        if (astronautas.empty()) {
            cout << "\nNão há astronautas disponiveis\n\n";
            return {};
        }

        cout << "\nAstronautas cadastrados no voo:\n\n";
        for (auto ait : astronautas) {
            cout << Astronauta::to_string(ait) << "\n";
        }

        map<string, Astronauta> astronautasMap;
        for(auto &ait : astronautas) {
            astronautasMap.insert({ait.cpf, ait});
        }

        Astronauta astronauta = findAstronautaUser(astronautasMap);

        return astronauta;
        
    }


  private:
    static Astronauta findAstronautaUser(map<string, Astronauta> astronautas) {
        string cpf;
        while (true) {
            cout << "\nDigite o cpf do astronauta: ";
            cin >> cpf;

            if (astronautas.find(cpf) == astronautas.end())  {
                cout << "\nDigite um cpf válido!";
                continue;
            }
            break;
        }

        Astronauta astronauta = astronautas.find(cpf)->second;

        return astronauta;
    }
    
    static map<string, Astronauta> listAstronautasVivosDisponiveis(map<string, Astronauta> &astronautas) {
        map<string, Astronauta> astronautasVivosDisponiveis;

        for (auto &ita : astronautas) {
            Astronauta astronautaAtual = ita.second;

            if (astronautaAtual.vivo && !astronautaAtual.ocupado) {
                astronautasVivosDisponiveis.insert({astronautaAtual.cpf, astronautaAtual});
            }
        }

        return astronautasVivosDisponiveis;
    }
};