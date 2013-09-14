/*
 * FiguraCompuesta.cpp
 *
 *  Created on: 12/09/2013
 *      Author: jonathan
 */

#include "FiguraCompuesta.h"
#include <iostream>
using namespace std;

FiguraCompuesta::FiguraCompuesta(float x, float y) :
	Figura(x, y) {
}

FiguraCompuesta::~FiguraCompuesta() {
	list<Figura*>::iterator it;
	for (it = this->figuras.begin(); it != figuras.end(); ++it) {
		delete *it;
	}
}

bool FiguraCompuesta::contacto(float x, float y) {
	bool contacto = false;
	list<Figura*>::iterator it;
	for (it = this->figuras.begin(); it != figuras.end() && !contacto; ++it) {
		contacto = (*it)->contacto(x, y);
	}
	return contacto;
}

bool FiguraCompuesta::contieneCentro(Posicionable* figura) {
	return this->contacto(figura->getX(), figura->getY());
}

void FiguraCompuesta::addFigura(Figura* figura) {
	this->figuras.push_back(figura);
}

Figura* FiguraCompuesta::getFiguraEn(float x, float y) {
	list<Figura*>::iterator it;
	for (it = this->figuras.begin(); it != figuras.end(); ++it) {
		if ((*it)->contacto(x, y)) {
			return *it;
		}
	}
	return NULL;
}

void FiguraCompuesta::acept(VisitorFigura*) {

}
