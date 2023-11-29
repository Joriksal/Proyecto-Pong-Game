#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>

class Paleta
{
public:
    Paleta(int x, int y, int w, int h, int alturaVentana) : rect{x, y, w, h}, alturaVentana(alturaVentana) {}

    void MoverArriba();

    void MoverAbajo();

    SDL_Rect ObtenerRect() const;

private:
    SDL_Rect rect;
    int alturaVentana;
    static const int VELOCIDAD_PALETA = 5;
};

void Paleta::MoverArriba()
{
    if (rect.y > 0)
    {
        rect.y -= VELOCIDAD_PALETA;
    }
}

void Paleta::MoverAbajo()
{
    if (rect.y + rect.h < alturaVentana)
    {
        rect.y += VELOCIDAD_PALETA;
    }
}

SDL_Rect Paleta::ObtenerRect() const
{
    return rect;
}