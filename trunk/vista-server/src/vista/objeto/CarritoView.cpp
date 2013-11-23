/*
 * CarritoView.cpp
 *
 *  Created on: 14/11/2013
 *      Author: joel
 */

#include "CarritoView.h"
#include "../../controller/editor/SimpleEditorNivel.h"
#include "../../controller/editor/SimpleEditorEstirar.h"
#include "src/objeto/Carrito.h"
#include "src/mensajes/viewMensaje/ViewCarritoMsj.h"
CarritoView::CarritoView(float x, float y,SimpleEditorNivel* editor): ObjetoView(x, y, editor, OBJ_SIMPLE_S_CARRITO) {
	// TODO Auto-generated constructor stub

}

CarritoView::~CarritoView() {
	// TODO Auto-generated destructor stub
}

void CarritoView::seleccionarEventoSonido(){
	if(this->getNumeroEvento() == 1){
		this->alertarEvento(ID_SONIDO_CARRITO);
	}
}


void CarritoView::dibujarse(list<ViewMsj*> & lista){
	this->seleccionarEventoSonido();
	Carrito* figura = (Carrito*)this->getModelo();
	ViewCarritoMsj* viewMensaje;
	if(figura == NULL){
		float xi= getXCentro() -ANCHO_CARRITO/4.0;
		float yi= getYCentro() - ALTO_CARRITO/2.0;
		float xd= getXCentro() + ANCHO_CARRITO/4.0;
		float yd= getYCentro() - ALTO_CARRITO/2.0;
		viewMensaje = new ViewCarritoMsj(this->getXCentro(),this->getYCentro(),xi,yi,xd,yd,0,0,0, this->getId(),this->getNumeroEvento());
		lista.push_back(viewMensaje);
	} else {
		if(figura->isViva()){
		viewMensaje = new ViewCarritoMsj(figura->getX(),figura->getY(),figura->getXi(),figura->getYi(),figura->getXd(),figura->getYd(),figura->getRotacion(),figura->getRotI(),figura->getRotD(),this->getId(),this->getNumeroEvento());
		lista.push_back(viewMensaje);
		}
	}
	this->resetearNumeroEvento();
}

void CarritoView::dropTemplate(){


	((SimpleEditorNivel* )this->controller)->dropNuevaFigura(this);
}

EditorNivel * CarritoView::getEditor(){
	SimpleEditorNivel * editor = (SimpleEditorNivel*)controller;
	editor->setFigura(this);
	return editor;
}


