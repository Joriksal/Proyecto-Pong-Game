#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>

#include <Juego.hpp>
#include <Paleta.hpp>
#include <Pelota.hpp>
#include <Ventana.hpp>

using namespace std;

int main(int argc, char *argv[])
{
    Juego juego;
    Menu menu;

    int opcionMenu = 0;

    do
    {

        switch (opcionMenu)
        {
        case 1:
            do
            {
                juego.ManejarEventos();
                juego.Actualizar();
                juego.Renderizar();
                SDL_Delay(10);
            } while (!juego.Salir());
            break;

        case 2:
            // Instrucciones
            std::cout << "Instrucciones:" << std::endl;
            std::cout << "1. Usa las teclas W y S para mover la paleta izquierda." << std::endl;
            std::cout << "2. Usa las teclas de flecha arriba y abajo para mover la paleta derecha." << std::endl;
            std::cout << "3. Presiona la tecla ESC para salir del juego." << std::endl;
            break;

        case 3:
            std::cout << "Saliendo del juego." << std::endl;
            break;

        default:
            std::cout << "Opcion invalida. Intente de nuevo." << std::endl;
            break;
        }

    } while (opcionMenu != 3); // Salir del bucle si la opción es "Salir"

    return 0;
}

//while (!juego.Salir())
 //   {
 //       juego.ManejarEventos();
   //     juego.Actualizar();
   //     juego.Renderizar(); asi funciona sin el menu 
   // SDL_Delay(10);
   // }


   // return 0;