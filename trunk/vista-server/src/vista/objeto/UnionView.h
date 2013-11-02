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
#include <src/observer/ObserverModelo.h>
class EditorUnion;
class UnionView: public ObjetoView, public ObserverModelo {
private:
	typedef ObjetoView super;
//	void dibujarse(SDL_Renderer* renderer, SDL_Rect& src, SDL_Rect& dest);
protected:
	float xDesde,yDesde,xHasta,yHasta;
	void dibujarse(SDL_Renderer * ren,Uint8 r,Uint8 g,Uint8 b);
	void dibujarseEstatica(SDL_Renderer* ren);
public:
	UnionView(float x, float y, EditorUnion * controller);
	virtual ~UnionView();
	EditorNivel * getEditor();
//	void update();
	void setModelo(Figura * f);
	void notifyEvent(ObservableModelo*, Evento_type);
//	void resizear();
	int getLayer();
};

#endif /* UNIONVIEW_H_ */