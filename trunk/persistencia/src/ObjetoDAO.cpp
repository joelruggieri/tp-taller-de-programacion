/*
 * ObjetoDAO.cpp
 *
 *  Created on: 31/08/2013
 *      Author: javier
 */

#include "ObjetoDAO.h"

ObjetoDAO::ObjetoDAO(): archivo("config.yaml") {

}

ObjetoDAO::~ObjetoDAO() {
}


bool ObjetoDAO::guardar(Circulo* objeto) {
	bool resultado = archivo.guardar(objeto);
	return resultado;
}

bool ObjetoDAO::guardar(Cuadrado* objeto) {
	bool resultado = archivo.guardar(objeto);
	return resultado;
}

bool ObjetoDAO::guardar(Triangulo* objeto) {
	bool resultado = archivo.guardar(objeto);
	return resultado;
}

std::list<Figura*> ObjetoDAO::obtenerTodos() {
	return archivo.obtenerTodos();
}
