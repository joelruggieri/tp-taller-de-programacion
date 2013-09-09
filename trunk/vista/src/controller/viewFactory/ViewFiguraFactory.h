/*
 * ViewFiguraFactory.h
 *
 *  Created on: 05/09/2013
 *      Author: jonathan
 */

#ifndef VIEWFIGURAFACTORY_H_
#define VIEWFIGURAFACTORY_H_
#include "../../vista/figura/FiguraView.h"
#include "../DropController.h"
#include <string>
#include "SDL2/SDL.h"
using namespace std;

class ViewFiguraFactory {
private:
	SDL_Texture* cargarTexture (const string &file, SDL_Renderer* ren);
protected:
	SDL_Texture * textura;
	DropController * controller;
public:
	ViewFiguraFactory(string path,SDL_Renderer* ren, DropController * controller);
	virtual ~ViewFiguraFactory();
	virtual FiguraView * crear(int,int,int,int)=0;
	virtual FiguraView * crearVistaPropia(int,int,int,int) = 0;
	float getAlto() const;
	void setAlto(float alto);
	float getAncho() const;
	void setAncho(float ancho);
};

#endif /* VIEWFIGURAFACTORY_H_ */
