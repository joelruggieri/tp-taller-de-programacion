#include "FiguraView.h"

#include <iostream>
#include "../../controller/DropManager.h"
/********************************************************
 * FIGURAVIEW
 ********************************************************/
Figura* FiguraView::getModelo() {
	return this->modelo;
}

void FiguraView::setModelo(Figura* modelo) {
	this->modelo = modelo;
}

void FiguraView::drop(DropManager* manager) {
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

