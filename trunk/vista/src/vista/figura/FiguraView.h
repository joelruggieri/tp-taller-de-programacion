/*
 * FiguraView.h
 *
 *  Created on: 04/09/2013
 *      Author: jonathan
 */

#ifndef FIGURAVIEW_H_
#define FIGURAVIEW_H_
#include <iostream>
#include "../View.h"
#include "SDL2/SDL.h"
#include "../../modelo/Observable.h"
using namespace std;
#include "../../ConstantesVista.h"
namespace CLIENTE {
class FiguraView: public View, public Observable{
private:
	SDL_Texture * textura;
	int numeroEvento;
	typedef View super;

protected:
	float angulo;
public:
	FiguraView(float x, float y, float w, float h,int layer,int numeroEvent,SDL_Texture* textura);
	virtual ~FiguraView();
	virtual void dibujarse(SDL_Renderer*);
	void dibujarse(SDL_Renderer*, SDL_Rect&);
	SDL_Texture* getTexture();
	void resizear();
	float getAngulo() const;
	void setAngulo(float angulo);
	int getNumeroEvento() const;
};
}
#endif /* FIGURAVIEW_H_ */
