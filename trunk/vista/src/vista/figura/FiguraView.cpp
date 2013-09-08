#include "FiguraView.h"

#include <iostream>
#include "../../controller/DropController.h"
/********************************************************
 * FIGURAVIEW
 ********************************************************/
Figura* FiguraView::getModelo() {
	return this->modelo;
}

void FiguraView::setModelo(Figura* modelo) {
	this->modelo = modelo;
}

void FiguraView::drop(DropController* manager) {
	if (this->getModelo() != NULL) {
		manager->dropFigura(this);
	} else {
		this->dropTemplate(manager);
	}
}
FiguraView::FiguraView(int x, int y, int w, int h ) {
	this->modelo = NULL;
	this->x= x;
	this->y= y;
	this->w= w;
	this->h= h;
}

FiguraView::~FiguraView(){

}



/********************************************************
 * CIRCULOVIEW
 ********************************************************/

int FiguraView::getH() const {
	return h;
}

int FiguraView::getW() const {
	return w;
}

int FiguraView::getX() const {
	return x;
}

int FiguraView::getY() const {
	return y;
}
