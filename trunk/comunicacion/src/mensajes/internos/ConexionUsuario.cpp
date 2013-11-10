/*
 * ConexionUsuario.cpp
 *
 *  Created on: 09/11/2013
 *      Author: jonathan
 */

#include "ConexionUsuario.h"

ConexionUsuario::ConexionUsuario(bool on) {
	conectado = on;
}

bool ConexionUsuario::isConectado() const {
	return conectado;
}

ConexionUsuario::~ConexionUsuario() {
	// TODO Auto-generated destructor stub
}

void ConexionUsuario::acept(MensajeInternoVisitor* v) {
	v->visit(this);
}

void ConexionUsuario::serialize(YAML::Node* nodo) {
	nodo->push_back(TAG_INTERNO_CONEXION);
	nodo->push_back(this->conectado);
}

NetworkMensaje* ConexionUsuario::deserialize(YAML::const_iterator& it) {
	bool c= it->as<bool>();
	it++;
	return new ConexionUsuario(c);
}
