#include <map>
#include <string>
#include <vector>

#include "../classes/Astronauta.hpp"

#ifndef PROJETO1_ASTRONAUTAUTILS_H
#define PROJETO1_ASTRONAUTAUTILS_H

#endif //PROJETO1_ASTRONAUTAUTILS_H

class AstronautaUtils {
public:
    static Astronauta selectAstronauta(map<string, Astronauta> astronautas) {}
    static Astronauta selectAstronautaOcupado(vector<Astronauta> astronautas) {}

private:
    static Astronauta findAstronautaUser(map<string, Astronauta> astronautas) {}
    static map<string, Astronauta> mapAstronautasVivosDisponiveis(map<string, Astronauta> &astronautas) {}
    static map<string, Astronauta> mapAstronautasVivosOcupados(map<string, Astronauta> &astronautas) {}
    static map<string, Astronauta> mapAstronautasVivosOcupados(vector<Astronauta> &astronautas) {}
};