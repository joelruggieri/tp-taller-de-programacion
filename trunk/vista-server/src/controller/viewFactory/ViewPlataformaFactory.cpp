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


ViewPlataformaFactory::ViewPlataformaFactory(SimpleEditorEstirar * editor): ViewFiguraFactory(editor) {
}

FiguraView* ViewPlataformaFactory::crear(float x, float y, float w, float h) {
	//TODO REVEER MEDIDAS DE LA VISTA DE LA FACTORY
	return new PlataformaView(x, y,ANCHO_PLATAFORMA,(SimpleEditorEstirar *) this->controller);
}

ViewPlataformaFactory::~ViewPlataformaFactory() {
	// TODO Auto-generated destructor stub
}

View* ViewPlataformaFactory::crearVistaPropia(float x, float y, float w, float h) {
	return new FactoryView(x,y);
}
