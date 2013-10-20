/*
 * PlataformaView.cpp
 *
 *  Created on: 03/10/2013
 *      Author: joel
 */

#include "PlataformaView.h"
#include "../../controller/editor/SimpleEditorEstirar.h"
#include "src/objeto/Plataforma.h"
PlataformaView::PlataformaView(int x, int y, int w, int h, SDL_Texture * textura,SimpleEditorEstirar* editor) : ObjetoView(x,y,w,h,textura,editor) {

}

PlataformaView::~PlataformaView() {
	// TODO Auto-generated destructor stub
}

void 	PlataformaView::dropTemplate() {
	((SimpleEditorEstirar * )this->controller)->dropNuevaFigura(this);
}

EditorNivel* PlataformaView::getEditor() {
	SimpleEditorEstirar * editor = (SimpleEditorEstirar *)controller;
	editor->setFigura(this);
	return editor;
}


void PlataformaView::update(){
	super::update();
	float y = 0;
	Plataforma * p = (Plataforma *)this->getModelo();
	tl.setVector(p->getAncho(),y);
	float nuevoAncho;
	tl.getResultadoInverso(nuevoAncho,y);
	this->setW(nuevoAncho);
}
