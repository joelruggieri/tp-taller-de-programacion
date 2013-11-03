/*
 * ViewGloboUpdateMsj.cpp
 *
 *  Created on: 30/10/2013
 *      Author: jonathan
 */

#include "ViewGloboUpdateMsj.h"
#include "../ConstantesComunicacion.h"
ViewGloboUpdateMsj::ViewGloboUpdateMsj(float x, float y, float angulo, int id) : ViewObjetoUpdateMsj(x,y,angulo,id) {
//	this->x = x;
//	this->y = y;
}

ViewGloboUpdateMsj::~ViewGloboUpdateMsj() {
	// TODO Auto-generated destructor stub
}

void ViewGloboUpdateMsj::serialize(YAML::Node* nodo) {
//	nodo->push_back(TAG_VIEW_GLOBO);
//	nodo->push_back(this->x);
//	nodo->push_back(this->y);
	super::serialize(nodo);

}

NetworkMensaje* ViewGloboUpdateMsj::deserialize(YAML::const_iterator & it) {
	float xl = it->as<float>();
	it++;
	float yl = it->as<float>();
	it++;
	float angulo = it->as<float>();
	it++;
	NetworkMensaje * salida = new ViewGloboUpdateMsj(xl,yl,angulo);
	return salida;
}

string ViewGloboUpdateMsj::getTag() {
	return TAG_VIEW_GLOBO;
}

void ViewGloboUpdateMsj::getMensaje() {
	cout << this->x << " " << this->y << " " << this->angulo << endl;
}
