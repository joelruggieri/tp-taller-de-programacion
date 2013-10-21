/*
 * VistaEngranaje.cpp
 *
 *  Created on: 12/10/2013
 *      Author: javier
 */

#include "VistaEngranaje.h"
#include "SDL2/SDL.h"
#include "../../controller/editor/SimpleEditorAnguloFijo.h"
#include "src/objeto/Engranaje.h"
#include <iostream>
using namespace std;

VistaEngranaje::VistaEngranaje(int x, int y, int w, int h, SDL_Texture * textura, SimpleEditorAnguloFijo * editor): ObjetoView(x, y, w, h,textura, editor) {
	// TODO Auto-generated constructor stub

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

void VistaEngranaje::update() {
		super::update();
		Engranaje* e = (Engranaje*) this->getModelo();
		float y = 0 ;
		tl.setVector(e->getAncho(),e->getAncho());
		float nuevoRadio;
		tl.getResultadoInverso(nuevoRadio,y);
		this->setW(nuevoRadio);
		this->setH(nuevoRadio);

//		float a,b;
//		tl.getResultadoInverso(a,b);
//		cout << a << " " << b << endl;
//				this->setW(a);
//				this->setH(b);
}
