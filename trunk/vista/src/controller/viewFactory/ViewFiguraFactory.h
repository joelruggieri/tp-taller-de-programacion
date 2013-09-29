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
	SDL_Texture * textura;
	DropController * controller;
public:
	ViewFiguraFactory(string path, DropController * controller);
	virtual ~ViewFiguraFactory();
	virtual FiguraView * crear(int,int,int,int)=0;
	virtual View * crearVistaPropia(int,int,int,int) = 0;
	float getAlto() const;
	void setAlto(float alto);
	float getAncho() const;
	void setAncho(float ancho);
};

#endif /* VIEWFIGURAFACTORY_H_ */
