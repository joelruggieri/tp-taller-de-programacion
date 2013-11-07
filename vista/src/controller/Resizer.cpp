/*
 * Resizer.cpp
 *
 *  Created on: 08/09/2013
 *      Author: ezequiel
 */

#include "src/Logger.h"
#include "Resizer.h"
#include <iostream>
using namespace std;
#include <cmath>
namespace CLIENTE {
Resizer* Resizer::pinstance = 0; // Inicializar el puntero

int Resizer::resizearDistanciaX(int valor) {
	float valorFloat = (float) valor;
	if (valor == 0) {
		return 0;
	}
	return round(this->relacionX * valorFloat);
}

int Resizer::resizearDistanciaLogicaX(float valor) {
	float valorFloat = (float) valor;
	return round(this->relacionXLogica * valorFloat);
}

int Resizer::resizearDistanciaLogicaY(float valor) {
	float valorFloat = (float) valor;
	return round(this->relacionYLogica * valorFloat);
}

float Resizer::resizearDistanciaPixelX(int valor) {
	float valorFloat = (float) valor;
	return (valorFloat / this->relacionXLogica);
}

float Resizer::resizearDistanciaPixelY(int valor) {
	float valorFloat = (float) valor;
	return (valorFloat / this->relacionYLogica);
}

void Resizer::setearResizer(int xNuevo, int yNuevo) {
	this->xViejo = this->xNuevo;
	this->yViejo = this->yNuevo;
	this->xNuevo = xNuevo;
	this->relacionX = this->xNuevo / this->xViejo;
	this->relacionX = this->xNuevo / this->xViejo;
	this->yNuevo = yNuevo;
	this->relacionX = (float) this->xNuevo / (float) this->xViejo;
	this->relacionY = (float) this->yNuevo / (float) this->yViejo;
	this->relacionXLogica = (float) this->xNuevo / (float) this->xLogico;
	this->relacionYLogica = (float) this->yNuevo / (float) this->yLogico;
	transf.traslacion(0, 100);
	transf.escalar(getRelacionX(), getRelacionY());
	transf.invertir(false, true);
}

int Resizer::resizearDistanciaY(int valor) {
	if (valor == 0) {
		return 0;
	}

	return round(this->relacionY * valor);
}

int Resizer::resizearPosicionY(int valor) {
	return round(this->relacionY * valor);
}

void Resizer::quitarResizeable(Resizeable* resizeable) {
	this->resizeables.remove(resizeable);
}

void Resizer::resizearResizeables() {
	transf.traslacion(0, 100);
	transf.escalar(getRelacionX(), getRelacionY());
	transf.invertir(false, true);
	list<Resizeable*>::iterator iter;
	for (iter = this->resizeables.begin(); iter != this->resizeables.end();
			iter++) {
		(*iter)->resizear();

	}
}

float Resizer::resizearPosicionPixelY(int valor) {
	int yPixel = valor;
	float valorFloat = (float) yPixel;
	return (valorFloat / this->relacionYLogica);
}

int Resizer::resizearPosicionLogicaY(float valor) {
	int yPixel = round(this->relacionYLogica * valor);
	return yPixel;
}

Resizer::Resizer(int x, int y, float xLogico, float yLogico) {
	this->xViejo = x;
	this->yViejo = y;
	this->xNuevo = x;
	this->yNuevo = y;
	this->relacionX = 1;
	this->relacionY = 1;
	this->xLogico = xLogico;
	this->yLogico = yLogico;
	this->relacionXLogica = (float) this->xNuevo / (float) this->xLogico;
	this->relacionYLogica = (float) this->yNuevo / (float) this->yLogico;
	transf.traslacion(0, 100);
	transf.escalar(getRelacionX(), getRelacionY());
	transf.invertir(false, true);
	transf.setVector(0, 0);

}

int Resizer::getAltoPantalla() {
	return this->yNuevo;
}

void Resizer::addResizeable(Resizeable* resizeable) {
	this->resizeables.push_back(resizeable);
}

void Resizer::adaptarPosicionLogica(float x, float y, int& xNuevo,
		int& yNuevo) {
	xNuevo = this->resizearDistanciaLogicaX(x);
	yNuevo = this->resizearPosicionLogicaY(y);

}

void Resizer::adaptarDimensionLogica(float w, float h, int& wNuevo,
		int& hNuevo) {
	wNuevo = this->resizearDistanciaLogicaX(w);
	hNuevo = this->resizearDistanciaLogicaY(h);

}

void Resizer::adaptarPosicionPixel(int x, int y, float& xNuevo, float& yNuevo) {
	xNuevo = this->resizearDistanciaPixelX(x);
	yNuevo = this->resizearPosicionPixelY(y);
}

void Resizer::adaptarDimensionPixel(int w, int h, float& wNuevo,
		float& hNuevo) {
	wNuevo = this->resizearDistanciaPixelX(w);
	hNuevo = this->resizearDistanciaPixelY(h);
}

float Resizer::getRelacionX() {
	return 1 / this->relacionXLogica;
}

float Resizer::getRelacionY() {
	return 1 / this->relacionYLogica;
}

Transformacion& Resizer::getTransformacionToModelo() {
	transf.setVector(0, 0);
	return this->transf;
}

Transformacion* Resizer::crearTransformacionALogica(int xNuevo,
		int yNuevo) {


	float relacionLogicaPixelX = 120.0 /(float) xNuevo ;
	float relacionLogicaPixelY = 120.0 / (float) yNuevo;
	Transformacion * t = new Transformacion();
	t->traslacion(0, 100.0);
	t->escalar(relacionLogicaPixelX, relacionLogicaPixelY);
	t->invertir(false, true);
	return t;
}

}
