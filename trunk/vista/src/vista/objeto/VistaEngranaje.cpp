/*
 * VistaEngranaje.cpp
 *
 *  Created on: 12/10/2013
 *      Author: javier
 */

#include "VistaEngranaje.h"
#include "SDL2/SDL.h"
#include "../../controller/editor/SimpleEditorAnguloFijo.h"

VistaEngranaje::VistaEngranaje(int x, int y, int w, int h, SDL_Texture * textura, SimpleEditorAnguloFijo * editor): ObjetoView(x, y, w, h,textura, editor) {
	// TODO Auto-generated constructor stub

}

VistaEngranaje::~VistaEngranaje() {
	// TODO Auto-generated destructor stub
}

void VistaEngranaje::dropTemplate() {
	controller->dropNuevaFigura(this);
}

EditorNivel* VistaEngranaje::getEditor() {
	SimpleEditorAnguloFijo * editor = (SimpleEditorAnguloFijo *)controller;
	editor->setFigura(this);
	return editor;
}

void VistaEngranaje::update(Transformacion& tl) {
	super::update(tl);
		float y = 0;
		tl.setVector(this->getModelo()->getAncho(),y);
		float radioPixels;
		tl.getResultadoInverso(radioPixels,y);
		this->setW(radioPixels * 2);
}