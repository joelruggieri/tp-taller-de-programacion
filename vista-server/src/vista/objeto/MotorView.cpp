/*
 * MotorView.cpp
 *
 *  Created on: 28/09/2013
 *      Author: jonathan
 */

#include "MotorView.h"
#include "../../controller/editor/SimpleEditorAnguloFijo.h"
#include "../../controller/editor/SimpleEditorOrientacionCambiable.h"
#include "../../ConstantesVista.h"

MotorView::MotorView(float x, float y,SimpleEditorOrientacionCambiable * editor): ObjetoView(x, y, editor,  OBJ_SIMPLE_S_MOTOR) {

}

MotorView::~MotorView() {
	// TODO Auto-generated destructor stub
}

void MotorView::dropTemplate() {
	((SimpleEditorOrientacionCambiable * )this->controller)->dropNuevaFigura(this);
}

EditorNivel* MotorView::getEditor() {
	SimpleEditorOrientacionCambiable * editor = (SimpleEditorOrientacionCambiable *)controller;
	editor->setFigura(this);
	return editor;
}

int MotorView::getLayer() {
	return LAYER_ENGRANAJES;
}

void MotorView::seleccionarEventoSonido(){
	if(this->getNumeroEvento() == 1){
		this->alertarEvento(ID_SONIDO_MOTOR);
	}
}

void MotorView::dibujarse(list<ViewMsj*> & lista){
	this->seleccionarEventoSonido();
	super::dibujarse(lista);
	this->resetearNumeroEvento();
}

