/*
 * ViewMotorFactory.cpp
 *
 *  Created on: 28/09/2013
 *      Author: jonathan
 */

#include "ViewMotorFactory.h"
#include "../../vista/objeto/MotorView.h"
#include "src/Constantes.h"
#include "../../ConstantesVista.h"
//ViewMotorFactory::ViewMotorFactory(SimpleEditorAnguloFijo * editor):ViewFiguraFactory("resource/pelota.png", editor) {
//}

ViewMotorFactory::ViewMotorFactory(SimpleEditorOrientacionCambiable * editor, int cantidad):ViewFiguraFactory(editor, cantidad,ID_FACTORY_MOTOR) {
}

ViewMotorFactory::~ViewMotorFactory() {
	// TODO Auto-generated destructor stub
}

FiguraView* ViewMotorFactory::crear(float x, float y) {
	return new MotorView(x, y,(SimpleEditorOrientacionCambiable *) this->controller);
}

View* ViewMotorFactory::crearVistaPropia(){
	return new FactoryView();
}

string ViewMotorFactory::getTagRemoto() {
	return TAG_FACTORY_MOTOR;
}

View * ViewMotorFactory::crearVistaPropia(float,float,float,float){
	return NULL;
}

ViewFiguraFactory* ViewMotorFactory::clone(int cantidad){
	SimpleEditorOrientacionCambiable * editor = ((SimpleEditorOrientacionCambiable*) this->controller);
	editor = (SimpleEditorOrientacionCambiable *)editor->clone();
	return new ViewMotorFactory(editor,cantidad);
}
