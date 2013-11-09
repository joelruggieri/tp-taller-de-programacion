/*
 * ViewPlataformaFactory.cpp
 *
 *  Created on: 03/10/2013
 *      Author: joel
 */

#include "ViewPlataformaFactory.h"
#include "../../ConstantesVista.h"
#include "src/Constantes.h"
#include "../../controller/editor/SimpleEditorEstirar.h"


ViewPlataformaFactory::ViewPlataformaFactory(SimpleEditorEstirar * editor, int cantidad): ViewFiguraFactory(editor, cantidad) {
}

FiguraView* ViewPlataformaFactory::crear(float x, float y) {
	//TODO REVEER MEDIDAS DE LA VISTA DE LA FACTORY
	return new PlataformaView(x, y,ANCHO_PLATAFORMA,(SimpleEditorEstirar *) this->controller);
}

ViewPlataformaFactory::~ViewPlataformaFactory() {
	// TODO Auto-generated destructor stub
}

View* ViewPlataformaFactory::crearVistaPropia(){
	return new FactoryView();
}

string ViewPlataformaFactory::getTagRemoto() {
	return TAG_FACTORY_PLATAFORMA;
}

View * ViewPlataformaFactory::crearVistaPropia(float,float,float,float){
	return NULL;
}

ViewFiguraFactory* ViewPlataformaFactory::clone(int cantidad){
	SimpleEditorEstirar * editor = ((SimpleEditorEstirar*) this->controller);
	editor = (SimpleEditorEstirar *)editor->clone();
	return new ViewPlataformaFactory(editor,cantidad);
}

