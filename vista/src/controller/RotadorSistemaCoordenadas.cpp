/*
 * RotadorSistemaCoordenadas.cpp
 *
 *  Created on: 19/09/2013
 *      Author: jonathan
 */

#include "RotadorSistemaCoordenadas.h"
#include <cmath>
#include "Resizer.h"
RotadorSistemaCoordenadas::RotadorSistemaCoordenadas() {
	// TODO Auto-generated constructor stub

}

RotadorSistemaCoordenadas::~RotadorSistemaCoordenadas() {
	// TODO Auto-generated destructor stub
}

void RotadorSistemaCoordenadas::rotar(Figura* figura, double& x, double& y) {
	Resizer* r = Resizer::Instance();
	//LLEVO LAS COORDENADAS AL MUNDO PIXEL:
	int xp = r->resizearDistanciaLogicaX(x);
	int yp = r->resizearPosicionLogicaY(y);

	int yc = r->resizearPosicionLogicaY(figura->getY());
	int xc = r->resizearDistanciaLogicaX(figura->getX());

	//centro en el centro de la figura.

	double rotacionRad = figura->getRotacion() * -3.14 / 180.0;
	x = (xp - xc) * cos(rotacionRad) - (yp - yc) * sin(rotacionRad);
	y = (xp - xc) * sin(rotacionRad) + (yp - yc) * cos(rotacionRad);
	x = r->resizearDistanciaPixelX(x + xc);
	y = r->resizearPosicionPixelY(y + yc);

}
