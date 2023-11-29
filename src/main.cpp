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

    while (!juego.Salir())
    {
        juego.ManejarEventos();
        juego.Actualizar();
        juego.Renderizar();

        SDL_Delay(10);
    }

    return 0;
}
