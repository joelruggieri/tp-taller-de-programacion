/*
 * ViewBolaBolicheUpdateMsj.cpp
 *
 *  Created on: 30/10/2013
 *      Author: ezequiel
 */

#include "ViewBolaBolicheUpdateMsj.h"
#include "../ConstantesComunicacion.h"
ViewBolaBolicheUpdateMsj::ViewBolaBolicheUpdateMsj(float x, float y, float angulo,int id):ViewObjetoUpdateMsj(x,y, angulo,id) {
//this->x = x;
//this->y = y;
}

ViewBolaBolicheUpdateMsj::~ViewBolaBolicheUpdateMsj() {
	// TODO Auto-generated destructor stub
}

void ViewBolaBolicheUpdateMsj::serialize(YAML::Node* nodo) {
//	nodo->push_back(TAG_VIEW_BOLA);
//	nodo->push_back(this->x);
//	nodo->push_back(this->y);
	super::serialize(nodo);
}

NetworkMensaje* ViewBolaBolicheUpdateMsj::deserialize(
		YAML::const_iterator& it) {
	int id = it->as<int>();
	it++;
	float xl = it->as<float>();
	it++;
	float yl = it->as<float>();
	it++;
	float angulo = it->as<float>();
	it++;
	NetworkMensaje * salida = new ViewBolaBolicheUpdateMsj(xl,yl, angulo, id);
	return salida;
}

string ViewBolaBolicheUpdateMsj::getTag() {
	return TAG_VIEW_BOLA;
}

void ViewBolaBolicheUpdateMsj::getMensaje() {
	cout << this->x << " " << this->y << " " << this->angulo<< endl;
}
