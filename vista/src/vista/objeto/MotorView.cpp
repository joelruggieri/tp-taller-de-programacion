/*
 * MotorView.cpp
 *
 *  Created on: 28/09/2013
 *      Author: jonathan
 */

#include "MotorView.h"
#include "../../controller/DropController.h"
MotorView::MotorView(int x, int y, int w, int h, SDL_Texture * textura,DropController * controller): ObjetoView(x, y, w, h,textura, controller) {
	// TODO Auto-generated constructor stub

}

MotorView::~MotorView() {
	// TODO Auto-generated destructor stub
}

void MotorView::dropTemplate() {
	controller->dropNuevaFigura(this);
}

