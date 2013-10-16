/*
 * Sogaview.cpp
 *
 *  Created on: Oct 5, 2013
 *      Author: matias
 */

#include "SogaView.h"
#include "../../controller/editor/EditorUnion.h"
#include <src/objeto/Soga.h>
#include "../CargadorDeTextures.h"

SogaView::SogaView(int x, int y, int w, int h, SDL_Texture * textura, EditorUnion * editor): UnionView(x, y, textura, editor) {
	texturaTramo = CargadorDeTextures::Instance()->cargarTexture("resource/eslabon_cinta.png");
}

void SogaView::dropTemplate() {
	//controller->dropNuevaFigura(this);
}

EditorNivel* SogaView::getEditor() {
	EditorUnion* editor = (EditorUnion*)controller;
	editor->setFigura(this);
	return editor;
}

SogaView::~SogaView() {
	// TODO Auto-generated destructor stub
}

void SogaView::dibujarse(SDL_Renderer * renderer, SDL_Rect & dest){
	Soga *soga = (Soga*) getModelo();
	if (!soga) return;
	std::vector<float>& angulos = soga->getAngulosTramos();
	std::vector<SDL_Rect>& marcos = soga->getMarcosTramos();
	for (unsigned int i=0; i < marcos.size(); ++i){
		dibujarParte(renderer, marcos[i], angulos[i], texturaTramo);
	}
}


void SogaView::dibujarParte(SDL_Renderer * renderer, SDL_Rect & dest, float angulo, SDL_Texture* text) {
	SDL_RenderCopyEx(renderer,text, NULL, &dest,angulo,NULL,SDL_FLIP_NONE);
}

