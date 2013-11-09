/*
 * ObjetoView.cpp
 *
 *  Created on: 28/09/2013
 *      Author: jonathan
 */

#include "ObjetoView.h"
//#include "../comunicacion/src/mensajes/viewMensaje/ViewObjetoUpdateMsj.h"
#include "src/mensajes/viewMensaje/ViewObjetoUpdateMsj.h"
ObjetoView::ObjetoView(float x, float y, DropController * controller, char selector): FiguraView(x, y, controller) {
this->selector	= selector;
}

ObjetoView::~ObjetoView() {
	// TODO Auto-generated destructor stub
}

void ObjetoView::dibujarse(list<ViewMsj*> & lista){
	Figura* figura = this->getModelo();
	ViewObjetoUpdateMsj* viewMensaje;
	if(figura == NULL){
		viewMensaje = new ViewObjetoUpdateMsj(getXCentro(),getYCentro(),0,this->getId(), this->selector);
	} else {
		viewMensaje = new ViewObjetoUpdateMsj(figura->getX(),figura->getY(),figura->getRotacion(),this->getId(), this->selector);
	}

	lista.push_back(viewMensaje);

}

char ObjetoView::getSelector() const {
	return selector;
}
