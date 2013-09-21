/*
 * ViewCoheteFactory.cpp
 *
 *  Created on: 21/09/2013
 *      Author: joel
 */

#include "ViewCoheteFactory.h"
#include "../../vista/figura/CoheteView.h"

ViewCoheteFactory::ViewCoheteFactory(DropController* controller): ViewFiguraFactory("resource/cohete.png",controller) {

}

ViewCoheteFactory::~ViewCoheteFactory() {
	// TODO Auto-generated destructor stub
}

FiguraView* ViewCoheteFactory::crear(int x, int y, int w, int h) {
	return new CoheteView(x,y,w,h, this->textura, this->controller);
}

FiguraView* ViewCoheteFactory::crearVistaPropia(int x, int y,
		int w, int h) {
	return new CoheteView(x,y,w,h, this->textura,this->controller);
}
