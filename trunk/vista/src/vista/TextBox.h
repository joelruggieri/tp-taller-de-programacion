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
#define TAM_BUFFER 39
#define BACKSPACE 8
#define TAM_FUENTE 10
#define SHIFT 15

using namespace std;

class TextBox: public Herramientas {
public:
	TextBox(int x, int y, int w, int h, SDL_Texture* imagen) : Herramientas(x, y, w, h){
		this->seleccionado = false ;
		this->shiftIn = false;
		TTF_Init();

		this->imagen = imagen ;
		this->fuente = TTF_OpenFont("resource/Arial Bold.ttf", TAM_FUENTE);
		this->texto = "";
		this->textoCurrent = texto ;

		this->color.a = 50;
		this->color.b = 20;
		this->color.g = 20;
		this->color.r = 200;
		this->surfaceTexto = NULL;
		this->textureTexto = NULL ;
	}
	virtual ~TextBox();
	void dibujarse(SDL_Renderer* render);
	void dibujarse(SDL_Renderer* render, SDL_Rect& dest);
	void agregarCaracter(char caracter);
	void borrarCaracter();
	void setearTexto();
	bool fueSeleccionado(int x, int y);
	void presionarMouse();
	void desPresionarMouse();
	void resetearTexto();
	void ejecutarTecla(char key);
	void clickeoFueraDeHerramienta();
	void desEjecutarTecla() ;
	void resizear();

	string* getTexto();
private:
//	int x,y,w,h;
	SDL_Texture* imagen ;
	TTF_Font* fuente ;
	string texto ;
	string textoCurrent;
	SDL_Color color  ;
	SDL_Surface *surfaceTexto;
	SDL_Texture * textureTexto;
	bool seleccionado ;
	bool shiftIn;



};

#endif /* TEXTBOX_H_ */

