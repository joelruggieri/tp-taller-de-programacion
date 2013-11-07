/*
 * ViewObjetoConAnchoUpdateMsj.cpp
 *
 *  Created on: 03/11/2013
 *      Author: joel
 */

#include "ViewObjetoConAnchoUpdateMsj.h"
#include "../../ConstantesComunicacion.h"


ViewObjetoConAnchoUpdateMsj::ViewObjetoConAnchoUpdateMsj(float x, float y, float angulo, float ancho, int id): ViewObjetoUpdateMsj(x,y,angulo,id){
	this->ancho = angulo;
}

ViewObjetoConAnchoUpdateMsj::~ViewObjetoConAnchoUpdateMsj() {
	// TODO Auto-generated destructor stub
}

void ViewObjetoConAnchoUpdateMsj::serialize(YAML::Node* nodo) {
	super::serialize(nodo);
	nodo->push_back(this->ancho);

}

NetworkMensaje* ViewObjetoConAnchoUpdateMsj::deserialize(YAML::const_iterator & it) {
	int id = it->as<int>();
	it++;
	float xl = it->as<float>();
	it++;
	float yl = it->as<float>();
	it++;
	float angulol = it->as<float>();
	it++;
	float anchol = it->as<float>();
	it++;
	NetworkMensaje * salida = new ViewObjetoConAnchoUpdateMsj(xl,yl,angulol, anchol, id);
	return salida;
}

string ViewObjetoConAnchoUpdateMsj::getTag() {
	return TAG_VIEW_OBJETO_CON_ANCHO;
}

void ViewObjetoConAnchoUpdateMsj::getMensaje() {
	cout << this->x << " " << this->y << " " << this->angulo << " " <<  this->ancho <<  endl;
}

void ViewObjetoConAnchoUpdateMsj::acept(ViewMsjVisitor* v) {
	v->visit(this);
}
