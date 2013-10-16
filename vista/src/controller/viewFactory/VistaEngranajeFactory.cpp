/*
 * VistaEngranajeFactory.cpp
 *
 *  Created on: 12/10/2013
 *      Author: javier
 */

#include "VistaEngranajeFactory.h"
#include "../editor/SimpleEditorAnguloFijo.h"
#include "../../vista/objeto/VistaEngranaje.h"
#include "../../ConstantesVista.h"

VistaEngranajeFactory::VistaEngranajeFactory(SimpleEditorAnguloFijo *editor): ViewFiguraFactory(PATH_VISTA_ENGRANAJE, editor) {
	// TODO Auto-generated constructor stub

}

VistaEngranajeFactory::~VistaEngranajeFactory() {
	// TODO Auto-generated destructor stub
}

FiguraView* VistaEngranajeFactory::crear(int x, int y, int w,
		int h) {
	return new VistaEngranaje(x, y, w, h, this->textura, dynamic_cast<SimpleEditorAnguloFijo*>(this->controller));
}

View* VistaEngranajeFactory::crearVistaPropia(int x, int y, int w,
		int h) {
	return new FactoryView(x,y,w,h, this->textura);
}