/*
 * BombaView.cpp
 *
 *  Created on: 17/11/2013
 *      Author: ezequiel
 */

#include "BombaView.h"
#include "../../controller/editor/SimpleEditorAnguloFijo.h"
#include "src/mensajes/viewMensaje/ViewObjetoUpdateMsj.h"
BombaView::BombaView(float x, float y , SimpleEditorAnguloFijo* editor): ObjetoView(x, y, editor, OBJ_SIMPLE_S_BOMBA){

}

BombaView::~BombaView() {
	// TODO Auto-generated destructor stub
}

void BombaView::dropTemplate() {
	((SimpleEditorAnguloFijo * )this->controller)->dropNuevaFigura(this);
}

EditorNivel* BombaView::getEditor() {
	SimpleEditorAnguloFijo * editor = (SimpleEditorAnguloFijo *)controller;
	editor->setFigura(this);
	return editor;
}

void BombaView::seleccionarEventoSonido(){
	if(this->getNumeroEvento() == VALOR_ACTIVAR_SONIDO_DEFECTO){
		this->alertarEvento(ID_SONIDO_BOMBA_CONTACTO);

	}else if (this->getNumeroEvento() == VALOR_ACTIVAR_SONIDO_DEFECTO2){
		this->alertarEvento(ID_SONIDO_BOMBA_EXPLOSION);
	}
}


void BombaView::dibujarse(list<ViewMsj*> & lista){
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
		}else if (this->getNumeroEvento() == ID_SONIDO_BOMBA_EXPLOSION){
			viewMensaje = new ViewObjetoUpdateMsj(figura->getX(),figura->getY(),figura->getRotacion(),this->getId(), this->selector,this->getNumeroEvento());
			lista.push_back(viewMensaje);
		}
	}

	this->resetearNumeroEvento();
}

