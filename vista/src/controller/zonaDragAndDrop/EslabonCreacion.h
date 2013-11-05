/*
 * EslabonCreacion.h
 *
 *  Created on: 29/08/2013
 *      Author: jonathan
 */

#ifndef ESLABONCREACION_H_
#define ESLABONCREACION_H_

#include "../../vista/figura/FiguraView.h"
#include "../viewFactory/ViewFiguraFactory.h"
#include "../../modelo/Cuadrado.h"
#include <string>
using namespace std;

class EslabonCreacion {
private:
	EslabonCreacion * siguiente;
	string tag;
	Cuadrado * cuerpo;
public:
	EslabonCreacion(string tag, Cuadrado *cuerpo);
	virtual ~EslabonCreacion();
	void setSiguiente(EslabonCreacion * sig);
	string atender(float posX, float posY, float corrimientoScroll);
};

#endif /* ESLABONCREACION_H_ */
