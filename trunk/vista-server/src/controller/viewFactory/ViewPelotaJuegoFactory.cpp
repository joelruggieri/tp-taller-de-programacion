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

FiguraView* ViewPelotaJuegoFactory::crear(float x, float y) {
	return new PelotaJuegoView(x, y, (SimpleEditorAnguloFijo*)this->controller);
}

View* ViewPelotaJuegoFactory::crearVistaPropia(){
	return new FactoryView();
}

string ViewPelotaJuegoFactory::getTagRemoto() {
	return TAG_FACTORY_PELOTA;
}
