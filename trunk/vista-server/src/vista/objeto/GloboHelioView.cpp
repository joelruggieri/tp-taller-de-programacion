/*
 * GloboHelioView.cpp
 *
 *  Created on: 05/10/2013
 *      Author: ezequiel
 */

#include "GloboHelioView.h"
#include "../../controller/editor/SimpleEditorAnguloFijo.h"
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
	super::dibujarse(lista);
	this->resetearNumeroEvento();
}
