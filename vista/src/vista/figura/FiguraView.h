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
using namespace std;

class DropController;
class FiguraView: public View {
private:
	Figura * modelo;
protected:
	virtual void dropTemplate(DropController*) = 0;
public:
	FiguraView(int x, int y, int w, int h);
	virtual ~FiguraView();
	Figura * getModelo();
	void setModelo(Figura* modelo);
	void drop(DropController* manager);
	virtual void dibujarse(SDL_Renderer*)=0;
};

#endif /* FIGURAVIEW_H_ */
