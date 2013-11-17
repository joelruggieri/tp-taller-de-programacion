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
		UnionView(x, y, editor, OBJ_UNION_S_SOGA) {
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

	if(figura != NULL && figura->isViva()){
		viewMensaje = new ViewObjetoUnionUpdateMsj(figura->getXInicial(),figura->getYInicial(),figura->getXFinal(),figura->getYFinal(),0,0,figura->estaEstatica(),figura->conEslabon(),figura->getRadio(),this->getId(), this->selector);
		if(figura->conEslabon()){
			viewMensaje->setPosEslabon(figura->getXEslabon(),figura->getYEslabon());
			viewMensaje->setActivoPrimerTramo(figura->activoPrimerTramo());
			viewMensaje->setActivoSegundoTramo(figura->activoSegundoTramo());
		}
//	else	idem correaView
//		viewMensaje = new ViewObjetoUnionUpdateMsj(this->xDesde,this->yDesde,this->xHasta,this->yHasta,this->getId(), this->selector);
	lista.push_back(viewMensaje);
	}
}
