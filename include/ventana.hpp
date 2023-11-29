#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>

class Ventana
{
public:
    Ventana(const char *titulo, int ancho, int altura)
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

        renderer = SDL_CreateRenderer(ventana, -1, SDL_RENDERER_ACCELERATED);
        if (renderer == nullptr)
        {
            // Manejar error
        }
    }

    ~Ventana()
    {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(ventana);
        SDL_Quit();
    }

    SDL_Renderer *getRenderer() const
    {
        return renderer;
    }

private:
    SDL_Window *ventana;
    SDL_Renderer *renderer;
};