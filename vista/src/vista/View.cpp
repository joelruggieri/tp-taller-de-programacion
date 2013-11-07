/*
 * View.cpp
 *
 *  Created on: 05/09/2013
 *      Author: jonathan
 */

#include "View.h"
namespace CLIENTE {
View::View(float x, float y, float w, float h) {
	this->wl = w;
	this->hl = h;
	this->xl= x;
	this->yl = y;
	xp = 0;
	yp = 0;
	wp=0;
	hp = 0;
}

View::~View() {
//	Resizer::Instance()->quitarResizeable(this);
}


void View::resizear() {
	wp = tl->escalarEnX(wl);
	hp = tl->escalarEnY(hl);
	float xesquina = xl - wl/2;
	float yesquina = yl + hl/2;
	tl->setVector(xesquina, yesquina);
	float xpf, ypf;
	tl->getResultado(xpf,ypf);
	xp = round(xpf);
	yp = round (ypf);
}
}
