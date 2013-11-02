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
protected:
	float xDesde,yDesde,xHasta,yHasta;
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
