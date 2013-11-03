/*
 * ViewBalancinUpdateMsj.cpp
 *
 *  Created on: 31/10/2013
 *      Author: ezequiel
 */

#include "ViewBalancinUpdateMsj.h"
#include "../ConstantesComunicacion.h"
ViewBalancinUpdateMsj::ViewBalancinUpdateMsj(float x, float y, float angulo, int id) : ViewObjetoUpdateMsj(x,y,angulo,id) {

}

ViewBalancinUpdateMsj::~ViewBalancinUpdateMsj() {
	// TODO Auto-generated destructor stub
}

void ViewBalancinUpdateMsj::serialize(YAML::Node* nodo) {
	super::serialize(nodo);
}

NetworkMensaje* ViewBalancinUpdateMsj::deserialize(YAML::const_iterator& it) {
	int id = it->as<int>();
	it++;
	float xl = it->as<float>();
	it++;
	float yl = it->as<float>();
	it++;
	float angulo = it->as<float>();
	it++;

	NetworkMensaje * salida = new ViewBalancinUpdateMsj(xl,yl, angulo, id);
	return salida;
}

string ViewBalancinUpdateMsj::getTag() {
	return TAG_VIEW_BALANCIN;
}

void ViewBalancinUpdateMsj::getMensaje() {
	cout << this->x << " " << this->y << " " << this->angulo << endl;

}
