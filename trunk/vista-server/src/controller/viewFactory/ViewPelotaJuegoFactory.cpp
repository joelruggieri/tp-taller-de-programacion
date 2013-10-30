/*
 * ViewPelotaJuegoFactory.cpp
 *
 *  Created on: 06/10/2013
 *      Author: ezequiel
 */

#include "ViewPelotaJuegoFactory.h"
#include  "../../vista/objeto/PelotaJuegoView.h"
#include "../../controller/editor/SimpleEditorAnguloFijo.h"
#include "src/Constantes.h"
#include "../../ConstantesVista.h"
ViewPelotaJuegoFactory::ViewPelotaJuegoFactory(SimpleEditorAnguloFijo * editor) : ViewFiguraFactory(editor) {
	// TODO Auto-generated constructor stub

}

ViewPelotaJuegoFactory::~ViewPelotaJuegoFactory() {
	// TODO Auto-generated destructor stub
}

FiguraView* ViewPelotaJuegoFactory::crear(float x, float y, float w, float h) {
	return new PelotaJuegoView(x, y, (SimpleEditorAnguloFijo*)this->controller);
}

View* ViewPelotaJuegoFactory::crearVistaPropia(float x, float y, float w, float h) {
	return new FactoryView(x,y);
}
