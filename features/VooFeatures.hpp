#pragma once

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

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
            Astronauta astronautaEscolhido;
            if (opcao == 'S' || opcao == 's') {
                while (true) {
                    astronautaEscolhido = AstronautaUtils::selectAstronautaDisponivel(astronautas);

                    if ( astronautaEscolhido.nome == "") {
                        return;
                    }
                    astronautaEscolhido.ocupado = true;
                    voo.astronautas.push_back(astronautaEscolhido);

                    cout << "\nGostaria de cadastrar outro astronauta ao voo? (S/N) ";
                    cin >> opcao;
                    if (opcao == 'N' || opcao == 'n') {
                        break;
                    }
                }
            }

            voos.insert({codigo, voo});
            astronautas.erase(astronautaEscolhido.cpf);
            astronautas.insert({astronautaEscolhido.cpf, astronautaEscolhido});

            cout << "\nVoo " << codigo << " criado com sucesso! \n\n";

            cout << Voo::to_string(voo);
            break;
        }
    }

    static void cadastrarAstronautaVoo(map<int, Voo> &voos, map<string, Astronauta> &astronautas) {

        if (voos.empty()) {
            cout << "Não há nenhum voo cadastrado\n";
            return;
        }

        while (true) {

            Voo vooEscolhido = VooUtils::selectVooDisponivel(voos);

            if (vooEscolhido.codigoVoo == 050505) {
                return;
            }

            Astronauta astronautaEscolhido = AstronautaUtils::selectAstronautaDisponivel(astronautas);
            
            if (astronautaEscolhido.nome == "") {
                return;
            }

            astronautaEscolhido.ocupado = true;

            vooEscolhido.astronautas.push_back(astronautaEscolhido);

            cout << Voo::to_string(vooEscolhido);

            cout << "Astronauta: " << astronautaEscolhido.nome << " cadastrado(a) no voo " << vooEscolhido.codigoVoo
                 << "\n\n";

            astronautas.erase(astronautaEscolhido.cpf);
            astronautas.insert({astronautaEscolhido.cpf, astronautaEscolhido});
            voos.erase(vooEscolhido.codigoVoo);
            voos.insert({vooEscolhido.codigoVoo, vooEscolhido});

            break;
        }
    }

    static void removerAstronautaVoo(map<int, Voo> &voos, map<string, Astronauta> &astronautas) {

        if (voos.empty()) {
            cout << "Não há nenhum voo cadastrado\n";
            return;
        }

        while (true) {

            Voo vooEscolhido = VooUtils::selectVooDisponivel(voos);

            if (vooEscolhido.codigoVoo == 050505) {
                return;
            }

            vector<Astronauta> astronautasVoo = vooEscolhido.astronautas;
            Astronauta astronautaEscolhido = AstronautaUtils::removeAstronauta(astronautasVoo);

            if(astronautaEscolhido.nome == "") {
                return;
            }

            astronautaEscolhido.ocupado = false;

            cout << Voo::to_string(vooEscolhido);

            astronautas.erase(astronautaEscolhido.cpf);
            astronautas.insert({astronautaEscolhido.cpf, astronautaEscolhido});
            voos.erase(vooEscolhido.codigoVoo);
            voos.insert({vooEscolhido.codigoVoo, vooEscolhido});

            break;
        }

    }
};