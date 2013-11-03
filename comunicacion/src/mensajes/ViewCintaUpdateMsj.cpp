/*
 * ViewCintaUpdateMsj.cpp
 *
 *  Created on: 31/10/2013
 *      Author: ezequiel
 */

#include "ViewCintaUpdateMsj.h"
#include "../ConstantesComunicacion.h"
ViewCintaUpdateMsj::ViewCintaUpdateMsj(float x, float y, float angulo, float ancho, int id):ViewObjetoUpdateMsj(x,y,angulo,id) {
this->ancho = ancho;
}

ViewCintaUpdateMsj::~ViewCintaUpdateMsj() {
}

void ViewCintaUpdateMsj::serialize(YAML::Node* nodo) {
	super::serialize(nodo);
	nodo->push_back(this->ancho);
}

NetworkMensaje* ViewCintaUpdateMsj::deserialize(YAML::const_iterator& it) {
	int id = it->as<int>();
	it++;
	float xl = it->as<float>();
	it++;
	float yl = it->as<float>();
	it++;
	float angulol = it->as<float>();
	it++;
	float anchol = it->as<float>();
	it++;
	NetworkMensaje * salida = new ViewCintaUpdateMsj(xl,yl,angulol, anchol, id);
	return salida;
}

string ViewCintaUpdateMsj::getTag() {
	return TAG_VIEW_CINTA;
}

void ViewCintaUpdateMsj::getMensaje() {
	cout << this->x << " " << this->y << " " << this->angulo << " " <<  this->ancho <<  endl;
}
