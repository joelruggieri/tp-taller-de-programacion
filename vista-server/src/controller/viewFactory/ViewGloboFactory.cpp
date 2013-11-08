/*
 * ViewGloboFactory.cpp
 *
 *  Created on: 20/09/2013
 *      Author: joel
 */

#include "ViewGloboFactory.h"
#include "../../vista/objeto/GloboHelioView.h"
#include "../../controller/editor/SimpleEditorAnguloFijo.h"
#include "src/Constantes.h"
#include "../../ConstantesVista.h"
ViewGloboFactory::ViewGloboFactory(SimpleEditorAnguloFijo * editor): ViewFiguraFactory(editor)  {


}

ViewGloboFactory::~ViewGloboFactory() {
	// TODO Auto-generated destructor stub
}

FiguraView* ViewGloboFactory::crear(float x, float y) {
	return new GloboHelioView(x, y, (SimpleEditorAnguloFijo*)this->controller);
}

View* ViewGloboFactory::crearVistaPropia(){
	return new FactoryView();
}

string ViewGloboFactory::getTagRemoto() {
	return TAG_FACTORY_GLOBO;
}
