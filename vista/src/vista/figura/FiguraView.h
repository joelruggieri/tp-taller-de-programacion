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

namespace CLIENTE {
class FiguraView: public View, public Observable{
private:
	SDL_Texture * textura;
	typedef View super;
	float angulo;

protected:
	Transformacion tl;
public:
	FiguraView(int x, int y, int w, int h, SDL_Texture* textura);
	virtual ~FiguraView();
	void dibujarse(SDL_Renderer*);
	void dibujarse(SDL_Renderer*, SDL_Rect&);
	SDL_Texture* getTexture();
	void resizear();
	float getAngulo() const;
	void setAngulo(float angulo);
};
}
#endif /* FIGURAVIEW_H_ */
