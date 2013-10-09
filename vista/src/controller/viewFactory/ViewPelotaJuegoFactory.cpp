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
ViewPelotaJuegoFactory::ViewPelotaJuegoFactory(SimpleEditorAnguloFijo * editor) : ViewFiguraFactory("resource/pelota.png", editor) {
	// TODO Auto-generated constructor stub

}

ViewPelotaJuegoFactory::~ViewPelotaJuegoFactory() {
	// TODO Auto-generated destructor stub
}

FiguraView* ViewPelotaJuegoFactory::crear(int x, int y, int w,
		int h) {
	Resizer* r = Resizer::Instance();
	int ancho, alto;
	r->adaptarDimensionLogica(RADIO_PELOTA*2,RADIO_PELOTA*2,ancho,alto);
	return new PelotaJuegoView(x, y, ancho, alto, this->textura, (SimpleEditorAnguloFijo*)this->controller);
}

View* ViewPelotaJuegoFactory::crearVistaPropia(int x, int y, int w,
		int h) {
	return new FactoryView(x,y,w,h, this->textura);
}
