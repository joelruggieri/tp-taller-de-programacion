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

