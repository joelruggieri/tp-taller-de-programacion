/*
 * CorreaEstaticaView.cpp
 *
 *  Created on: 16/10/2013
 *      Author: jonathan
 */

#include "CorreaEstaticaView.h"

#include "../../controller/editor/EditorUnion.h"
#include "CorreaView.h"
CorreaEstaticaView::CorreaEstaticaView(int x, int y, int w, int h, SDL_Texture * textura,EditorUnion * editor): UnionEstaticaView(x, y, w, h,textura, editor) {

}

CorreaEstaticaView::~CorreaEstaticaView() {
	// TODO Auto-generated destructor stub
}

void CorreaEstaticaView::dropTemplate() {
	controller->dropNuevaFigura(this);
}

EditorNivel* CorreaEstaticaView::getEditor() {
	EditorUnion * editor = (EditorUnion *)controller;
	editor->setFigura(this);
	return editor;
}

UnionView* CorreaEstaticaView::toDinamica() {
	return new CorreaView (this->getY(),this->getY(),this->getTexture(),(EditorUnion*)this->controller);
}
