/*
 * GloboHelioView.cpp
 *
 *  Created on: 05/10/2013
 *      Author: ezequiel
 */

#include "GloboHelioView.h"
#include "../../controller/editor/SimpleEditorAnguloFijo.h"
#include "src/mensajes/viewMensaje/ViewObjetoUpdateMsj.h"
GloboHelioView::GloboHelioView(float x, float y,SimpleEditorAnguloFijo * editor): ObjetoView(x, y, editor, OBJ_SIMPLE_S_GLOBO) {

}

GloboHelioView::~GloboHelioView() {
	// TODO Auto-generated destructor stub
}

void GloboHelioView::dropTemplate() {
	((SimpleEditorAnguloFijo * )this->controller)->dropNuevaFigura(this);
}

EditorNivel* GloboHelioView::getEditor() {
	SimpleEditorAnguloFijo * editor = (SimpleEditorAnguloFijo *)controller;
	editor->setFigura(this);
	return editor;
}

void GloboHelioView::seleccionarEventoSonido(){
	if(this->getNumeroEvento() == 1){
		this->alertarEvento(ID_SONIDO_GLOBO);
	}
}

void GloboHelioView::dibujarse(list<ViewMsj*> & lista){
	this->seleccionarEventoSonido();
	Figura* figura = this->getModelo();
	ViewObjetoUpdateMsj* viewMensaje;
	if(figura == NULL){
		viewMensaje = new ViewObjetoUpdateMsj(getXCentro(),getYCentro(),0,this->getId(), this->selector,this->getNumeroEvento());
		lista.push_back(viewMensaje);
	} else {
		if(figura->isViva()){
		viewMensaje = new ViewObjetoUpdateMsj(figura->getX(),figura->getY(),figura->getRotacion(),this->getId(), this->selector,this->getNumeroEvento());
		lista.push_back(viewMensaje);
		}else if (this->getNumeroEvento() == ID_SONIDO_GLOBO){
			viewMensaje = new ViewObjetoUpdateMsj(figura->getX(),figura->getY(),figura->getRotacion(),this->getId(), this->selector,this->getNumeroEvento());
			lista.push_back(viewMensaje);
		}
	}
	this->resetearNumeroEvento();
}
