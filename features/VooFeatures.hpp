#pragma once

#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "../classes/Astronauta.hpp"
#include "../classes/Voo.hpp"
#include "../utils/AstronautaUtils.hpp"
#include "../utils/vooUtils.hpp"

class VooFeatures {
  public:
    static void cadastrarVoo(map<int, Voo> &voos, map<string, Astronauta> &astronautas) {

        while (true) {

            int codigo;
            cout << "\nDigite o código de voo: ";
            cin >> codigo;

            if (voos.find(codigo) != voos.end()) {
                cout << "\nUm voo com este código já está cadastrado\n";
                continue;
            }

            char opcao;
            cout << "Gostaria de cadastrar um astronauta ao voo? (S/N) ";
            cin >> opcao;

            Voo voo = Voo(codigo);

            if (opcao == 'S' || opcao == 's') {
                while (true) {
                    Astronauta *astronautaSelecionado = AstronautaUtils::selectAstronautaDisponivel(astronautas);

                    if ( astronautaSelecionado == NULL) {
                        return;
                    }

                    voo.astronautas.push_back(*astronautaSelecionado);

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
    }

    static void cadastrarAstronautaVoo(map<int, Voo> &voos, map<string, Astronauta> &astronautas) {

        if (voos.empty() == true) {
            cout << "Não há nenhum voo cadastrado\n";
            return;
        }

        while (true) {

            Astronauta *astronautaEscolhido = AstronautaUtils::selectAstronautaDisponivel(astronautas);
            
            if (astronautaEscolhido == NULL) {
                return;
            }

            Voo *vooEscolhido = VooUtils::selectVooDisponivel(voos);

            astronautaEscolhido->ocupado = true;

            vooEscolhido->astronautas.push_back(*astronautaEscolhido);

            cout << Voo::to_string(*vooEscolhido);

            cout << "Astronauta: " << astronautaEscolhido->nome << " cadastrado(a) no voo " << vooEscolhido->codigoVoo
                 << "\n\n";

            string cpf = astronautaEscolhido->cpf;
            astronautas[cpf] = *astronautaEscolhido;

            voos[vooEscolhido->codigoVoo] = *vooEscolhido;

            break;
        }
    }

    static void removerAstronautaVoo(map<int, Voo> &voos, map<string, Astronauta> &astronautas) {
    }
};