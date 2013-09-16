/*
 * TextBox.h
 *
 *  Created on: 14/09/2013
 *      Author: ezequiel
 */

#ifndef TEXTBOX_H_
#define TEXTBOX_H_
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "Herramientas.h"
#include "SDL2/SDL_ttf.h"

#include <iostream>

using namespace std;

class TextBox: public Herramientas {
public:
	TextBox(int x, int y, int w, int h, SDL_Texture* imagen);
	virtual ~TextBox();
	void dibujarse(SDL_Renderer* render);
	void agregarCaracter(char caracter);
	void borrarCaracter();
	void setearTexto();
	bool fueSeleccionado(int x, int y);
	void ejecutar();
	void desEjecutar();

private:
	int x,y,w,h;
	SDL_Texture* imagen ;
	TTF_Font* fuente ;
	string texto ;
	SDL_Color color  ;
	SDL_Surface *surfaceTexto;
	SDL_Texture * textureTexto;
	bool seleccionado ;


};

#endif /* TEXTBOX_H_ */
