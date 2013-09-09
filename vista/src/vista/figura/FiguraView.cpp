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
FiguraView::FiguraView(int x, int y, int w, int h ): View(x,y,w,h) {
	this->modelo = NULL;
}

FiguraView::~FiguraView(){

}

