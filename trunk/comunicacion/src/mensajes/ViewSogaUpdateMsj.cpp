/*
 * ViewSogaUpdateMsj.cpp
 *
 *  Created on: 03/11/2013
 *      Author: joel
 */
#include "ViewSogaUpdateMsj.h"
#include "../ConstantesComunicacion.h"

using namespace std;

ViewSogaUpdateMsj::ViewSogaUpdateMsj(float x1,float x2, float x3, float x4, int id) : ViewObjetoUpdateMsj(0,0,0,id) {
	this->xDesde = x1;
	this->yDesde = x2;
	this->xHasta = x3;
	this->yHasta = x4;

}

ViewSogaUpdateMsj::~ViewSogaUpdateMsj() {
	// TODO Auto-generated destructor stub
}
//ENTREG3EZE chequear si la soga necesita mas datos para dibujarse

void ViewSogaUpdateMsj::serialize(YAML::Node* nodo) {
	nodo->push_back(this->getTag());
	nodo->push_back(xDesde);
	nodo->push_back(yDesde);
	nodo->push_back(xHasta);
	nodo->push_back(yHasta);
}

NetworkMensaje* ViewSogaUpdateMsj::deserialize(YAML::const_iterator& it) {
		float xD = it->as<float>();
		it++;
		float yD = it->as<float>();
		it++;
		float xH = it->as<float>();
		it++;
		float yH = it->as<float>();
		it++;
		NetworkMensaje * salida = new ViewSogaUpdateMje(xD,yD, xH, yH );
		return salida;
}

string ViewSogaUpdateMsj::getTag() {
	return TAG_VIEW_SOGA;
}

void ViewSogaUpdateMsj::getMensaje() {
	cout << this->xDesde << " " << this->yDesde << " " << this->xHasta << " " <<  this->yHasta <<  endl;
}
