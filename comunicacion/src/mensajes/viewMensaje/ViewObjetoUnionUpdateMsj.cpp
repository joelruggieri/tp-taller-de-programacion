/*
 * ViewObjetoUnionUpdateMsj.cpp
 *
 *  Created on: 03/11/2013
 *      Author: joel
 */

#include "ViewObjetoUnionUpdateMsj.h"
#include "../../ConstantesComunicacion.h"

ViewObjetoUnionUpdateMsj::ViewObjetoUnionUpdateMsj(float x1,float x2, float x3, float x4, int id) : ViewObjetoUpdateMsj(x1,x2,0,id) {
	this->xHasta = x3;
	this->yHasta = x4;

}

ViewObjetoUnionUpdateMsj::~ViewObjetoUnionUpdateMsj() {
	// TODO Auto-generated destructor stub
}

void ViewObjetoUnionUpdateMsj::serialize(YAML::Node* nodo) {
	nodo->push_back(this->getTag());
	nodo->push_back(this->id);
	nodo->push_back(x);
	nodo->push_back(y);
	nodo->push_back(xHasta);
	nodo->push_back(yHasta);
}

NetworkMensaje* ViewObjetoUnionUpdateMsj::deserialize(YAML::const_iterator& it) {
	int id = it->as<int>();
	it++;
	float xD = it->as<float>();
	it++;
	float yD = it->as<float>();
	it++;
	float xH = it->as<float>();
	it++;
	float yH = it->as<float>();
	it++;
	NetworkMensaje * salida = new ViewObjetoUnionUpdateMsj(xD,yD, xH, yH,id);
	return salida;
}

string ViewObjetoUnionUpdateMsj::getTag() {
	return TAG_VIEW_OBJETO_UNION;
}

void ViewObjetoUnionUpdateMsj::getMensaje() {
	cout << this->x << " " << this->y<< " " << this->xHasta << " " <<  this->yHasta <<  endl;
}

