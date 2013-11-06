/*
 * ViewMotorFactory.cpp
 *
 *  Created on: 28/09/2013
 *      Author: jonathan
 */

#include "ViewMotorFactory.h"
#include "../../vista/objeto/MotorView.h"
#include "../Resizer.h"
#include "../../ConstantesVista.h"
//ViewMotorFactory::ViewMotorFactory(SimpleEditorAnguloFijo * editor):ViewFiguraFactory("resource/pelota.png", editor) {
//}
namespace CLIENTE {
ViewMotorFactory::ViewMotorFactory():ViewFiguraFactory("resource/mot.png") {
}

ViewMotorFactory::~ViewMotorFactory() {
	// TODO Auto-generated destructor stub
}

FiguraView* ViewMotorFactory::crear(int x, int y, int w, int h) {
//	return new MotorView(x, y, w, h, this->textura,(SimpleEditorAnguloFijo *) this->controller);
	Resizer* r = Resizer::Instance();
	int ancho,alto;
	r->adaptarDimensionLogica(5.0 * 2 ,5.0 * 2,ancho,alto);
	return new MotorView(x, y, ancho, alto, this->textura);
}
}
