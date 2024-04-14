#include <iostream>
#include "string"
#include <vector>

#define MAX_SIZE 10

class Astronauta {
public:
    Astronauta() { }
    Astronauta(std::string cpf, std::string nome, int idade, bool ocupado, bool vivo) {}

    std::string cpf;
    std::string nome;
    int idade;
    bool ocupado;
    bool vivo;
};

class Voo {
public:
    Voo(){}
    Voo(int codigoVoo, Astronauta astronautas[])

    int codigoVoo;
    Astronauta astronautas[MAX_SIZE];
};

// Estruturas
std::vector<Astronauta> astronautas;
std::vector<Voo> voos;

void cadastrarAstronauta() {
    std::string cpf;
    std::cout << "Digite o cpf do astronatua: ";
    std::cin >> cpf;

    std::string nome;
    std::cout << "Digite o nome do astronauta: ";
    std::cin >> nome;

    int idade;
    std::cout << "Digite a idade do astronauta: ";
    std::cin >> idade;

    Astronauta astronauta = Astronauta(cpf, nome, idade, false, true);
    astronautas.push_back(astronauta);

    std::cout << "Astronauta " << nome << " cadastrado(a)";
}

Astronauta findAstronauta(std::string cpf) {



}

void cadastrarVoo() {
    std::string codigo;
    std::cout << "Digite o código de voo: ";
    std::cin >> codigo;

    char opcao;
    std::cout << "Gostaria de cadastrar um astronauta ao voo? (S/N) ";
    std::cin >> opcao;

    Voo voo = Voo()
    if (opcao == 'S' || opcao == 's') {
        while(true) {
            std::string cpf;
            std::cout << "Digite o cpf do astronauta que quer cadastrar no voo: ";
            std::cin >> cpf;

            Astronauta astronauta = findAstronauta(cpf);


        }
    }
}

int main() {

    std::string SGA = "\t\t   _____ _________\n"
                      "\t\t  / ___// ____/   |\n"
                      "\t\t  \\__ \\/ / __/ /| |\n"
                      "\t\t ___/ / /_/ / ___ |\n"
                      "\t\t/____/\\____/_/  |_|";

    std::cout << SGA << std::endl << "Sistema de Gerenciamento de Astronautas" << std::endl;

    std::cout << std::endl << std::endl;

    while (true) {

        std::cout << "Selecione a ação que quer realizar:" << std::endl
                  << "1 - CADASTRAR ASTROUNAUTA\t\t\t\t2 - CADASTRAR VOO" << std::endl
                  << "3 - ADICIONAR ASTRONAUTA A UM VOO\t\t4 - REMOVER ASTRONAUTA DE UM VOO" << std::endl
                  << "4 - LANÇAR UM VOO\t\t\t\t\t\t5-EXPLODIR UM VOO" << std::endl
                  << "6 - FINALIZAR UM VOO COM SUCESSO\t\t7 - LISTAR TODOS OS VOOS" << std::endl
                  << "8 - LISTAR TODOS OS ASTRONAUTAS MORTOS\t9 - ENCERRAR O PROGRAMA" << std::endl << std::endl;
        std::cout << std::flush;

        int opcao;

        std::cin >> opcao;

        switch (opcao) {
            case 1:
                cadastrarAstronauta();
            case 2:
            case 3:
            case 4:
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
