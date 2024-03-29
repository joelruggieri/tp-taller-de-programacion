/*
 * ViewObjetoUpdateMsj.cpp
 *
 *  Created on: 30/10/2013
 *      Author: ezequiel
 */

#include "ViewObjetoUpdateMsj.h"
#include "../../ConstantesComunicacion.h"


ViewObjetoUpdateMsj::ViewObjetoUpdateMsj(float x , float y, float angulo, int id, char sel,int idEvent): ViewMsj(id, sel){
this->x = x;
this->y = y;
this->angulo = angulo;
this->idEvento = idEvent;
}

ViewObjetoUpdateMsj::~ViewObjetoUpdateMsj() {
	//TODO
}

void ViewObjetoUpdateMsj::serialize(YAML::Emitter & out) {
	out << this->getTag();
	out << this->id;
	out << this->selector;
	out << this->x;
	out << this->y;
	out << this->angulo;
	out<< this->idEvento;
}

NetworkMensaje* ViewObjetoUpdateMsj::deserialize(YAML::const_iterator& it) {
	int id = it->as<int>();
	it++;
	char sel = it->as<char>();
	it++;
	float xl = it->as<float>();
	it++;
	float yl = it->as<float>();
	it++;
	float angulo = it->as<float>();
	it++;
	int idDelEvento = it->as<int>();
	it++;
	NetworkMensaje * salida = new ViewObjetoUpdateMsj(xl,yl, angulo, id, sel,idDelEvento);
	return salida;
}

void ViewObjetoUpdateMsj::getMensaje() {
	cout << this->x << " " << this->y << " " << this->angulo << endl;

}

string ViewObjetoUpdateMsj::getTag(){
	return TAG_VIEW_OBJETO_SIMPLE;
}

void ViewObjetoUpdateMsj::acept(ViewMsjVisitor* v) {
	v->visit(this);
}

float ViewObjetoUpdateMsj::getAngulo() const {
	return angulo;
}

float ViewObjetoUpdateMsj::getX() const {
	return x;
}

float ViewObjetoUpdateMsj::getY() const {
	return y;
}

int ViewObjetoUpdateMsj::getIdEvento() const {
	return idEvento;
}


ViewMsj* ViewObjetoUpdateMsj::clone(int dest) {
	ViewMsj* msj = new ViewObjetoUpdateMsj(x, y, angulo, id,selector,this->idEvento);
	msj->setDestinatario(dest);
	return msj;
}
