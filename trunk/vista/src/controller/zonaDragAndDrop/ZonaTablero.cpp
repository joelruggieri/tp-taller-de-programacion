/*
 * ZonaTablero.cpp
 *
 *  Created on: 30/08/2013
 *      Author: jonathan
 */

#include "ZonaTablero.h"
#include "../Resizer.h"
#include "src/Logger.h"
//ENTREGA3 EN REALIDAD PARA NO ENVIAR BOLUDECES AL SERVER ACA HAY QUE SETEAR EL AREA DEL JUGADOR Y ESA POSICION ENTONCES SOLAMENTE SE ENVIAN LAS COSAS QUE CAEN AHI.

ZonaTablero::ZonaTablero(SDL_Texture * imagenFondo) {
	cuerpo =new Cuadrado(50,50,100,100);
//	Resizer * instance = Resizer::Instance();
//	//TODO HARCODEADA LA ALTURA DE LA BARRA DE HERRAMIENTAS
//	int xC = instance->resizearDistanciaLogicaX(x);
//	int yC =instance->resizearPosicionLogicaY(y);
//	int wC = instance->resizearDistanciaLogicaX(100);
//	int hC =instance->resizearDistanciaLogicaY(100);
//	this->canvas = new Canvas(xC,yC,wC,hC,imagenFondo);
//	this->viewCanvas= new ViewConBorde(canvas);
//	this->viewCanvas->setAjustarTamanio(false);
}

//Canvas* ZonaTablero::getCanvas(){
//	return this->canvas;
//}



ZonaTablero::~ZonaTablero() {
//	std::list<FiguraView*>::const_iterator iterator;
//	delete this->viewCanvas;
}
