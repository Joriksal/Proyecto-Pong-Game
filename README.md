# Pong Game

El juego Pong es un clásico atemporal que pone a prueba tus reflejos y habilidades para rebotar la pelota en la pantalla. ¡Dale una oportunidad a la nostalgia y diviértete con este sencillo pero adictivo juego!

![](/images/descarga01.jpg)

## Contenido

1. [Instalación](#instalación)
2. [Cómo jugar](#cómo-jugar)
3. [Características](#características)
4. [Diagrama de Clases](#diagrama-de-clases)
5. [Autores](#autores)

## Instalación

1. Clona este repositorio en tu máquina local usando el siguiente comando:

   ```shell
   git clone https://github.com/Joriksal/Proyecto-Pong-Game.git  

2. Despues de clonar el repositorio en tu paquina local tienes que instalar los siguientes componentes: 

    ```shell
    Ligas de descarga: 
   Msys2: msys2-x86_64-20231026.exe

    Una vez hecha la instalación hay que instalar los paquetes de Msys2;

    Paquete mixer: pacman -S mingw-w64-x86_64-SDL2_mixer
    Paquete ttf: pacman -S mingw-w64-x86_64-SDL2_ttf
    Paquete SDL2: pacman -S mingw-w64-x86_64-SDL2

   Nota: Estos paquetes se tienen que instalar en la aplicación Msys2 color Azul. 


## Cómo jugar
- Para mejor experiencia, expanda lo maximo posible la ventana de la terminal.
- Usa las teclas W y S para mover la paleta izquierda hacia arriba y abajo, respectivamente.
- Usa las teclas I y K para controlar la paleta derecha hacia arriba y abajo, respectivamente.
- El objetivo del juego es evitar que la pelota caiga por tu paleta y hacer que la pelota caiga por la paleta del oponente.
- Cada vez que la pelota pasa por la paleta del oponente, ganas un punto.
El juego termina cuando alcanzas la puntuación máxima preestablecida (5 puntos).
- Si deseas salir del juego tienes que apretar las teclas de Ctrl + q.

## Características
- Gráficos simples pero efectivos.
- Control de paletas para dos jugadores.
- Sistema de puntuación.
- Sonido de presentación al inicio y fin del juego.

## Diagrama de Clases

![](/images/diagramapong.png)

## Autores
- Salas Castañon Jose Ricardo
- Lozano Hernandez Jose Angel