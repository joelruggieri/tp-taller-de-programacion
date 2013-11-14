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
#include "src/mensajes/viewMensaje/ViewObjetoUnionUpdateMsj.h"
namespace CLIENTE {
class UnionView: public ObjetoView {
private:
	typedef ObjetoView super;
//	void dibujarse(SDL_Renderer* renderer, SDL_Rect& src, SDL_Rect& dest);
protected:
	float xHastal,yHastal, radiol, xcl, ycl;
	int xHastap, yHastap, radiop, xcp, ycp;
	bool estatica;

	void dibujarseCirculoEstatico(SDL_Renderer* ren);
	void dibujarse(SDL_Renderer * ren,Uint8 r,Uint8 g,Uint8 b);
public:
	UnionView(float xDesde,float yDesde,float xHasta, float yHasta,float radio, SDL_Texture * textura);
	virtual ~UnionView();
	void update(ViewMsj *);
	void resizear();

};
}
#endif /* UNIONVIEW_H_ */
