/*
 * BalancinView.cpp
 *
 *  Created on: 05/10/2013
 *      Author: joel
 */

#include "BalancinView.h"
#include "../../controller/editor/SimpleEditorAnguloFijo.h"
#include "src/objeto/Balancin.h"

BalancinView::BalancinView(float x, float y,SimpleEditorAnguloFijo * editor): ObjetoView(x, y, editor, OBJ_SIMPLE_S_BALANCIN) {

}

void BalancinView::dropTemplate(){


	((SimpleEditorAnguloFijo * )this->controller)->dropNuevaFigura(this);
}

EditorNivel * BalancinView::getEditor(){
	SimpleEditorNivel * editor = (SimpleEditorNivel*)controller;
	editor->setFigura(this);
	return editor;
}

BalancinView::~BalancinView() {
	// TODO Auto-generated destructor stub
}

void BalancinView::seleccionarEventoSonido(){
	if(this->getNumeroEvento() == 1){
		this->alertarEvento(ID_SONIDO_SUBIBAJA);
	}
}

void BalancinView::dibujarse(list<ViewMsj*> & lista){
	this->seleccionarEventoSonido();
	super::dibujarse(lista);
}
