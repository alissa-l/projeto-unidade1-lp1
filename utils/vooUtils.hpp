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

        int codigo;
        cout << "Digite o código de voo: ";
        cin >> codigo;

        char opcao;
        cout << "Gostaria de cadastrar um astronauta ao voo? (S/N) ";
        cin >> opcao;

        Voo voo = Voo(codigo);

        if (opcao == 'S' || opcao == 's') {
            while (true) {
                cout << "Astronautas disponiveis:" << endl;

                map<string, Astronauta> astronautasVivos =
                    AstronautaUtils::listAstronautasVivosDisponiveis(astronautas, true);

                string cpf;
                cout << "Digite o cpf do astronauta que você quer cadastrar ao voo: ";
                cin >> cpf;

                if (astronautasVivos.find(cpf) == astronautasVivos.end()) {
                    astronautas[cpf].ocupado = true;
                }

                Astronauta astronauta = AstronautaUtils::findAstronauta(cpf, astronautas);

                voo.astronautas.push_back(astronauta);

                cout << "\nGostaria de cadastrar outro astronauta ao voo? (S/N) ";
                cin >> opcao;
                if (opcao == 'N' || opcao == 'n') {
                    break;
                }
            }
        }

        voos[codigo] = voo;

        cout << "\nVoo " << codigo << " criado com sucesso! \n\n";

        cout << Voo::to_string(voo);
    }

    static void cadastrarAstronautaVoo(map<int, Voo> &voos, map<string, Astronauta> &astronautas) {

        if (voos.empty() == true) {
            cout << "Não há nenhum voo cadastrado\n";
            return;
        }

        while (true) {

            cout << "Voos disponiveis:\n\n";

            map<int, Voo>::iterator it = voos.begin();

            for (it; it != voos.end(); it++) {
                cout << Voo::to_string(it->second);
            }

            cout << "Digite o código de voo: ";
            int codigoOpcao;
            cin >> codigoOpcao;
            Voo vooEscolhido;
            if (voos.find(codigoOpcao) == voos.end()) {
                cout << "Digite uma opção válida.\n\n";
                continue;
            } else {
                vooEscolhido = voos[codigoOpcao];
            }

            while (true) {

                cout << "Astronautas disponiveis:" << endl;

                map<string, Astronauta> astronautasVivos =
                    AstronautaUtils::listAstronautasVivosDisponiveis(astronautas, true);

                
                string cpf;
                cout << "Digite o cpf do astronauta que você quer cadastrar ao voo: ";
                cin >> cpf;

                if (astronautasVivos.find(cpf) == astronautasVivos.end()) {
                    cout << "Digite um cpf valido.\n\n";
                }

                Astronauta astronautaEscolhido = astronautas[cpf];
                astronautaEscolhido.ocupado = true;

                vooEscolhido.astronautas.push_back(astronautaEscolhido);

                cout << "Astronauta: " << astronautaEscolhido.nome << " cadastrado(a) no voo " << vooEscolhido.codigoVoo
                     << "\n\n";

                astronautas[cpf] = astronautaEscolhido;
                voos[vooEscolhido.codigoVoo] = vooEscolhido;
                break;
            }
            break;
        }
    }
};