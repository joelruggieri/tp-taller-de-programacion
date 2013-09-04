/*
 * TextBox.h
 *
 *  Created on: 02/09/2013
 *      Author: ezequiel
 */

#ifndef TEXTBOX_H_
#define TEXTBOX_H_
#include "SDL2/SDL_ttf.h"
#include <iostream>
#include "Dibujable.h"
#include "Resizeable.h"
using namespace std;


namespace std {

class TextBox : public Dibujable, public Resizeable {
public:
	TextBox(int x, int y, int w, int h, SDL_Texture* imagen, SDL_Renderer* render);
	virtual ~TextBox();
	//void Dibujarse();
	void Resizear(int x, int y);

private:
	TTF_Font *font;
	SDL_Color colorTexto;

	string texto;

	SDL_Surface* superficieText;



};

} /* namespace std */
#endif /* TEXTBOX_H_ */
