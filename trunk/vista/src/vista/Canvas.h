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





class Canvas: public View {
private:
	SDL_Texture* imagenCanvas;
	list<Dibujable*> vistas;
	bool border;

	void generarSinBorde(SDL_Rect & dest);

public:
	 void resizear();
	Canvas(int x, int y, int h, int w, SDL_Texture* textura);
	void dibujarse(SDL_Renderer *);
	void dibujarse(SDL_Renderer *, SDL_Rect&);
	virtual ~Canvas();
	void ModificarFondo(SDL_Texture* nuevaImagen);
	void agregar(Dibujable *);
	void remover(Dibujable *);
	//void Resizear(int x, int y);
	const list<Dibujable*>& getDibujables() const;
	const list<Dibujable*>& getVistas();
//	static const RGB COLOR_BORDE_EXTERNO;
};

#endif /* CANVAS_H_ */


