/*
 * ViewGloboUpdateMsj.cpp
 *
 *  Created on: 30/10/2013
 *      Author: jonathan
 */

#include "ViewGloboUpdateMsj.h"
#include "../ConstantesComunicacion.h"
ViewGloboUpdateMsj::ViewGloboUpdateMsj(float x, float y) {
	this->x = x;
	this->y = y;
}

ViewGloboUpdateMsj::~ViewGloboUpdateMsj() {
	// TODO Auto-generated destructor stub
}

void ViewGloboUpdateMsj::serialize(YAML::Node* nodo) {
	nodo->push_back(TAG_VIEW_GLOBO);
	nodo->push_back(this->x);
	nodo->push_back(this->y);

}

NetworkMensaje* ViewGloboUpdateMsj::deserialize(YAML::const_iterator & it) {
	float xl = it->as<float>();
	float yl = it->as<float>();
	NetworkMensaje * salida = new ViewGloboUpdateMsj(xl,yl);
	return salida;
}
