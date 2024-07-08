#include <iostream>
#include <vector>
#include <map>
#include <string>

#include "classes/Astronauta.hpp"
#include "classes/Voo.hpp"

#include "utils/AstronautaUtils.hpp"
#include "utils/VooUtils.hpp"

#include "features/VooFeatures.hpp"
#include "features/AstronautaFeatures.hpp"

#include "utils/PrettyPrintUtils.hpp"

using namespace std;

// Estruturas
map<string, Astronauta> astronautas;
map<int, Voo> voos;

map<string, Astronauta> &astronautasRef = astronautas;
map<int, Voo> &voosRef = voos;


int main() {

    cout << PrettyPrintUtils::sga() << endl << "Sistema de Gerenciamento de Astronautas" << endl;

    cout << endl << endl;

    bool keep = true;

    while (keep) {

        cout << "Selecione a ação que quer realizar:" << endl
                  << "1 - CADASTRAR ASTRONAUTA\t\t\t2 - CADASTRAR VOO" << endl
                  << "3 - ADICIONAR ASTRONAUTA A UM VOO\t\t4 - REMOVER ASTRONAUTA DE UM VOO" << endl
                  << "5 - LANÇAR UM VOO\t\t\t\t6 - EXPLODIR UM VOO" << endl
                  << "7 - FINALIZAR UM VOO COM SUCESSO\t\t8 - LISTAR TODOS OS VOOS" << endl
                  << "9 - LISTAR TODOS OS ASTRONAUTAS MORTOS\t\t10 - ENCERRAR O PROGRAMA" << endl << endl;
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
                VooFeatures::astronautaVoo(voosRef, astronautasRef, false);
                break;
            case 4:
                VooFeatures::astronautaVoo(voosRef, astronautasRef, true);
                break;
            case 5:
                VooFeatures::lancarVoo(voosRef, astronautasRef);
                break;
            case 6:
                VooFeatures::explodirVoo(voosRef, astronautasRef);
                break;
            case 7:
                VooFeatures::finalizarVoo(voosRef, astronautasRef);
                break;
            case 8:
                VooUtils::listarTodosOsVoos(voosRef);
                break;
            case 9:
                AstronautaUtils::listarAstronautasMortos(astronautasRef);
                break;
            case 10:
                keep = false;
                break;

        }
    }

    return 0;
}
