#include <iostream>
#include "string"
#include <vector>

#define MAX_SIZE 10

class Astronauta {
public:
    Astronauta() { }
    Astronauta(std::string cpf, std::string nome, int idade) {}

    std::string cpf;
    std::string nome;
    int idade;
    bool ocupado;
    bool vivo;
};

class Voo {
public:
    int codigoVoo;
    Astronauta astronautas[MAX_SIZE];
};

// Estruturas
std::vector<Astronauta> astronautas;

int cadastrarAstronauta() {
    std::cout << "Digite o cpf "
    std::cin >>
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
