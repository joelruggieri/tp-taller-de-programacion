/*
 * ViewEngranajeUpdateMsj.cpp
 *
 *  Created on: 31/10/2013
 *      Author: ezequiel
 */

#include "ViewEngranajeUpdateMsj.h"
#include "../ConstantesComunicacion.h"
ViewEngranajeUpdateMsj::ViewEngranajeUpdateMsj(float x, float y, float angulo, float radio, int id) : ViewObjetoUpdateMsj(x,y,angulo,id) {
this->radio = radio;
}

ViewEngranajeUpdateMsj::~ViewEngranajeUpdateMsj() {
	// TODO Auto-generated destructor stub
}

void ViewEngranajeUpdateMsj::serialize(YAML::Node* nodo) {
	super::serialize(nodo);
	nodo->push_back(this->radio);
}

NetworkMensaje* ViewEngranajeUpdateMsj::deserialize(YAML::const_iterator& it) {
	float xl = it->as<float>();
	it++;
	float yl = it->as<float>();
	it++;
	float angulo = it->as<float>();
	it++;
	float radio = it->as<float>();
	it++;
	NetworkMensaje * salida = new ViewEngranajeUpdateMsj(xl,yl, angulo, radio );
	return salida;
}

string ViewEngranajeUpdateMsj::getTag() {
	return TAG_VIEW_ENGRANAJE;
}

void ViewEngranajeUpdateMsj::getMensaje() {
	cout << this->x << " " << this->y << " " << this->angulo << this->radio << " " << endl;

}
