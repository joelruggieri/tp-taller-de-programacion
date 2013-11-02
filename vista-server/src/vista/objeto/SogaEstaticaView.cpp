/*
 * SogaEstaticaView.cpp
 *
 *  Created on: 15/10/2013
 *      Author: jonathan
 */

#include "SogaEstaticaView.h"
#include "../../controller/editor/EditorUnion.h"
#include <src/objeto/Soga.h>
#include "SogaView.h"
SogaEstaticaView::SogaEstaticaView(float x, float y,EditorUnion * editor): UnionEstaticaView (x, y,editor) {
}

void SogaEstaticaView::dropTemplate() {
	((EditorUnion * )this->controller)->dropNuevaFigura(this);
}

EditorNivel* SogaEstaticaView::getEditor() {
	EditorUnion* editor = (EditorUnion*)controller;
	editor->setFigura(this);
	return editor;
}

SogaEstaticaView::~SogaEstaticaView() {
	// TODO Auto-generated destructor stub
}

UnionView* SogaEstaticaView::toDinamica() {
	return new SogaView(this->getXCentro(),this->getYCentro(),(EditorUnion*) this->controller);
}

void SogaEstaticaView::dibujarse(list<ViewMsj*> & lista){
}
