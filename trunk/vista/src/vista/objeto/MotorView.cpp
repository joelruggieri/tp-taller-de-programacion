/*
 * MotorView.cpp
 *
 *  Created on: 28/09/2013
 *      Author: jonathan
 */

#include "MotorView.h"
#include "../../ConstantesVista.h"
//MotorView::MotorView(int x, int y, int w, int h, SDL_Texture * textura,SimpleEditorAnguloFijo * editor): ObjetoView(x, y, w, h,textura, editor) {
//
//}

MotorView::MotorView(int x, int y, int w, int h, SDL_Texture * textura): ObjetoView(x, y, w, h,textura) {

}

MotorView::~MotorView() {
	// TODO Auto-generated destructor stub
}


int MotorView::getLayer() {
	return LAYER_ENGRANAJES;
}

void MotorView::update(ViewMsj*) {
}
