/*
 * ViewCarritoMsj.cpp
 *
 *  Created on: 17/11/2013
 *      Author: jonathan
 */

#include "ViewCarritoMsj.h"


ViewCarritoMsj::~ViewCarritoMsj() {
}

void ViewCarritoMsj::acept(ViewMsjVisitor*v) {
	v->visit(this);
}

void ViewCarritoMsj::serialize(YAML::Emitter& out) {
	out << TAG_VIEW_CARRITO;
	out << id;
	out<<x;
	out<< y;
	out<< xi;
	out<< yi;
	out<< xd;
	out<< yd;
	out << rotCarrito;
	out << rotRuedaI;
	out << rotRuedaD;
}

NetworkMensaje* ViewCarritoMsj::deserialize(YAML::const_iterator& it) {
	float x,y,xi,yi,xd, yd,rotCarrito, rotRuedaI, rotRuedaD;
	int id = it->as<int> ();
	it++;
	x = it->as<float>();
	it++;
	y = it->as<float>();
	it++;
	xi = it->as<float>();
	it++;
	yi = it->as<float>();
	it++;
	xd = it->as<float>();
	it++;
	yd = it->as<float>();
	it++;
	rotCarrito = it->as<float>();
	it++;
	rotRuedaI= it->as<float>();
	it++;
	rotRuedaD = it->as<float>();
	it++;
	return new ViewCarritoMsj(x,y,xi,yi,xd, yd,rotCarrito,rotRuedaI,rotRuedaD,id);
}

ViewMsj* ViewCarritoMsj::clone(int destinatario) {
	ViewMsj * msj = new ViewCarritoMsj(x,y,xi,yi,xd, yd,rotCarrito,rotRuedaI,rotRuedaD,this->id);
	msj->setDestinatario(destinatario);
	return  msj;
}

ViewCarritoMsj::ViewCarritoMsj(float x, float y,float xi,float yi,float xd,float yd, float rotCarrito, float rotRuedI, float rotRuedaD,int id):ViewMsj(id, 'a') {
	this->x = x;
	this->y = y;
	this->rotCarrito = rotCarrito;
	this->rotRuedaI = rotRuedI;
	this->rotRuedaD = rotRuedaD;
	this->xi = xi;
	this->yi = yi;
	this->xd = xd;
	this->yd = yd;
}

float ViewCarritoMsj::getRotCarrito() const {
	return rotCarrito;
}

float ViewCarritoMsj::getRotRuedaD() const {
	return rotRuedaD;
}

float ViewCarritoMsj::getRotRuedaI() const {
	return rotRuedaI;
}

float ViewCarritoMsj::getX() const {
	return x;
}

float ViewCarritoMsj::getXd() const {
	return xd;
}

float ViewCarritoMsj::getXi() const {
	return xi;
}

float ViewCarritoMsj::getY() const {
	return y;
}

float ViewCarritoMsj::getYd() const {
	return yd;
}

float ViewCarritoMsj::getYi() const {
	return yi;
}
