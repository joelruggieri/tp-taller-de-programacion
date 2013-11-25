/*
 * ControlRemotoView.cpp
 *
 *  Created on: 17/11/2013
 *      Author: ezequiel
 */

#include "ControlRemotoView.h"
#include "../../controller/editor/SimpleEditorAnguloFijo.h"
#include "../../controller/editor/SimpleEditorOrientacionCambiable.h"
#include "../../ConstantesVista.h"
#include "src/mensajes/viewMensaje/ViewObjetoUpdateMsj.h"
ControlRemotoView::ControlRemotoView(float x, float y, SimpleEditorAnguloFijo* editor) : ObjetoView(x,y,editor, OBJ_SIMPLE_S_CONTROL) {
this->resetearNumeroEvento();
}

ControlRemotoView::~ControlRemotoView() {
	// TODO Auto-generated destructor stub
}

void ControlRemotoView::dropTemplate() {
	((SimpleEditorAnguloFijo * )this->controller)->dropNuevaFigura(this);
}

EditorNivel* ControlRemotoView::getEditor() {
	SimpleEditorAnguloFijo * editor = (SimpleEditorAnguloFijo *)controller;
	editor->setFigura(this);
	return editor;
}

int ControlRemotoView::getLayer() {
	return LAYER_DEFAULT;
}

void ControlRemotoView::dibujarse(list<ViewMsj*>& lista) {

	Figura* figura = this->getModelo();
	ViewObjetoUpdateMsj* viewMensaje;
	if(figura == NULL){
		viewMensaje = new ViewObjetoUpdateMsj(getXCentro(),getYCentro(),0,this->getId(), this->selector,0);
		lista.push_back(viewMensaje);
	} else {
		if(figura->isViva()){
		viewMensaje = new ViewObjetoUpdateMsj(figura->getX(),figura->getY(),figura->getRotacion(),this->getId(), this->selector,0);
		lista.push_back(viewMensaje);
		}
	}
//	this->resetearNumeroEvento();
}
