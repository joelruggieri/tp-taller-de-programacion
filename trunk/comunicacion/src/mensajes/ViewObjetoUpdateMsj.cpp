/*
 * ViewObjetoUpdateMsj.cpp
 *
 *  Created on: 30/10/2013
 *      Author: ezequiel
 */

#include "ViewObjetoUpdateMsj.h"


//ENTREGA3 AGREGAR LA HERENCIA A VIEWMSJ CON ID
ViewObjetoUpdateMsj::ViewObjetoUpdateMsj(float x , float y, float angulo, int id): ViewMsj(id){
this->x = x;
this->y = y;
this->angulo = angulo;
}

ViewObjetoUpdateMsj::~ViewObjetoUpdateMsj() {
	//TODO
}

void ViewObjetoUpdateMsj::serialize(YAML::Node* nodo) {
	//nodo->push_back(this->getTag());
	nodo->push_back(this->id);
	nodo->push_back(this->x);
	nodo->push_back(this->y);
	nodo->push_back(this->angulo);
}

NetworkMensaje* ViewObjetoUpdateMsj::deserialize(YAML::const_iterator& it) {
	int id = it->as<int>();
	it++;
	float xl = it->as<float>();
	it++;
	float yl = it->as<float>();
	it++;
	float angulo = it->as<float>();
	it++;

	NetworkMensaje * salida = new ViewObjetoUpdateMsj(xl,yl, angulo, id);
	return salida;
}
