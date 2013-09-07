/*
 * TextBox.h
 *
 *  Created on: 02/09/2013
 *      Author: ezequiel
 */

#ifndef TEXTBOX_H_
#define TEXTBOX_H_
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL.h"
#include <iostream>
#include "Dibujable.h"
#include "Resizeable.h"
#include "Seleccionable.h"
using namespace std;


namespace std {

class TextBox : public Dibujable, public Resizeable, public Seleccionable {
public:
	TextBox(int x, int y, int h, int w, SDL_Texture* textura, SDL_Renderer* render) : Dibujable(x,y,h,w,textura,render)
	{
		TTF_Init();
		font = TTF_OpenFont("Arial Bold.ttf", 10);
			colorTexto.b = 255;
			colorTexto.g = 255;
			colorTexto.r = 255;
			colorBackGroundTexto.b = 0;
			colorBackGroundTexto.r = 0;
			colorBackGroundTexto.g = 0;

			TTF_SizeText(font,"a", &w, &h);
			snprintf(buf,256," Escriba su texto aqui ");
	}
	virtual ~TextBox();
	void Dibujarse();
	void Resizear(int x, int y);
	int EditarTextBox(char letra);
	//bool FueSeleccionado(int x, int y);

private:
	TTF_Font *font;
	SDL_Color colorTexto;
	SDL_Color colorBackGroundTexto;
	string texto;
	char buf[20] ;
	SDL_Surface* superficieText;



};

} /* namespace std */
#endif /* TEXTBOX_H_ */
