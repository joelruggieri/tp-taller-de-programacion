#include "SDL2/SDL.h"

#define USREVENT_CHANGEBACKGROUND 1
#define USREVENT_SAVEGAME 2
#define USREVENT_QUIT 3
#define USREVENT_START 4
#define USREVENT_STOP 5

//Metodo que crea un user event con la inforacion recibida. Los codigos de evento posible son los definidos arriba.
SDL_Event crearEvento(int code, void* data1, void* data2);
