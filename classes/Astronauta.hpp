#pragma once

#include "string"
using namespace std;

class Astronauta {
public:
    Astronauta() {}
    Astronauta(string cpf1, string nome1, int idade1, bool ocupado1, bool vivo1) {
        cpf = cpf1;
        nome = nome1;
        idade = idade1;
        ocupado = ocupado1;
        vivo = vivo1;
    }

    string cpf;
    string nome;
    int idade;
    bool cadastrado;
    bool ocupado;
    bool vivo;
    map<int, bool> voos;

    static string to_string(Astronauta astronauta) {
        int idade = astronauta.idade;
        string idadeStr = std::to_string(idade);
        return ("Nome: " + astronauta.nome + "\nCPF: " + astronauta.cpf + "\nIdade: " + idadeStr + "\nOcupado(a): " + ((astronauta.ocupado) ? "Sim" : "Não") + "\n");
    }
};

