/*
 * ZonaTablero.h
 *
 *  Created on: 30/08/2013
 *      Author: jonathan
 */

#ifndef ZONATABLERO_H_
#define ZONATABLERO_H_

#include "ZonaDragAndDrop.h"
#include <list>
#include "../../vista/figura/FiguraView.h"
#include <map>
#include "../../modelo/Observer.h"
#include <src/observer/ObserverModelo.h>
using namespace std;


class ZonaTablero: public Zona, public ObserverModelo{
private:
	bool agregarTemplate(FiguraView * dragueable);
	FiguraView * getFiguraTemplate(float x, float y);
	list<View*> canvas;
	bool remover(View*);
public:
	FiguraView * getVista(float, float);
	bool agregarFigura(FiguraView*);
	ZonaTablero(float, float);
	virtual ~ZonaTablero();
	void dibujarse(list<ViewMsj*> & lista);
	bool removerFigura(FiguraView*);
	bool click(float x, float y);
	bool mouseScroll(float x, float y, int amountScrolled);
//	void notify(Observable* o, event_type t);
	void notifyEvent(ObservableModelo* o, Evento_type t);
};

#endif /* ZONATABLERO_H_ */

