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
	int layer;
	void generarSinBorde(SDL_Rect & dest);
public:
	Canvas(float x, float y, float h, float w,int layer,  SDL_Texture* textura);
	void dibujarse(SDL_Renderer *);
	void dibujarse(SDL_Renderer *, SDL_Rect&);
	virtual ~Canvas();
	void ModificarFondo(SDL_Texture* nuevaImagen);
	void update(ViewMsj *);
	int getLayer();
	bool isUpdated();
};

}
#endif /* CANVAS_H_ */


