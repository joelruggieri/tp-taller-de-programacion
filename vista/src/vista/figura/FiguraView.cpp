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
void FiguraView::dibujarse(){

}

/********************************************************
 * CUADRADOVIEW
 ********************************************************/

void CuadradoView::dropTemplate(DropManager* manager) {
	manager->dropNuevaFigura(this);
}

CuadradoView::CuadradoView() {

}

CuadradoView::~CuadradoView() {

}

/********************************************************
 * TRIANGULOVIEW
 ********************************************************/

void TrianguloView::dropTemplate(DropManager* manager) {
	manager->dropNuevaFigura(this);
}

TrianguloView::TrianguloView() {

}

TrianguloView::~TrianguloView() {

}


/********************************************************
 * CIRCULOVIEW
 ********************************************************/

void CirculoView::dropTemplate(DropManager* manager) {
	manager->dropNuevaFigura(this);
}

CirculoView::CirculoView() {

}

CirculoView::~CirculoView() {
}

FiguraView::~FiguraView() {
}
