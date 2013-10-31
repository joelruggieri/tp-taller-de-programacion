/*
 * ViewObjetoUpdateMsj.cpp
 *
 *  Created on: 30/10/2013
 *      Author: ezequiel
 */

#include "ViewObjetoUpdateMsj.h"

ViewObjetoUpdateMsj::ViewObjetoUpdateMsj(float x , float y, float angulo) {
this->x = x;
this->y = y;
this->angulo = angulo;
}

ViewObjetoUpdateMsj::~ViewObjetoUpdateMsj() {
	//TODO
}

void ViewObjetoUpdateMsj::serialize(YAML::Node* nodo) {
	nodo->push_back(this->getTag());
	nodo->push_back(this->x);
	nodo->push_back(this->y);
	nodo->push_back(this->angulo);
}

//NetworkMensaje* ViewObjetoUpdateMsj::deserialize(YAML::const_iterator& it) {
//
//
//}
