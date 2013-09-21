/*
 * CarritoView.h
 *
 *  Created on: 21/09/2013
 *      Author: joel
 */

#ifndef CARRITOVIEW_H_
#define CARRITOVIEW_H_
#include "FiguraView.h"
#include "SDL2/SDL.h"

class CarritoView: public FiguraView {
private:
	void dropTemplate();

public:
	CarritoView(int x, int y, int w, int h, SDL_Texture * textura,DropController * controller);
	virtual ~CarritoView();
};

#endif /* CARRITOVIEW_H_ */
