#pragma once

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

#include "../classes/Astronauta.hpp"
#include "../classes/Voo.hpp"
#include "../utils/AstronautaUtils.hpp"
#include "../utils/VooUtils.hpp"
#include "../utils/PrettyPrintUtils.hpp"

class VooFeatures {
  public:
    /**
     * Cadastra um voo e pode cadastrar um astronauta no voo
     * @param voos
     * @param astronautas
     */
    static void cadastrarVoo(map<int, Voo> &voos, map<string, Astronauta> &astronautas) {

        while (true) {

            int codigo;
            cout << "\nDigite o código de voo: ";
            cin >> codigo;

            if (voos.find(codigo) != voos.end()) {
                cout << "\nUm voo com este código já está cadastrado\n";
                continue;
            }


            Voo voo = Voo(codigo);



            voos[codigo] = voo;

            cout << "\nVoo " << codigo << " criado com sucesso! \n\n";

            cout << Voo::to_string(voo);
            break;
        }
    }

    /**
     * Cadastra ou remove um astronauta de um voo
     * @param voos
     * @param astronautas
     * @param remover
     */
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
                astronautaEscolhido = AstronautaUtils::selectAstronautaOcupado(vooEscolhido.astronautas);
                astronautaEscolhido.cadastrado = false;
                astronautaEscolhido.voos[vooEscolhido.codigoVoo] = false;

            } else {
                astronautaEscolhido = AstronautaUtils::selectAstronauta(astronautas);
                astronautaEscolhido.cadastrado = true;
                astronautaEscolhido.voos[vooEscolhido.codigoVoo] = true;
            }

            if (astronautaEscolhido.cpf.empty()) {
                return;
            }

            if(remover) {
                vector<Astronauta> astroOriginal = vooEscolhido.astronautas;
                vector<Astronauta> newAstronautas;
                for(const auto& x : vooEscolhido.astronautas) {
                    if(x.cpf != astronautaEscolhido.cpf) {
                        newAstronautas.push_back(x);
                    }
                }
                vooEscolhido.astronautas = newAstronautas;
                cout << Voo::to_string(vooEscolhido) << endl;
                cout << "Astronauta: " << astronautaEscolhido.nome << " removido(a) do voo " << vooEscolhido.codigoVoo
                     << "\n\n";
            } else {

                string cpf = astronautaEscolhido.cpf;
                bool incluir = true;

                for(const auto& x : vooEscolhido.astronautas) {
                    if(x.cpf == cpf) {
                        incluir = false;
                    }
                }

                if(incluir) {
                    vooEscolhido.astronautas.push_back(astronautaEscolhido);
                    cout << Voo::to_string(vooEscolhido) << endl;
                    cout << "Astronauta: " << astronautaEscolhido.nome << " cadastrado(a) no voo " << vooEscolhido.codigoVoo
                         << "\n\n";
                } else {
                    cout << "Astronauta: " << astronautaEscolhido.nome << " já está cadastrado(a) no voo " << vooEscolhido.codigoVoo << "\n\n";
                }


            }

            voos[vooEscolhido.codigoVoo] = vooEscolhido;
            astronautas[astronautaEscolhido.cpf] = astronautaEscolhido;

            break;
        }
    }


    static void lancarVoo(map<int, Voo> &voos, map<string, Astronauta> &astronautas) {

        Voo vooEscolhido = VooUtils::selectVooDisponivel(voos);

        if (vooEscolhido.codigoVoo == 9999999) {
            return;
        }

        if (vooEscolhido.astronautas.empty()) {
            cout << "O voo " << vooEscolhido.codigoVoo << " não possui astronautas cadastrados e não pode ser lançado" << "\n";
            return;
        }

        vector<string> cpfs;

        for (const auto& a : vooEscolhido.astronautas) {
            if(a.ocupado) {
                cout << "O voo " << vooEscolhido.codigoVoo << " possui um astronauta ocupado e não pode ser lançado :" << a.cpf;
                return;
            } else {
                cpfs.push_back(a.cpf);
            }
        }

        vector<Astronauta> newAstronautas;
        for (const auto& cpf : cpfs) {
            Astronauta astronauta = astronautas[cpf];
            astronauta.ocupado = true;
            astronautas[cpf] = astronauta;
            newAstronautas.push_back(astronauta);
        }

        vooEscolhido.astronautas = newAstronautas;
        vooEscolhido.lancado = true;

        voos[vooEscolhido.codigoVoo] = vooEscolhido;

        cout << "O voo " << vooEscolhido.codigoVoo << " foi lançado com sucesso!!!" << endl;
        cout << PrettyPrintUtils::foguete() << "\n\n\n";

    }

    static void explodirVoo(map<int, Voo> &voos, map<string, Astronauta> &astronautas) {

        Voo vooEscolhido = VooUtils::selectVooLancado(voos);

        if (vooEscolhido.codigoVoo == 9999999) {
            return;
        }

        vector<Astronauta> astronautasVoo = vooEscolhido.astronautas;
        for(auto va : astronautasVoo) {
            va.vivo = false;
            va.ocupado = false;
            va.cadastrado = false;
            astronautas[va.cpf] = va;
        }
        vooEscolhido.astronautas = astronautasVoo;

        vooEscolhido.explodido = true;

        voos[vooEscolhido.codigoVoo] = vooEscolhido;

        cout << "O voo " << vooEscolhido.codigoVoo << " explodiu por alguma razão misteriosa." << "\n\n";

    }

    static void finalizarVoo(map<int, Voo> &voos, map<string, Astronauta> &astronautas) {

        Voo vooEscolhido = VooUtils::selectVooLancado(voos);

        vector<Astronauta> astronautasVoo = vooEscolhido.astronautas;
        for(auto va : astronautasVoo) {
            va.ocupado = false;
            va.cadastrado = false;
            astronautas[va.cpf] = va;
        }

        vooEscolhido.astronautas = astronautasVoo;

        vooEscolhido.finalizado = true;

        voos[vooEscolhido.codigoVoo] = vooEscolhido;

    }

};