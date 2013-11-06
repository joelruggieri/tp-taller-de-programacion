/*
 * PlataformaView.cpp
 *
 *  Created on: 03/10/2013
 *      Author: joel
 */

#include "PlataformaView.h"
#include "../../controller/editor/SimpleEditorEstirar.h"
#include "src/objeto/Plataforma.h"
#include "src/mensajes/viewMensaje/ViewObjetoConAnchoUpdateMsj.h"
PlataformaView::PlataformaView(float x, float y, float ancho, SimpleEditorEstirar* editor) :
		ObjetoView(x, y, editor) {
	this->ancho = ancho;
}

PlataformaView::~PlataformaView() {
	// TODO Auto-generated destructor stub
}

void PlataformaView::dropTemplate() {
	((SimpleEditorEstirar *) this->controller)->dropNuevaFigura(this);
}

EditorNivel* PlataformaView::getEditor() {
	SimpleEditorEstirar * editor = (SimpleEditorEstirar *) controller;
	editor->setFigura(this);
	return editor;
}

//void PlataformaView::update(){
//	super::update();
//	float y = 0;
//	Plataforma * p = (Plataforma *)this->getModelo();
//	tl.setVector(p->getAncho(),y);
//	float nuevoAncho;
//	tl.getResultadoInverso(nuevoAncho,y);
//	this->setW(nuevoAncho);
//}


void PlataformaView::dibujarse(list<ViewMsj*> & lista){
	Plataforma* figura = (Plataforma*) this->getModelo();
	ViewObjetoConAnchoUpdateMsj* viewMensaje;
	if(figura != NULL)
		viewMensaje = new ViewObjetoConAnchoUpdateMsj(figura->getX(),figura->getY(),figura->getRotacion(),figura->getAncho(),this->getId());
	else
		//EL ANGULO SE PASA EN CERO PORQUE LA PLATAFORMA SE CREA CON UN ANGULO EN CERO
		viewMensaje = new ViewObjetoConAnchoUpdateMsj(this->getXCentro(),this->getYCentro(),0,this->ancho,this->getId());
	lista.push_back(viewMensaje);
}
