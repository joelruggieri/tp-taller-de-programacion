/*
 * FiguraView.h
 *
 *  Created on: 04/09/2013
 *      Author: jonathan
 */

#ifndef FIGURAVIEW_H_
#define FIGURAVIEW_H_
#include "src/figura/Figura.h"
#include <iostream>
#include "../View.h"
#include "SDL2/SDL.h"
using namespace std;

class DropController;
class FiguraView: public View {
private:
	Figura * modelo;
	SDL_Texture * textura;
protected:
	DropController * controller;
	virtual void dropTemplate() = 0;
public:
	FiguraView(int x, int y, int w, int h, SDL_Texture* textura, DropController * controller);
	virtual ~FiguraView();
	Figura * getModelo();
	void setModelo(Figura* modelo);
	void drop();
	void dibujarse(SDL_Renderer*);
	void click(float x, float y);
	void resizear(int x, int y);
};

#endif /* FIGURAVIEW_H_ */
