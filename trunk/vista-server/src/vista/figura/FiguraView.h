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
#include "../../modelo/Observable.h"

#include <list>
using namespace std;

class DropController;
class FiguraView: public View, public Vista, public Observable{
private:
	Figura * modelo;
	typedef View super;
protected:
	DropController * controller;
	virtual void dropTemplate() = 0;

public:
	FiguraView(float x, float y, DropController * controller);
	virtual ~FiguraView();
	Figura * getModelo();
	virtual void setModelo(Figura* modelo);
	void drop();
	void dibujarse(list<ViewMsj*> & lista) = 0;
	void click(float x, float y);
//	virtual void update();
	virtual EditorNivel* getEditor() = 0;
//	SDL_Texture* getTexture();
//	void resizear();
};

#endif /* FIGURAVIEW_H_ */
