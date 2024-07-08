#pragma once

#include "../classes/Voo.hpp"
#include "map"
#include "iostream"

using namespace std;

class VooUtils {
public:
    static Voo selectVooDisponivel(const map<int, Voo>& voos) {

        if (voos.empty()) {
            cout << "\n\nNão há nenhum voo cadastrado.\n\n";
            return {};
        }

        vector<Voo> voosDisponiveis = findVoosDisponiveis(voos);

        if (voosDisponiveis.empty()) {
            cout << "\n\nNão há nenhum voo disponivel.\n\n";
            return {};
        }

        return selectVoo(voosDisponiveis);
    }

    static Voo selectVooLancado(const map<int, Voo>& voos) {

        if (voos.empty()) {
            cout << "\n\nNão há nenhum voo cadastrado.\n\n";
            return {};
        }

        vector<Voo> voosLancados = findVoosLancados(voos);

        if (voosLancados.empty()) {
            cout << "\n\nNão há nenhum voo lançado.\n\n";
            return {};
        }

        return selectVoo(voosLancados);

    }

    static void listarTodosOsVoos(map<int, Voo> &voos) {

        cout << "Voos em planejamento:" << "\n";
        for(const auto& v : findVoosDisponiveis(voos)) {
            cout << Voo::to_string(v) << "\n";
        }

        cout << "Voos em curso:" << "\n";
        for(const auto& v : findVoosLancados(voos)) {
            cout << Voo::to_string(v) << "\n";
        }

        cout << "Voos finalizados:" << "\n";
        cout << "Finalizados com sucesso:" << "\n";
        for(const auto& v : findVoosFinalizados(voos)) {
            if(!v.explodido) {
                cout << Voo::to_string(v);
            }
        }

        cout << "Não finalizados com sucesso:" << "\n";
        for(const auto& v : findVoosExplodidos(voos)) {
            if(v.explodido) {
                cout << Voo::to_string(v);
            }
        }

        cout << "\n";

    }
private:

    /**
     * Prompta pro usuario selecionar um voo
     * @param voos
     * @return
     */
    static Voo selectVoo(const vector<Voo>& voosV) {
        map<int, Voo> voos;

        for(const auto& v : voosV) {
            voos[v.codigoVoo] = v;
        }

        Voo vooEscolhido;
        while (true) {


            cout << "Voos disponiveis:\n\n";

            for (const auto& vit : voos) {
                cout << Voo::to_string(vit.second);
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

    /**
     * Encontra voos disponiveis
     * @param voos
     * @return
     */
    static vector<Voo> findVoosDisponiveis(const map<int, Voo>& voos) {

        vector<Voo> voosDisponiveis;
        for (const auto& vit : voos) {

            if (!vit.second.lancado && !vit.second.explodido && !vit.second.finalizado) {
                voosDisponiveis.push_back(vit.second);
            }
        }

        return voosDisponiveis;
    }

    /**
     * Encontra voos lançados
     * @param voos
     * @return
     */
    static vector<Voo> findVoosLancados(const map<int, Voo>& voos) {

        vector<Voo> voosLancados;

        for(const auto& vit : voos) {

            if(vit.second.lancado && !vit.second.explodido) {
                voosLancados.push_back(vit.second);
            }

        }

        return voosLancados;

    }

    /**
     * Encontra voos finalizados com sucesso
     * @param voos
     * @return
     */
    static vector<Voo> findVoosFinalizados(const map<int, Voo>& voos) {

        vector<Voo> voosFinalizados;

        for(const auto& vit : voos) {

            if(vit.second.finalizado) {
                voosFinalizados.push_back(vit.second);
            }

        }

        return voosFinalizados;

    }

    /**
     * Encontra voos explodidos (RIP)
     * @param voos
     * @return
     */
    static vector<Voo> findVoosExplodidos(const map<int, Voo>& voos) {

        vector<Voo> voosExplodidos;

        for(const auto& vit : voos) {

            if(vit.second.explodido) {
                voosExplodidos.push_back(vit.second);
            }

        }

        return voosExplodidos;

    }
};