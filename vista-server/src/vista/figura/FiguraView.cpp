#include "FiguraView.h"

#include <iostream>
#include "../../controller/DropController.h"
#include "src/Logger.h"
#include <cmath>
using namespace std;

/********************************************************
 * FIGURAVIEW

 ********************************************************/
Figura* FiguraView::getModelo() {
	return this->modelo;
}

void FiguraView::setModelo(Figura* modelo) {
	this->modelo = modelo;
}

void FiguraView::drop() {
	Logger log;
	std::string mensaje_info;
	if (this->getModelo() != NULL) {
		log.debug("Drop generico de FiguraView");
		controller->dropFigura(this);
	} else {
		log.debug("Drop especifico de FiguraView");
		this->dropTemplate();
	}
}
FiguraView::FiguraView(float x, float y,DropController * controller ): View(x,y) {
	this->modelo = NULL;
	this->controller = controller;
	this->numeroEvento = VALOR_DESACTIVAR_SONIDO;
}

FiguraView::~FiguraView(){
	this->notifY(DESTRUIR_VISTA);
}


void FiguraView::click(float x, float y) {
	this->controller->drag(this,x,y);
}

//void FiguraView::update() {
//	tl.setVector((float)this->modelo->getX(), (float)this->modelo->getY());
//	float x,y;
//	tl.getResultadoInverso(x,y);
//	int xi = round(x);
//	int yi = round(y);
//	this->setXc(xi);
//	this->setYc(yi);

//}


//}
