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
	virtual void dropTemplate(DropController*) = 0;
public:
	FiguraView(int x, int y, int w, int h, SDL_Texture* textura);
	virtual ~FiguraView();
	Figura * getModelo();
	void setModelo(Figura* modelo);
	void drop(DropController* manager);
	void dibujarse(SDL_Renderer*);
};

#endif /* FIGURAVIEW_H_ */
