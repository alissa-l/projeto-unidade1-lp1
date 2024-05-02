#pragma once

#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "../classes/Astronauta.hpp"
#include "../classes/Voo.hpp"
#include "../utils/AstronautaUtils.hpp"

using namespace std;

class VooUtils {
  public:
    static Voo selectVooDisponivel(map<int, Voo> voos) {

        if (voos.empty()) {
            cout << "\n\nNão há nenhum voo cadastrado.\n\n";
            return Voo(050505);
        }
        vector<Voo> voosDisponiveis = findVoosDisponiveis(voos);
        Voo vooEscolhido;

        while (true) {


            cout << "Voos disponiveis:\n\n";

            for (auto vit : voosDisponiveis) {
                cout << Voo::to_string(vit);
            }

            cout << "Digite o código de voo: ";
            int codigoOpcao;
            cin >> codigoOpcao;
            if (voos.find(codigoOpcao) == voos.end()) {
                cout << "Digite uma opção válida.\n\n";
                continue;
            } else {
                vooEscolhido = voos[codigoOpcao];
                break;
            }
        }
        return vooEscolhido;
    }

  private:
    static vector<Voo> findVoosDisponiveis(map<int, Voo> voos) {

        vector<Voo> voosDisponiveis;
        for (auto vit : voos) {

            if (!vit.second.lancado && !vit.second.explodido) {
                voosDisponiveis.push_back(vit.second);
            }
        }

        return voosDisponiveis;
    }
};