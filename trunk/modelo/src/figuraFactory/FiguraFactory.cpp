/*
 * FiguraFactory.cpp
 *
 *  Created on: 04/09/2013
 *      Author: jonathan
 */

#include "FiguraFactory.h"
#include "../figura/Cuadrado.h"
#include "../figura/Circulo.h"
#include "../figura/Triangulo.h"

FiguraFactory::FiguraFactory() {
	// TODO Auto-generated constructor stub

}

FiguraFactory::~FiguraFactory() {
	// TODO Auto-generated destructor stub
}

Figura* FiguraFactory::crearCuadrado() {
	return new Cuadrado(1,1,1,1);
}

Figura* FiguraFactory::crearCirculo() {
	return new Circulo(1,1,1);
}

Figura* FiguraFactory::crearTriangulo() {
	return new Triangulo();
}