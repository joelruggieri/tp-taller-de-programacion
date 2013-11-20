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
SogaEstaticaView::SogaEstaticaView(float x, float y,EditorUnion * editor): UnionEstaticaView (x, y,editor, OBJ_UNION_S_SOGA_ESTATICA) {
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

}

UnionView* SogaEstaticaView::toDinamica() {
	SogaView * rt = new SogaView(this->getXCentro(),this->getYCentro(),(EditorUnion*) this->controller);
	list<Observer*>::iterator it;
	for(it=observers.begin(); it != observers.end(); ++it){
		rt->addObserver(*it);
	}
	observers.clear();
	return rt;
}

//void SogaEstaticaView::dibujarse(list<ViewMsj*> & lista){
//}
