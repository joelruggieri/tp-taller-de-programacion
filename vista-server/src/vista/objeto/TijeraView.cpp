/*
 * TijeraView.cpp
 *
 *  Created on: 17/11/2013
 *      Author: joel
 */

#include "TijeraView.h"
#include "../../controller/editor/SimpleEditorAnguloFijo.h"
#include <src/mensajes/viewMensaje/ViewTijeraMsj.h>
#include "src/objeto/Tijera.h"

TijeraView::TijeraView(float x, float y, SimpleEditorAnguloFijo* editor): ObjetoView(x,y,editor,OBJ_SIMPLE_S_TIJERA) {


}

TijeraView::~TijeraView() {
	// TODO Auto-generated destructor stub
}

void TijeraView::dropTemplate(){
	((SimpleEditorAnguloFijo* )this->controller)->dropNuevaFigura(this);
}

EditorNivel * TijeraView::getEditor(){
	SimpleEditorAnguloFijo* editor = (SimpleEditorAnguloFijo*)controller;
	editor->setFigura(this);
	return editor;
}

void TijeraView::dibujarse(list<ViewMsj*>& mjes) {
	Tijera* figura = (Tijera*)this->getModelo();
	ViewTijeraMsj* viewMensaje;
	if(figura == NULL){

		viewMensaje = new ViewTijeraMsj(this->getXCentro(),this->getYCentro(),-ANGULO_DEFECTO_ASPA,ANGULO_DEFECTO_ASPA, this->getId(),this->getNumeroEvento());
		mjes.push_back(viewMensaje);
	} else {
		if(figura->isViva()){
		viewMensaje = new ViewTijeraMsj(figura->getX(),figura->getY(),figura->getRotacionAspa1(),figura->getRotacionAspa2(),this->getId(),this->getNumeroEvento());
		mjes.push_back(viewMensaje);
		}
	};
}
