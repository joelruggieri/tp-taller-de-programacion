/*
 * Jugador.cpp
 *
 *  Created on: 27/10/2013
 *      Author: jonathan
 */

#include "Jugador.h"

Jugador::Jugador() {
	area= new Area(50,50,100,100);
	numero = 0;
}

Area* Jugador::getArea() {
	return area;
}

int Jugador::getNumero() {
	return numero;
}

Jugador::~Jugador() {
	delete area;
}

