#include <iostream>
#include <vector>
#include <map>
#include <string>

#include "classes/Astronauta.hpp"
#include "classes/Voo.hpp"

#include "utils/AstronautaUtils.hpp"
#include "utils/vooUtils.hpp"

#include "features/VooFeatures.hpp"
#include "features/AstronautaFeatures.hpp"

using namespace std;

// Estruturas
map<string, Astronauta> astronautas;
map<int, Voo> voos;

map<string, Astronauta> &astronautasRef = astronautas;
map<int, Voo> &voosRef = voos;


int main() {

    Astronauta astronauta = Astronauta("123", "Me", 20, false, true);
    astronautas["123"] = astronauta;

    Voo voo = Voo(42);
    voos[42] = voo;


    string SGA = "\t\t   _____ _________\n"
                      "\t\t  / ___// ____/   |\n"
                      "\t\t  \\__ \\/ / __/ /| |\n"
                      "\t\t ___/ / /_/ / ___ |\n"
                      "\t\t/____/\\____/_/  |_|";

    cout << SGA << endl << "Sistema de Gerenciamento de Astronautas" << endl;

    cout << endl << endl;

    while (true) {

        cout << "Selecione a ação que quer realizar:" << endl
                  << "1 - CADASTRAR ASTRONAUTA\t\t\t2 - CADASTRAR VOO" << endl
                  << "3 - ADICIONAR ASTRONAUTA A UM VOO\t\t4 - REMOVER ASTRONAUTA DE UM VOO" << endl
                  << "4 - LANÇAR UM VOO\t\t\t\t5 - EXPLODIR UM VOO" << endl
                  << "6 - FINALIZAR UM VOO COM SUCESSO\t\t7 - LISTAR TODOS OS VOOS" << endl
                  << "8 - LISTAR TODOS OS ASTRONAUTAS MORTOS\t\t9 - ENCERRAR O PROGRAMA" << endl << endl;
        cout << flush;

        int opcao;

        cin >> opcao;



        switch (opcao) {
            case 1:
                AstronautaFeatures::cadastrarAstronauta(astronautasRef);
                break;
            case 2:
                VooFeatures::cadastrarVoo(voosRef, astronautasRef);
                break;
            case 3:
                VooFeatures::cadastrarAstronautaVoo(voosRef, astronautasRef);
                break;
            case 4:
                VooFeatures::removerAstronautaVoo(voosRef, astronautasRef);
                break;
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
                return 0;

        }
    }

    return 0;
}
