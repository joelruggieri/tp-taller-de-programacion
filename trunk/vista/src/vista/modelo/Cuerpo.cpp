/*
 * Cuerpo.cpp
 *
 *  Created on: 29/08/2013
 *      Author: jonathan
 */

#include "Cuerpo.h"

Cuerpo::Cuerpo(float posX,float posY,float ancho,float alto) {
	this->posX = posX;
	this->posY = posY;
	this->alto = alto;
	this->ancho = ancho;

}
Cuerpo::Cuerpo(const Cuerpo& other){
	this->posX = other.posX;
	this->posY = other.posY;
	this->alto = other.alto;
	this->ancho = other.ancho;
}
Cuerpo::Cuerpo (){
	this->posX = 0;
	this->posY = 0;
	this->alto = 0;
	this->ancho = 0;
}
Cuerpo::~Cuerpo() {
	// TODO Auto-generated destructor stub
}


bool Cuerpo::isAdentro(float posX, float posY) {
	return this->isAdentro1D(posX, this->posX, this->ancho) &&
			this->isAdentro1D(posY, this->posY, this->alto);
}

bool Cuerpo::isAdentro1D(float pos, float posCentro, float ancho) {
	return (pos <= (posCentro + ancho/2)) && (pos >= posCentro - ancho/2);

}

bool Cuerpo::isAdentro(const Cuerpo& cuerpo){
	// si el centro del cuerpo esta dentro de este, entonces esta dentro.
	 return isAdentro(cuerpo.posX,cuerpo.posY);
}
