/*
 * UnionView.h
 *
 *  Created on: 16/10/2013
 *      Author: jonathan
 */

#ifndef UNIONVIEW_H_
#define UNIONVIEW_H_

#include "ObjetoView.h"
#include "SDL2/SDL.h"

namespace CLIENTE {
class UnionView: public ObjetoView {
private:
	typedef ObjetoView super;
//	void dibujarse(SDL_Renderer* renderer, SDL_Rect& src, SDL_Rect& dest);
protected:
	int xDesde,yDesde,xHasta,yHasta;
	void dibujarse(SDL_Renderer * ren,Uint8 r,Uint8 g,Uint8 b);
	void dibujarseEstatica(SDL_Renderer* ren);
public:
	UnionView(int x, int y, SDL_Texture * textura);
	virtual ~UnionView();
	void update(ViewMsj *);
	void resizear();
	int getLayer();
};
}
#endif /* UNIONVIEW_H_ */
