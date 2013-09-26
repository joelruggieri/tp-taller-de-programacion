/*
 * Circulo.cpp
 *
 *  Created on: 04/09/2013
 *      Author: jonathan
 */

#include "Circulo.h"
#include "VisitorFigura.h"

Circulo::Circulo(): Figura(0,0,0) {
	this->radio = 0;
}

Circulo::Circulo(float x, float y, Rotador * rotador, float radio):Figura(x,y,rotador) {
	this->radio = radio;

}

Circulo::Circulo(const Circulo& figura){
	this->x = figura.getX();
	this->y = figura.getY();
	this->setRotacion(figura.getRotacion());
	this->rotador = figura.rotador;
	this->radio = figura.getRadio();

}

float Circulo::getRadio() const {
	return radio;
}

void Circulo::setRadio(float radio) {
	this->radio = radio;
}

Circulo::~Circulo() {
	// TODO Auto-generated destructor stub
}

bool Circulo::contacto(float x, float y) {
	float cx = this->getX();
	float cy = this->getY();
	double xAux = x;
	double yAux = y;
	if(this->getRotacion() != 0){
		this->rotador->rotar(this,xAux,yAux);
	}
	//Distancia al punto
	float SqrDist = ((cx - xAux) * (cx - xAux)) + ((cy - yAux) * (cy - yAux));
	float SqrRadius = radio * radio;
	return (SqrDist <= SqrRadius);
}

bool Circulo::contieneCentro(Posicionable* cuadrado) {
	return false;
}

void Circulo::acept(VisitorFigura* visitor) {
	visitor->visit(this);
}

float Circulo::getAlto() const {
	return radio * 2;
}

float Circulo::getAncho() const {
	return radio * 2;
}
