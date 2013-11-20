/*
 * CorreaEstaticaView.cpp
 *
 *  Created on: 16/10/2013
 *      Author: jonathan
 */

#include "CorreaEstaticaView.h"

#include "../../controller/editor/EditorUnion.h"
#include "CorreaView.h"
CorreaEstaticaView::CorreaEstaticaView(float x, float y,EditorUnion * editor): UnionEstaticaView(x, y, editor, OBJ_UNION_S_CORREA_ESTATICA) {

}

CorreaEstaticaView::~CorreaEstaticaView() {
	// TODO Auto-generated destructor stub
}

void CorreaEstaticaView::dropTemplate() {
	((EditorUnion * )this->controller)->dropNuevaFigura(this);
}

EditorNivel* CorreaEstaticaView::getEditor() {
	EditorUnion * editor = (EditorUnion *)controller;
	editor->setFigura(this);
	return editor;
}

UnionView* CorreaEstaticaView::toDinamica() {
	CorreaView * rt = new CorreaView (this->getXCentro(),this->getYCentro(),(EditorUnion*)this->controller);
	list<Observer*>::iterator it;
	for(it=observers.begin(); it != observers.end(); ++it){
		rt->addObserver(*it);
	}
	observers.clear();
	return rt;
}
