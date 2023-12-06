#pragma once

#include <SDL.h>
#include <iostream>

class Ventana
{
public:
    Ventana(const char *titulo, int ancho, int altura);

    ~Ventana();

    SDL_Renderer *ObtenerRenderer() const
    {
        return renderer;
    }

    SDL_Window *ObtenerVentana() const
    {
        return ventana;
    }

    int ObtenerVentanaAncho() const;
    int ObtenerVentanaAltura() const;

private:
    SDL_Surface *icon;
    SDL_Window *ventana;
    SDL_Renderer *renderer;
};

Ventana::Ventana(const char *titulo, int ancho, int altura)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        // Manejar error
    }

    ventana = SDL_CreateWindow(titulo, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                               ancho, altura, SDL_WINDOW_SHOWN);
    if (ventana == nullptr)
    {
        // Manejar error
    }

    icon = SDL_LoadBMP("assets/images/icon.bmp"); // Reemplaza con el nombre de tu archivo de icono
    SDL_SetWindowIcon(ventana, icon);

    renderer = SDL_CreateRenderer(ventana, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr)
    {
        // Manejar error
    }
}

int Ventana::ObtenerVentanaAncho() const
{
    int ancho;
    SDL_GetWindowSize(ventana, &ancho, nullptr);
    return ancho;
}

int Ventana::ObtenerVentanaAltura() const
{
    int altura;
    SDL_GetWindowSize(ventana, nullptr, &altura);
    return altura;
}

Ventana::~Ventana()
{
    SDL_FreeSurface(icon);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(ventana);
    SDL_Quit();
}
