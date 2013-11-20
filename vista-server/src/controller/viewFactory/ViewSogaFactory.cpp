/*
 * ViewSogaFactory.cpp
 *
 *  Created on: Oct 5, 2013
 *      Author: matias
 */

#include "ViewSogaFactory.h"
#include "../../vista/objeto/SogaEstaticaView.h"
#include "../../ConstantesVista.h"
namespace std {

ViewSogaFactory::ViewSogaFactory(EditorUnion* editor, int cantidad):ViewFiguraFactory(editor, cantidad, ID_FACTORY_SOGA) {

}

ViewSogaFactory::~ViewSogaFactory() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */

View* ViewSogaFactory::crearVistaPropia(){
	return new FactoryView();
}

FiguraView* ViewSogaFactory::crear(float x, float y) {
	return new SogaEstaticaView(x, y, (EditorUnion*) this->controller);
}

string std::ViewSogaFactory::getTagRemoto() {
return TAG_FACTORY_SOGA;
}

View * ViewSogaFactory::crearVistaPropia(float,float,float,float){
	return NULL;
}

ViewFiguraFactory* ViewSogaFactory::clone(int cantidad){
	EditorUnion * editor = ((EditorUnion*) this->controller);
	editor = (EditorUnion *)editor->clone();
	return new ViewSogaFactory(editor,cantidad);
}
