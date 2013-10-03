/*
 * Transformacion.cpp
 *
 *  Created on: 02/10/2013
 *      Author: jonathan
 */

#include "Transformacion.h"
#include <cmath>
using namespace std;

Transformacion::Transformacion() {
	angulo = 0;
	transx = 0;
	transy = 0;
	escalax = 1;
	escalay = 1;
	x = 0;
	y = 0;
	ejex = 0;
	ejey = 0;
	this->invertirx = false;
	this->invertiry = false;
}

Transformacion::~Transformacion() {
	// TODO Auto-generated destructor stub
}

void Transformacion::rotar(float angulo) {
	this->angulo = angulo;
}

void Transformacion::escalar(float x, float y) {
	this->escalax = x;
	this->escalay = y;

}

void Transformacion::traslacion(float x, float y) {
	this->transx = x;
	this->transy = y;
}

void Transformacion::invertir(bool x, bool y) {
	invertirx = x;
	invertiry = y;
}

void Transformacion::setVector(float x, float y) {
	this->x = x;
	this->y = y;
}

void Transformacion::setEjeRotacion(float x, float y) {
	this->ejex = x;
	this->ejey = y;
}

void Transformacion::getResultado(float& x, float& y) {
	//primero escalo.
	float xActual = this->x * escalax;
	float yActual = this->y * escalay;

	//voy al eje de rotacion, roto, y vuelvo al corrimiento.

	if (angulo != 0) {
		xActual = xActual - ejex;
		yActual = yActual - ejey;
		double rotacionRad = angulo * -3.14 / 180.0;
		float xAux = xActual * cos(rotacionRad) - yActual * sin(rotacionRad);
		float yAux = xActual * sin(rotacionRad) + yActual * cos(rotacionRad);
		xActual = xAux + ejex;
		yActual = yAux + ejey;
	}

	//hago la translacion.
	xActual = xActual - transx;
	yActual = yActual - transy;

	//invierto los ejes si es necesario.
	xActual = invertirx ? xActual * -1 : xActual;
	yActual = invertiry ? yActual * -1 : yActual;
	x = xActual;
	y = yActual;

}

void Transformacion::getResultadoInverso(float& x, float& y) {

	float xActual = this->x;
	float yActual = this->y;

	//invierto los ejes si es necesario.
	xActual = invertirx ? xActual * -1 : xActual;
	yActual = invertiry ? yActual * -1 : yActual;

	//hago la translacion.
	xActual = xActual + transx;
	yActual = yActual + transy;


	//escalo
	xActual = xActual/ escalax;
	yActual = yActual / escalay;

	//voy al eje de rotacion, roto, y vuelvo al corrimiento.

	if (angulo != 0) {
//		xActual = xActual - ejex;
//		yActual = yActual - ejey;
//		double rotacionRad = angulo * -3.14 / 180.0;
//		float xAux = xActual * cos(rotacionRad) - yActual * sin(rotacionRad);
//		float yAux = xActual * sin(rotacionRad) + yActual * cos(rotacionRad);
//		xActual = xAux + ejex;
//		yActual = yAux + ejey;
		// TODO NO SE CALCULAR ESTO AUN.
	}

//	//hago la translacion.
//	xActual = xActual - transx;
//	yActual = yActual - transy;

	x = xActual;
	y = yActual;
}
