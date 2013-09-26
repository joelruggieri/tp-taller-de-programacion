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

void Scroll::desplazarBarra(int sentido){
	int posAnterior = this->posicion;
	int corrimiento = this->velocidad * sentido;
	this->ultimoClick = corrimiento;
	this->posicion = corrimiento + this->posicion;

	//Valido que no se pase de los maximos.
	if(this->posicion > this->max) this->posicion = this->max;
	if(this->posicion < 0) this->posicion = 0;

	corrimiento = this->posicion - posAnterior;
	this->actualizarVistas(corrimiento);

	this->notifY();
}

bool Scroll::click(float x, float y) {
	Figura * fig = this->figura->getFiguraEn(x,y);

	if(fig != NULL){
		this->desplazarBarra(this->signado.find(fig) ->second);
		return true;
	}
	//cout<< "SCROL: " << getScrollPixels()<< endl;
	return false;
}

bool enContacto(float posX, float posY, int xC, int yC, int wC, int hC){
	return (posX <= (xC + wC / 2)) && (posX >= (xC - wC / 2)) && (posY <= (yC + hC / 2)) && (posY >= (yC - hC / 2));
}

bool Scroll::mouseScroll(float x, float y, int amountScrolled, int xC, int yC, int w, int h){
	bool enContactoFlechas = true;
	bool enContactoZona = true;
	if(enContactoFlechas || enContactoZona){
		this->desplazarBarra(amountScrolled);
		//cout << "Se escroleo" <<endl;
		return false;
	}
	return true;
}

//int Scroll::getScrollPixels() {
//	return Resizer::Instance()->resizearDistanciaLogicaY(this->posicion);
//}

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
		vista->desplazarCentroA(vista->getXCentro(), vista->getYCentro() + Resizer::Instance()->resizearDistanciaLogicaY(corrimiento));
	}
}


int Scroll::getltimoClick() const {
	return this->ultimoClick;
}
