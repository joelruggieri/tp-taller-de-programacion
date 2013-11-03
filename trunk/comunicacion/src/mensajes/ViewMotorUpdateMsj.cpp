/*
 * ViewMotorUpdateMsj.cpp
 *
 *  Created on: 31/10/2013
 *      Author: ezequiel
 */

#include "ViewMotorUpdateMsj.h"
#include "../ConstantesComunicacion.h"
ViewMotorUpdateMsj::ViewMotorUpdateMsj(float x, float y, float angulo, int id) : ViewObjetoUpdateMsj(x,y,angulo,id) {

}

ViewMotorUpdateMsj::~ViewMotorUpdateMsj() {
	// TODO Auto-generated destructor stub
}

void ViewMotorUpdateMsj::serialize(YAML::Node* nodo) {
	super::serialize(nodo);
}

NetworkMensaje* ViewMotorUpdateMsj::deserialize(YAML::const_iterator& it) {
	float xl = it->as<float>();
	it++;
	float yl = it->as<float>();
	it++;
	float angulo = it->as<float>();
	it++;
	NetworkMensaje * salida = new ViewMotorUpdateMsj(xl,yl, angulo );
	return salida;
}

string ViewMotorUpdateMsj::getTag() {
	return TAG_VIEW_MOTOR;
}

void ViewMotorUpdateMsj::getMensaje() {
	cout << this->x << " " << this->y << " " << this->angulo << endl;
}
