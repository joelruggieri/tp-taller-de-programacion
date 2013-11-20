/*
 * ViewCorreaFactory.cpp
 *
 *  Created on: 15/10/2013
 *      Author: joel
 */

#include "ViewCorreaFactory.h"
#include "../../vista/objeto/CorreaEstaticaView.h"
#include "../../ConstantesVista.h"

ViewCorreaFactory::ViewCorreaFactory(EditorUnion* editor, int cantidad): ViewFiguraFactory(editor, cantidad, 0) {


}

FiguraView* ViewCorreaFactory::crear(float x, float y){
	return new CorreaEstaticaView(x, y,(EditorUnion*) this->controller);
}

ViewCorreaFactory::~ViewCorreaFactory() {
	// TODO Auto-generated destructor stub
}

View* ViewCorreaFactory::crearVistaPropia(){
	return new FactoryView();
}

string ViewCorreaFactory::getTagRemoto() {
	return TAG_FACTORY_CORREA;
}

View * ViewCorreaFactory::crearVistaPropia(float,float,float,float){
	return NULL;

}

ViewFiguraFactory* ViewCorreaFactory::clone(int cantidad){
	EditorUnion * editor = ((EditorUnion*) this->controller);
	editor = (EditorUnion *)editor->clone();
	return new ViewCorreaFactory(editor,cantidad);
}

