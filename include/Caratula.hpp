#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <iostream>

#include <Ventana.hpp>
#include <Juego.hpp>

class Caratula
{
public:
    Caratula(const Ventana &ventana, const char *rutaImagen);
    ~Caratula();

    void Mostrar();
    bool Terminado() const;

private:
    Mix_Music *musicaFondo;
    SDL_Texture *textura;
    const Ventana &ventana;
    bool terminado;
};

Caratula::Caratula(const Ventana &ventana, const char *rutaImagen) : ventana(ventana)
{
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        // Manejar error
    }

    musicaFondo = Mix_LoadMUS("assets/music/background.mp3");

    SDL_Surface *imagenSurface = SDL_LoadBMP(rutaImagen);
    textura = SDL_CreateTextureFromSurface(ventana.ObtenerRenderer(), imagenSurface);
    SDL_FreeSurface(imagenSurface);

    terminado = false;
}

Caratula::~Caratula()
{
    SDL_DestroyTexture(textura);
    Mix_FreeMusic(musicaFondo);
}

void Caratula::Mostrar()
{
    Mix_VolumeMusic(MIX_MAX_VOLUME / 8);
    Mix_PlayMusic(musicaFondo, -1);

    SDL_RenderClear(SDL_GetRenderer(ventana.ObtenerVentana()));
    SDL_RenderCopy(SDL_GetRenderer(ventana.ObtenerVentana()), textura, NULL, NULL);
    SDL_RenderPresent(SDL_GetRenderer(ventana.ObtenerVentana()));

    SDL_Delay(5000);

    terminado = true;
}

bool Caratula::Terminado() const
{
    return terminado;
}
