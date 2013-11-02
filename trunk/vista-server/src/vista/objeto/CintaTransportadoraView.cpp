/*
 * CintaTransportadoraView.cpp
 *
 *  Created on: 05/10/2013
 *      Author: javier
 */

#include "CintaTransportadoraView.h"

#include "../../controller/DropController.h"
#include "../../controller/editor/SimpleEditorEstirar.h"
#include "../figura/FiguraView.h"
#include "ObjetoView.h"
#include <src/objeto/CintaTransportadora.h>
#include "../../ConstantesVista.h"


CintaTransportadoraView::CintaTransportadoraView(float x, float y, float ancho, SimpleEditorEstirar* editor) :
		ObjetoView(x, y, editor) {
	this->ancho = ancho;
}

CintaTransportadoraView::~CintaTransportadoraView() {
	// TODO Auto-generated destructor stub
}

void CintaTransportadoraView::dropTemplate() {
	((SimpleEditorEstirar *) this->controller)->dropNuevaFigura(this);
}

EditorNivel* CintaTransportadoraView::getEditor() {
	SimpleEditorEstirar * editor = (SimpleEditorEstirar *) controller;
	editor->setFigura(this);
	return editor;
}

void CintaTransportadoraView::dibujarse(list<ViewMsj*> & lista){
	cout << "PLATAFORMA: ";
	if(getModelo() != NULL){
		CintaTransportadora * p = (CintaTransportadora *) this->getModelo();
		cout << p->getX() << " ";
		cout << p->getY() << " ";
		cout << p->getAncho() << endl;
	} else {
		cout << getXCentro() << " ";
		cout << getYCentro() << " ";
		cout << ancho << endl;
	}
}


int CintaTransportadoraView::getLayer() {
	return LAYER_CINTA;
}
