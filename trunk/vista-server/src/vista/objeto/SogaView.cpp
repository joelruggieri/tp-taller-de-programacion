/*
 * Sogaview.cpp
 *
 *  Created on: Oct 5, 2013
 *      Author: matias
 */

#include "SogaView.h"
#include "../../controller/editor/EditorUnion.h"
#include <src/objeto/Soga.h>
#include "src/mensajes/viewMensaje/ViewObjetoUnionUpdateMsj.h"
SogaView::SogaView(float x, float y, EditorUnion * editor) :
		UnionView(x, y, editor) {
}

void SogaView::dropTemplate() {
	//controller->dropNuevaFigura(this);
}

EditorNivel* SogaView::getEditor() {
	EditorUnion* editor = (EditorUnion*) controller;
	editor->setFigura(this);
	return editor;
}

SogaView::~SogaView() {
	// TODO Auto-generated destructor stub
}

void SogaView::dibujarse(list<ViewMsj *> & lista) {
	Soga* figura = (Soga*) this->getModelo();
	ViewObjetoUnionUpdateMsj* viewMensaje;
	if(figura != NULL)
		viewMensaje = new ViewObjetoUnionUpdateMsj(figura->getXInicial(),figura->getYFinal(),figura->getXFinal(),figura->getYFinal(),this->getId());
	else
		viewMensaje = new ViewObjetoUnionUpdateMsj(this->xDesde,this->yDesde,this->xHasta,this->yHasta,this->getId());
	lista.push_back(viewMensaje);
}
