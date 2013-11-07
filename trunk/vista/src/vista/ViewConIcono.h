/*
 * ViewConIcono
 *
 *  Created on: 03/10/2013
 *      Author: jonathan
 */

#ifndef VIEWCONICONO_H_
#define VIEWCONICONO_H_
#include "View.h"
#include "SDL2/SDL.h"

namespace CLIENTE {
class ViewConIcono: public Dibujable {
private:
	SDL_Texture * textura;
	View * vista;
	int esquina;
//	SDL_Rect rectEsquina0();
//	SDL_Rect rectEsquina1();
//	SDL_Rect rectEsquina2();
//	SDL_Rect rectEsquina3();
public:
	//esquina contando desde abajo a la izquierda en sentido horario de 0-3. no seas puto pone de 0 - 3 o se rompe
	ViewConIcono(View * view, SDL_Texture * textura, int esquina);
	virtual ~ViewConIcono();
	void dibujarse(SDL_Renderer *);
	void dibujarse(SDL_Renderer *, SDL_Rect& destino);
};
}
#endif /* VIEWCONICONO_H_ */

