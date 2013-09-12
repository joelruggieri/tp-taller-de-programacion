/*
 * Rotacion.cpp
 *
 *  Created on: 11/09/2013
 *      Author: jonathan
 */

#include "Rotacion.h"
#include <cmath>
#include <iostream>
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
	this->angulo = 0;
	this->rotaciones = 0;
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
    if(xN == this->x0 && this->y0 == yN){
    	return 0;
    }
	//calculo la componente z del producto vectorial entre ambos para saber la direccion.
	double direccion = this->y0 * xN -  this->x0 * yN ;
//	direccion = direccion;
	direccion = direccion >0 ? 1 : -1;
	this->angulo = direccion * acos(this->x0 * xN + this->y0 * yN) * 180 / 3.14;
	cout << "Vector inicial " << this->x0 << ":" << this->y0 << endl;
	cout << "Vector final " << xN << ":" << yN << endl;
	cout << "rotacion " << angulo<< endl;
	this->x0 = xN;
	this->y0 = yN;
	return this->angulo;
}

double Rotacion::getAngulo() const {
	return angulo;
}

Rotacion::~Rotacion() {
	// TODO Auto-generated destructor stub
}

