/*
 * ViewTijeraMsj.cpp
 *
 *  Created on: 17/11/2013
 *      Author: jonathan
 */

#include "ViewTijeraMsj.h"


ViewTijeraMsj::~ViewTijeraMsj() {
}

void ViewTijeraMsj::acept(ViewMsjVisitor*v) {
	v->visit(this);
}

void ViewTijeraMsj::serialize(YAML::Emitter& out) {
	out << TAG_VIEW_TIJERA;
	out << id;
	out<<x;
	out<< y;
	out<< rotacionAspa1;
	out<< rotacionAspa2;
}

NetworkMensaje* ViewTijeraMsj::deserialize(YAML::const_iterator& it) {
	float x,y,rot1,rot2;;
	int id = it->as<int> ();
	it++;
	x = it->as<float>();
	it++;
	y = it->as<float>();
	it++;
	rot1 = it->as<float>();
	it++;
	rot2 = it->as<float>();
	it++;
	return new ViewTijeraMsj(x,y,rot1,rot2,id);
}

ViewMsj* ViewTijeraMsj::clone(int destinatario) {
	ViewMsj * msj = new ViewTijeraMsj(x,y,rotacionAspa1,rotacionAspa2,this->id);
	msj->setDestinatario(destinatario);
	return  msj;
}

ViewTijeraMsj::ViewTijeraMsj(float x, float y,float rotAspa1,float rotAspa2, int id):ViewMsj(id, 'a') {
	this->x = x;
	this->y = y;
	this->rotacionAspa1= rotAspa1;
	this->rotacionAspa2= rotAspa2;
}


float ViewTijeraMsj::getRotacionAspa1() const {
	return rotacionAspa1;
}

float ViewTijeraMsj::getRotacionAspa2() const {
	return rotacionAspa2;
}

float ViewTijeraMsj::getX() const {
	return x;
}

float ViewTijeraMsj::getY() const {
	return y;
}
