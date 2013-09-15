/*
 * Scroll.cpp
 *
 *  Created on: 12/09/2013
 *      Author: jonathan
 */

#include "Scroll.h"
#include <iostream>
#include "../controller/Resizer.h"
using namespace std;
Scroll::Scroll(Figura * flechaSup, Figura* flechaInf,int velocidad, int max) {
	this->ultimoClick = 0;
	float x = (flechaSup->getX() + flechaInf->getX())/2;
	float y = (flechaSup->getY() + flechaInf->getY())/2;
	this->figura = new FiguraCompuesta(x,y);
	this->figura->addFigura(flechaSup);
//	flechaSup->setRotacion(0);
//	flechaInf->setRotacion(90);
	this->figura->addFigura(flechaInf);
	this->signado.insert(pair<Figura*,int>(flechaSup,1));
	this->signado.insert(pair<Figura*,int>(flechaInf,-1));
	this->posicion = max;
	this->max = max;
	this->velocidad = velocidad;
}

Scroll::~Scroll() {
	delete this->figura;
}

bool Scroll::click(float x, float y) {
	Figura * fig = this->figura->getFiguraEn(x,y);
	bool resultado = false;

	if(fig != NULL){
		int posAnterior = this->posicion;
		int corrimiento = this->velocidad * this->signado.find(fig) ->second;
		this->ultimoClick = corrimiento;
		this->posicion = corrimiento + this->posicion;
		resultado = true;
		if(this->posicion > this->max){
			this->posicion = this->max;

		}
		if(this->posicion < 0){
			this->posicion = 0;
		}
			corrimiento = this->posicion - posAnterior;
		this->actualizarVistas(corrimiento);

		this->notifY();
	}
	//cout<< "SCROL: " << getScrollPixels()<< endl;
	return resultado;
}

int Scroll::getScrollPixels() {
	return Resizer::Instance()->resizearDistanciaLogicaX(this->posicion);
}

float Scroll::getScroll() {
	return this->max - this->posicion;
}

void Scroll::addScrolleable(View* vista) {
	this->scrolleables.push_back(vista);
}

void Scroll::actualizarVistas(int corrimiento) {
	list<View*>::iterator it;
	View *vista;

	for(it= scrolleables.begin(); it!= scrolleables.end(); ++it){
		vista = *it;
		vista->desplazarCentroA(vista->getXCentro(), vista->getYCentro() + Resizer::Instance()->resizearDistanciaLogicaX(corrimiento));
	}
}


int Scroll::getltimoClick() const {
	return this->ultimoClick;
}
