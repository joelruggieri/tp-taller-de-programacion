/*
 * PelotaJuegoView.cpp
 *
 *  Created on: 06/10/2013
 *      Author: ezequiel
 */

#include "PelotaJuegoView.h"
#include "../../controller/editor/SimpleEditorAnguloFijo.h"
PelotaJuegoView::PelotaJuegoView(float x, float y,SimpleEditorAnguloFijo * editor): ObjetoView(x, y, editor, OBJ_SIMPLE_S_PELOTAJUEGO) {

}

PelotaJuegoView::~PelotaJuegoView() {
	// TODO Auto-generated destructor stub
}

void PelotaJuegoView::dropTemplate() {
	((SimpleEditorAnguloFijo * )this->controller)->dropNuevaFigura(this);
}

EditorNivel* PelotaJuegoView::getEditor() {
	SimpleEditorAnguloFijo * editor = (SimpleEditorAnguloFijo *)controller;
	editor->setFigura(this);
	return editor;
}

void PelotaJuegoView::seleccionarEventoSonido(){
	if(this->getNumeroEvento() == 1){
		this->alertarEvento(ID_SONIDO_PELOTA);
	}
}

void PelotaJuegoView::dibujarse(list<ViewMsj*> & lista){
	this->seleccionarEventoSonido();
	super::dibujarse(lista);
}
