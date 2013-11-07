/*
 * Scroll.cpp
 *
 *  Created on: 12/09/2013
 *      Author: jonathan
 */

#include "Scroll.h"
#include <iostream>
#include "../controller/Resizer.h"
#include "../vista/CargadorDeTextures.h"
#include "../vista/FlechaScrollView.h"
#include "../ConstantesVista.h"
using namespace std;
namespace CLIENTE {
Scroll::Scroll(ViewController * controller, Cuadrado* cuerpo, int velocidad,
		int max) {
	this->ultimoClick = 0;

	sup = new Cuadrado(cuerpo->getX(),
			(cuerpo->getY() + cuerpo->getAlto() / 2.0) - 2, cuerpo->getAncho(),
			4);
	inf = new Cuadrado(cuerpo->getX(),
			(cuerpo->getY() - (cuerpo->getAlto() / 2.0)) + 2,
			cuerpo->getAncho(), 4);
	this->posicion = 0;
	this->max = max;
	this->velocidad = velocidad;
	this->controller = controller;
	this->cuerpo = cuerpo;
	crearVista(controller);
}

Scroll::~Scroll() {
	delete sup;
	delete inf;
	delete cuerpo;
}

void Scroll::desplazarBarra(int sentido) {
	int posAnterior = this->posicion;
	int corrimiento = this->velocidad * sentido;
	this->ultimoClick = corrimiento;
	this->posicion = corrimiento + this->posicion;

	//Valido que no se pase de los maximos.
	if (this->posicion > this->max)
		this->posicion = this->max;
	if (this->posicion < 0)
		this->posicion = 0;

	corrimiento = this->posicion - posAnterior;
	this->controller->scrollUnidadesLogicas(corrimiento);
}

bool Scroll::click(float x, float y) {
	Cuadrado * fig =
			sup->contacto(x, y) ? sup : (inf->contacto(x, y) ? inf : NULL);
	if (fig != NULL) {
		int idUpdate = fig == sup ? ID_SCROLL_ARRIBA : ID_SCROLL_ABAJO;
		int signado = (sup == fig ? -1 : 1);
		this->desplazarBarra(signado);
		FlechaScrollView* flecha = (FlechaScrollView*) controller->getForUpdate(
				idUpdate);
		if (flecha != NULL) {
			flecha->accionar();
		}
		controller->endUpdate();
		return true;
	}
	//cout<< "SCROL: " << getScrollPixels()<< endl;
	return false;
}

bool Scroll::mouseScroll(float x, float y, int amountScrolled) {
	bool enContactoZona = cuerpo->contacto(x, y);
	if (enContactoZona) {
		this->desplazarBarra(amountScrolled);
		int idUpdate = amountScrolled < 0 ? ID_SCROLL_ARRIBA : ID_SCROLL_ABAJO;
		FlechaScrollView* flecha = (FlechaScrollView*) controller->getForUpdate(
				idUpdate);
		if (flecha != NULL) {
			flecha->accionar();
		}
		controller->endUpdate();
		return false;
	}
	return true;
}

float Scroll::getScroll() {
	return this->posicion;
}

void Scroll::addScrolleable(View* vista) {
	this->scrolleables.push_back(vista);
}

int Scroll::getltimoClick() const {
	return this->ultimoClick;
}

void Scroll::crearVista(ViewController* vc) {
	SDL_Texture * texturaFlecha = CargadorDeTextures::Instance()->cargarTexture(
	PATH_VISTA_FLECHA_SCROLL);
	FlechaScrollView * view = new FlechaScrollView(sup->getX(), sup->getY(),
			sup->getAncho(), sup->getAlto(), texturaFlecha, 5);
	controller->addView(ID_SCROLL_ARRIBA, view);
	view = new FlechaScrollView(inf->getX(), inf->getY(), inf->getAncho(),
			inf->getAlto(), texturaFlecha, 5, true);
	controller->addView(ID_SCROLL_ABAJO, view);
}

Cuadrado* Scroll::getCuerpo() {
	return cuerpo;
}

}
