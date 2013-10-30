/*
 * ViewFiguraFactory.h
 *
 *  Created on: 05/09/2013
 *      Author: jonathan
 */

#ifndef VIEWFIGURAFACTORY_H_
#define VIEWFIGURAFACTORY_H_
#include "../../vista/figura/FiguraView.h"
#include "../../vista/FactoryView.h"
#include "../DropController.h"
#include <string>
#include "SDL2/SDL.h"
using namespace std;

class ViewFiguraFactory {
protected:
	DropController * controller;
public:
	ViewFiguraFactory(DropController * controller);
	virtual ~ViewFiguraFactory();
	virtual FiguraView * crear(float,float,float,float)=0;
	virtual View * crearVistaPropia(float,float,float,float) = 0;
	float getAlto() const;
	void setAlto(float alto);
	float getAncho() const;
	void setAncho(float ancho);
};

#endif /* VIEWFIGURAFACTORY_H_ */
