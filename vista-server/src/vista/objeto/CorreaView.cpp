/*
 * CorreaView.cpp
 *
 *  Created on: 15/10/2013
 *      Author: joel
 */

#include "CorreaView.h"
#include "../../controller/editor/EditorUnion.h"
#include "src/objeto/Correa.h"
#include "src/mensajes/viewMensaje/ViewObjetoUnionUpdateMsj.h"
#include "src/ConstantesComunicacion.h"
#include <cmath>
#define PI 3.14159265

CorreaView::CorreaView(float x, float y, EditorUnion* editor) :
		UnionView(x, y, editor, OBJ_UNION_S_CORREA) {

}

CorreaView::~CorreaView() {
	// TODO Auto-generated destructor stub
}

EditorNivel* CorreaView::getEditor() {
	EditorUnion * editor = (EditorUnion *) controller;
	editor->setFigura(this);
	return editor;
}

void CorreaView::dropTemplate() {

}

void CorreaView::dibujarse(list<ViewMsj*> & lista) {
	Correa* figura = (Correa*) this->getModelo();
	ViewObjetoUnionUpdateMsj* viewMensaje;
	if (figura != NULL)
		viewMensaje = new ViewObjetoUnionUpdateMsj(figura->getXInicial(), figura->getYInicial(), figura->getXFinal(),
				figura->getYFinal(), figura->getRadioInicial(), figura->getRadioFinal(), figura->estaEstatica(),false,
				figura->getRadio(), this->getId(), this->selector);
	lista.push_back(viewMensaje);
}

