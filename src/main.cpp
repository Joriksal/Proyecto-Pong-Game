#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>

#include <Ventana.hpp>
#include <Juego.hpp>
#include <Caratula.hpp>

using namespace std;

int main(int argc, char *argv[])
{
    Ventana ventana("Pong Game", 800, 600);

    Caratula caratula(ventana, "assets/images/caratula-pg.bmp");
    caratula.Mostrar();

    Juego juego(ventana);

    while (!juego.Salir())
    {
        juego.ManejarEventos();
        juego.Actualizar();
        juego.Renderizar();

        SDL_Delay(10);
    }

    return 0;
}
