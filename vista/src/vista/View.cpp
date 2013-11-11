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
	updated = true;
	id = -1;
}

View::~View() {
//	Resizer::Instance()->quitarResizeable(this);
}


void View::resizear() {
	wp = tl->escalarInversaEnX(wl);
	hp = tl->escalarInversaEnX(hl);
	float xesquina = xl - wl/2;
	float yesquina = yl + hl/2;
	tl->setVector(xesquina, yesquina);
	float xpf, ypf;
	tl->getResultadoInverso(xpf,ypf);
	xp = round(xpf);
	yp = round (ypf);
}


void CLIENTE::View::setYL(float yl) {
	this->yl = yl;
	resizear();
}

float CLIENTE::View::getYL() {
	return yl;
}

int View::getHp() const {
	return hp;
}

void View::setHp(int hp) {
	this->hp = hp;
}

int View::getWp() const {
	return wp;
}

void View::setWp(int wp) {
	this->wp = wp;
}

int View::getXp() const {
	return xp;
}

void View::setXp(int xp) {
	this->xp = xp;
}

int View::getYp() const {
	return yp;
}

void View::setYp(int yp) {
	this->yp = yp;
}



}

bool CLIENTE::View::isUpdated() {
	return updated;
}

void CLIENTE::View::markUpdated() {
	updated = true;
}

void CLIENTE::View::invalidate() {
	updated = false;
}
