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
#include "../../ConstantesVista.h"
#include <iostream>
using namespace std;

VistaEngranaje::VistaEngranaje(float x, float y, float diametro,SimpleEditorCambiarRadio * editor): ObjetoView(x, y, editor) {

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

int VistaEngranaje::getLayer() {
	return LAYER_ENGRANAJES;
}

void VistaEngranaje::dibujarse(SDL_Renderer*) {
	cout << "EngranajeView";
	if(getModelo() == NULL){
		cout << this->diametro << endl;
	} else {
		cout<<((Engranaje *) getModelo())->getRadio()*2<< endl;
	}
}