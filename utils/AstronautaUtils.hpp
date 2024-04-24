#include <string>
#include <map>
#include <vector>

#include "Astronauta.hpp"

using namespace std;

class AstronautaUtils {
public:
    static map<string, Astronauta> cadastrarAstronauta(map<string, Astronauta> &astronautas) {

        string cpf;
        cout << "Digite o cpf do astronatua: ";
        cin >> cpf;

        string nome;
        cout << "Digite o nome do astronauta: ";
        cin >> nome;

        int idade;
        cout << "Digite a idade do astronauta: ";
        cin >> idade;

        Astronauta astronauta = Astronauta(cpf, nome, idade, false, true);

        if (astronautas.find(cpf) == astronautas.end()) {
            astronautas[cpf] = astronauta;
            cout << "Astronauta " << nome << " cadastrado(a)" << endl;
        }
        else {
            cout << "Um astronauta com este cpf já existe" << endl;
        }
    }

    static Astronauta findAstronauta(string cpf, map<string, Astronauta> &astronautas) {
        return astronautas[cpf];
    }

    static vector<string> listAstronautas(map<string, Astronauta> &astronautas) {
        
    }
};