/*
 * ViewMotorFactory.cpp
 *
 *  Created on: 28/09/2013
 *      Author: jonathan
 */

#include "ViewMotorFactory.h"

ViewMotorFactory::ViewMotorFactory(DropController* controller):ViewFiguraFactory("resource/motor.png", controller) {
	// TODO Auto-generated constructor stub

}

ViewMotorFactory::~ViewMotorFactory() {
	// TODO Auto-generated destructor stub
}

FiguraView* ViewMotorFactory::crear(int x, int y, int w, int h) {
	return new MotorView(x, y, w, h, this->textura, this->controller);
}

View* ViewMotorFactory::crearVistaPropia(int x, int y, int w,
		int h) {
	return new FactoryView(x,y,w,h, this->textura);
}
