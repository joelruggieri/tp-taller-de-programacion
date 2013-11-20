/*
 * MensajeCantidadRestante.cpp
 *
 *  Created on: 19/11/2013
 *      Author: ezequiel
 */

#include "MensajeCantidadRestante.h"

MensajeCantidadRestante::MensajeCantidadRestante(int id , int cantidad) : ViewMsj(id, -1)  {
this->cantidadRestante = cantidad ;


}

MensajeCantidadRestante::~MensajeCantidadRestante() {
	// TODO Auto-generated destructor stub
}

void MensajeCantidadRestante::serialize(YAML::Emitter& out) {
	out << this->getTag();
	out << this->id;
	out << this->cantidadRestante ;
}

NetworkMensaje* MensajeCantidadRestante::deserialize(YAML::const_iterator& it) {
	int id = it->as<int>();
		it++;
	int cant = it->as<int>();
	it++;
	return new MensajeCantidadRestante(id, cant);
}

string MensajeCantidadRestante::getTag() {
	return TAG_CANTIDAD_RESTANTE;
}

void MensajeCantidadRestante::acept(ViewMsjVisitor* v) {
	v->visit(this);

}

ViewMsj* MensajeCantidadRestante::clone(int dest) {
	ViewMsj* msj = new MensajeCantidadRestante(this->id, this->cantidadRestante);
	msj->setDestinatario(dest);
	return msj;
}
