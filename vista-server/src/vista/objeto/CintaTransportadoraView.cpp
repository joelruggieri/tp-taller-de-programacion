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
#include "src/mensajes/viewMensaje/ViewObjetoConAnchoUpdateMsj.h"
#include "src/ConstantesComunicacion.h"

CintaTransportadoraView::CintaTransportadoraView(float x, float y, float ancho, SimpleEditorEstirar* editor) :
		ObjetoView(x, y, editor, OBJ_CON_ANCHO_S_CINTA) {
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
	CintaTransportadora* figura = (CintaTransportadora*) this->getModelo();
	ViewObjetoConAnchoUpdateMsj* viewMensaje;
	if(figura != NULL)
		viewMensaje = new ViewObjetoConAnchoUpdateMsj(figura->getX(),figura->getY(),figura->getRotacionEje(),figura->getAncho(),this->getId(), this->selector );
	else //ENTREGA3 CUANDO NO EXISTE EL MODELO, NO SE DE DONDE AGARRAR EL ANGULO, SI QUIREN LO METO EN LA VISTA.
		viewMensaje = new ViewObjetoConAnchoUpdateMsj(this->getXCentro(),this->getYCentro(),0,this->ancho,this->getId(), this->selector);
	lista.push_back(viewMensaje);
}

