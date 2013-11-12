/*
 * VistaEngranaje.cpp
 *
 *  Created on: 12/10/2013
 *      Author: javier
 */

#include "VistaEngranaje.h"
#include "SDL2/SDL.h"
#include "../../controller/editor/SimpleEditorAnguloFijo.h"
#include "../../controller/editor/SimpleEditorCambiarRadio.h"
#include "src/objeto/Engranaje.h"
#include "src/mensajes/viewMensaje/ViewObjetoConAnchoUpdateMsj.h"
#include <iostream>
using namespace std;

VistaEngranaje::VistaEngranaje(float x, float y, float diametro,SimpleEditorCambiarRadio * editor): ObjetoView(x, y, editor, OBJ_CON_ANCHO_S_ENGRANAJE) {

	this->diametro = diametro;
}

VistaEngranaje::~VistaEngranaje() {
	// TODO Auto-generated destructor stub
}

void VistaEngranaje::dropTemplate() {
	((SimpleEditorAnguloFijo * )this->controller)->dropNuevaFigura(this);
}

EditorNivel* VistaEngranaje::getEditor() {
	SimpleEditorAnguloFijo * editor = (SimpleEditorAnguloFijo *)controller;
	editor->setFigura(this);
	return editor;
}

//void VistaEngranaje::update() {
//		super::update();
//		Engranaje* e = (Engranaje*) this->getModelo();
//		float y = 0 ;
//		tl.setVector(e->getRadio()*2,0);
//		float nuevoRadio;
//		tl.getResultadoInverso(nuevoRadio,y);
//		this->setW(nuevoRadio);
//		this->setH(nuevoRadio);

//		float a,b;
//		tl.getResultadoInverso(a,b);
//		cout << a << " " << b << endl;
//				this->setW(a);
//				this->setH(b);
//}


void VistaEngranaje::dibujarse(list<ViewMsj*> & lista){
	Engranaje* figura = (Engranaje*) this->getModelo();
	ViewObjetoConAnchoUpdateMsj* viewMensaje;
	if(figura != NULL)
		viewMensaje = new ViewObjetoConAnchoUpdateMsj(figura->getX(),figura->getY(),figura->getRotacion(),figura->getAncho() + 0.4,this->getId(), this->selector);
	else //ENTREGA3 CUANDO NO EXISTE EL MODELO, NO SE DE DONDE AGARRAR EL ANGULO, SI QUIREN LO METO EN LA VISTA.
		viewMensaje = new ViewObjetoConAnchoUpdateMsj(this->getXCentro(),this->getYCentro(),0,this->diametro * 2 + 0.4,this->getId(), this->selector);
	lista.push_back(viewMensaje);
}
