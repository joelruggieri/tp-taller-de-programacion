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
FiguraView::FiguraView() {
	this->modelo = NULL;
}

FiguraView::~FiguraView(){

}
void FiguraView::dibujarse(){

}



/********************************************************
 * CIRCULOVIEW
 ********************************************************/

