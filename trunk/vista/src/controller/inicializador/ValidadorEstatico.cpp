/*
 * ValidadorEstatico.cpp
 *
 *  Created on: 07/10/2013
 *      Author: jonathan
 */

#include "ValidadorEstatico.h"


ValidadorEstatico::~ValidadorEstatico() {
}

void ValidadorEstatico::visit(Motor* f) {
	if(!validarPosicion(f)){
		return;
	}
}

void ValidadorEstatico::visit(Plataforma* f) {
	if(!validarPosicion(f)){
		return;
	}

}

void ValidadorEstatico::visit(Balancin* f) {
	if(!validarPosicion(f)){
		return;
	}

}

void ValidadorEstatico::visit(CintaTransportadora* f) {
	if(!validarPosicion(f)){
		return;
	}

}

void ValidadorEstatico::visit(BolaBoliche* f) {
	if(!validarPosicion(f)){
		return;
	}

}

void ValidadorEstatico::visit(PelotaJuego* f) {
	if(!validarPosicion(f)){
		return;
	}

}

bool ValidadorEstatico::validarPosicion(Figura*f) {
	this->ultimaValidacion  = f->getX() <= xmax && f->getX() >= xmin && f->getY() <= ymax && f->getY() >= ymin;
	this->errorValidacion = "Posicion invalida";
	return ultimaValidacion;
}

ValidadorEstatico::ValidadorEstatico(float xmin, float xmax, float ymin,
		float ymax) {
	this->xmin= xmin;
	this->xmax= xmax;
	this->ymin= ymin;
	this->ymax= ymax;
	errorValidacion= "";
	ultimaValidacion= true;
}


void ValidadorEstatico::visit(GloboHelio*f){
	if(!validarPosicion(f)){
		return;
	}

}

string ValidadorEstatico::getErrorValidacion() {
	return this->errorValidacion;
}

bool ValidadorEstatico::isValido() {
	 return this->ultimaValidacion;
}

void ValidadorEstatico::validar(Figura* f) {
	f->acept(this);
}

void ValidadorEstatico::visit(Engranaje* engranaje) {
	if(!validarPosicion(engranaje)){
		return;
	}
}
