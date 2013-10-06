/*
 * ViewPelotaJuegoFactory.cpp
 *
 *  Created on: 06/10/2013
 *      Author: ezequiel
 */

#include "ViewPelotaJuegoFactory.h"
#include  "../../vista/objeto/PelotaJuegoView.h"
#include "../../controller/editor/SimpleEditorAnguloFijo.h"
ViewPelotaJuegoFactory::ViewPelotaJuegoFactory(SimpleEditorAnguloFijo * editor) : ViewFiguraFactory("resource/pelota.png", editor) {
	// TODO Auto-generated constructor stub

}

ViewPelotaJuegoFactory::~ViewPelotaJuegoFactory() {
	// TODO Auto-generated destructor stub
}

FiguraView* ViewPelotaJuegoFactory::crear(int x, int y, int w,
		int h) {
	return new PelotaJuegoView(x, y, w, h, this->textura, (SimpleEditorAnguloFijo*)this->controller);
}

View* ViewPelotaJuegoFactory::crearVistaPropia(int x, int y, int w,
		int h) {
	return new FactoryView(x,y,w,h, this->textura);
}
