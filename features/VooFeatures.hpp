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

    static void astronautaVoo(map<int, Voo> &voos, map<string, Astronauta> &astronautas, bool remover) {

        if (voos.empty()) {
            cout << "Não há nenhum voo cadastrado\n";
            return;
        }

        while (true) {

            Voo vooEscolhido = VooUtils::selectVooDisponivel(voos);

            if(vooEscolhido.codigoVoo == 9999999) {
                return;
            }

            Astronauta astronautaEscolhido;
            if(remover) {
                astronautaEscolhido = AstronautaUtils::selectAstronautaDisponivel(vooEscolhido.astronautas);
            } else {
                astronautaEscolhido = AstronautaUtils::selectAstronautaDisponivel(astronautas);
            }

            if (astronautaEscolhido.cpf.empty()) {
                return;
            }

            if(remover) {
                vector<Astronauta> astroOriginal = vooEscolhido.astronautas;
                vector<Astronauta> newAstronautas;
                for(auto x : vooEscolhido.astronautas) {
                    if(x.cpf == astronautaEscolhido.cpf) {
                        newAstronautas.push_back(x);
                    }
                }
                vooEscolhido.astronautas = newAstronautas;
                astronautaEscolhido.ocupado = false;
                cout << Voo::to_string(vooEscolhido) << endl;
                cout << "Astronauta: " << astronautaEscolhido.nome << " removido(a) do voo " << vooEscolhido.codigoVoo
                     << "\n\n";
            } else {
                astronautaEscolhido.ocupado = true;
                cout << Voo::to_string(vooEscolhido) << endl;
                cout << "Astronauta: " << astronautaEscolhido.nome << " cadastrado(a) no voo " << vooEscolhido.codigoVoo
                     << "\n\n";
            }

            voos[vooEscolhido.codigoVoo] = vooEscolhido;
            astronautas[astronautaEscolhido.cpf] = astronautaEscolhido;

            break;
        }
    }
};