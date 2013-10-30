/*
 * ViewBolaBolicheUpdateMsj.cpp
 *
 *  Created on: 30/10/2013
 *      Author: ezequiel
 */

#include "ViewBolaBolicheUpdateMsj.h"
#include "../ConstantesComunicacion.h"
ViewBolaBolicheUpdateMsj::ViewBolaBolicheUpdateMsj(float x, float y) {
this->x = x;
this->y = y;
}

ViewBolaBolicheUpdateMsj::~ViewBolaBolicheUpdateMsj() {
	// TODO Auto-generated destructor stub
}

void ViewBolaBolicheUpdateMsj::serialize(YAML::Node* nodo) {
	nodo->push_back(TAG_VIEW_BOLA);
	nodo->push_back(this->x);
	nodo->push_back(this->y);

}

NetworkMensaje* ViewBolaBolicheUpdateMsj::deserialize(
		YAML::const_iterator& it) {
	float xl = it->as<float>();
	it++;
	float yl = it->as<float>();
	NetworkMensaje * salida = new ViewBolaBolicheUpdateMsj(xl,yl);
	return salida;
}
