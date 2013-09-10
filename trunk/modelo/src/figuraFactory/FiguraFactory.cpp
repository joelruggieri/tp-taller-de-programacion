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

Figura * FiguraFactory::crearCuadrado(float x,float y){
	return new Cuadrado(x,y,10,10);
}
Figura* FiguraFactory::crearCirculo(float x, float y) {
	return new Circulo(x,y,12);
}

Figura* FiguraFactory::crearTriangulo(float x,float y) {
	return new Triangulo(x,y,10,10);
}
