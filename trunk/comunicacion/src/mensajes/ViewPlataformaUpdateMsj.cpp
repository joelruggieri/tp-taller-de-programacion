/*
 * .cpp
 *
 *  Created on: 30/10/2013
 *      Author: ezequiel
 */

#include "ViewPlataformaUpdateMsj.h"
#include "../ConstantesComunicacion.h"
ViewPlataformaUpdateMsj::ViewPlataformaUpdateMsj(float x, float y, float ancho) {
	this->x = x;
	this->y = y;
	this->ancho = ancho;
}

ViewPlataformaUpdateMsj::~ViewPlataformaUpdateMsj() {
	// TODO Auto-generated destructor stub
}

void ViewPlataformaUpdateMsj::serialize(YAML::Node* nodo) {
	nodo->push_back(TAG_VIEW_PLATAFORMA);
	nodo->push_back(this->x);
	nodo->push_back(this->y);
	nodo->push_back(this->ancho);

}

NetworkMensaje* ViewPlataformaUpdateMsj::deserialize(YAML::const_iterator & it) {
	float xl = it->as<float>();
	it++;
	float yl = it->as<float>();
	it++;
	float ancho = it->as<float>();
	NetworkMensaje * salida = new ViewPlataformaUpdateMsj(xl,yl,ancho);
	return salida;
}
