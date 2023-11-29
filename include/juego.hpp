#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>

#include <Ventana.hpp>
#include <Ventana.hpp>
#include <Paleta.hpp>
#include <Pelota.hpp>

class Juego
{
public:
    Juego();

    ~Juego();

    void ManejarEventos();

    void Actualizar();

    void Renderizar();

    bool Salir() const;

private:
    static const int AnchoVentana;
    static const int AlturaVentana;
    static const int AnchoPaleta;
    static const int AlturaPaleta;
    static const int RadioPelota;
    static int VelocidadPelotaX;
    static int VelocidadPelotaY;

    Ventana ventana{"Pong Game", AnchoVentana, AlturaVentana};
    Paleta paleta1;
    Paleta paleta2;
    Pelota pelota;
    bool quit = false;
};

const int Juego::AnchoVentana = 800;
const int Juego::AlturaVentana = 600;
const int Juego::AnchoPaleta = 20;
const int Juego::AlturaPaleta = 100;
const int Juego::RadioPelota = 10;
int Juego::VelocidadPelotaX = 5;
int Juego::VelocidadPelotaY = 2;

Juego::Juego() : paleta1(50, 250, AnchoPaleta, AlturaPaleta, AlturaVentana),
                 paleta2(730, 250, AnchoPaleta, AlturaPaleta, AlturaVentana),
                 pelota(400, 300, RadioPelota) {}

Juego::~Juego() {}

void Juego::ManejarEventos()
{
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0)
    {
        if (e.type == SDL_QUIT)
        {
            quit = true;
        }
    }

    const Uint8 *teclasPresionadas = SDL_GetKeyboardState(nullptr);
    if (teclasPresionadas[SDL_SCANCODE_W])
    {
        paleta1.MoverArriba();
    }
    if (teclasPresionadas[SDL_SCANCODE_S])
    {
        paleta1.MoverAbajo();
    }
    if (teclasPresionadas[SDL_SCANCODE_I])
    {
        paleta2.MoverArriba();
    }
    if (teclasPresionadas[SDL_SCANCODE_K])
    {
        paleta2.MoverAbajo();
    }
}

void Juego::Actualizar()
{
    pelota.Mover(VelocidadPelotaX, VelocidadPelotaY);

    if (pelota.ObtenerRect().y - pelota.ObtenerRect().h / 2 < 0 ||
        pelota.ObtenerRect().y + pelota.ObtenerRect().h / 2 > AlturaVentana)
    {
        VelocidadPelotaY = -VelocidadPelotaY;
    }

    SDL_Rect rectanguloPelota = pelota.ObtenerRect();
    SDL_Rect rectanguloPaleta1 = paleta1.ObtenerRect();
    SDL_Rect rectanguloPaleta2 = paleta2.ObtenerRect();

    if (SDL_HasIntersection(&rectanguloPelota, &rectanguloPaleta1) ||
        SDL_HasIntersection(&rectanguloPelota, &rectanguloPaleta2))
    {
        VelocidadPelotaX = -VelocidadPelotaX;
    }

    if (rectanguloPelota.x - rectanguloPelota.w / 2 < 0 || rectanguloPelota.x + rectanguloPelota.w / 2 > AnchoVentana)
    {
        pelota = Pelota(400, 300, RadioPelota);
    }
}

void Juego::Renderizar()
{
    SDL_Renderer *renderer = ventana.ObtenerRenderer();

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_Rect rectanguloPaleta1 = paleta1.ObtenerRect();
    SDL_Rect rectanguloPaleta2 = paleta2.ObtenerRect();
    SDL_Rect rectanguloPelota = pelota.ObtenerRect();

    SDL_RenderFillRect(renderer, &rectanguloPaleta1);
    SDL_RenderFillRect(renderer, &rectanguloPaleta2);
    SDL_RenderFillRect(renderer, &rectanguloPelota);

    SDL_RenderPresent(renderer);
}

bool Juego::Salir() const
{
    return quit;
}
