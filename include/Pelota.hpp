#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>

class Pelota
{
public:
    Pelota(int x, int y, int radio) : rect{x, y, radio * 2, radio * 2} {}

    void Mover(int velocidadX, int velocidadY);

    SDL_Rect ObtenerRect() const;

private:
    SDL_Rect rect;
};

void Pelota::Mover(int velocidadX, int velocidadY)
{
    rect.x += velocidadX;
    rect.y += velocidadY;
}

SDL_Rect Pelota::ObtenerRect() const
{
    return rect;
}