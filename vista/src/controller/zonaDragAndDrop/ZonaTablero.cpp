/*
 * ZonaTablero.cpp
 *
 *  Created on: 30/08/2013
 *      Author: jonathan
 */

#include "ZonaTablero.h"
#include "../Resizer.h"
#include "../../vista/Canvas.h"

//TODO UN CUADRADO DE 100X100 CENTRADO EN X,Y
ZonaTablero::ZonaTablero(Mapa * mapa, float x, float y , SDL_Texture * imagenFondo):Zona(new Cuadrado(x,y,100,100)) {
	this->mapa = mapa;
	Resizer * instance = Resizer::Instance();
	//TODO HARCODEADA LA ALTURA DE LA BARRA DE HERRAMIENTAS
	int xC = instance->resizearDistanciaLogicaX(x);
	int yC =instance->resizearDistanciaLogicaY(y);
	int wC = instance->resizearDistanciaLogicaX(100);
	int hC =instance->resizearDistanciaLogicaY(100);
	this->fondo = new Canvas(xC,yC,wC,hC,imagenFondo);
}

bool ZonaTablero::agregarTemplate(FiguraView* view) {
	if(view->getModelo() == NULL){
		return false;
	}
	this->figuras.push_back(view);
//	this->mapa->addFigura(view->getModelo());
	return true;
}

bool ZonaTablero::clickTemplate(float x, float y) {
	std::list<FiguraView*>::const_iterator iterator;
	FiguraView* result = NULL;
	//TODO ACA SI ANDA MAL HABRÍA QUE HACER UNA DIVISION DE ARBOL PARA IR UBICANDO BINARIO.
	for (iterator = figuras.begin(); iterator != figuras.end(); ++iterator) {
	    Figura * c =(*iterator)->getModelo();
	    if(c->contacto(x,y)){
	    	result = *iterator;
	    	break;
	    }
	}
	if(result != NULL){
		figuras.remove(result);
		result->click(x,y);
		//TODO DARLE CLICK A LA FIGURA Y NO REMOVERLA, TIENE QUE HACERLO EL CONTROLLER DE DRAG AND DROP
	}

	return result;
}

ZonaTablero::~ZonaTablero() {
	std::list<FiguraView*>::const_iterator iterator;
	for (iterator = figuras.begin(); iterator != figuras.end(); ++iterator) {
		delete *iterator;
	}

	delete this->mapa;
}

void ZonaTablero::dibujarse(SDL_Renderer* renderer) {
	this->fondo->dibujarse(renderer);
}

bool ZonaTablero::removerFigura(FiguraView* figura) {
	int unsigned cantInicial = this->figuras.size();
	this->figuras.remove(figura);
	return cantInicial != figuras.size();
}
