/*
 * PlataformaView.cpp
 *
 *  Created on: 03/10/2013
 *      Author: joel
 */

#include "PlataformaView.h"
#include "../../controller/editor/SimpleEditorEstirar.h"
PlataformaView::PlataformaView(int x, int y, int w, int h, SDL_Texture * textura,SimpleEditorNivel* editor) : ObjetoView(x,y,w,h,textura,editor) {

}

PlataformaView::~PlataformaView() {
	// TODO Auto-generated destructor stub
}

void 	PlataformaView::dropTemplate() {
	controller->dropNuevaFigura(this);
}

EditorNivel* PlataformaView::getEditor() {
	SimpleEditorNivel * editor = (SimpleEditorNivel *)controller;
	editor->setFigura(this);
	return editor;
}
