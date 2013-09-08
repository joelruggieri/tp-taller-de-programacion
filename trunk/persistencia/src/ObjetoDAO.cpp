/*
 * ObjetoDAO.cpp
 *
 *  Created on: 31/08/2013
 *      Author: javier
 */

#include "ObjetoDAO.h"
#include <yaml-cpp/yaml.h>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <assert.h>




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
