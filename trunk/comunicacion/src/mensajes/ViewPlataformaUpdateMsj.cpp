/*
 * .cpp
 *
 *  Created on: 30/10/2013
 *      Author: ezequiel
 */

#include "ViewPlataformaUpdateMsj.h"
#include "../ConstantesComunicacion.h"
ViewPlataformaUpdateMsj::ViewPlataformaUpdateMsj(float x, float y, float angulo, float ancho, int id) : ViewObjetoUpdateMsj(x,y,angulo,id)  {
//	this->x = x;
//	this->y = y;
	this->ancho = ancho;
}

//ViewPlataformaUpdateMsj::~ViewPlataformaUpdateMsj() {
//	// TODO Auto-generated destructor stub
//}

void ViewPlataformaUpdateMsj::serialize(YAML::Node* nodo) {
//	nodo->push_back(TAG_VIEW_PLATAFORMA);
//	nodo->push_back(this->x);
//	nodo->push_back(this->y);
	super::serialize(nodo);
	nodo->push_back(this->ancho);

}

NetworkMensaje* ViewPlataformaUpdateMsj::deserialize(YAML::const_iterator & it) {
	float xl = it->as<float>();
	it++;
	float yl = it->as<float>();
	it++;
	float angulol = it->as<float>();
	it++;
	float anchol = it->as<float>();
	it++;
	NetworkMensaje * salida = new ViewPlataformaUpdateMsj(xl,yl,angulol, anchol);
	return salida;
}


string ViewPlataformaUpdateMsj::getTag() {
	return TAG_VIEW_PLATAFORMA;
}

void ViewPlataformaUpdateMsj::getMensaje() {
	cout << this->x << " " << this->y << " " << this->angulo << " " <<  this->ancho <<  endl;
}
