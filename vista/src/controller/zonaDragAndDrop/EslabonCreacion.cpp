/*
 * EslabonCreacion.cpp
 *
 *  Created on: 29/08/2013
 *      Author: jonathan
 */

#include "EslabonCreacion.h"
#include <iostream>
#include "../Resizer.h"
using namespace std;

EslabonCreacion::EslabonCreacion(ViewFiguraFactory * factory, Cuadrado * cuerpo, int maxItems){
	this->factory = factory;
	this->siguiente = NULL;
	this->cuerpo = cuerpo;
	this->itemsDisponibles  = maxItems;
	//TODO: Adaptar posicion con resizer.
	int x = Resizer::Instance()->resizearDistanciaX(cuerpo->getX());
	int y =(400/120) * cuerpo->getY() ;
	this->vista = this->factory->crearVistaPropia(x , y, (400/150) * this->cuerpo->getAncho(),(400/120)* this->cuerpo->getAlto());
}
//
EslabonCreacion::~EslabonCreacion() {
	if(this->siguiente != NULL)
	delete this->siguiente;
	delete factory;
	delete this->cuerpo;
}
//
void EslabonCreacion::setSiguiente(EslabonCreacion* sig) {
	this->siguiente = sig;
}
//
FiguraView * EslabonCreacion::antender(float posX, float posY) {
	if(this->cuerpo->contacto(posX, posY)){
//		if(this->itemsDisponibles >0){
			this->itemsDisponibles--;
			//TODO LLAMAR AL ADAPTADOR DE COORDENADAS
			int x = (400/150) * posX;
			int y =(400/120) * posY;
			return this->factory->crear(x, y,(400/150) * this->cuerpo->getAncho(),(400/120)* this->cuerpo->getAlto());
//		} else {
//			return NULL;
//		}
	}
	if(this->siguiente != NULL){
		return this->siguiente->antender(posX, posY);
	}
	return NULL;
}


void EslabonCreacion::dibujarse(SDL_Renderer* renderer) {
	this->vista->dibujarse(renderer);
	if(this->siguiente != NULL){
		return this->siguiente->dibujarse(renderer);
	}
}
