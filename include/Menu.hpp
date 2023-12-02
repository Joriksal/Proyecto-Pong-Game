#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include <Juego.hpp>

class Menu {
public:
    int Mostrar() {
        int opcion;
        std::cout << "MENU" << std::endl;
        std::cout << "1. Jugar" << std::endl;
        std::cout << "2. Instrucciones" << std::endl;
        std::cout << "3. Salir" << std::endl;
        std::cout << "Seleccione una opcion (1-3): " << std::endl;
        std::cin >> opcion;

        return opcion;
    }
};