/*
 * ViewPelotaFactory.cpp
 *
 *  Created on: 20/09/2013
 *      Author: joel
 */

#include "ViewPelotaFactory.h"
#include "ViewFiguraFactory.h"
#include "../../vista/figura/PelotaView.h"

ViewPelotaFactory::ViewPelotaFactory(DropController* controller): ViewFiguraFactory("resource/pelota.png", controller) {

}

ViewPelotaFactory::~ViewPelotaFactory() {
	// TODO Auto-generated destructor stub
}

FiguraView* ViewPelotaFactory::crear(int x, int y, int w, int h) {
	return new PelotaView(x, y, w, h, this->textura, this->controller);
}

FiguraView* ViewPelotaFactory::crearVistaPropia(int x, int y, int w,
		int h) {
	return new PelotaView(x,y,w,h, this->textura, this->controller);
}
