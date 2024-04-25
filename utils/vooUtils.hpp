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
    static void cadastrarVoo(map<int, Voo> &voos, map<string, Astronauta> &astronautas) {
        string codigo;
        cout << "Digite o código de voo: ";
        cin >> codigo;

        char opcao;
        cout << "Gostaria de cadastrar um astronauta ao voo? (S/N) ";
        cin >> opcao;

        Voo voo = Voo();
        if (opcao == 'S' || opcao == 's') {
            while (true) {
                cout << "Astronautas disponiveis:" << endl;

                map<string, Astronauta> astronautasVivos =
                    AstronautaUtils::listAstronautasVivosDisponiveis(astronautas, true);

                string cpf;
                cout << "Digite o cpf do astronauta que você quer cadastrar ao "
                        "voo: ";
                cin >> cpf;

                if (astronautasVivos.find(cpf) == astronautasVivos.end()) {
                    astronautas[cpf].ocupado = true;
                }

                Astronauta astronauta = AstronautaUtils::findAstronauta(cpf, astronautas);
                voo.astronautas.push_back(astronauta);

                cout << "Gostaria de cadastrar outro astronauta ao voo? (S/N) ";
                cin >> opcao;
                if (opcao == 'N' || opcao == 'n') {
                    break;
                }
            }

            cout << "Voo " << codigo << " criado com sucesso! \n\n";
        }
    }

    static void cadastrarAstronautaVoo(map<int, Voo> &voos, map<string, Astronauta> &astronautas) {
        cout << "Voos disponiveis:\n\n";

        map<int, Voo>::iterator it = voos.begin();

        for(it; it != voos.end(); it++) {
            
        }
        
        cout << "Astronautas disponiveis:" << endl;

        map<string, Astronauta> astronautasVivos = AstronautaUtils::listAstronautasVivosDisponiveis(astronautas, true);

        string cpf;
        cout << "Digite o cpf do astronauta que você quer cadastrar ao voo: ";
        cin >> cpf;

        if (astronautasVivos.find(cpf) == astronautasVivos.end()) {
            astronautas[cpf].ocupado = true;
        }

        Astronauta astronauta = AstronautaUtils::findAstronauta(cpf, astronautas);
        voo.astronautas.push_back(astronauta);
    }
};