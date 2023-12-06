#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <iostream>

#include <Ventana.hpp>
#include <Paleta.hpp>
#include <Pelota.hpp>

class Juego
{
public:
    Juego(const Ventana &ventana);
    ~Juego();
    void ManejarEventos();
    void Actualizar();
    void Renderizar();
    bool Salir() const;
    void ReproducirSonidoHit();
    void ReproducirSonidoScore();

private:
    const Ventana &ventana;
    Paleta paleta1;
    Paleta paleta2;
    Pelota pelota;
    bool quit;

    Mix_Chunk *hitSound;
    Mix_Chunk *scoreSound;

    static const int AnchoPaleta;
    static const int AlturaPaleta;
    static const int RadioPelota;
    static int VelocidadPelotaX;
    static int VelocidadPelotaY;
};

const int Juego::AnchoPaleta = 20;
const int Juego::AlturaPaleta = 100;
const int Juego::RadioPelota = 10;
int Juego::VelocidadPelotaX = 5;
int Juego::VelocidadPelotaY = 2;

Juego::Juego(const Ventana &ventana)
    : ventana(ventana), paleta1(50, 250, AnchoPaleta, AlturaPaleta, ventana.ObtenerVentanaAltura()),
      paleta2(730, 250, AnchoPaleta, AlturaPaleta, ventana.ObtenerVentanaAltura()),
      pelota(400, 300, RadioPelota),
      quit(false)
{

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        // Manejar error
    }

    hitSound = Mix_LoadWAV("assets/sounds/hit.wav");
    scoreSound = Mix_LoadWAV("assets/sounds/score.wav");
}

void Juego::ManejarEventos()
{
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0)
    {
        if (e.type == SDL_QUIT)
        {
            quit = true;
        }
        else if (e.type == SDL_KEYDOWN)
        {
            if (e.key.keysym.sym == SDLK_q)
            {
                quit = true;
            }
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
        pelota.ObtenerRect().y + pelota.ObtenerRect().h / 2 > ventana.ObtenerVentanaAltura())
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

        ReproducirSonidoHit();
    }

    if (rectanguloPelota.x - rectanguloPelota.w / 2 < 0 || rectanguloPelota.x + rectanguloPelota.w / 2 > ventana.ObtenerVentanaAncho())
    {
        pelota = Pelota(400, 300, RadioPelota);

        ReproducirSonidoScore();
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

Juego::~Juego()
{
    Mix_FreeChunk(hitSound);
    Mix_FreeChunk(scoreSound);
    Mix_CloseAudio();
}

void Juego::ReproducirSonidoHit()
{
    Mix_PlayChannel(-1, hitSound, 0);
}

void Juego::ReproducirSonidoScore()
{
    Mix_PlayChannel(-1, scoreSound, 0);
}
