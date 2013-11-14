/*
 * FactoryView.h
 *
 *  Created on: 21/09/2013
 *      Author: jonathan
 */

#ifndef FACTORYVIEW_H_
#define FACTORYVIEW_H_

#include "SDL2/SDL.h"
#include "View.h"

namespace CLIENTE {
class FactoryView: public View {
private:
	SDL_Texture * textura;
	void dibujarFondo(SDL_Renderer *);
	void dibujarBorde(SDL_Renderer * renderer);
	void dibujarBordeIzquierdo(SDL_Renderer* renderer);
	void dibujarBordeDerecho(SDL_Renderer* renderer);
	void dibujarBordeSuperior(SDL_Renderer* renderer);
	void dibujarBordeInferior(SDL_Renderer* renderer);
	void generarConBorde(SDL_Rect & dest);
	void generarSinBorde(SDL_Rect & dest);
public:
	FactoryView(float x, float y, float w, float h, SDL_Texture * textura);
	virtual ~FactoryView();
	void dibujarse(SDL_Renderer*);
	void dibujarse(SDL_Renderer*, SDL_Rect&);
	void update(ViewMsj *);
	typedef struct RGBFactory{
	    int r;
	    int g;
	    int b;
	} RGB;
	bool isUpdated();
};

const struct FactoryView::RGBFactory CBORDE_EXTERNO = {94,139,0};
const struct FactoryView::RGBFactory CBORDE_INTERNO = {22, 41, 28};
}
#endif /* FACTORYVIEW_H_ */

