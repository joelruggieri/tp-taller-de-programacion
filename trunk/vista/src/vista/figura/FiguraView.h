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
#include "src/Vista.h"
#include "SDL2/SDL.h"
#include "../../controller/editor/EditorNivel.h"
#include "Enganche.h"

using namespace std;

class DropController;
class FiguraView: public View, public Vista {
private:
	Figura * modelo;
	SDL_Texture * textura;
	Lista_Enganches enganches; //Cada hijo debe agregar a la lista sus enganches.
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
	void dibujarse(SDL_Renderer*, SDL_Rect&);
	void click(float x, float y);
	virtual void update(Transformacion & tl);
	virtual EditorNivel* getEditor() = 0;
	virtual Lista_Enganches getEnganches();
};

#endif /* FIGURAVIEW_H_ */
