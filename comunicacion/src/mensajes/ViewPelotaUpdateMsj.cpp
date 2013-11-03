/*
 * ViewPelotaUpdateMsj.cpp
 *
 *  Created on: 30/10/2013
 *      Author: ezequiel
 */

#include "ViewPelotaUpdateMsj.h"
#include "../ConstantesComunicacion.h"
ViewPelotaUpdateMsj::ViewPelotaUpdateMsj(float x, float y, float angulo, int id) : ViewObjetoUpdateMsj(x,y,angulo,id){
//	this->x = x;
//	this->y = y;
}

ViewPelotaUpdateMsj::~ViewPelotaUpdateMsj() {
	// TODO Auto-generated destructor stub
}

void ViewPelotaUpdateMsj::serialize(YAML::Node* nodo){
//	nodo->push_back(TAG_VIEW_GLOBO);
//	nodo->push_back(this->x);
//	nodo->push_back(this->y);
	super::serialize(nodo);

}

NetworkMensaje* ViewPelotaUpdateMsj::deserialize(YAML::const_iterator & it) {
	int id = it->as<int>();
	it++;
	float xl = it->as<float>();
	it++;
	float yl = it->as<float>();
	it++;
	float angulol = it->as<float>();
	it++;
	NetworkMensaje * salida = new ViewPelotaUpdateMsj(xl,yl, angulol, id);
	return salida;
}

string ViewPelotaUpdateMsj::getTag() {
return TAG_VIEW_PELOTA;
}

void ViewPelotaUpdateMsj::getMensaje() {
	cout << this->x << " " << this->y << " " << this->angulo << endl;
}
