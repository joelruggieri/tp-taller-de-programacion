/*
 * ViewSogaUpdateMje.cpp
 *
 *  Created on: 31/10/2013
 *      Author: ezequiel
 */

#include "ViewSogaUpdateMje.h"
#include "../ConstantesComunicacion.h"
ViewSogaUpdateMje::ViewSogaUpdateMje(float x1,float x2, float x3, float x4) : ViewObjetoUpdateMsj(0,0,0) {
	this->xDesde = x1;
	this->yDesde = x2;
	this->xHasta = x3;
	this->yHasta = x4;

}

ViewSogaUpdateMje::~ViewSogaUpdateMje() {
	// TODO Auto-generated destructor stub
}
//ENTREG3EZE chequear si la soga necesita mas datos para dibujarse

void ViewSogaUpdateMje::serialize(YAML::Node* nodo) {
	nodo->push_back(this->getTag());
	nodo->push_back(xDesde);
	nodo->push_back(yDesde);
	nodo->push_back(xHasta);
	nodo->push_back(yHasta);
}

NetworkMensaje* ViewSogaUpdateMje::deserialize(YAML::const_iterator& it) {
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

string ViewSogaUpdateMje::getTag() {
	return TAG_VIEW_SOGA;
}

void ViewSogaUpdateMje::getMensaje() {
	cout << this->xDesde << " " << this->yDesde << " " << this->xHasta << " " <<  this->yHasta <<  endl;
}
