/*
 * ViewPelotaUpdateMsj.cpp
 *
 *  Created on: 30/10/2013
 *      Author: ezequiel
 */

#include "ViewPelotaUpdateMsj.h"
#include "../ConstantesComunicacion.h"
ViewPelotaUpdateMsj::ViewPelotaUpdateMsj(float x, float y) {
	this->x = x;
	this->y = y;
}

ViewPelotaUpdateMsj::~ViewPelotaUpdateMsj() {
	// TODO Auto-generated destructor stub
}

void ViewPelotaUpdateMsj::serialize(YAML::Node* nodo) {
	nodo->push_back(TAG_VIEW_GLOBO);
	nodo->push_back(this->x);
	nodo->push_back(this->y);

}

NetworkMensaje* ViewPelotaUpdateMsj::deserialize(YAML::const_iterator & it) {
	float xl = it->as<float>();
	it++;
	float yl = it->as<float>();
	NetworkMensaje * salida = new ViewPelotaUpdateMsj(xl,yl);
	return salida;
}
