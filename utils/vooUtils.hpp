#include <iostream>
#include <string>
#include <map>
#include <vector>

#include "Astronauta.hpp"
#include "AstronautaUtils.hpp"
#include "Voo.hpp"

using namespace std;

class VooUtils
{
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
                AstronautaUtils::listAstronautas(astronautas);

                string cpf;
                cout << "Digite o cpf do astronauta que quer cadastrar no voo: ";
                cin >> cpf;

                Astronauta astronauta = AstronautaUtils::findAstronauta(cpf, astronautas);
            }
        }
    }
};