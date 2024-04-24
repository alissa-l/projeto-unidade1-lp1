#include "string"
using namespace std;

class Astronauta {
public:
    Astronauta() {}
    Astronauta(string cpf, string nome, int idade, bool ocupado, bool vivo) {}

    string cpf;
    string nome;
    int idade;
    bool ocupado;
    bool vivo;

    string to_string(Astronauta astronauta) const {
        int idade = astronauta.idade;
        string idadeStr = std::to_string(idade);
        return ("Nome: " + astronauta.nome + "\n CPF: " + astronauta.cpf + "\n Idade: " + idadeStr);
    }
};

