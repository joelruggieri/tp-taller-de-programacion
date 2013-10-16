/*
 * SogaEstaticaView.cpp
 *
 *  Created on: 15/10/2013
 *      Author: jonathan
 */

#include "SogaEstaticaView.h"
#include "../../controller/editor/EditorUnion.h"
#include <src/objeto/Soga.h>
#include "../CargadorDeTextures.h"
SogaEstaticaView::SogaEstaticaView(int x, int y, int w, int h, SDL_Texture * textura, EditorUnion * editor): ObjetoView(x, y, w, h,textura, editor) {
	texturaTramo = CargadorDeTextures::Instance()->cargarTexture("resource/eslabon_cinta.png");
}

void SogaEstaticaView::dropTemplate() {
//	controller->dropNuevaFigura(this);
}

EditorNivel* SogaEstaticaView::getEditor() {
	EditorUnion* editor = (EditorUnion*)controller;
	editor->setFigura(this);
	return editor;
}

SogaEstaticaView::~SogaEstaticaView() {
	// TODO Auto-generated destructor stub
}


