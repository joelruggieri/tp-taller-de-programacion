/*
 * ViewPlataformaFactory.cpp
 *
 *  Created on: 03/10/2013
 *      Author: joel
 */

#include "ViewPlataformaFactory.h"
#include "../../vista/CargadorDeTextures.h"
#include "../../ConstantesVista.h"
#include "src/Constantes.h"
#include "../../controller/editor/SimpleEditorEstirar.h"


ViewPlataformaFactory::ViewPlataformaFactory(SimpleEditorEstirar * editor): ViewFiguraFactory(PATH_VISTA_PLATAFORMA_F, editor) {
}

FiguraView* ViewPlataformaFactory::crear(int x, int y, int w, int h) {
	//TODO REVEER MEDIDAS DE LA VISTA DE LA FACTORY
	Resizer* r = Resizer::Instance();
	int ancho, alto;
	CargadorDeTextures* c = CargadorDeTextures::Instance();
	r->adaptarDimensionLogica(ANCHO_PLATAFORMA,ALTO_VISTA_PLATAFORMA_LOG,ancho,alto);
	return new PlataformaView(x, y, ancho, alto,c->cargarTexture(PATH_VISTA_PLATAFORMA), (SimpleEditorEstirar *) this->controller);
}

ViewPlataformaFactory::~ViewPlataformaFactory() {
	// TODO Auto-generated destructor stub
}

View* ViewPlataformaFactory::crearVistaPropia(int x, int y, int w,int h) {
	return new FactoryView(x,y,w,h, this->textura);
}
