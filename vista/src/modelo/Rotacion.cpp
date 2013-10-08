/*
 * Rotacion.cpp
 *
 *  Created on: 11/09/2013
 *      Author: jonathan
 */

#include "Rotacion.h"
#include <cmath>
#include <iostream>
#include "src/Logger.h"
#include <string>
using namespace std;

Rotacion::Rotacion(int x, int y, int x0, int y0, float anguloI) {
	this->xc = x;
	this->yc = y;
	this->x0 = x0 - x;
	this->y0 = y0 - y;
	// normalizo
	float norma = sqrt(this->x0 * this->x0 + this->y0 * this->y0);
	this->x0 = this->x0 / norma;
	this->y0 = this->y0 / norma;
	if(isnan(this->x0) || isnan(this->y0)){
		this->x0 = 1;
		this->y0 = 0;
//		cout<<"se dio el error" <<endl;
	}

	this->angulo = 0;
	this->rotaciones = 0;
}

void Rotacion::loggear(double xN, double yN) {
	Logger log;
	string msj = "Vector Inicial ";
	log.concatenar(msj, this->x0);
	msj = msj + ":";
	log.concatenar(msj, this->y0);
	log.debug(msj);
	msj = "Vector final ";
	log.concatenar(msj, xN);
	msj = msj + ":";
	log.concatenar(msj, yN);
	log.debug(msj);
	msj = "Rotacion ";
	log.concatenar(msj, angulo);
	log.debug(msj);
}

double Rotacion::rotar(double x, double y) {
	//de cada 10 vcs que se le dice rotar, el tipo rota
//traslada el vector al centro.
	double xN = x - xc;
	double yN = y - yc;
	//normalizo eso
	double norma2 = sqrt(xN * xN + yN * yN);
	xN = xN / norma2;
	yN = yN / norma2;


	if(isnan(xN) || isnan(yN)){
//		cout<<"se dio el error" <<endl;
    	return 0;
    }
	//calculo la componente z del producto vectorial entre ambos para saber la direccion.
	 direccion = this->y0 * xN -  this->x0 * yN ;
//	direccion = direccion;
	direccion = direccion >0 ? 1 : -1;
	this->angulo = direccion * acos(this->x0 * xN + this->y0 * yN) * 180 / 3.14;
	loggear(xN, yN);
	this->x0 = xN;
	this->y0 = yN;
	if(isnan(angulo)){
		angulo = 0;
//		cout<<"se dio el error" <<endl;
	}
	return this->angulo;
}

double Rotacion::getAngulo() const {
	return angulo;
}

double Rotacion::getDireccion() const {
	return direccion;
}

Rotacion::~Rotacion() {
	// TODO Auto-generated destructor stub
}

void Rotacion::setAngulo(double angulo) {
	this->direccion =  this->angulo - angulo;
	this->angulo = angulo;
}
