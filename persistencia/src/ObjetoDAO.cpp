/*
 * ObjetoDAO.cpp
 *
 *  Created on: 31/08/2013
 *      Author: javier
 */

#include "ObjetoDAO.h"
#include <iostream>
#include <fstream>

ObjetoDAO::ObjetoDAO()/*: archivo("config.yaml") */{

	archivo = new AdministradorDeArchivos("config.yaml");

}

ObjetoDAO::ObjetoDAO(std::string nombre_archivo){

	archivo = new AdministradorDeArchivos(nombre_archivo);
}

ObjetoDAO::~ObjetoDAO() {
	delete archivo;
}


bool ObjetoDAO::guardar(Circulo* objeto) {
	bool resultado = archivo->guardar(objeto);
	return resultado;
}

bool ObjetoDAO::guardar(Cuadrado* objeto) {
	bool resultado = archivo->guardar(objeto);
	return resultado;
}

bool ObjetoDAO::guardar(Triangulo* objeto) {
	bool resultado = archivo->guardar(objeto);
	return resultado;
}

std::list<Figura*> ObjetoDAO::obtenerTodos() {
	return archivo->obtenerTodos();
}
