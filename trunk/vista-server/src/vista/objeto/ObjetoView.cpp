/*
 * ObjetoView.cpp
 *
 *  Created on: 28/09/2013
 *      Author: jonathan
 */

#include "ObjetoView.h"
#include "../comunicacion/src/mensajes/viewMensaje/ViewObjetoUpdateMsj.h"

ObjetoView::ObjetoView(float x, float y, DropController * controller): FiguraView(x, y, controller) {
	// TODO Auto-generated constructor stub

}

ObjetoView::~ObjetoView() {
	// TODO Auto-generated destructor stub
}

void ObjetoView::dibujarse(list<ViewMsj*> & lista){
	Figura* figura = this->getModelo();
	ViewObjetoUpdateMsj* viewMensaje = new ViewObjetoUpdateMsj(figura->getX(),figura->getY(),figura->getRotacion(),this->getId());
	lista.push_back(viewMensaje);

}

