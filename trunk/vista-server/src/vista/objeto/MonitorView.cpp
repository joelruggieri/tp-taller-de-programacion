/*
 * MonitorView.cpp
 *
 *  Created on: 06/10/2013
 *      Author: ezequiel
 */

#include "MonitorView.h"
#include "../../controller/editor/SimpleEditorNivel.h"
MonitorView::MonitorView(float x, float y,SimpleEditorNivel * editor): ObjetoView(x, y, editor, 's') {

}

MonitorView::~MonitorView() {
	// TODO Auto-generated destructor stub
}

void MonitorView::dropTemplate() {
	((SimpleEditorNivel * )this->controller)->dropNuevaFigura(this);
}

EditorNivel* MonitorView::getEditor() {
	SimpleEditorNivel * editor = (SimpleEditorNivel *)controller;
	editor->setFigura(this);
	return editor;
}

void MonitorView::seleccionarEventoSonido(){
	if(this->getNumeroEvento() == 1){
		this->alertarEvento(ID_SONIDO_PELOTA);
	}
}

void MonitorView::dibujarse(list<ViewMsj*> & lista){
//	this->seleccionarEventoSonido();
//	super::dibujarse(lista);
//	this->resetearNumeroEvento();
}
