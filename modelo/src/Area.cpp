/*
 * Area.cpp
 *
 *  Created on: 04/09/2013
 *      Author: jonathan
 */

#include "Area.h"
#include <cmath>

Area::Area(float x, float y, float ancho, float alto) {
	this->ancho = ancho;
	this->alto = alto;
	this->x = x;
	this->y = y;
}

Area::Area() {
	this->x = 0;
	this->y = 0;
	this->ancho = 1;
	this->alto = 1;
}


void Area::setAlto(float alto){
	this->alto = alto;

}

void Area::setAncho(float ancho){
	this->ancho = ancho;

}

float Area::getAlto() const {
	return alto;

}

float Area::getAncho() const{
	return ancho;

}
Area::~Area() {
	// TODO Auto-generated destructor stub
}


bool Area::contacto(float posX, float posY) {
	double xc = posX;
	double yc= posY;
//	if(this->getRotacion() != 0 && rotador != 0){
////		//traslado al centro, roto el punto y pruebo el contacto.
////		xc = posX - this->x;
////		yc = posY - this->y;
////		//roto
////		double rotacionRad = this->getRotacion() *-3.14 /180.0;
////		xc = (posX - this->x) * cos(rotacionRad)- (posY - this->y) * sin(rotacionRad);
////		yc = (posX - this->x) * sin(rotacionRad)+ (posY - this->y) * cos(rotacionRad);
////		xc =xc + this->x;
////		yc=yc + this->y;
//		this->rotador->rotar(this,xc, yc);
//	}

	return this->isAdentro1D(xc, this->x, this->ancho)
			&& this->isAdentro1D(yc, this->y, this->alto);
}

bool Area::contieneCentro(Posicionable* posicion) {
	return this->contacto(posicion->getX(), posicion->getY());
}
bool Area::isAdentro1D(float pos, float posCentro, float ancho) {
	return (pos <= (posCentro + ancho / 2)) && (pos >= posCentro - ancho / 2);

}

float Area::getX() const {
	return x;
}

void Area::setX(float x) {
	this->x = x;
}

float Area::getY() const {
	return y;
}

void Area::setY(float y) {
	this->y = y;
}
