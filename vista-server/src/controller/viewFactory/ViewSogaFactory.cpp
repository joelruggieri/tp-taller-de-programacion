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

ViewSogaFactory::ViewSogaFactory(EditorUnion* editor):ViewFiguraFactory(editor) {

}

ViewSogaFactory::~ViewSogaFactory() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */

View* ViewSogaFactory::crearVistaPropia(float x, float y, float w, float h) {
	return new FactoryView(x,y);
}

FiguraView* ViewSogaFactory::crear(float x, float y, float w, float h) {
	return new SogaEstaticaView(x, y, (EditorUnion*) this->controller);
}
