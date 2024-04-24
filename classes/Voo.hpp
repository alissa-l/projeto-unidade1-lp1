#include "Astronauta.hpp"

#include <vector>

class Voo {
public:
    Voo(){};
    Voo(int codigoVoo, Astronauta astronautas[]);

    int codigoVoo;
    std::vector<Astronauta> astronautas;
};