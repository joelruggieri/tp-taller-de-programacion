/*
 * ViewObjetoConAnchoUpdateMsj.cpp
 *
 *  Created on: 03/11/2013
 *      Author: joel
 */

#include "ViewObjetoConAnchoUpdateMsj.h"
#include "../../ConstantesComunicacion.h"


ViewObjetoConAnchoUpdateMsj::ViewObjetoConAnchoUpdateMsj(float x, float y, float angulo, float ancho, int id, char sel): ViewObjetoUpdateMsj(x,y,angulo,id, sel){
	this->ancho = ancho;
}

ViewObjetoConAnchoUpdateMsj::~ViewObjetoConAnchoUpdateMsj() {
	// TODO Auto-generated destructor stub
}

void ViewObjetoConAnchoUpdateMsj::serialize(YAML::Emitter & out) {
	super::serialize(out);
	out<< ancho;

}

NetworkMensaje* ViewObjetoConAnchoUpdateMsj::deserialize(YAML::const_iterator & it) {
	int id = it->as<int>();
	it++;
	char sel = it->as<char>();
	it++;
	float xl = it->as<float>();
	it++;
	float yl = it->as<float>();
	it++;
	float angulol = it->as<float>();
	it++;
	float anchol = it->as<float>();
	it++;
	NetworkMensaje * salida = new ViewObjetoConAnchoUpdateMsj(xl,yl,angulol, anchol, id, sel);
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

float ViewObjetoConAnchoUpdateMsj::getAncho() const {
	return ancho;
}

ViewMsj* ViewObjetoConAnchoUpdateMsj::clone(int destinatario) {
	ViewObjetoConAnchoUpdateMsj* msj = new ViewObjetoConAnchoUpdateMsj(x, y, angulo, ancho, id, selector);
	msj->setDestinatario(destinatario);
	return msj;
}
