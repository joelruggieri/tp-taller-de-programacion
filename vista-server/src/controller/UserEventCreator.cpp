#include "UserEventCreator.h"

SDL_Event crearEvento(int code, void* data1, void* data2){
	SDL_Event evento;

	if(code == USREVENT_QUIT){
		evento.type = SDL_QUIT;
		return evento;
	}

	evento.type = SDL_USEREVENT;
	evento.user.code = code;
	evento.user.data1 = data1;
	evento.user.data2 = data2;

	return evento;
}
