/*
 * FlechaScrollView.h
 *
 *  Created on: 14/09/2013
 *      Author: jonathan
 */

#ifndef FLECHASCROLLVIEW_H_
#define FLECHASCROLLVIEW_H_
#include "SDL2/SDL.h"
#include "View.h"
class FlechaScrollView: public View {
private:
	bool abajo;
	SDL_Texture * textura;
	void inicializar(SDL_Texture * flecha, bool);
	bool presionado;
public:
	FlechaScrollView(int x, int y, int w, int h,SDL_Texture * flecha);
	FlechaScrollView(int x, int y, int w, int h,SDL_Texture * flecha, bool);
	virtual ~FlechaScrollView();
	bool isAbajo() const;
	void setAbajo(bool abajo);
	void dibujarse(SDL_Renderer*);
	void dibujarse(SDL_Renderer*, SDL_Rect & dest);
	void setPresionado(bool presionado);
	bool isPresionado() const;
	void resizear();
};

#endif /* FLECHASCROLLVIEW_H_ */
