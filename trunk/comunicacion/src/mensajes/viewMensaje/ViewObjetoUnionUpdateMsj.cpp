/*
 * ViewObjetoUnionUpdateMsj.cpp
 *
 *  Created on: 03/11/2013
 *      Author: joel
 */

#include "ViewObjetoUnionUpdateMsj.h"
#include "../../ConstantesComunicacion.h"

ViewObjetoUnionUpdateMsj::ViewObjetoUnionUpdateMsj(float x1,float x2, float x3, float x4, float radioInicial, float radioFinal, bool isEstatico, bool conEslabon, float radio, int id, char sel) : ViewObjetoUpdateMsj(x1,x2,0,id, sel) {
	this->xHasta = x3;
	this->yHasta = x4;
	this->radioInicial = radioInicial;
	this->radioFinal = radioFinal;
	this->estatico = isEstatico;
	this->radio = radio ;
	this->conEslabon = conEslabon;
	xEslb = 0;
	yEslb = 0;
}

ViewObjetoUnionUpdateMsj::~ViewObjetoUnionUpdateMsj() {
	// TODO Auto-generated destructor stub
}

void ViewObjetoUnionUpdateMsj::serialize(YAML::Emitter & out) {
	out << this->getTag();
	out << this->id;
	out << this->selector;
	out << x;
	out << y;
	out << xHasta;
	out << yHasta;
	out << radioInicial;
	out << radioFinal;
	out << estatico;
	out << radio;
	out << conEslabon;
	if(conEslabon){
		out << xEslb;
		out << yEslb;
	}
	}

NetworkMensaje* ViewObjetoUnionUpdateMsj::deserialize(YAML::const_iterator& it) {
	int id = it->as<int>();
	it++;
	char sel = it->as<char>();
	it++;
	float xD = it->as<float>();
	it++;
	float yD = it->as<float>();
	it++;
	float xH = it->as<float>();
	it++;
	float yH = it->as<float>();
	it++;
	float radioInicial = it->as<float>();
	it++;
	float radioFinal = it->as<float>();
	it++;
	bool estatico = it->as<bool>();
	it++;
	float radio = it->as<float>();
	it++;
	bool eslabon = it->as<bool>();
	it++;
	ViewObjetoUnionUpdateMsj * salida = new ViewObjetoUnionUpdateMsj(xD,yD, xH, yH,radioInicial, radioFinal,estatico,eslabon, radio,id, sel);
	if(eslabon){
		float xEsl, yEsl;
		xEsl =	it->as<float>();
		it++;
		yEsl = it->as<float>();
		it++;
		salida->setPosEslabon(xEsl,yEsl);
	}
	return salida;
}

string ViewObjetoUnionUpdateMsj::getTag() {
	return TAG_VIEW_OBJETO_UNION;
}

void ViewObjetoUnionUpdateMsj::getMensaje() {
	cout << this->x << " " << this->y<< " " << this->xHasta << " " <<  this->yHasta <<  endl;
}

void ViewObjetoUnionUpdateMsj::acept(ViewMsjVisitor*v) {
	v->visit(this);
}

ViewMsj* ViewObjetoUnionUpdateMsj::clone(int dest) {
	ViewObjetoUnionUpdateMsj * msj = new ViewObjetoUnionUpdateMsj(x,y,xHasta,yHasta,radioInicial, radioFinal,estatico,conEslabon,radio,id,selector);
	msj->setPosEslabon(xEslb,yEslb);
	msj->setDestinatario(dest);
	return msj;

}

float ViewObjetoUnionUpdateMsj::getRadioFinal() const {
	return radioFinal;
}

float ViewObjetoUnionUpdateMsj::getRadioInicial() const {
	return radioInicial;
}

void ViewObjetoUnionUpdateMsj::setPosEslabon(float x, float y) {
	xEslb = x;
	yEslb = y;
}

bool ViewObjetoUnionUpdateMsj::isConEslabon() const {
	return conEslabon;
}

float ViewObjetoUnionUpdateMsj::getXEslb() const {
	return xEslb;
}

float ViewObjetoUnionUpdateMsj::getYEslb() const {
	return yEslb;
}
