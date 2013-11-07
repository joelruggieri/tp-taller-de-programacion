/*
 * Canvas.h
 *
 *  Created on: 31/08/2013
 *      Author: ezequiel
 */

#ifndef CANVAS_H_
#define CANVAS_H_
#include "SDL2/SDL_image.h"
#include "SDL2/SDL.h"
#include <iostream>
#include "View.h"
#include <list>
using namespace std;


namespace CLIENTE {


class Canvas: public View {
private:
	SDL_Texture* imagenCanvas;
	bool border;
	void generarSinBorde(SDL_Rect & dest);
public:
	 void resizear();
	Canvas(int x, int y, int h, int w, SDL_Texture* textura);
	void dibujarse(SDL_Renderer *);
	void dibujarse(SDL_Renderer *, SDL_Rect&);
	virtual ~Canvas();
	void ModificarFondo(SDL_Texture* nuevaImagen);
	void update(ViewMsj *);
};

}
#endif /* CANVAS_H_ */


